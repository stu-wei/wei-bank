#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LibraryBook;

class Student
{
private:
	string stuId;
	string stuName;
	string department;
	int maxBorrow;
	int curBorrow;
	vector<string> borrowBookIdList;
public:
	Student();
	void inputStudentInfo();
	void setStudentInfo(string id, string name, string dep, int maxBor);

	bool borrowBook(LibraryBook& book);
	bool returnBook(LibraryBook& book);

	void showStudentInfo() const;
	int getCurBorrow() const;
	int getMaxBorrow() const;
};