#pragma once
#include <iostream>
#include <vector>
#include "librarybook.h"
using namespace std;

class Warehouse
{
private:
	vector<LibraryBook> bookList;
public:
	void addBook(const LibraryBook& bk);
	void showAllBooks() const;
	LibraryBook* findBookById(const string& bid);
};