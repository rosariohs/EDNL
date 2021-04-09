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
1. Implementa una nueva operaci�n del TAD Abb que tomando un elemento de este
elimine al completo el sub�rbol que cuelga de �l.
Ejemplo: Para el �rbol binario de b�squeda de la figura se muestra la transformaci�n
si la entrada fuera el valor 9.
*/

void podaABB(T elto, Abb<T>& A)
{
    Abb<T> subA = A.buscar(elto);
    if(!A.vacio())
    {
        podaABB_rec(A, subA);
    }
}

void podaABB_rec(Abb<T>& A, Abb<T>& subA)
{
    if(subA.izqdo().vacio() && subA.drcho().vacio())
        A.eliminar(subA.elemento());
    else
    {
        podaABB_rec(A, izqdo());
        podaABB_rec(A, drcho());
    }
}



