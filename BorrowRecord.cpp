#include "BorrowRecord.h"

BorrowRecord::BorrowRecord()
	:resId(""), borrowYear(0), borrowMonth(0), borrowDay(0),
	isReturned(false), isLost(false), fine(0.0)
{
}

BorrowRecord::BorrowRecord(string rid, int y, int m, int d)
	:resId(rid), borrowYear(y), borrowMonth(m), borrowDay(d),
	isReturned(false), isLost(false), fine(0.0)
{
}

int BorrowRecord::getMonthDiff(int curY, int curM, int curD) const
{
	int diff = (curY - borrowYear) * 12 + (curM - borrowMonth);
	if (curD < borrowDay)
	{
		diff -= 1;
	}
	return diff;
}