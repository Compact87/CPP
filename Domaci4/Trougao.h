#pragma once
#include "Tacka.h"
class Trougao
{
	Tacka *t1,*t2,*t3;
public:
	Trougao(void);
	Trougao(Tacka &t1,Tacka &t2, Tacka &t3);
	double povrsina();
	double obim();
	void ispis(){cout<<"Trougao: ";t1->ispis();t2->ispis();t3->ispis();}
};

