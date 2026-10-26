#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include "warehouse.h"

Person::Person()
{
	id = "";
	name = "";
	department = "";
	maxBorrow = 0;
	curBorrow = 0;
	recordList.clear();
	ebookViewList.clear();
}
Person::Person(string id, string name, string dep, int maxBor)
{
	this->id = id;
	this->name = name;
	this->department = dep;
	this->maxBorrow = maxBor;
	this->curBorrow = 0;
	recordList.clear();
	ebookViewList.clear();
}

void Person::getNowDate(int& y, int& m, int& d) const
{
	time_t now = time(nullptr);
	tm* t = localtime(&now);
	y = t->tm_year + 1900;
	m = t->tm_mon + 1;
	d = t->tm_mday;
}

bool Person::borrowBook(LibraryResource& res)
{
	if (res.isEBook())
	{
		if (res.doBorrow())
		{
			ebookViewList.push_back(res.getResId());
			cout << "电子书馆内阅览成功！已记录阅览记录；电子书不可带出图书馆，不计借阅名额，无超期罚款。" << endl;
			return true;
		}
		cout << "电子书访问失败！" << endl;
		return false;
	}

	if (curBorrow >= maxBorrow)
	{
		cout << "借书失败：达到纸质资源借阅上限！上限：" << maxBorrow << endl;
		return false;
	}
	if (res.getStill() <= 0)
	{
		cout << "借书失败：库存不足，暂时不可借！" << endl;
		return false;
	}
	if (res.doBorrow())
	{
		int y, m, d;
		getNowDate(y, m, d);
		BorrowRecord rec(res.getResId(), y, m, d);
		recordList.push_back(rec);
		curBorrow++;
		cout << "纸质资源借阅成功！已生成馆外借阅记录。" << endl;
		return true;
	}
	return false;
}

bool Person::returnBook(LibraryResource& res)
{
	string rid = res.getResId();
	int yNow, mNow, dNow;
	getNowDate(yNow, mNow, dNow);

	for (auto& rec : recordList)
	{
		if (rec.resId == rid && !rec.isReturned && !rec.isLost)
		{
			int monthGap = rec.getMonthDiff(yNow, mNow, dNow);
			if (monthGap > 4)
			{
				rec.fine = res.getPrice() * 0.5;
				cout << "该书已经超期" << monthGap << "个月，产生罚款：" << rec.fine << "元（书价50%）" << endl;
			}

			res.doReturn();
			rec.isReturned = true;
			curBorrow--;
			cout << "归还资源成功！" << endl;
			return true;
		}
	}
	cout << "还书失败：没有对应的未归还借阅记录！" << endl;
	return false;
}

bool Person::reportLost(const string& rid, warehouse& ware)
{
	int yNow, mNow, dNow;
	getNowDate(yNow, mNow, dNow);

	for (auto& rec : recordList)
	{
		if (rec.resId == rid && !rec.isReturned && !rec.isLost)
		{
			LibraryResource* pRes = ware.findResById(rid);
			if (pRes == nullptr)
			{
				cout << "找不到该资源！" << endl;
				return false;
			}
			double bookPrice = pRes->getPrice();
			rec.fine = bookPrice;
			rec.isLost = true;
			curBorrow--;
			cout << "书籍丢失！需要原价赔偿：" << bookPrice << "元" << endl;
			return true;
		}
	}
	cout << "找不到未归还的该借阅记录，上报丢失失败！" << endl;
	return false;
}

void Person::calcAllFine(warehouse& ware)
{
	int yNow, mNow, dNow;
	getNowDate(yNow, mNow, dNow);
	for (auto& rec : recordList)
	{
		if (rec.isReturned || rec.isLost) continue;
		LibraryResource* pRes = ware.findResById(rec.resId);
		if (pRes == nullptr) continue;

		int gap = rec.getMonthDiff(yNow, mNow, dNow);
		if (gap > 4)
		{
			rec.fine = pRes->getPrice() * 0.5;
		}
	}
}

void Person::showFullBorrowInfo(warehouse& ware) const
{
	cout << "\n========完整记录【" << name << "(" << id << ")】========" << endl;

	cout << "-----【馆外纸质借阅记录】-----" << endl;
	if (recordList.empty())
	{
		cout << "  暂无纸质借阅记录\n";
	}
	else
	{
		for (const auto& rec : recordList)
		{
			LibraryResource* pRes = ware.findResById(rec.resId);
			cout << "资源编号：" << rec.resId;
			if (pRes != nullptr) cout << " |名称：" << pRes->getTitle();
			cout << "\n\t借阅日期：" << rec.borrowYear << "-" << rec.borrowMonth << "-" << rec.borrowDay;
			cout << "\n\t状态：";
			if (rec.isLost) cout << "【已上报丢失】";
			else if (rec.isReturned) cout << "【已归还】";
			else cout << "【借阅中】";
			cout << "\n\t罚款金额：" << rec.fine << " 元\n";
		}
	}

	cout << "\n-----【馆内电子书阅览记录】-----" << endl;
	if (ebookViewList.empty())
	{
		cout << "  暂无电子书阅览记录\n";
	}
	else
	{
		for (auto& rid : ebookViewList)
		{
			cout << "电子书资源编号：" << rid << endl;
		}
	}
}

string Person::getId() const
{
	return id;
}
string Person::getName() const
{
	return name;
}
string Person::getDepartment() const
{
	return department;
}
int Person::getCurBorrow() const
{
	return curBorrow;
}
int Person::getMaxBorrow() const
{
	return maxBorrow;
}