#pragma once
#include "Grupa.h"
#include<iostream>
using namespace std;
class Raspored
{
	Grupa matrix[14][5];
	
public:
	static int vreme[14][5];
	Raspored(void);
	Grupa& getMatrix(int sat,int dan);
	static void initVreme();
	void ispis();
	void sema();
};

