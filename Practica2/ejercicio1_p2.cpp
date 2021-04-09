#include<stdio.h>
#include<stdlib.h>

#include "abin.h"
#include "abin_E-S.h"

using namespace std;

bool sonSimilares(Abin<T> A&, Abin<T> B&)
{
	//¿sería necesario?
	if(A.riaz() == Abin<T>::NODO_NULO && B.riaz() == Abin<T>::NODO_NULO)
		return true;

	sonSimilares_rec(A, A.raiz(), B, B.raiz());
}

bool sonSimilares_rec(Abin<T> A&, Abin<T>::nodo a, Abin<T> B&, Abin<T>::nodo b)
{
	//caso base, ambos nodos son nulos
	if(a == Abin<T>::NODO_NULO && n == Abin<T>::NODO_NULO)
		return true;
	else
	{
		if(a == Abin<T>::NODO_NULO  || b == Abin<T>::NODO_NULO)
			return false; 
		else
			return sonSimilares_rec(A, A.hijoIzqdo(a), B, B.hijoIzqdo(b)) && 
			sonSimilares_rec(A, A.hijoDrcho(a), B, B.hijoDrcho(b));
	}
}

/*PARA USAR ÁRBOLES DE CARACTERES:*/
    typedef char tElto;
    tElto fin = '#';
/*PARA USAR ÁRBOLES DE ENTEROS:*/
//  typedef int tElto;
//  tElto fin = -99;
int main()
{
    Abin<tElto> A;
    //PARA RELLENAR DESDE FICHERO:
        ifstream fA("abin2-char.txt"); // Abrir fichero de entrada.
        rellenarAbin(fA,A); // Rellenar desde fichero.
    //PARA RELLENAR MANUALMENTE:
    //    rellenarAbin(A, fin);

    imprimirAbin(A);
    cout << "Número de nodos del árbol: " << nNodos(A)<< endl;

    return 0;
}
