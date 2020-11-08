#include "Tacka.h"


Tacka::Tacka(void):x(0),y(0){}
Tacka::Tacka(float X, float Y):x(X),y(Y){}
void Tacka::IspisiTacku(){cout<<"("<<x<<","<<y<<")";}
float Tacka::getX(){return x;}
float Tacka::getY(){return y;}
void Tacka::citaj(float a, float b){x=a, y=b;}
