#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"

using namespace std;

template <typename T>
int altura(const Abin<T> &A)
{
    return altura_rec(A.raizB(), A);
}

template <typename T>
int altura_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + max(altura_rec(A.hijoIzqdoB(n), A), altura_rec(A.hijoDrchoB(n), A));
}

/*
* 4. Implementa un subprograma que determine el nivel de desequilibrio de un �rbol binario,
* definido como el m�ximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
* define como la diferencia entre las alturas de los sub�rboles del mismo.
*/

template <typename T>
int desequilibrio(const Abin<T> &A)
{
    return desequilibrio_rec(A.raizB(), A);
}

template <typename T>
int desequilibrio_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max(
            abs(altura_rec(A.hijoIzqdoB(n), A) - altura_rec(A.hijoDrchoB(n), A)),                  //1� param. de max: desequilibrio de n
            std::max(desequilibrio_rec(A.hijoIzqdoB(n), A), desequilibrio_rec(A.hijoDrchoB(n), A)) //2� param. de max: maximo del desequilibrio entre sus hijos
        );
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
    cout << "Desequilibrio del �rbol: " << desequilibrio(A) << endl;

    return 0;
}
