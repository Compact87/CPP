#include "Korisnik.h"

int Korisnik::rBr=0;
Korisnik::Korisnik(){}
Korisnik::Korisnik(string im)
{
	ime=im;
	broj=++rBr;
	addToQue(*this);

}


Korisnik::~Korisnik(void)
{
}
void Korisnik::edit(string im,int k)
{
	ime=im;
}
int Korisnik::getBroj(){return broj;}
void Korisnik::ispis()
{
	cout<<ime<<" rbr= "<<broj<<endl;
}
string Korisnik::getIme(){return ime;}
