#include "teacher.h"
teacher::teacher() : Person()
{
	jobTitle = "";
	maxBorrow = 5;
}
teacher::~teacher()
{
}
void teacher::inputInfo()
{
	cout << "\n====录入教师信息====" << endl;
	cout << "工号：";
	cin >> id;
	cout << "姓名：";
	cin >> name;
	cout << "院系：";
	cin >> department;
	cout << "职称：";
	cin >> jobTitle;
	maxBorrow = 5;
	curBorrow = 0;
}
void teacher::showInfo() const
{
	cout << "\n--------教师信息--------" << endl;
	cout << "工号：" << id << endl;
	cout << "姓名：" << name << endl;
	cout << "院系：" << department << endl;
	cout << "职称：" << jobTitle << endl;
	cout << "最大可借纸质资源数量：" << maxBorrow << endl;
	cout << "当前已借纸质资源：" << curBorrow << endl;
}