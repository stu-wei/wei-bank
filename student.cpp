#include "student.h"
#include "librarybook.h"
using namespace std;
Student::Student()
{
	stuId = "";
	stuName = "";
	department = "";
	maxBorrow = 3;
	curBorrow = 0;
}
void Student::inputStudentInfo()
{
	cout << "输入学生学号：";
	cin >> stuId;
	cout << "输入学生姓名：";
	cin >> stuName;
	cout << "输入院系：";
	cin >> department;
	cout << "最大可借本数：";
	cin >> maxBorrow;
	curBorrow = 0;
	borrowBookIdList.clear();
}
void Student::setStudentInfo(string id, string name, string dep, int maxBor)
{
	stuId = id;
	stuName = name;
	department = dep;
	maxBorrow = maxBor;
	curBorrow = 0;
	borrowBookIdList.clear();
}
bool Student::borrowBook(LibraryBook& book)
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
		cout << "学生 借书成功！" << endl;
		return true;
	}
	return false;
}
bool Student::returnBook(LibraryBook& book)
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
	cout << "学生 还书成功！" << endl;
	return true;
}
void Student::showStudentInfo() const
{
	cout << "学生信息" << endl;
	cout << "学号：" << stuId << " 姓名：" << stuName << " 院系：" << department << endl;
	cout << "最大可借：" << maxBorrow << "本，已借：" << curBorrow << "本" << endl;
}
int Student::getCurBorrow() const
{
	return curBorrow;
}
int Student::getMaxBorrow() const
{
	return maxBorrow;
}