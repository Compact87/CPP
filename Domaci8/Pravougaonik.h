#pragma once
#include "Tacka.h"
class Pravougaonik
{
   Tacka doleL, goreD;

public:
	 
	static Tacka okvirGoreD;
	static Tacka okvirDoleL;
	enum jednaki{NISU_JEDNAKI,JESU_JEDNAKI};
	Pravougaonik(void);
	Pravougaonik(Tacka& dL, Tacka& gD);
	void citaj(Tacka& doleLevo, Tacka& goreDesno);
	Tacka getDoleL();
	Tacka getGoreD();
	void podesiOkvir(Tacka& p1, Tacka& p2);
	friend Pravougaonik presek(Pravougaonik& , Pravougaonik& );
	float duzinaX();
	float duzinaY();
	bool jednaki(Pravougaonik&);
	void IspisPravougaonika();
};

