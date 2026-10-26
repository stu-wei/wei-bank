#include "EBook.h"
using namespace std;
EBook::EBook()
{
	resId = "";
	title = "";
	author = "";
	publisher = "";
	total = 0;
	still = 0;
	fileFormat = "";
	downloadUrl = "";
}
EBook::~EBook()
{
}
bool EBook::doBorrow()
{
	return true;
}
void EBook::doReturn()
{
}
// 去掉 override！！
bool EBook::isEBook() const
{
	return true;
}
double EBook::getPrice() const
{
	return 0.0;
}

void EBook::inputInfo()
{
	cout << "\n====录入电子图书====" << endl;
	cout << "资源编号：";
	cin >> resId;
	cout << "电子书名称：";
	cin >> title;
	cout << "作者：";
	cin >> author;
	cout << "出版社：";
	cin >> publisher;
	cout << "授权副本总数：";
	cin >> total;
	still = total;
	cout << "文件格式(pdf/epub)：";
	cin >> fileFormat;
	cout << "访问链接：";
	cin >> downloadUrl;
}
void EBook::printInfo() const
{
	cout << "----------电子图书----------" << endl;
	cout << "资源编号：" << resId << endl;
	cout << "电子书名称：" << title << endl;
	cout << "作者：" << author << endl;
	cout << "出版社：" << publisher << endl;
	cout << "授权副本：" << total << "（电子书不限并发阅览）" << endl;
	cout << "文件格式：" << fileFormat << endl;
	cout << "访问链接：" << downloadUrl << endl;
	cout << "状态：仅馆内阅览" << endl;
}