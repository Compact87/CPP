#include "Student.h"


Student::Student(void)
{
	ime="nema";
	index="nema";
}
void Student::init(string i, string p){ime=i;index=p;}
string Student::getIme(){return ime;}
string Student::getIndex(){return index;}
void Student::ispis(){
	
	
	cout<<index;
}
