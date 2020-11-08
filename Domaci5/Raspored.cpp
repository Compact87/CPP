#include "Raspored.h"


Raspored::Raspored(void)
{
}

void Raspored::ispis()
{
	for(int sat=0;sat<14;sat++)
	{
		for(int dan=0;dan<5;dan++)
		{
			cout<<"["<<sat<<"]["<<dan<<"] ";
			matrix[sat][dan].ispis();
		}
		cout<<endl;
	}

}

void Raspored::sema()
{
	for(int i=PON;i!=NEMA;i++)
	{
		switch(i)
		{
		case dani::PON:cout<<"Pon\t";break;
		case dani::UTO:cout<<"Uto\t";break;
		case dani::SRE:cout<<"Sre\t";break;
		case dani::CET:cout<<"Cet\t";break;
		case dani::PET:cout<<"Pet\t";break;
		}

	}
	cout<<"Vreme"<<endl;
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<5;j++)
		{
			getMatrix(i+8,j+1).ispisRez();cout<<"\t";
			if(j==4)
			{
				cout<<i+8<<":00 ";
			}
		}
		cout<<endl;
	}
}
Grupa& Raspored::getMatrix(int sat, int dan){return matrix[sat-8][dan-1];}