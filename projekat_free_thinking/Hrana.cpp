#include "Hrana.h"


Hrana::Hrana(string im)
{
	ime=im;
	cena=0;
}
void Hrana::ispis(){cout<<Hrana::ime<<" "<<cena<<" | ";}

Hrana::~Hrana(void)
{
}

Hamburger::Hamburger():Hrana("Hamburger"){cena=200;}
void Hamburger::ispis(){Hrana::ispis();}
string Hamburger::getIme(){return ime;}
Supa::Supa():Hrana("Supa"){cena=50;}
void Supa::ispis(){Hrana::ispis();}
string Supa::getIme(){return ime;}

Salata::Salata():Hrana("Salata"){cena=80;}
void Salata::ispis(){Hrana::ispis();}
string Salata::getIme(){return ime;}
