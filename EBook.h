#pragma once
#include "LibraryResource.h"
using namespace std;
class EBook : public LibraryResource
{
private:
	string fileFormat;
	string downloadUrl;
	friend class warehouse;
public:
	EBook();
	virtual ~EBook() override;
	virtual void inputInfo() override;
	virtual void printInfo() const override;
	virtual bool doBorrow() override;
	virtual void doReturn() override;
	virtual bool isEBook() const override;
	virtual double getPrice() const override;
};