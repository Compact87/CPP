

#pragma once
#include<string>
#include<iostream>
#include "StudijskiProgrami.h"
using namespace std;
#include"ENUMI.h"
class Grupa
{
	string studProgram;
	string predmet;	
	int brGrupe,brStudenata,brSemestra;
	string rezervisano;
public:
	static int ukupno;
	Grupa(void);
	void init(string program, string predmet, int studenti, int semestar, int grupa);

  void ispis();
  void ispisRez();
  string getRez();
  void setRez();
};

