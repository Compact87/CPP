#include<iostream>
#include "Grupa.h"
#include "Raspored.h"
#include "GrupePredef.h"
using namespace std;

Raspored R;

void initShemu();
int main()
{
	
	initShemu();
	cout<<"=========Raspored nastave=========="<<endl<<endl;
	R.sema();
	
	int i=1,j,m,n,brStud,brGrup,brSem;
	string pred,prog;

	while(i){
		do{
			cout<<"Uneti vreme(ceo broj od 8 do 21) i dan(Pon=1,Uto=2,Sre=3,Cet=4,Pet=5) "<<endl;
			cin>>m>>n;
			if(R.getMatrix(m,n).getRez()!="-"){cout<<"Termin je rezervisan"<<endl;m=1000;};
		}while((m<8 || m>21) || (n<1 || n>5));

		cout<<"Uneti program,predmet, broj studenata, broj semestra i broj grupe"<<endl;
		cin>>prog>>pred>>brStud>>brSem>>brGrup;
		R.getMatrix(m,n).init(prog,pred,brStud,brSem,brGrup);
	
		cout<<endl;
		R.sema();
		cout<<"Nastaviti unos(0=NE, 1=DA)?";
		cin>>i;
	}
	R.ispis();
	return 0;
}

void initShemu()
{
	
	for(int sat=0;sat<8;sat++)
	{
		for(int dan=1;dan<3;dan++){
		
			R.getMatrix(sat+8,dan).init(nizPrograma[sat],nizPredmeta[sat],20,nizSemestara[sat],nizGrupa[sat]);
		}

	}

}