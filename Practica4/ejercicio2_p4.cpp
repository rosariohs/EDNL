#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "abin.h"
#include "abin_E-S.h"
#include "abb.h"

/*
Un �rbol binario de b�squeda se puede equilibrar realizando el recorrido en inorden
del �rbol para obtener el listado ordenado de sus elementos y a continuaci�n, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la ra�z y
construyendo recursivamente los sub�rboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB.
*/

Abb<T> equilibrioABB(Abb<T>& A)
{
    std::vector<T> eltos;
    Abb<T> B;
    inordenVector(eltos, A);
    rellenarAbb(eltos, B, 0, eltos.size()-1);
    return B;
}

void inordenVector(std::vector<T>& eltos, Abb<T>& A)
{
    if(!A.vacio())
    {
        inordenVector(eltos, A.izqdo());
        eltos.push_back(A.elemento());
        inordenVector(eltos, A.drcho());
    }
}

void rellenarAbb(std::vector<T> eltos, Abb<T>& A, int minimo, int maximo)
{
    int eltoInsert = (maximo+minimo)/2;
    A.insertar(eltos[eltoInsert]);

    if(minimo != maximo)
    {
        rellenarAbb(eltos, A, minimo, eltoInsert);
        rellenarAbb(eltos, A, eltoInsert+1, maximo);
    }
}


