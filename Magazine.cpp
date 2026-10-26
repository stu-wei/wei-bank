#include "Magazine.h"
using namespace std;
Magazine::Magazine()
{
	resId = "";
	title = "";
	author = "";
	publisher = "";
	total = 0;
	still = 0;
	pubYear = 0;
	issue = 0;
	price = 0;
}
Magazine::~Magazine()
{
}
bool Magazine::doBorrow()
{
	if (still > 0)
	{
		still--;
		return true;
	}
	return false;
}
void Magazine::doReturn()
{
	if (still < total)
		still++;
}

bool Magazine::isEBook() const 
{
	return false;
}

double Magazine::getPrice() const
{
	return price;
}

void Magazine::inputInfo()
{
	cout << "\n====录入杂志期刊====" << endl;
	cout << "杂志编号：";
	cin >> resId;
	cout << "杂志名称：";
	cin >> title;
	cout << "主编：";
	cin >> author;
	cout << "出版单位：";
	cin >> publisher;
	cout << "单本价格：";
	cin >> price;
	cout << "总册数：";
	cin >> total;
	still = total;
	cout << "出版年份：";
	cin >> pubYear;
	cout << "期号：";
	cin >> issue;
}
void Magazine::printInfo() const
{
	cout << "----------杂志期刊----------" << endl;
	cout << "杂志编号：" << resId << endl;
	cout << "杂志名称：" << title << endl;
	cout << "主编：" << author << endl;
	cout << "出版单位：" << publisher << endl;
	cout << "单本价格：" << price << "元" << endl;
	cout << "总：" << total << " 可借：" << still << endl;
	cout << "出版年份：" << pubYear << " 第" << issue << "期" << endl;
	if (still > 0)
		cout << "状态：可借阅" << endl;
	else
		cout << "状态：不可借阅" << endl;
}