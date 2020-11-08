#include "Tacka.h"


Tacka::Tacka(void):x(0),y(0){}
Tacka::Tacka(double a,double b):x(a),y(b){}

double Tacka::getX(){return x;}
double Tacka::getY(){return y;}

void Tacka::setX(double a){x=a;}
void Tacka::setY(double b){y=b;}
double Tacka::udaljenostOd(Tacka &t)
{
	return sqrt(pow(x-t.x,2)+pow(y-t.y,2));

}
void Tacka::ispis(){cout<<"T("<<x<<","<<y<<")";}