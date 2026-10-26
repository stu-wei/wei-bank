#pragma once
#include "Person.h"
using namespace std;
class teacher : public Person
{
private:
	string jobTitle;
	friend class warehouse;
public:
	teacher();
	virtual ~teacher() override;
	void inputInfo();
	virtual void showInfo() const override;
};