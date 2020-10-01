#pragma once
#include<string>
using namespace std;
const int MAX=4;

template<class T>
class Sto{
	T sto;
    string zauzeto;
public:
	Sto();
	Sto(T t);
	void setZauzeto();
	string getZauzeto();
	void unSetZauzeto();
	void init(T t);
};




template<class T>
class Krcma
{
public:
	Sto<T> matrix[MAX/2][MAX/2];

	static int slobodni;
	Krcma();
	void init();
	void setSto();
	string getSto();
	void prikazi();
};

//////////////////DEFINICJE////////////
template <class T>
Sto<T>::Sto()
{
	T t;
	zauzeto="-";
}

template<class T>
Sto<T>::Sto(T t){
	sto=t;
	zauzeto="-";}
template<class T>
string Sto<T>::getZauzeto(){return zauzeto;}
template<class T>
void Sto<T>::setZauzeto(){zauzeto="+";}
template<class T>
void Sto<T>::unSetZauzeto(){zauzeto="-";}
template<class T>
void Sto<T>::init(T t)
{
	sto=t;
	zauzeto="+"
}
				
	


template<class T>
int Krcma<T>::slobodni=4;
template <class T>
Krcma<T>::Krcma()
{
	init();
}

template <class T>
void Krcma<T>::init()
{
	for(int i=0;i<MAX/2;i++)
		for(int j=0;j<MAX/2;j++)
			matrix[i][j].unSetZauzeto();
}
template <class T>
void Krcma<T>::prikazi()
{
	system("CLS");
	cout<<"\nTRENUTNO ZAUZETI STOLOVI\n";
	for(int i=0;i<MAX/2;i++)
	{
		for(int j=0;j<MAX/2;j++)
			cout<<matrix[i][j].getZauzeto();
		cout<<endl;
	}
	cout<<endl;
}