#pragma once
#include<iostream>
#include<string>
using namespace std;
class Student
{
	string ime, index;
public:
	Student(void);
	void init(string, string);
	
	string getIme();
	string getIndex();
	void ispis();
};

