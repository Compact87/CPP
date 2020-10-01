/*#include "Krcma.h"

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
int Krcma<T>::slobodni=4;
template <class T>
Krcma<T>::Krcma()
{

}
template <class T>
Krcma<T>::~Krcma(void)
{
	init();
}
template <class T>
void Krcma<T>::init()
{
	for(int i=0;i<MAX/2;i++)
		for(int j=0;j<MAX/2;j++)
			matrix[i][j].unsetZauzeto();
}
template <class T>
void Krcma<T>::prikazi()
{
	for(int i=0;i<MAX/2;i++)
	{
		for(int j=0;j<MAX/2;j++)
			cout<<matrix[i][j].getZauzeto();
		cout<<endl;
	}

}*/