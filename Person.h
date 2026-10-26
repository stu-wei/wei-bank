#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include "LibraryResource.h"
#include "BorrowRecord.h"

class warehouse;

using namespace std;

class Person
{
protected:
	string id;
	string name;
	string department;
	int maxBorrow;
	int curBorrow;

	vector<BorrowRecord> recordList;
	vector<string> ebookViewList;
	friend class warehouse;
public:
	Person();
	Person(string id, string name, string dep, int maxBor);
	virtual ~Person() {}

	virtual void showInfo() const = 0;

	bool borrowBook(LibraryResource& res);
	bool returnBook(LibraryResource& res);
	bool reportLost(const string& rid, warehouse& ware);

	void calcAllFine(warehouse& ware);
	void showFullBorrowInfo(warehouse& ware) const;

	string getId() const;
	string getName() const;
	string getDepartment() const;
	int getCurBorrow() const;
	int getMaxBorrow() const;

	void getNowDate(int& y, int& m, int& d) const;
};