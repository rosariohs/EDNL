#include <iostream>
#include <fstream>
#include <cassert>
#include "agen_lis.h"
#include "agen_E-S.h"

using namespace std;

/*
   Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
*/

//devuelve el nodo donde se cuentra el elto si existe sino devuelve el nodo nulo
template <typename T>
void busqueda(const Agen<T> &A, const T elto)
{
    return busqueda_rec(A,elto,A.raiz());
}

template <typename T>
void busqueda_rec(const Agen<T> &A, const T elto, typename Agen<T>::nodo n)
{
    if(A.elemento(n) == elto)
        podaAgen(n,A);
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            return busqueda_rec(A,elto,hijo);
            hijo = A.hermDrcho(hijo);
        }
    }
}

template <typename T>
void podaAgen(typename Agen<T>::nodo n, Agen<T>& A)
{
    //si no tiene hijos, es nodo hoja se elimina el propio nodo
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        A.eliminarHijoIzqdo(A.padre(n));
    }
    //si tiene hijos
    else if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
    {
        //mientras que tenga hijos
        while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
            podaAgen(A.hijoIzqdo(n),A);
    }
}

//MAIN
typedef char tElto;
const tElto fin = '#';

int main() {
    Agen<tElto> A(64);
    tElto x= 'g'; // x es el elemento que tratamos de podar del árbol

    ifstream fA("agenB.txt"); // Abrir fichero de entrada.
    rellenarAgen(fA, A); // Desde fichero.
    fA.close();

    cout << "---Árbol A:---" << endl;
    imprimirAgen(A);    //imprimir en salida estándar
    cout << "--------------" << endl;

    podaAgen(x,A);
    cout << "Se ha eliminado el subárbol cuyo nodo raíz contenía el elemento "<<x<<": "<<endl;
    imprimirAgen(A);
    /*
    if (elimElem(x,A))
    {
        cout << "Se ha eliminado el subárbol cuyo nodo raíz contenía el elemento "<<x<<": "<<endl;
        imprimirAgen(A);
    }
    else
        cout << "No se ha encontrado el elemento "<<x<<"."<<endl;
    */

    return 0;
}
