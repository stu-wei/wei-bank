#include "warehouse.h"
using namespace std;

void Warehouse::addBook(const LibraryBook& bk)
{
	bookList.push_back(bk);
}

void Warehouse::showAllBooks() const
{
	cout << "\n====仓库全部图书清单====" << endl;
	for (auto& bk : bookList)
	{
		bk.printInfo();
	}
}

// 重点改动：auto& bk 引用，不是拷贝！
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