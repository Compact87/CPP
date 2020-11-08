#include<iostream>
#include "Student.h"
using namespace std;
const int MAX=100;

enum program{ASUV,AVT,ELITE,EI,IS,NRT,RT,NECE_NISTA};
void insert();
int main(){
	int unos=1,i=0,prg;
	string ime,idx;
	int popunjenost[7]={-1,-1,-1,-1,-1,-1,-1};
	Student **matrica=new Student*[MAX];
	matrica[0]=new Student[7];
	do{
		cout<<"Uneti ime"<<endl;
		cin>>ime;
		cout<<"\nUneti zeljeni program AVT=0, ASUV=1, ELITE=2, EI=3, IS=4, NRT=5, RT=6"<<endl;
		cin>>prg;
		switch(prg)
		{
		case program::ASUV: popunjenost[ASUV]++;idx="ASUV";break;
		case program::AVT: popunjenost[AVT]++;idx="AVT";break;
		case program::ELITE: popunjenost[ELITE]++;idx="ELITE";break;
		case program::EI: popunjenost[EI]++;idx="EI";break;
		case program::IS: popunjenost[IS]++;idx="IS";break;
		case program::NRT:popunjenost[NRT]++; idx="NRT";break;
		case program::RT: popunjenost[RT]++; idx="RT";break;
		default:unos=0;break;
		}
		if(unos==0)break;
		idx=idx + to_string(popunjenost[prg])+ to_string(20);

		if(popunjenost[prg]<i)matrica[popunjenost[prg]][prg].init(ime, idx);
		else
		{   
			//Pravi se novi red u matrici
			matrica[i++]=new Student[7];
			matrica[popunjenost[prg]][prg].init(ime, idx);
		}

	
	
	}while(1);
	cout<<"=======INDEKSI STUDENATA PO STUDIJSKOM PROGRAMU=====\n"<<endl;
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<7;k++)
			{
				matrica[j][k].ispis();
				for(int i=matrica[j][k].getIndex().size();i<9;i++){cout<<" ";}
			}
		cout<<endl;
	}
	for(int j=0;j<i;j++)delete [] matrica[j];
	delete [] matrica;
	return 0;
}
