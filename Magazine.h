#pragma once
#include "LibraryResource.h"
using namespace std;
class Magazine : public LibraryResource
{
private:
	int pubYear;
	int issue;
	double price;
	friend class warehouse;
public:
	Magazine();
	virtual ~Magazine() override;
	virtual void inputInfo() override;
	virtual void printInfo() const override;
	virtual bool doBorrow() override;
	virtual void doReturn() override;
	virtual bool isEBook() const override;
	virtual double getPrice() const override;
};