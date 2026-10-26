#pragma once
#include<iostream>
#include<string>
using namespace std;

class LibraryResource
{
protected:
	string resId;
	string title;
	string author;
	string publisher;
	int total=0;
	int still=0;
public:
	virtual ~LibraryResource() {}
	virtual void inputInfo() = 0;
	virtual void printInfo() const = 0;
	virtual bool doBorrow() = 0;
	virtual void doReturn() = 0;
	virtual bool isEBook() const = 0;
	virtual double getPrice() const = 0;

	string getResId() const
	{
		return resId;
	}
	int getStill() const
	{
		return still;
	}

	string getTitle() const
	{
		return title;
	}
};