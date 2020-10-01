#pragma once
#include<iostream>
#include<string>
using namespace std;
class Hrana
{
protected:
	string ime;
	float cena;
public:
	Hrana(string im);
	 ~Hrana(void);
	virtual	 string getIme(){return ime;};
	virtual 	 float getCena(){return cena;}
	 void ispis();
bool operator <(const Hrana &h)                      //OVERLOADOVANI OPERATOR ZA "VECE OD" KOJI SE KORISTI U SORT FUNKCIJI
{
	return this->getCena() < const_cast<Hrana*>(&h)->getCena();

}
};

class Hamburger: public Hrana{

public:
	Hamburger();
	string getIme();
	void ispis();
};
class Supa:public Hrana{
public:
	Supa();
	void ispis();
	string getIme();
};
class Salata:public Hrana{
public:
	Salata();
	void ispis();
	string getIme();

};