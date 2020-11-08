#include <iostream>
#include <iomanip>
#include"Binarni.h"
using namespace std;
int main() {
Binarni x(120);
cout << " x binarno: "; x.display();
cout << " x decimalno: " << x.getdecimal()<<endl;
Binarni y(125);
cout << " y binarno: "; y.display();
cout << " y decimalno: " << y.getdecimal()<<endl;
cout << " 7. bit broja x: "<< x.bit(7) << endl;
cout << " 0. bit broja y: " << y.bit() << endl;
x.setbit(7);
cout << " x binarno nakon postavljanja 7. bita: "; x.display();
cout <<" x decimalno nakon postavljanja 7. bita: "<< x.getdecimal() << endl;
y.resetbit(0);
cout << " y binarno nakon resetovanja 0. bita: "; y.display();
cout << " y decimalno nakon resetovanja 0. bita: " << y.getdecimal() << endl;
Binarni g; //postavljanje broja g na nulu
cout << " g binarno: "; g.display();
cout << " g decimalno: " << g.getdecimal() << endl;
g.setdecimal(5); //postavljanje vrednosti g na 5
cout << " g binarno nakon promene: "; g.display();
cout << " g decimalno nakon promene: " << g.getdecimal() << endl;
cout << endl << " Sabiranje x i y bit po bit: " << endl << endl;
Binarni z = x.sum(y); //binarno sabiranje brojeva x i y
cout <<endl<< " Zbir z binarno nakon sabiranja x i y: "; z.display();
cout << endl<<" Zbir z decimalno nakon sabiranja x i y: ";
cout << z.getdecimal()<<endl;
cout << " Zbir z heksadecimalno nakon sabiranja x i y: "; z.hexdisplay();
system("pause");
return 0;
}