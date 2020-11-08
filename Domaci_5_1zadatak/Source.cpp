#include <iostream>
using namespace std;
const char *s="Ana voli Milovana";
int main()
{
	int brojac=0;
	const char *p=s;
	for(;*p;p++)if(*p=='a')brojac++;
	cout<<"Broj pojavljivanja znaka 'a' je: "<<brojac<<endl;



}
