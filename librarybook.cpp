#include "librarybook.h"
using namespace std;

LibraryBook::LibraryBook()
{
	bookid = "";
	title = "";
	writer = "";
	publisher = "";
	price = 0;
	page = 0;
	total = 0;
	still = 0;
}

LibraryBook::LibraryBook(string bid, string t, string w, string pub, double pr, int pg, int tot)
{
	bookid = bid;
	title = t;
	writer = w;
	publisher = pub;
	price = pr;
	page = pg;
	total = tot;
	still = total;
}

void LibraryBook::set(string bid, string t, string w, string pub, double pr, int pg, int tot)
{
	bookid = bid;
	title = t;
	writer = w;
	publisher = pub;
	price = pr;
	page = pg;
	total = tot;
	still = total;
}

string LibraryBook::getBookId() const
{
	return bookid;
}

string LibraryBook::getTitle() const
{
	return title;
}

int LibraryBook::getStill() const
{
	return still;
}

void LibraryBook::inputBookInfo()
{
	cout << "图书编号：";
	cin >> bookid;
	cout << "书名：";
	cin >> title;
	cout << "作者：";
	cin >> writer;
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

bool LibraryBook::checkIsbnValid() const
{
	if (bookid.empty())
		return false;
	return true;
}

bool LibraryBook::doBorrow()
{
	if (still > 0)
	{
		still--;
		return true;
	}
	return false;
}

void LibraryBook::doReturn()
{
	if (still < total)
		still++;
}

void LibraryBook::printInfo() const
{
	cout << "-------------------------" << endl;
	cout << "图书编号：" << bookid << endl;
	cout << "书名：" << title << endl;
	cout << "作者：" << writer << endl;
	cout << "出版社：" << publisher << endl;
	cout << "价格：" << price << "元" << endl;
	cout << "页数：" << page << "页" << endl;
	cout << "总：" << total << " 可借：" << still << endl;
	if (still > 0)
		cout << "状态：可借阅" << endl;
	else
		cout << "状态：不可借阅" << endl;
}