#include <iostream>
#include <fstream>
#include "agen_lis.h"
#include "agen_E-S.h"

using namespace std;

/*
  Se define el desequilibrio de un �rbol general como la m�xima diferencia entre las alturas
  de los sub�rboles m�s bajo y m�s alto de cada nivel. Implementa un subprograma que calcule
  el grado de desequilibrio de un �rbol general.
*/
template <typename T>
int altura_Agen(const Agen<T> &A)
{
    return altura_Agen_rec(A.raiz(), A);
}

//funci�n auxiliar: altura de un nodo de un Agen
template <typename T>
int altura_Agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
    if ( n == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        alturaHij = -1;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while (hijo != Agen<T>::NODO_NULO)
        {
            alturaHij= max( alturaHij, altura(hijo, A) );
            hijo= A.hermDrcho(hijo);
        }
        return 1 + alturaHij;
    }
}

template <typename T>
int alturaMin_Agen_rec(const Agen<T> &A)
{
    return altura_Agen_rec(A.raiz(), A);
}

//funci�n auxiliar: altura de un nodo de un Agen
template <typename T>
int alturaMin_Agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
    if ( n == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        alturaHij = -1;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while (hijo != Agen<T>::NODO_NULO)
        {
            alturaHij= min( alturaHij, altura(hijo, A) );
            hijo= A.hermDrcho(hijo);
        }
        return 1 + alturaHij;
    }
}

template <typename T>
unsigned desequilibrio(const Agen<T> &A)
{
    return altura_Agen(A) - alturaMin_Agen(A);
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
