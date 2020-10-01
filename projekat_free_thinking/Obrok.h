#pragma once
#include "Hrana.h"
#include <iostream>
#include<list>
#include<vector>
class Obrok
{
public:
	vector<Hrana> obrok;
	float UkCena;
	void ukupno();
	Obrok(void);
	~Obrok(void);
};

