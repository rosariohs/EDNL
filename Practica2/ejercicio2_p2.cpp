#include<stdio.h>
#include<stdlib.h>

#include "abin.h"
#include "abin_E-S.h"

using namespace std;

/*
	Para un árbol binario B, podemos construir el árbol binario reflejado B
	R cambiando los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que
	devuelva el árbol binario reflejado de uno dado.
*/

Abin<T> arbolReflejado(typename Abin<T> A&)
{
	Abin<T> B;	
	if(A.raiz() == Abin<T>::NODO_NULO)
		return A;
	else
		//insertamos la raiz
		B.insertarRaiz(A.elemento(A.raiz()));
		arbolReflejado_rec(A, A.raiz(), B, B.raiz());
}

Abin<T> arbolReflejado_rec(Abin<T> A&, Abin<T>::nodo a, Abin<T> B&, Abin<T>::nodo b)
{
	if(a == Abin<T>::NODO_NULO)
		return B;

	else
	{
		B.insertarHijoIzqrdo(A.elemento(A.hijoDrcho(a)));
		B.insertarHijoDrcho(A.elemento(A.hijoIzqrdo(a)));
		arbolReflejado_rec(A, A.hijoDrcho(a), B, B.hijoDrcho(b));
		arbolReflejado_rec(A, A.hijoIzqrdo(a), B, B.hijoIzqrdo(b));
	}
}