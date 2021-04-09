#include <iostream>
#include <fstream>
#include <cassert>
#include "agen_lis.h"
#include "agen_E-S.h"

using namespace std;

/*
  1. Implementa un subprograma que dado un árbol general nos calcule su grado.
*/

template <typename T>
int numHijos(const Agen<T> &A, typename Agen<T>::nodo n)
{
	int numHijos = 0;
	//suponiendo que el nodo pueda ser nulo
	if(n == Agen<T>::NODO_NULO)
		return 0;
	else
	{
		//si no tiene hijo izquerdo
		if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
			return 0;
		else
		{
			typename Agen<T>::nodo herm = A.hermDrcho(n);
			//mientra hay hermanos
			while(herm != Agen<T>::NODO_NULO)
			{
				numHijos++;
				herm = A.hermDrcho(herm);
			}
			return numHijos;
		}
	}//fin else
}

template <typename T>
int gradoArbol(const Agen<T> &A)
{
	return gradoArbol_rec(A, A.raiz());
}

template <typename T>
int gradoArbol_rec(const Agen<T> &A, typename Agen<T>::nodo n)
{
	if(n == Agen<T>::NODO_NULO)
		return 0;
	else
	{
		int gradoNodo = numHijos(A,n); //primero el nodo y luego A
		typename Agen<T>::nodo herm = A.hermDrcho(n);
		while(herm != Agen<T>::NODO_NULO)
		{
			gradoNodo = max(gradoNodo, gradoArbol_rec(A,herm));
			herm = A.hermDrcho(herm);
		}
		return gradoNodo;
	}
}

//MAIN
typedef char tElto;
const tElto fin = '#';

int main() {
    Agen<tElto> A(64);

    ifstream fA("agenB.txt"); // Abrir fichero de entrada.
    rellenarAgen(fA, A); // Desde fichero.
    fA.close();

    cout << "---Árbol A:---" << endl;
    imprimirAgen(A);    //imprimir en salida estándar

    cout << "Grado del árbol A: " << gradoArbol(A) << endl;

    return 0;
}
