#include<iostream>
#include "UMatrizV.h"

using namespace std;

MatrizDispersa* m;
int main(){
m=new MatrizDispersa();
m->dimensionar(5,5);
m->poner(1,1,100);
cout<< m->mostrar_atrib()<<endl;
m->poner(3,3,200);
cout<< m->mostrar_atrib()<<endl;
m->poner(1,3,150);
cout<< m->mostrar_atrib()<<endl;
cout<< m->mostrar()<<endl;


system("pause");
return 0;
}

