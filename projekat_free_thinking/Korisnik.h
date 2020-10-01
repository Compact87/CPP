#pragma once
#include<iostream>
#include <string>
using namespace std;

class Korisnik
{
	string ime;
	int broj;
public:
	static int rBr;
	Korisnik();
	Korisnik(string ime);
	~Korisnik(void);
	void edit(string im, int operacija);
	friend void addToQue(Korisnik k);
    int getBroj();
	void ispis();
	string getIme();
	friend ostream& operator << (ostream&, const Korisnik& k);
};

