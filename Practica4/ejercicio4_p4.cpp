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
Dados dos conjuntos representados mediante �rboles binarios de b�squeda,
implementa la operaci�n intersecci�n de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersecci�n de ambos. El resultado debe quedar en un �rbol
equilibrado.
*/

Abb<T> operacionInterseccion(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> C;
    C = A;

    while(!B.vacio())
    {
        //si el elemento no est� en B
        if(!B.buscar(C.elemento()))
            //elimino el elemento de C
            C.eliminar(B.elemento());
    }

    equilibrarAbb(C);
    return C;
}

