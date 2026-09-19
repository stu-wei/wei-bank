#pragma once
#include<iostream>
#include<string>
using namespace std;
class LibraryBook {
private:
	string bookid;
	string title;
	string writer;
	string publisher;
	double price;
	int total;
	int still;
public:
	LibraryBook();
	LibraryBook(string bookid, string t, string w, string pub, double p, int total);
	void set(string bookid, string t, string w, string pub, double p, int total);
	string getBook() const;
	string getTitle() const;
	bool doBorrow();
	void doReturn();
	void printInfo() const;
};