#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"

using namespace std;

/*
   3. Implementa un subprograma que, dados un �rbol binario y un nodo del mismo,
 * determine la profundidad de este nodo en dicho �rbol.
*/
template <typename T>
int profundidadNodo(const Abin<T> &A, typename Abin<T>::nodo n)
{
    if (n == A.raizB())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padreB(n));
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
        ifstream fA("abin1-char.txt"); // Abrir fichero de entrada.
        rellenarAbin(fA,A); // Rellenar desde fichero.
    //PARA RELLENAR MANUALMENTE:
    //    rellenarAbin(A, fin);

    imprimirAbin(A);
    cout << "Profundidad del hijo izquierdo de la ra�z del �rbol: " << profundidadNodo(A,A.hijoIzqdoB(A.raizB()))<< endl;

    return 0;
}
