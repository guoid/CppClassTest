// InheritanceTimer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Timer
{
protected:
	int year, month, day;
	int Hour, Minute, Second, Msecond;
	void autoFix();
public:
	Timer();
	Timer(int year, int month, int day, int Hour, int Minute, int Second, int Msecond);

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

Timer::Timer()
{
	this->year = 2019;
	this->month = 1;
	this->day = 1;

	this->Hour = 0;
	this->Minute = 0;
	this->Second = 0;
	this->Msecond = 0;
}

Timer::Timer(int y, int m, int d, int H, int M, int S, int MS)
{
	this->year = y;
	this->month = m;
	this->day = d;

	this->Hour = H;
	this->Minute = M;
	this->Second = S;
	this->Msecond = MS;

	autoFix();
}

void Timer::autoFix()
{
	int Months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

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

void Timer::setYear(int y)
{
	year = y;
}

void Timer::setMonth(int m)
{
	month = m;
	autoFix();
}

void Timer::setDay(int d)
{
	day = d;
	autoFix();
}

void Timer::setHour(int H)
{
	Hour = H;
	autoFix();
}

void Timer::setMinute(int M)
{
	Minute = M;
	autoFix();
}

void Timer::setSecond(int S)
{
	Second = S;
	autoFix();
}

void Timer::setMsecond(int MS)
{
	Msecond = MS;
	autoFix();
}

void Timer::addYear(int y)
{
	year += y;
}

void Timer::addMonth(int m)
{
	month += m;
	autoFix();
}

void Timer::addDay(int d)
{
	day += d;
	autoFix();
}

void Timer::addHour(int H)
{
	Hour += H;
	autoFix();
}

void Timer::addMinute(int M)
{
	Minute += M;
	autoFix();
}

void Timer::addSecond(int S)
{
	Second += S;
	autoFix();
}

void Timer::addMsecond(int MS)
{
	Msecond += MS;
	autoFix();
}

int Timer::getYear()
{
	return year;
}

int Timer::getMonth()
{
	return month;
}

int Timer::getDay()
{
	return day;
}

int Timer::getHour()
{
	return Hour;
}

int Timer::getMinute()
{
	return Minute;
}

int Timer::getSecond()
{
	return Second;
}

int Timer::getMsecond()
{
	return Msecond;
}

void Timer::printDate()
{
	cout << "[D] " << year << " / " << month << " / " << day << endl;
}

void Timer::printTime()
{
	cout << "[T] " << Hour << " : " << Minute << " : " << Second << " : " << Msecond << endl;
}

////////////////////////////////////////////////////////

class IDC : public Timer {
private:
	int LivedDays;

public:
	IDC();
	IDC(int y, int m, int d, int H, int M, int S, int MS);
	void CountLivedDays();
};


IDC::IDC() {
	cout << "[!]This is child for Timer Class" << endl;
}

IDC::IDC(int y, int m, int d, int H, int M, int S, int MS) {
	year = y;
	month = m;
	day = d;

	Hour = H;
	Minute = M;
	Second = S;
	Msecond = MS;
	
	autoFix();
}

void IDC::CountLivedDays() {
	int D[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int nYear, nMonth, nDay;
	LivedDays = 1;
	nYear = 2019;
	nMonth = 6;
	nDay = 13;

	for (int i = this->getYear(); i < nYear; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			LivedDays += 366;
		else LivedDays += 365;
	}

	if (this->getYear() % 400 == 0 || (this->getYear() % 4 == 0 && this->getYear() % 100 != 0))
		D[1]=29;
	for (int i = 0; i < this->month; i++)
		LivedDays -= D[i];
	LivedDays -= this->day;
	D[1]=28;

	if (nYear % 400 == 0 || (nYear % 100 != 0 && nYear % 4 == 0))
		D[1]=29;
	for (int i = 0; i < nMonth; i++) LivedDays += D[i];
	LivedDays += nDay;

	cout << "[L] you lived " << LivedDays << " days!" << endl;
}




int main()
{
	// test 1
	cout << "[!!]Test 1" << endl;
	IDC t1;
	t1.printDate();
	t1.printTime();
	cout << endl;

	// test 2
	cout << "[!!]Test 2" << endl;
	IDC t2(2019, 5, 32, 0, 0, 0, 0);
	t2.printDate();
	cout << endl;

	// test 3
	cout << "[!!]Test 3" << endl;
	IDC t3;
	t3.setDay(91);
	t3.printDate();
	t3.printTime();
	cout << endl;

	// test 4
	cout << "[!!]Test 4" << endl;
	IDC t4;
	t4.addDay(31);
	t4.printDate();
	cout << endl;

	// test 5
	cout << "[!!]Test 5" << endl;
	IDC t5;
	t5.setYear(2019);
	t5.setMonth(6);
	t5.setDay(12);
	cout << "[^]Birthday is :";
	t5.printDate();
	t5.CountLivedDays();
	cout << endl;


    return 0;
}

