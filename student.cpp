#include "student.h"
#include "warehouse.h"
student::student() : Person()
{
	className = "";
	maxBorrow = 3;
}
student::~student()
{
}
void student::inputInfo()
{
	cout << "\n====录入学生信息====" << endl;
	cout << "学号：";
	cin >> id;
	cout << "姓名：";
	cin >> name;
	cout << "院系：";
	cin >> department;
	cout << "班级：";
	cin >> className;
	maxBorrow = 3;
	curBorrow = 0;
}
void student::showInfo() const
{
	cout << "\n--------学生信息--------" << endl;
	cout << "学号：" << id << endl;
	cout << "姓名：" << name << endl;
	cout << "院系：" << department << endl;
	cout << "班级：" << className << endl;
	cout << "最大可借纸质资源数量：" << maxBorrow << endl;
	cout << "当前已借纸质资源：" << curBorrow << endl;
}