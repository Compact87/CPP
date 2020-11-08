#include "Pravougaonik.h"

 Tacka Pravougaonik::okvirGoreD(0,0);
 Tacka Pravougaonik::okvirDoleL(0,0);



Pravougaonik::Pravougaonik(void)
{
}

void Pravougaonik::podesiOkvir(Tacka& p1, Tacka& p2)
{
	float x1=min(okvirDoleL.getX(), p1.getX());
	float y1=min(okvirDoleL.getY(), p1.getY());
	float x2=max(okvirGoreD.getX(), p2.getX());
	float y2=max(okvirGoreD.getY(), p2.getY());
	okvirDoleL.citaj(x1,y1);
	okvirGoreD.citaj(x2,y2);
	
}
Pravougaonik::Pravougaonik(Tacka& dL, Tacka& gD)
{
	doleL=dL;
	goreD=gD;
	podesiOkvir(dL,gD);
}
Tacka Pravougaonik::getDoleL(){return doleL;}
Tacka Pravougaonik::getGoreD(){return goreD;}

void Pravougaonik::citaj(Tacka& t1, Tacka& t2 )
{
	doleL=t1;
	goreD=t2;
	podesiOkvir(t1,t2);
}

float Pravougaonik::duzinaX(){return abs(goreD.getX()-doleL.getX());}
float Pravougaonik::duzinaY(){return abs(goreD.getY()-doleL.getY());}

void Pravougaonik::IspisPravougaonika()
{
	cout<<"Pravougaonik: DoleL: ";doleL.IspisiTacku();cout<<" GoreD: ";goreD.IspisiTacku();
}
bool Pravougaonik::jednaki(Pravougaonik& p)
{
 if(this->doleL.getX()==p.doleL.getX() && this->doleL.getY()==p.doleL.getY() &&  this->goreD.getX()==p.goreD.getX() && this->goreD.getY()==p.goreD.getY())
	 return jednaki::JESU_JEDNAKI;
 else return jednaki::NISU_JEDNAKI;
}