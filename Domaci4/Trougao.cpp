#include "Trougao.h"


Trougao::Trougao(void){
	t1=new Tacka();
	t2=new Tacka();
	t3=new Tacka();
}
Trougao::Trougao(Tacka &t1,Tacka &t2, Tacka &t3):t1(&t1),t2(&t2),t3(&t3){}

double Trougao::povrsina(){
	
	return	abs((t1->getX()*(t2->getY()-t3->getY()) + t2->getX()*(t3->getY()-t1->getY())+ t3->getX()*(t1->getY()-t2->getY()))/2.0);

}

double Trougao::obim()
{
	return t1->udaljenostOd(*t2)+t2->udaljenostOd(*t3)+t3->udaljenostOd(*t1);	
}