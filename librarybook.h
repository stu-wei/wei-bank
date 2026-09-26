#pragma once
#include <iostream>
#include <string>
using namespace std;

class LibraryBook
{
private:
	string bookid;
	string title;
	string writer;
	string publisher;
	double price;
	int page;
	int total;
	int still;
public:
	LibraryBook();
	LibraryBook(string bid, string t, string w, string pub, double pr, int pg, int tot);

	void set(string bid, string t, string w, string pub, double pr, int pg, int tot);

	string getBookId() const;
	string getTitle() const;
	int getStill() const;

	void inputBookInfo();
	bool checkIsbnValid() const;

	bool doBorrow();
	void doReturn();
	void printInfo() const;
};