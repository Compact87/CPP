#include "Grupa.h"


Grupa::Grupa(void)
{
	 studProgram="Nije dodenjen";
	 predmet="Nije dodenjen";
	 brGrupe=0;
	 brStudenata=0;
	 brSemestra=0;
	 rezervisano="-";
	 ukupno++;
}
int Grupa::ukupno=0;
void Grupa::init(string program, string predmet, int studenti, int semestar, int grupa)
{ 
	string c=to_string(grupa);
    studProgram=program;
	this->predmet=predmet;
	brStudenata=studenti;
	brGrupe=grupa;
	brSemestra=semestar;
	rezervisano=program+c;
}
void Grupa::ispis()
{
	cout<<"Grupa: "<<studProgram<<" "<<brGrupe<<" brSemestra: "<<brSemestra<<" "<<"Predmet: "<<predmet<<endl;
}
void Grupa::ispisRez()
{
	cout<<rezervisano;
}
string Grupa::getRez(){return rezervisano;}
void Grupa::setRez(){rezervisano="+";}