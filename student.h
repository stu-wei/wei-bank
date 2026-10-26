#pragma once
#include "Person.h"
using namespace std;
class student : public Person
{
private:
	string className;
	friend class warehouse;
public:
	student();
	virtual ~student() override;
	void inputInfo();
	virtual void showInfo() const override;
};