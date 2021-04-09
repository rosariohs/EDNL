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
Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado.
*/

Abb<T> operacionInterseccion(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> C;
    C = A;

    while(!B.vacio())
    {
        //si el elemento no está en B
        if(!B.buscar(C.elemento()))
            //elimino el elemento de C
            C.eliminar(B.elemento());
    }

    equilibrarAbb(C);
    return C;
}

