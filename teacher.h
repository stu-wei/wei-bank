#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LibraryBook;

class Teacher
{
private:
	string teaId;
	string teaName;
	string department;
	int maxBorrow;
	int curBorrow;
	vector<string> borrowBookIdList;
public:
	Teacher();
	void inputTeacherInfo();
	void setTeacherInfo(string id, string name, string dep, int maxBor);

	bool borrowBook(LibraryBook& book);
	bool returnBook(LibraryBook& book);

	void showTeacherInfo() const;
	int getCurBorrow() const;
	int getMaxBorrow() const;
};