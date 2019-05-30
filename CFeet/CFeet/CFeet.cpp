// CFeet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CFeet {
private:
	int foot;
	int inch;
	void check();

public:
	CFeet();
	CFeet(int i, int f);

	void setInch(int i);
	void setFoot(int f);
	void set(int i, int f);
	int getInch();
	int getFoot();

	CFeet operator + (const CFeet & a);
	CFeet operator - (const CFeet & a);

	CFeet operator + (const int & a);
	CFeet operator - (const int & a);

	void display();
};

void CFeet::check() {
	if (inch >= 12) {
		foot += inch / 12;
		inch %= 12;
	}
}

CFeet::CFeet() {
	inch = 0;
	foot = 0;
}

CFeet::CFeet(int i, int f) {
	inch = i;
	foot = f;
	check();
}

void CFeet::setInch(int i) {
	inch = i;
	check();
}

void CFeet::setFoot(int f) {
	foot = f;
}

void CFeet::set(int i, int f) {
	inch = i;
	foot = f;
	check();
}

int CFeet::getInch() {
	return inch;
}

int CFeet::getFoot() {
	return foot;
}

CFeet CFeet::operator + (const CFeet & a) {
	CFeet temp;
	temp.setInch(inch + a.inch);
	temp.setFoot(foot + a.foot);
	return temp;
}

CFeet CFeet::operator - (const CFeet & a) {
	CFeet temp;
	if (foot * 12 + inch >= a.foot * 12 + a.inch)
		temp.setInch((foot * 12 + inch) - (a.foot * 12 + a.inch));
	else
		cout << "Can`t reduce!!!" << endl;
	return temp;
}

CFeet CFeet::operator + (const int & a) {
	CFeet temp;
	temp.setInch(foot * 12 + inch + a);
	return temp;
}
CFeet CFeet::operator - (const int & a) {
	CFeet temp;
	if ((foot * 12 + inch) >= a)
		temp.setInch((foot * 12 + inch) - a);
	else
		cout << "Can`t reduce!!!" << endl;
	return temp;
}

void CFeet::display() {
	cout << "[^] " << inch << " Inch(s) " << foot << " Feet" << endl;
}

int main()
{
	CFeet a, b, c, d;
	a.set(2, 1);
	b.set(1, 0);

	cout << "[C] A:" << endl;
	a.display();

	cout << "[C] B" << endl;
	b.display();
	
	// plus
	cout << "[!] Plus   : A + B" << endl;
	c = a + b;
	c.display();
	cout << "[!] Plus   : A + 14" << endl;
	c.set(0, 0);
	c = a + 14;
	c.display();

	// reduce
	cout << "[!] Reduce : A - B" << endl;
	d = a - b;
	d.display();
	cout << "[!] Reduce : A - 7" << endl;
	d.set(0, 0);
	d = a - 7;
	d.display();
	cout << "[!] Can`t reduce : A - 222" << endl;
	d.set(0, 0);
	d = a - 222;
	d.display();

    return 0;
}

