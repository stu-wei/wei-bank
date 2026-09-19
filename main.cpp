#include<iostream>
#include"librarybook.h"
using namespace std;
int main() {
	LibraryBook b1;
	LibraryBook b2("A2", "C语言", "bob", "高等教育出版社", 42, 2);
	cout << "图书一" << endl;
	b1.printInfo();
	cout << "图书二" << endl;
	b2.printInfo();
	cout << "尝试借b2" << endl;
	if (b2.doBorrow()) {
		cout << "借书成功" << endl;
	}
	else {
		cout << "借书失败" << endl;
	}
	b2.printInfo();
	cout << "归还b2" << endl;
	b2.doReturn();
	b2.printInfo();
	cout << "修改b1信息" << endl;
	b1.set("A3", "数据结构", "tom", "机械工程出版社", 50, 3);
	b1.printInfo();
	return 0;
}