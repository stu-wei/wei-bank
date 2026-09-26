#include "teacher.h"
#include "librarybook.h"
using namespace std;
Teacher::Teacher()
{
	teaId = "";
	teaName = "";
	department = "";
	maxBorrow = 8;
	curBorrow = 0;
}
void Teacher::inputTeacherInfo()
{
	cout << "输入教师工号：";
	cin >> teaId;
	cout << "输入教师姓名：";
	cin >> teaName;
	cout << "输入院系：";
	cin >> department;
	cout << "最大可借本数：";
	cin >> maxBorrow;
	curBorrow = 0;
	borrowBookIdList.clear();
}
void Teacher::setTeacherInfo(string id, string name, string dep, int maxBor)
{
	teaId = id;
	teaName = name;
	department = dep;
	maxBorrow = maxBor;
	curBorrow = 0;
	borrowBookIdList.clear();
}
bool Teacher::borrowBook(LibraryBook& book)
{
	if (curBorrow >= maxBorrow)
	{
		cout << "借书失败：达到借阅上限！" << endl;
		return false;
	}
	if (book.getStill() <= 0)
	{
		cout << "借书失败：没有可借库存！" << endl;
		return false;
	}
	if (book.doBorrow())
	{
		curBorrow++;
		borrowBookIdList.push_back(book.getBookId());
		cout << "教师 借书成功！" << endl;
		return true;
	}
	return false;
}
bool Teacher::returnBook(LibraryBook& book)
{
	if (curBorrow <= 0)
	{
		cout << "还书失败：没有借任何图书！" << endl;
		return false;
	}
	string bid = book.getBookId();
	vector<string>::iterator it = borrowBookIdList.begin();
	for (; it != borrowBookIdList.end(); ++it)
	{
		if (*it == bid)
			break;
	}
	if (it == borrowBookIdList.end())
	{
		cout << "还书失败：你没有借这本书！" << endl;
		return false;
	}
	book.doReturn();
	curBorrow--;
	borrowBookIdList.erase(it);
	cout << "教师 还书成功！" << endl;
	return true;
}
void Teacher::showTeacherInfo() const
{
	cout << "教师信息" << endl;
	cout << "工号：" << teaId << " 姓名：" << teaName << " 院系：" << department << endl;
	cout << "最大可借：" << maxBorrow << "本，已借：" << curBorrow << "本" << endl;
}
int Teacher::getCurBorrow() const
{
	return curBorrow;
}
int Teacher::getMaxBorrow() const
{
	return maxBorrow;
}