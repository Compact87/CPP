#include "Trougao.h"
Trougao& funcTrougao(Trougao *p){
	return *p;
	
}
Tacka& funcTacka(Tacka *t)
{
	return *t;
}
int main()
{
	double m,n;
	Trougao niz[3],*ptr;
	Tacka *p,nizTacki[9];
	p=nizTacki;
	ptr=niz;
	//pravi se 9 tacaka za 3 trougla, vrednost koju vraca f-ja funcTacka(p) se koristi kao lvrednost
	for(int j=0;j<9;j++)
	{
			cout<<"uneti x i y za tacku "<<j+1<<endl;
			cin>>m>>n;
			funcTacka(p)=Tacka(m,n);
			p++;
	}
	//niz tacki se koristi za inicijalizaciju 3 objekta tipa trougao, vrednost koju vraca f-ja funcTrougao(ptr) se koristi kao lvrednost
	p=nizTacki;
	for(int i=0;i<3;i++)
	{
		cout<<"Napravljen"<<i+1<<". trougao"<<endl;
		funcTrougao(ptr)=Trougao(*p,*(p+1),*(p+2));
		ptr++;p=p+3;
	}
	cout<<"Ispis indeksom"<<endl;
	ptr=niz;
	for(int i=0;i<3;i++)
	{
		niz[i].ispis();
		cout<<"\nPovrsina: "<<niz[i].povrsina()<<endl;
		cout<<"\nObim: "<<niz[i].obim()<<endl;
	}
	cout<<"Ispis pokazivacem"<<endl;
	for(int i=0;i<3;i++)
	{
		niz[i].ispis();
		cout<<"\nPovrsina: "<<ptr->povrsina()<<endl;
		cout<<"\nObim: "<<ptr->obim()<<endl;
		ptr++;
	}
	
	return 0;
}
