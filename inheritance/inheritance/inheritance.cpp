// inheritance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Student {
protected:
	string name;
	int id;
	int grade;
	char sex;
	
public:
	Student() {
		name = "XiaoMing";
		id = 2018;
		grade = 1;
		sex = 'm';
	}
	Student(string name, int id, int grade, char sex) {
		this->name = name;
		this->id = id;
		this->grade = grade;
		this->sex = sex;
	}

	void display() {
		cout << "[N]name:" << name << "\n[I]id:" << id << "\n[G]grade:" << grade << "\n[S]sex:" << sex << endl;
	}
};

class MongolStu :public Student {
protected:
	string nation;

public:
	MongolStu() {
		nation = "Mongol";
	}

	MongolStu(string name, int id, int grade, char sex) {
		this->name = name;
		this->id = id;
		this->grade = grade;
		this->sex = sex;
		this->nation = "Mongol";
	}
};

int main() {

	Student stu("ZhangWei", 2017, 2, 'm');
	stu.display();
	cout << endl;

	MongolStu mstu("Gerel",2018,1,'w');
	mstu.display();

	return 0;
}