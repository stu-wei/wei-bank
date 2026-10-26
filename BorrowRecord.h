#pragma once
#include <iostream>
#include <string>
using namespace std;

//纸质资源借出借阅记录
struct BorrowRecord
{
	string resId;			//借阅资源编号
	int borrowYear;
	int borrowMonth;
	int borrowDay;
	bool isReturned;		//是否已经归还
	bool isLost;			//书籍是否丢失
	double fine;			//当前罚款金额

	BorrowRecord();
	BorrowRecord(string rid, int y, int m, int d);

	//计算月份差值，用于判断是否超过4个月
	int getMonthDiff(int curY, int curM, int curD) const;
};