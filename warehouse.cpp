#include "warehouse.h"
using namespace std;

void Warehouse::addBook(const LibraryBook& bk)
{
	bookList.push_back(bk);
}

void Warehouse::showAllBooks() const
{
	cout << "===图书清单==" << endl;
	for (auto& bk : bookList)
	{
		bk.printInfo();
	}
}
LibraryBook* Warehouse::findBookById(const string& bid)
{
	for (auto& bk : bookList)
	{
		if (bk.getBookId() == bid)
		{
			return &bk;
		}
	}
	return nullptr;
}