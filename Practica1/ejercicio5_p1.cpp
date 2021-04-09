
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"

using namespace std;

//devuelve la profundidad de un árbol
template <typename T>
int altura(const Abin<T> &A)
{
    return altura_rec(A, A.raiz());
}

template <typename T>
int altura_rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
    //si el nodo es nulo
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + max(altura_rec(A, A.hijoDrcho(n)), altura_rec(A, A.hijoIzqdo(n)));
}

//devuelve el numero de hijos de un nodo
template <typename T>
int contarHijos(const Abin<T> &A, typename Abin<T>::nodo n)
{
    if (A.hijoIzqdo(n)== Abin<T>::NODO_NULO && A.hijoDrcho(n)== Abin<T>::NODO_NULO)
        return 0;
    if (A.hijoIzqdo(n)!= Abin<T>::NODO_NULO && A.hijoDrcho(n)!= Abin<T>::NODO_NULO)
        return 2;
    else
        return 1;
}

//devuelve true si es pseudocompleto y false si no lo es
template <typename T>
bool esPseudocompleto(const Abin<T> &A)
{
    return esPseudocompleto_rec(A.raiz(), A, altura(A), 0);
}

template <typename T>
bool esPseudocompleto_rec(typename Abin<T>::nodo n, const Abin<T> &A, int alturaArbol, int profNodo)
{
    //caso base, si el nodo es nulo
    if (n == Abin<T>::NODO_NULO)
        return true;
    else
    {
        //si se está en el nivel adecuado, último nivel-1,
        //comprobamos y devolvemos true si tiene 0 o 2 hijos sino devolvemos false
        if (profNodo == alturaArbol-1)
            return (contarHijos(A,n) != 1);
        else
        {
            return esPseudocompleto_rec(A.hijoIzqdo(n), A, alturaArbol, ++profNodo) && esPseudocompleto_rec(A.hijoDrcho(n), A, alturaArbol, ++profNodo);
        }
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
    if (esPseudocompleto(A))
        cout << "El árbol es pseudocompleto" << endl;
    else
        cout << "El árbol NO es pseudocompleto" << endl;


    return 0;
}

