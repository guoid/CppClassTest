// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CInchFoot {
private:
	double inch;
	double foot;
	void check();
public:
	CInchFoot();
	CInchFoot(double i, double f);
	CInchFoot operator +(const CInchFoot &a);
	CInchFoot operator -(const CInchFoot &a);
	void set(double i, double f);
	int getInch();
	int getFoot();
	void display();
};

void CInchFoot::check() {
	if (inch >= 12) {
		foot += ((int)inch % 12);
		inch -= (int)(inch/12)*12;
	}
}

CInchFoot::CInchFoot() {
	inch = 0;
	foot = 0;
}

CInchFoot::CInchFoot(double i, double f) {
	inch = i;
	foot = f;
	check();
}


int CInchFoot::getInch() {
	return inch;
}

int CInchFoot::getFoot() {
	return foot;
}
void CInchFoot::display() {
	cout << "[I]Inch:" << inch << " [F]Foot:" << foot << endl;
}

void CInchFoot::set(double i, double f) {
	inch = i;
	foot = f;
	check();
}
CInchFoot CInchFoot::operator +(const CInchFoot &a) {
	CInchFoot temp;
	temp.set(inch+a.inch, foot + a.foot);
	return temp;
}
CInchFoot CInchFoot::operator -(const CInchFoot &a) {
	check();
	CInchFoot temp;
	int sum1, sum2;
	sum1 = foot * 12 + inch;
	sum2 = a.foot * 12 + a.inch;
	if (sum1 < sum2) {
		cout << "[!]Can`t reduce!!! Init to 0 foot 0 inch." << endl;
		temp.set(0, 0);
	}
	else {
		temp.set(sum1 - sum2, 0);
	}
	return temp;
}


int main()
{
	CInchFoot a, b,c;
	a.set(11, 1);
	b.set(2, 2);
	c = a + b;
	c.display();
	c = a - b;
	c.display();
    return 0;
}

