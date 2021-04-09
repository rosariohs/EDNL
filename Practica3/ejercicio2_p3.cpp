#include <iostream>
#include <fstream>
#include <cassert>
#include "agen_lis.h"
#include "agen_E-S.h"

using namespace std;

/*
  2. Implementa un subprograma que dados un �rbol y un nodo dentro de dicho �rbol determine
  la profundidad de �ste nodo en el �rbol.
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

    cout << "---�rbol A:---" << endl;
    imprimirAgen(A);    //imprimir en salida est�ndar

    cout << "Profundidad del hijo izquierdo de la ra�z: " << profundidad(A.hijoIzqdo(A.raiz()),A) << endl;

    return 0;
}

