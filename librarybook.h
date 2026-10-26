#pragma once
#include <iostream>
#include <string>
#include "LibraryResource.h"
using namespace std;
class librarybook : public LibraryResource
{
private:
	double price;
	int page;
	friend class warehouse;
public:
	librarybook();
	librarybook(string bid, string t, string w, string pub, double pr, int pg, int tot);
	void set(string bid, string t, string w, string pub, double pr, int pg, int tot);
	bool checkIsbnValid() const;
	virtual ~librarybook() override;
	virtual void inputInfo() override;
	virtual void printInfo() const override;
	virtual bool doBorrow() override;
	virtual void doReturn() override;
	virtual bool isEBook() const override;
	virtual double getPrice() const override;
};