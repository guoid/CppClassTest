// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CTestCopy {
private:
	int x, y;
public:
	CTestCopy();
	CTestCopy(int a, int b);
	CTestCopy(CTestCopy & om);
	void setXY(int a, int b);
	void display();
};

CTestCopy::CTestCopy() {
	x = 0;
	y = 0;
}
CTestCopy::CTestCopy(int a, int b) {
	x = a;
	y = b;
}
CTestCopy::CTestCopy(CTestCopy & om) {
	x = om.x * 3;
	y = om.y * 3;
	for (int i = 0; i < 10; i++) cout << "*";
	cout << endl;

}
void CTestCopy::setXY(int a, int b) {
	x = a;
	y = b;
}
void CTestCopy::display() {
	cout << "x = " << x << " y = " << y << endl;
}

void testOne(CTestCopy test) {
	test.display();
}

CTestCopy testTwo() {
	CTestCopy t(10, 20);
	return t;
}

int main()
{
	CTestCopy ot(200, 300);
	testOne(ot);
	CTestCopy om = testTwo();
	om.display();
    return 0;
}

