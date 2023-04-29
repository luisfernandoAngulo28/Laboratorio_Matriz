//---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatrizV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

 MatrizDispersa::MatrizDispersa(){
	df=dc=repe=nt=0;
	Vf=new int[df*dc]; // filas
	Vc=new int[df*dc]; // Columnas
	Vd=new int[df+1]; // elementos
	for(int i=0;i<df+1;i++){ //0<1
		  Vf[i]=1;   //V[0]=1
	}
 }
									//5 ,   5
  void MatrizDispersa::dimensionar(int f,int c){
	df=f;
	dc=c;
	Vf=new int[df*dc]; // filas
	Vc=new int[df*dc]; // Columnas
	Vd=new int[df+1]; // elementos
	for(int i=0;i<df+1;i++){ //0<5+1
		  Vf[i]=1;   //V[0]=1
	}
  }

  int MatrizDispersa::dimension_Fila(){
	 return df;
  }

  int MatrizDispersa::dimension_columna(){
	 return dc;
  }

  int MatrizDispersa::existe_elemento(int f,int c){
	  int lug_antes=0;
	  for(int i=0;i<(f-1);i++){
		lug_antes=lug_antes+(Vf[i+1]-Vf[i]);
	  }
	  int max_elem=Vf[f+1-1]-Vf[f-1];  //1-1=0
	  for(int i=0;i<max_elem;i++){
		   if(Vc[lug_antes+i]==c){
				 return  lug_antes+i;
		   }
	  }
	  return -1;

  }
  int MatrizDispersa::donde_insertar(int f, int c) {
	int lug_antes = 0;
	for (int i = 0; i < (f - 1); i++) {
		lug_antes += (Vf[i + 1] - Vf[i]);
	}
	int nuevo_lugar = lug_antes;
	int lugar = lug_antes;
	int max_elem = Vf[f + 1 - 1] - Vf[f - 1];
	for (int i = 0; i < max_elem; i++) {
		lugar = lug_antes + i;
		if (c == Vc[lugar])

				nuevo_lugar = lugar;
	}

	return nuevo_lugar;
}


							  //  1,   1,    100
  void MatrizDispersa::poner(int f,int c,int valor){
	if((f>=1 && f<=df)&&(c>=1 && c<= dc)){
	   int lugar=existe_elemento(f,c); //-1
	   if(lugar!=-1){
			Vd[lugar] = valor;
			if (valor == repe) {
				for (int i = lugar; i < nt; i++) {
					Vd[i] = Vd[i + 1];
					Vc[i] = Vc[i + 1];
				}
				for (int i = f; i < df + 1; i++)
					Vf[i]--;
				nt--;
			}

	   }else{
		   if(valor!=repe){
		   int pos=donde_insertar(f,c);
			   for(int i=nt;i>pos;i--){
				  Vd[i]=Vd[i-1];
				  Vc[i]=Vc[i-1];

			   }
			   Vd[pos]=valor;
			   Vc[pos]=c;
			   nt++;
			   for(int i=f;i<df+1;i++){
				 Vf[i]++;
			   }
		   }
	   }
	}
  }

	int  MatrizDispersa::elemento(int f,int c){
		if((f>=1 && f<=df)&&(c>=1 && c<= dc)){
		   int lugar=existe_elemento(f,c);
		   if(lugar==-1){
			 return repe;
		   }else{
			   return Vd[lugar];
		   }

		}else{
			cout<<"Error de Rango\n";
		}


	}

    void MatrizDispersa::definir_valor_repetido(int valor) {

		bool hayRepe = false;
		for (int i = 0; i < nt && hayRepe == false; i++) {
			if (Vd[i] == valor)
				hayRepe = true;
		}
		if (nt == 0 || hayRepe == false) {
			repe = valor;
		}
		else {
			int nRep = valor;
			int aRep = repe;
			for (int i = 1; i <= df; i++) {
				for (int j = 1; j <= dc; j++) {
					int e = elemento(i, j);
					if (e == nRep) {
						int lugar = existe_elemento(i, j);
						for (int k = lugar; k < nt; k++) {
							Vd[k] = Vd[k + 1];
							Vc[k] = Vc[k + 1];
						}
						for (int k = i; k < df + 1; k++)
							Vf[k]--;
						nt--;
					}
					else if (e == aRep) {
						int pos = donde_insertar(i, j);
						for (int k = nt; k > pos; k--) {
							Vd[k] = Vd[k - 1];
							Vc[k] = Vc[k - 1];
						}
						Vd[pos] = valor;
						Vc[pos] = j;
						nt++;
						for (int k = i; k < df + 1; k++)
							Vf[k]++;
					}
				}
			}
			repe = valor;
		}
	}


	 string MatrizDispersa::mostrar(){
		string salida="";
		for(int i=1;i<=df;i++){
			salida=salida+"|   ";
			 for(int j=1;j<=dc;j++){
			   int elemen=elemento(i,j);
			   salida=salida+to_string(elemen)+"  ";
			 }
			 salida=salida+"|  \n";

		}
		return salida;

	 }

	 string MatrizDispersa::mostrar_atrib(){
		int max=df*dc;
		string s="";
		s=s+"vd:";
		for(int i=0;i<max;i++){
		  s=s+to_string(Vd[i])+",";
		}
		s=s+"\nVc: ";
		for(int i=0;i<max;i++){
		  s=s+to_string(Vc[i])+",";
		}
		s=s+"\nVf: ";
		for(int i=0;i<max;i++){
		  s=s+to_string(Vf[i])+",";
		}
		s=s+"\ndf:"+to_string(dimension_Fila());
		s=s+"\ndc:"+to_string(dimension_columna());
		s=s+"\nrepe:"+to_string(repe);
		s=s+"\nnt:"+to_string(nt);
		return s;
	 }


