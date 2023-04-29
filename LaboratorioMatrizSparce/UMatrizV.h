//---------------------------------------------------------------------------

#ifndef UMatrizVH
#define UMatrizVH
#include<string>
#include<iostream>
 using namespace std;
//---------------------------------------------------------------------------
class MatrizDispersa{
	private:
	/// Atributos
	int *Vf; // filas
	int *Vc; // Columnas
	int *Vd ; // elementos
	int df,dc ; // Dimensión
	int repe; // elemento // es el elemento que se repetirá en la matriz
	int nt;

	int fila(int indiceVC);
	int existe_elemento(int f,int c);
	int donde_insertar(int f,int c);

	public:
	 MatrizDispersa();
	 void dimensionar(int df,int dc);
	 int dimension_Fila();
	 int  dimension_columna();
	 void poner(int f,int c,int valor);
	 int  elemento(int f,int c);
	 void definir_valor_repetido(int valor);
	 string mostrar();
	 string mostrar_atrib();
};



#endif
