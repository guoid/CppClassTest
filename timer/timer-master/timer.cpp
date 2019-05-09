// timer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CNaQin
{
private:
	int year, month, day;
	int Hour, Minute, Second, Msecond;
	void autoFix();
public:
	CNaQin();
	CNaQin(int year, int month, int day, int Hour, int Minute, int Second, int Msecond);

	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setHour(int H);
	void setMinute(int M);
	void setSecond(int S);
	void setMsecond(int MS);

	void addYear(int y);
	void addMonth(int m);
	void addDay(int d);
	void addHour(int H);
	void addMinute(int M);
	void addSecond(int S);
	void addMsecond(int MS);

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();
	int getMsecond();

	void printDate();
	void printTime();
};

CNaQin::CNaQin()
{
	year = 2019;
	month = 1;
	day = 1;

	Hour = 0;
	Minute = 0;
	Second = 0;
	Msecond = 0;
}

CNaQin::CNaQin(int y, int m, int d, int H, int M, int S, int MS)
{
	year = y;
	month = m;
	day = d;

	Hour = H;
	Minute = M;
	Second = S;
	Msecond = MS;

	autoFix();
}

void CNaQin::autoFix()
{
	int Months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int flag = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		flag = 1;
	Months[1] += flag;
	
	if (Msecond >= 1000)
	{
		Second += Msecond / 1000;
		Msecond %= 1000;
	}
	if (Second >= 60)
	{
		Minute += Second / 60;
		Second %= 60;
	}
	if (Minute >= 60)
	{
		Hour += Minute % 60;
		Minute %= 60;
	}
	if (Hour >= 24)
	{
		day += Hour / 24;
		Hour %= 24;
	}
	if (day > Months[month - 1])
	{
		int temp = month;
		for (int i = temp - 1; i < 12; i++)
		{
			if (day > Months[i])
			{
				month++;
				day -= Months[i];
			}
			else break;
		}
	}
	if (month > 12)
	{
		year += month % 12;
		month %= 12;
	}

}

void CNaQin::setYear(int y)
{
	year = y;
}

void CNaQin::setMonth(int m)
{
	month = m;
	autoFix();
}

void CNaQin::setDay(int d)
{
	day = d;
	autoFix();
}

void CNaQin::setHour(int H)
{
	Hour = H;
	autoFix();
}

void CNaQin::setMinute(int M)
{
	Minute = M;
	autoFix();
}

void CNaQin::setSecond(int S)
{
	Second = S;
	autoFix();
}

void CNaQin::setMsecond(int MS)
{
	Msecond = MS;
	autoFix();
}

void CNaQin::addYear(int y)
{
	year += y;
}

void CNaQin::addMonth(int m)
{
	month += m;
	autoFix();
}

void CNaQin::addDay(int d)
{
	day += d;
	autoFix();
}

void CNaQin::addHour(int H)
{
	Hour += H;
	autoFix();
}

void CNaQin::addMinute(int M)
{
	Minute += M;
	autoFix();
}

void CNaQin::addSecond(int S)
{
	Second += S;
	autoFix();
}

void CNaQin::addMsecond(int MS)
{
	Msecond += MS;
	autoFix();
}

int CNaQin::getYear()
{
	return year;
}

int CNaQin::getMonth()
{
	return month;
}

int CNaQin::getDay()
{
	return day;
}

int CNaQin::getHour()
{
	return Hour;
}

int CNaQin::getMinute()
{
	return Minute;
}

int CNaQin::getSecond()
{
	return Second;
}

int CNaQin::getMsecond()
{
	return Msecond;
}

void CNaQin::printDate()
{
	cout << "[D] " << year << " / " << month << " / " << day << endl;
}

void CNaQin::printTime()
{
	cout << "[T] " << Hour << " : " << Minute << " : " << Second << " : " << Msecond << endl;
}

int main()
{
	// init test 1
	cout << "init test 1" << endl;
	CNaQin nq1;
	nq1.printDate();
	nq1.printTime();
	cout << endl;
    
	// init test 2
	cout << "init test 2" << endl;
	CNaQin nq2(2019, 5, 32, 0, 0, 0, 0);
	nq2.printDate();
	cout << endl;

	// set test
	cout << "set test" << endl;
	CNaQin nq;
	nq.setDay(91);
	nq.printDate();
	nq.printTime();
	cout << endl;

	// add test
	cout << "add test" << endl;
	CNaQin anq;
	anq.addDay(31);
	anq.printDate();
	cout << endl;

	// count lived days
	cout << "count lived days" << endl;
	CNaQin lived(1999, 7, 1, 0, 0, 0, 0);
	int count = 1;
	while (!(lived.getYear() == 2019 && lived.getMonth() == 4 && lived.getDay() == 29))
	{
		count++;
		lived.addDay(1);
	}
	cout << "[L] you lived " << count << " days!" << endl;
	

	return 0;
}

