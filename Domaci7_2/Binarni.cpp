#include "Binarni.h"
#include <iostream>
#include <iomanip>
using namespace std;
IspisBroja::IspisBroja() { dbroj=0; }
void IspisBroja::PostaviDouble(double broj) { dbroj=broj; }
void IspisBroja::IspisiBinarnoDoubleClan()
{
	
	unsigned char *q = reinterpret_cast<unsigned char*>(&dbroj);

	cout<<"DOUBLE BROJ -------- BINARNO PRIKAZAN --------"<<endl;
	cout<<" s kkkkkkkkkkk mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<setw(10)<<dbroj<<" ";
		for(int i=7;i>=0;i--)
		for(int j=7;j>=0;j--)
		{
			(q[i]&(1<<j))?cout<<"1":cout<<"0";
			//if((i==7 && j==7)||(i==6&&j==4))cout<<" ";
		}	
		cout<<endl;
}