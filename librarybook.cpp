#include "librarybook.h"
using namespace std;
librarybook::librarybook()
{
	resId = "";
	title = "";
	author = "";
	publisher = "";
	total = 0;
	still = 0;
	price = 0;
	page = 0;
}
librarybook::librarybook(string bid, string t, string w, string pub, double pr, int pg, int tot)
{
	resId = bid;
	title = t;
	author = w;
	publisher = pub;
	total = tot;
	still = tot;
	price = pr;
	page = pg;
}
void librarybook::set(string bid, string t, string w, string pub, double pr, int pg, int tot)
{
	resId = bid;
	title = t;
	author = w;
	publisher = pub;
	total = tot;
	still = tot;
	price = pr;
	page = pg;
}
bool librarybook::checkIsbnValid() const
{
	if (resId.empty())
		return false;
	return true;
}
librarybook::~librarybook()
{
}
bool librarybook::doBorrow()
{
	if (still > 0)
	{
		still--;
		return true;
	}
	return false;
}
void librarybook::doReturn()
{
	if (still < total)
		still++;
}

bool librarybook::isEBook() const 
{
	return false;
}
double librarybook::getPrice() const
{
	return price;
}

void librarybook::inputInfo()
{
	cout << "图书编号：";
	cin >> resId;
	cout << "书名：";
	cin >> title;
	cout << "作者：";
	cin >> author;
	cout << "出版社：";
	cin >> publisher;
	cout << "价格：";
	cin >> price;
	cout << "页数：";
	cin >> page;
	cout << "总数量：";
	cin >> total;
	still = total;
}
void librarybook::printInfo() const
{
	cout << "-------------------------" << endl;
	cout << "图书编号：" << resId << endl;
	cout << "书名：" << title << endl;
	cout << "作者：" << author << endl;
	cout << "出版社：" << publisher << endl;
	cout << "价格：" << price << "元" << endl;
	cout << "页数：" << page << "页" << endl;
	cout << "总：" << total << " 可借：" << still << endl;
	if (still > 0)
		cout << "状态：可借阅" << endl;
	else
		cout << "状态：不可借阅" << endl;
}