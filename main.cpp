#include <iostream>
#include <string>
#include <limits>
#include "librarybook.h"
#include "student.h"
#include "teacher.h"
#include "warehouse.h"
using namespace std;

int main()
{
	Warehouse ware;
	Student stu;
	Teacher tea;
	int op;

	while (true)
	{
		cout << "\n========图书馆管理系统========" << endl;
		cout << "1 录入学生信息" << endl;
		cout << "2 录入教师信息" << endl;
		cout << "3 录入一本图书，存入仓库" << endl;
		cout << "4 查看学生信息" << endl;
		cout << "5 查看教师信息" << endl;
		cout << "6 查看仓库全部图书" << endl;
		cout << "7 学生借书（输入图书编号）" << endl;
		cout << "8 学生还书（输入图书编号）" << endl;
		cout << "9 教师借书（输入图书编号）" << endl;
		cout << "10 教师还书（输入图书编号）" << endl;
		cout << "11 退出程序" << endl;
		cout << "请输入操作序号：";

		// =========核心修复：清空输入缓冲区，防止无限刷屏=========
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (!(cin >> op))
		{
			cout << "输入错误！请输入数字！" << endl;
			continue;
		}

		if (op == 11)
		{
			cout << "程序结束" << endl;
			break;
		}

		switch (op)
		{
		case 1:
			stu.inputStudentInfo();
			break;
		case 2:
			tea.inputTeacherInfo();
			break;
		case 3:
		{
			LibraryBook tempBook;
			tempBook.inputBookInfo();
			ware.addBook(tempBook);
			cout << "该图书已经成功加入仓库！" << endl;
			break;
		}
		case 4:
			stu.showStudentInfo();
			break;
		case 5:
			tea.showTeacherInfo();
			break;
		case 6:
			ware.showAllBooks();
			break;
		case 7:
		{
			string bid;
			cout << "请输入要借的图书编号：";
			cin >> bid;
			LibraryBook* p = ware.findBookById(bid);
			if (p == nullptr)
			{
				cout << "仓库找不到这本图书！" << endl;
				break;
			}
			stu.borrowBook(*p);
			break;
		}
		case 8:
		{
			string bid;
			cout << "请输入要还的图书编号：";
			cin >> bid;
			LibraryBook* p = ware.findBookById(bid);
			if (p == nullptr)
			{
				cout << "仓库找不到这本图书！" << endl;
				break;
			}
			stu.returnBook(*p);
			break;
		}
		case 9:
		{
			string bid;
			cout << "请输入要借的图书编号：";
			cin >> bid;
			LibraryBook* p = ware.findBookById(bid);
			if (p == nullptr)
			{
				cout << "仓库找不到这本图书！" << endl;
				break;
			}
			tea.borrowBook(*p);
			break;
		}
		case 10:
		{
			string bid;
			cout << "请输入要还的图书编号：";
			cin >> bid;
			LibraryBook* p = ware.findBookById(bid);
			if (p == nullptr)
			{
				cout << "仓库找不到这本图书！" << endl;
				break;
			}
			tea.returnBook(*p);
			break;
		}
		default:
			cout << "输入选项无效，请重新输入！" << endl;
			break;
		}
	}
	return 0;
}