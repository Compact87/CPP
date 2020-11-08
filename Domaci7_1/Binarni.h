#pragma once
#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;
class Binarni {
 bitset<32> x;//pokazivač na celi 32-bitni broj
 bool carry;//prenos iz MSB, ukoliko ga ima
 public:
 Binarni(int i=0) { x =bitset<32>(i);carry = 0; cout<<"def konstr\n";} /*konstruktor koji postavlja pokazivač na 32-bitni celi broj i prenos na nulu*/
 void display()
 {
   for (int j = 31; j >= 0; j--){ cout<<x[j]; };
  }
 bool bit (int n=0) { return x[n]; } /*vraća vrednost n-tog bita (od 0 do31)*/
 void setbit(int n) { x[n]= 1; }//postavlja n-ti bit na 1
 void resetbit(int n) { x[n] = 0; } //postavlja n-ti bit na 0
 int getdecimal() { int y=0; for(int i=31;i>=0;i--)y+=x[i]*pow(2,i); return y;} //vraća decimalnu vrednost broja
 void setdecimal(short int y) { x = static_cast<bitset<32>>(y); } //postavlja vrednost broja
 void hexdisplay() { cout << "0x" << setfill('0') << hex << setw(8) << getdecimal() << endl;}
 
Binarni sum(Binarni a) {//broj a je drugi sabirak, prvi sabirak je ovaj (this) objekat(neka bude b)
 bool aj, bj, sj; //aj je j-ti bit broja a, bj je j-ti bit broja b
 Binarni c; //početna vrednost c je 0, carry je 0, ovde će biti zbir
 cout << "Red.br.bita a b sum carry"<<endl;
 for (int j = 0; j <32; j++) { //od nultog do 31. bita
   bj = x[j]; /*iz celog broja b zapisanog sa 32 bita izdvaja bitsa rednim brojem j */
   aj = a.x[j]; /*iz celog broja a zapisanog sa 32 bita izdvaja bit sa rednim brojem j */
   sj = aj ^ bj ^ c.carry; //a xor b xor carry je vrednost sume bitova
   c.x[j]=sj;
   //c.setdecimal((sj << j) + c.getdecimal()); /* bit sj se šiftuje levo za j mesta i dodaje se prethodna vrednost sume */
   c.carry = (aj ^ bj)&c.carry | (aj & bj); /*prenos u sledeći bit, računa se po formuli (a xor b) and carry or a and b*/
   cout <<setw(7)<< j<<"."<<setw(6)<<aj << setw(3) << bj << setw(4) <<sj<<
   setw(6) <<c.carry<< endl;
  }
  return c;
 };
};