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
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.
*/

Abb<T> operacionUnion(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> C;
    C = A;

    while(!B.vacio())
    {
        //inserto el elemento en C
        C.insertar(B.elemento());
        //elimino el elemento insertado en C
        B.eliminar(B.elemento);
    }

    equilibrarAbb(C);
    return C;
}
