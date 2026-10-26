#define _CRT_SECURE_NO_WARNINGS
#include "warehouse.h"
#include "librarybook.h"
#include "EBook.h"
#include "Magazine.h"
#include "student.h"
#include "teacher.h"
#include "BorrowRecord.h"
#include <fstream>
#include <sstream>

warehouse::warehouse()
{
}
warehouse::~warehouse()
{
	for (auto p : resList) delete p;
	for (auto p : userList) delete p;
	resList.clear();
	userList.clear();
}

void warehouse::addResource(LibraryResource* p)
{
	resList.push_back(p);
}
void warehouse::addUser(Person* p)
{
	userList.push_back(p);
}

LibraryResource* warehouse::findResById(const string& rid)
{
	for (auto p : resList)
	{
		if (p->getResId() == rid)
			return p;
	}
	return nullptr;
}
Person* warehouse::findUserById(const string& uid)
{
	for (auto p : userList)
	{
		if (p->getId() == uid)
			return p;
	}
	return nullptr;
}

void warehouse::showAllResource() const
{
	cout << "\n====全部馆藏资源====" << endl;
	if (resList.empty())
	{
		cout << "暂无馆藏资源\n";
		return;
	}
	for (auto p : resList)
	{
		p->printInfo();
	}
}
void warehouse::showAllUser() const
{
	cout << "\n====全部用户====" << endl;
	if (userList.empty())
	{
		cout << "暂无用户\n";
		return;
	}
	for (auto p : userList)
	{
		p->showInfo();
	}
}

bool warehouse::saveAllData()
{
	//1.保存馆藏 resource.txt
	ofstream fRes("./resource.txt");
	if (!fRes.is_open())
	{
		cout << "打开resource.txt失败，无法保存资源！" << endl;
		return false;
	}
	for (auto p : resList)
	{
		if (librarybook* bk = dynamic_cast<librarybook*>(p))
		{
			fRes << "BOOK "
				<< bk->getResId() << " "
				<< bk->getTitle() << " "
				<< bk->author << " "
				<< bk->publisher << " "
				<< bk->getPrice() << " "
				<< bk->page << " "
				<< bk->total << " "
				<< bk->still << endl;
		}
		else if (EBook* eb = dynamic_cast<EBook*>(p))
		{
			fRes << "EBOOK "
				<< eb->getResId() << " "
				<< eb->getTitle() << " "
				<< eb->author << " "
				<< eb->publisher << " "
				<< eb->total << " "
				<< eb->still << " "
				<< eb->fileFormat << " "
				<< eb->downloadUrl << endl;
		}
		else if (Magazine* mg = dynamic_cast<Magazine*>(p))
		{
			fRes << "MAG "
				<< mg->getResId() << " "
				<< mg->getTitle() << " "
				<< mg->author << " "
				<< mg->publisher << " "
				<< mg->getPrice() << " "
				<< mg->pubYear << " "
				<< mg->issue << " "
				<< mg->total << " "
				<< mg->still << endl;
		}
	}
	fRes.close();

	//2.保存用户基础信息 user.txt
	ofstream fUser("./user.txt");
	if (!fUser.is_open())
	{
		cout << "打开user.txt失败！" << endl;
		return false;
	}
	for (auto p : userList)
	{
		if (student* stu = dynamic_cast<student*>(p))
		{
			fUser << "STU "
				<< stu->getId() << " "
				<< stu->getName() << " "
				<< stu->getDepartment() << " "
				<< stu->className << " "
				<< stu->getCurBorrow() << endl;
		}
		else if (teacher* tea = dynamic_cast<teacher*>(p))
		{
			fUser << "TEA "
				<< tea->getId() << " "
				<< tea->getName() << " "
				<< tea->getDepartment() << " "
				<< tea->jobTitle << " "
				<< tea->getCurBorrow() << endl;
		}
	}
	fUser.close();

	//====新增：保存每个用户的借阅记录 record.txt====
	//格式：用户ID|resId|borrowY|borrowM|borrowD|isReturned|isLost|fine
	ofstream fRec("./record.txt");
	if (!fRec.is_open())
	{
		cout << "打开record.txt失败！" << endl;
		return false;
	}
	for (Person* p : userList)
	{
		//访问Person里面recordList，这里需要给warehouse增加友元！！
		for (auto& rec : p->recordList)
		{
			fRec << p->getId() << "|"
				<< rec.resId << "|"
				<< rec.borrowYear << "|"
				<< rec.borrowMonth << "|"
				<< rec.borrowDay << "|"
				<< rec.isReturned << "|"
				<< rec.isLost << "|"
				<< rec.fine << "\n";
		}
	}
	fRec.close();

	//====新增：保存电子书阅览记录 ebook_view.txt====
	//格式：用户ID|电子书资源ID
	ofstream fEbook("./ebook_view.txt");
	if (!fEbook.is_open())
	{
		cout << "打开ebook_view.txt失败！" << endl;
		return false;
	}
	for (Person* p : userList)
	{
		for (auto& rid : p->ebookViewList)
		{
			fEbook << p->getId() << "|" << rid << "\n";
		}
	}
	fEbook.close();

	cout << "所有数据保存成功！" << endl;
	return true;
}

bool warehouse::loadAllData()
{
	//清空现有内存数据
	for (auto p : resList) delete p;
	resList.clear();
	for (auto p : userList) delete p;
	userList.clear();

	//1.加载资源 resource.txt
	ifstream fRes("./resource.txt");
	if (fRes.is_open())
	{
		string type;
		while (fRes >> type)
		{
			if (type == "BOOK")
			{
				string rid, title, auth, pub;
				double pr;
				int pg, tot, st;
				fRes >> rid >> title >> auth >> pub >> pr >> pg >> tot >> st;
				librarybook* bk = new librarybook;
				bk->set(rid, title, auth, pub, pr, pg, tot);
				bk->still = st;
				addResource(bk);
			}
			else if (type == "EBOOK")
			{
				string rid, title, auth, pub, fmt, url;
				int tot, st;
				fRes >> rid >> title >> auth >> pub >> tot >> st >> fmt >> url;
				EBook* eb = new EBook;
				eb->resId = rid; eb->title = title; eb->author = auth; eb->publisher = pub;
				eb->total = tot; eb->still = st;
				eb->fileFormat = fmt; eb->downloadUrl = url;
				addResource(eb);
			}
			else if (type == "MAG")
			{
				string rid, title, auth, pub;
				double pr;
				int py, iss, tot, st;
				fRes >> rid >> title >> auth >> pub >> pr >> py >> iss >> tot >> st;
				Magazine* mg = new Magazine;
				mg->resId = rid; mg->title = title; mg->author = auth; mg->publisher = pub;
				mg->price = pr; mg->pubYear = py; mg->issue = iss;
				mg->total = tot; mg->still = st;
				addResource(mg);
			}
		}
		fRes.close();
	}

	//2.加载用户 user.txt
	ifstream fUser("./user.txt");
	if (fUser.is_open())
	{
		string type;
		while (fUser >> type)
		{
			if (type == "STU")
			{
				string uid, name, dep, cls;
				int curBor;
				fUser >> uid >> name >> dep >> cls >> curBor;
				student* s = new student;
				s->id = uid;
				s->name = name;
				s->department = dep;
				s->className = cls;
				s->maxBorrow = 3;
				s->curBorrow = curBor;
				addUser(s);
			}
			else if (type == "TEA")
			{
				string uid, name, dep, job;
				int curBor;
				fUser >> uid >> name >> dep >> job >> curBor;
				teacher* t = new teacher;
				t->id = uid;
				t->name = name;
				t->department = dep;
				t->jobTitle = job;
				t->maxBorrow = 5;
				t->curBorrow = curBor;
				addUser(t);
			}
		}
		fUser.close();
	}

	//====加载借阅记录 record.txt====
	ifstream fRec("./record.txt");
	if (fRec.is_open())
	{
		string line;
		while (getline(fRec, line))
		{
			if (line.empty()) continue;
			stringstream ss(line);
			vector<string> items;
			string token;
			while (getline(ss, token, '|'))
			{
				items.push_back(token);
			}
			if (items.size() != 8) continue;
			string uid = items[0];
			string rid = items[1];
			int y = stoi(items[2]);
			int m = stoi(items[3]);
			int d = stoi(items[4]);
			bool ret = stoi(items[5]);
			bool lost = stoi(items[6]);
			double fine = stod(items[7]);

			Person* u = findUserById(uid);
			if (u != nullptr)
			{
				BorrowRecord rec(rid, y, m, d);
				rec.isReturned = ret;
				rec.isLost = lost;
				rec.fine = fine;
				u->recordList.push_back(rec);
			}
		}
		fRec.close();
	}

	//====加载电子书阅览记录 ebook_view.txt====
	ifstream fEbook("./ebook_view.txt");
	if (fEbook.is_open())
	{
		string line;
		while (getline(fEbook, line))
		{
			if (line.empty()) continue;
			stringstream ss(line);
			vector<string> items;
			string token;
			while (getline(ss, token, '|'))
			{
				items.push_back(token);
			}
			if (items.size() != 2) continue;
			string uid = items[0];
			string rid = items[1];
			Person* u = findUserById(uid);
			if (u != nullptr)
			{
				u->ebookViewList.push_back(rid);
			}
		}
		fEbook.close();
	}

	cout << "数据加载完成！" << endl;
	return true;
}