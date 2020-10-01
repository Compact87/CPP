#include "Libraries.h"


using namespace std;
int i=1;
int n, mutexHrana=0, mutexKazan=0,mutexMesto=0;
fstream f;
void addToQue(Korisnik k){red.push(k);}
void init();
void dodajHranu();
void obrisiItem(int i, Obrok &o);
int main()
{
	Krcma<Sto<pair<Korisnik,Obrok>>> krcma;
	init();													//smesta hranu u redove 
	char str[20];											
	Obrok *o;                                             //pokazivac na niz obroka jenog korisnika
	f.open("korisnici.bin", ios::in | ios::binary);       //datoteka sa korisnicima

	while(1){
		cout<<"\n==============================\nDOBRODOSLI U RESTORAN  \n==============================\n";
		while (1)                                         //smestanje korisnika u red
		{
			Korisnik *pom=new Korisnik();
			f.read((char*)&(*pom), sizeof(Korisnik));
			if (!f)break;
			red.push(*pom);
		}
		if(red.empty()){cout<<"Nema novih korisnika, kraj rada!"<<endl;exit(0);system("pause");}
	if(mutexMesto==0 && mutexKazan==0 && !red.empty()){          //ako ima mesta u restoranu i niko ne bira hranu, sledeci korisnik iz reda bira
		kazan.push(red.front());
		red.pop();
		mutexKazan=1;
		o=new Obrok();	
	}
	
	if(mutexMesto==1){                                           //oslobadjaju se mesta u restoranu kad je pun
		cout<<"\nSva mesta su zauzeta, sacekajte trenutak\n";
			for(int i=0;i<MAX/2;i++)
				for(int j=0;j<MAX/2;j++)
					if(krcma.matrix[i][j].getZauzeto()=="+")
					{
						krcma.matrix[i][j].unSetZauzeto();
						krcma.slobodni++;
						if(krcma.slobodni==1)mutexMesto=0;
						cout<<" . ";
						for(int i=0;i<200000000;i++);
						}
		   krcma.prikazi();		
		  continue;
	}
	if(!red.empty()){cout<<"\nSledeci je korisnik: ";red.front().ispis();cout<<endl;}
	else{cout<<"Poslednji korisnik"<<endl;}
	while(1){
		cout<<"Bira jelo korisnik:  ";
		if(!kazan.empty())
		{
			cout<<kazan.top();
			cout<<endl;
		}
		cout<<"Izaberite \n1 za Supu \n2 za Hamburger \n3 za Salatu \n4 Preskoci izbor\n";
		cin.getline(str,100);
	    n=static_cast<int>(str[0])-48;
		system("CLS");
		switch(n)
		{
		case 1:if(!supe.empty())
			   {
					o->obrok.push_back(supe.front());o->UkCena+=supe.front().getCena();supe.pop();
					cout<<"Uzeli ste Supu"<<endl;
			   }
			   else
			   {
				   cout<<"nema trenutno na stanju, sacekajte\n";mutexHrana=1;
			   };break;
		case 2:if(!hamburgeri.empty())
			   {
				   	o->obrok.push_back(hamburgeri.front());o->UkCena+=hamburgeri.front().getCena();hamburgeri.pop();
					cout<<"Uzeli ste Hamburger"<<endl;
			   }
			   else
			   {
				   cout<<"nema trenutno na stanju, sacekajte\n";mutexHrana=1;
			   }break;
		case 3:if(!salate.empty())
			   {
			    	o->obrok.push_back(salate.front());o->UkCena+=salate.front().getCena();salate.pop();
					cout<<"Uzeli ste Salatu"<<endl;
			   }
			   else
			   {
				   cout<<"nema trenutno na stanju, sacekajte\n";mutexHrana=1;
			   }break;
		default:cout<<"nepravilan unos ";break;
		}
		
		cout<<"\nTRENUTNI IZBOR: ";
			for (std::vector<Hrana>::iterator it = o->obrok.begin() ; it != o->obrok.end(); ++it)
				it->ispis();
			o->ukupno();

		cout<<"\nIzaberite opciju  \n1.Kraja rada \n2.Brisanje elementa \n3.Novi izbor"<<endl;
		cin.getline(str,20);
	    n=static_cast<int>(str[0])-48;


		if(n==1)          //KORISNIK JE IZABRAO KRAJ RADA
		{
		 	
			pair <Korisnik,Obrok> korisnik_obrok(kazan.top(),*o);
			korisnik_obrok.first.ispis();
			cout<<"Je porucio: ";
			std::sort(o->obrok.begin(),o->obrok.end());                        //SORT FUNKCIJA 
			cout<<"\nTRENUTNI IZBOR: ";
			for (std::vector<Hrana>::iterator it = o->obrok.begin() ; it != o->obrok.end(); ++it)
				it->ispis();
			o->ukupno();
			cout<<"\nPRIPREMA SE SLEDECI KORISNIK........pritisnite dugme za nastavak\n"<<endl;
			system("Pause");//_sleep(5000);
			cout<<endl;
			kazan.pop();
			mutexKazan=0;                     //OSLOBADJA SE KAZAN I NJEGOV MUTEX
			mutexHrana=0;					  //OSLOBADJA SE PORUCENA HRANA
			Sto<pair<Korisnik,Obrok>> *s=new Sto<pair<Korisnik,Obrok>>(korisnik_obrok);  //PRAVI SE NOVI ELEMENT ZA SMESTANJE U RESTORAN
			for(int i=0,zauzeo=0;i<MAX/2, zauzeo==0;i++)
				for(int j=0;j<MAX/2;j++)
					if(krcma.matrix[i][j].getZauzeto()=="-")
					{
						krcma.matrix[i][j]=*s;
						krcma.matrix[i][j].setZauzeto();
						zauzeo=1;
						krcma.slobodni--;
						if(krcma.slobodni==0){mutexMesto=1;cout<<"upravo su zauzeli sva mesta";}
						break;
					}
			delete o;
			delete s;
			break;
		}
		//KORISNIK JE ODABRAO BRISANJE ELEMENTA
		if(n==2){
			cout<<"\n================================\nIzaberite opciju \n 1.Obrisi supu\n 2.Obrisi hamburger\n 3.Obrisi salatu"<<endl;
			cin.getline(str,20);
			n=static_cast<int>(str[0])-48;
		   obrisiItem(n,*o);
		   cout<<"\nTRENUTNI IZBOR: ";
		   for (std::vector<Hrana>::iterator it = o->obrok.begin() ; it != o->obrok.end(); ++it)
				it->ispis();
			cout<<"\nTotal";
			o->ukupno();
		}
		
		if(mutexHrana==1){dodajHranu();}   //NAKON ZAHTEVA SE DODAJE HRANA AUTOMATSKI U RED
	  }
	  
	  krcma.prikazi();  
	}
	
	return 0;
}
void init()
{
	for (int i=0;i<3;i++){Hamburger *p=new Hamburger();hamburgeri.push(*p);delete p;}  
	for (int i=0;i<3;i++){Supa *p=new Supa();supe.push(*p);delete p;}  
	for (int i=0;i<3;i++){Salata *p=new Salata();salate.push(*p);delete p;}  

}
void dodajHranu()     //DODAJE HRANU U RED 
{
	Hamburger *p=new Hamburger();hamburgeri.push(*p);delete p;  
	Supa *r=new Supa();supe.push(*r);delete r;
	Salata *q=new Salata();salate.push(*q);delete q;  
	mutexHrana=0;
}

ostream& operator << (ostream& os, const Korisnik& k)   //OPERATOR ZA ISPIS
 {
	os<<const_cast<Korisnik*>(&k)->getIme();
	os<<const_cast<Korisnik*>(&k)->getBroj();
	return os;
}

void obrisiItem(int i, Obrok &o){
	vector<Hrana>::iterator it=begin(o.obrok);
	switch (i)
	{
	case obroci::SUPA : 
						while(it!=end(o.obrok))
						{
							if(it->getIme()=="Supa")
							{
								o.UkCena=o.UkCena-it->getCena();
								it=o.obrok.erase(it);
								break;
							}
							++it;
						}
						break;
	case obroci::HAMBURGER : while(it!=end(o.obrok))
						{
							if(it->getIme()=="Hamburger")
							{
								o.UkCena=o.UkCena-it->getCena();
								it=o.obrok.erase(it);
								break;
							}
							++it;
						}
						break;

	case obroci::SALATA : while(it!=end(o.obrok))
						{
							if(it->getIme()=="Salata")
							{
								o.UkCena=o.UkCena-it->getCena();
								it=o.obrok.erase(it);
								break;
							}
							++it;
						}
						break;

	default:
		break;
	}

}


