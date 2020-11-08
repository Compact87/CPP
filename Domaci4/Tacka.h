#pragma once
#include<iostream>
#include <cmath>
using namespace std;
class Tacka
{
	double x,y;
public:
	Tacka(void);
	Tacka(double,double);
	double getX();
	double getY();
	void setX(double);
	void setY(double);
	double udaljenostOd(Tacka &t);
	void ispis();

};

