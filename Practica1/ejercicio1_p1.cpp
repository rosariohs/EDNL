#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"

using namespace std;

/*
  1. Implementa un subprograma que calcule el n�mero de nodos de un �rbol binario.
*/
template <typename T>
int nNodos(const Abin<T> &A)
{
    return nNodos_rec(A.raizB(), A);
}

template <typename T>
int nNodos_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + nNodos_rec(A.hijoIzqdoB(n), A) + nNodos_rec(A.hijoDrchoB(n), A);
}



/*PARA USAR �RBOLES DE CARACTERES:*/
    typedef char tElto;
    tElto fin = '#';
/*PARA USAR �RBOLES DE ENTEROS:*/
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
    cout << "N�mero de nodos del �rbol: " << nNodos(A)<< endl;

    return 0;
}
