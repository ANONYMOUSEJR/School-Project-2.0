#pragma once
//for declerations.

#include <iostream>
#include <string>
#include "math.h"

using namespace std;

class Stud : public math{
public:
	unsigned short By{};
	string name, grade;
	void getName() {
		getline(cin, name);
	}
	void getGrade() {
		getline(cin, grade);
	}
	void getAge() {
		cin >> By;
	}
	inline short age(short By, short Cy) { return Cy - By; }
};
