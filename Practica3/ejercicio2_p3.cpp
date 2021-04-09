#include <iostream>
#include <fstream>
#include <cassert>
#include "agen_lis.h"
#include "agen_E-S.h"

using namespace std;

/*
  2. Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
  la profundidad de éste nodo en el árbol.
*/

template <typename T>
unsigned profundidad (typename Agen<T>::nodo n, const Agen<T> &A)
{
    if(n != Agen<T>::NODO_NULO)
        return -1;
    else
    {
        if (n == A.raiz())
            return 0;
        else
            return 1 + profundidad (A.padre(n),A);
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

    cout << "Profundidad del hijo izquierdo de la raíz: " << profundidad(A.hijoIzqdo(A.raiz()),A) << endl;

    return 0;
}

