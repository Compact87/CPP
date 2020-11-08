#include "Tacka.h"
#include "Pravougaonik.h"
#include<cmath>
float min(float a, float b)
{
	if(a<b)return a;
	else return b;
}
float max(float a, float b)

{
	if(a>b)return a;
	else return b;
}



Pravougaonik presek(Pravougaonik &p1, Pravougaonik &p2){
	float x1=min(p1.doleL.getX(), p2.doleL.getX());
	float y1=min(p1.doleL.getY(), p2.doleL.getY());
	float x2=max(p1.goreD.getX(), p2.goreD.getX());
	float y2=max(p1.goreD.getY(), p2.goreD.getY());

	Pravougaonik veliki(Tacka(x1,y1),Tacka(x2,y2));

	//postojanje preseka
	if(veliki.duzinaX()<(p1.duzinaX()+p2.duzinaX()) && veliki.duzinaY()<(p1.duzinaY()+p2.duzinaY()))
	{


		float x1=(veliki.goreD.getX()-p1.doleL.getX() < veliki.goreD.getX()-p2.doleL.getX())?p1.doleL.getX() : p2.doleL.getX();
		float x2=(veliki.goreD.getX()-p1.goreD.getX() > veliki.goreD.getX()-p2.goreD.getX())?p1.goreD.getX() : p2.goreD.getX();
		
        float y1=(veliki.goreD.getY()-p1.doleL.getY() < veliki.goreD.getY()-p2.doleL.getY())?p1.doleL.getY() : p2.doleL.getY() ;
		float y2=(veliki.goreD.getY()-p1.goreD.getY() > veliki.goreD.getY()-p2.goreD.getY())?p1.goreD.getY() : p2.goreD.getY() ;
		 
		 Tacka t1(x1,y1),t2(x2,y2);
		 Pravougaonik mali(t1,t2);
		 return mali;
	}
	 //slucaj kada nema preseka
		Pravougaonik mali(Tacka(0,0), Tacka(0,0));
		return mali;
}


int main()
{
	Tacka t1(-4,-3),t2(-1,5),t3(-2,-4),t4(3,-1),t5(-8,-8),t6(9,9);
    Pravougaonik  p1(t1,t2),p2(t3,t4),p, p3(t5,t6);
	cout<<endl;
	
	cout<<endl;p1.IspisPravougaonika(); cout<<" i ";p2.IspisPravougaonika(); 
	if(p1.jednaki(p2))cout<<" su jednaki\n";
	else cout<<" nisu jednaki\n";
	cout<<"Njihov presek je ";
	presek(p1,p2).IspisPravougaonika();
	cout<<"\nTrenutnoi Okvir je: ";
	Pravougaonik okvir(Pravougaonik::okvirDoleL,Pravougaonik::okvirGoreD);
	okvir.IspisPravougaonika();
	cout<<endl;
	system("pause");
return 0;
}