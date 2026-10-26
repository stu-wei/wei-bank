#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include "LibraryResource.h"
#include "Person.h"
using namespace std;

class warehouse
{
private:
	vector<LibraryResource*> resList;
	vector<Person*> userList;
public:
	warehouse();
	~warehouse();

	void addResource(LibraryResource* p);
	void addUser(Person* p);

	LibraryResource* findResById(const string& rid);
	Person* findUserById(const string& uid);

	void showAllResource() const;
	void showAllUser() const;

	bool loadAllData();
	bool saveAllData();
};