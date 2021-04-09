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
5. Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
La implementación del operador  debe realizarse utilizando obligatoriamente la
operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n).
*/

Abb<T> operacionRombo(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> C;
    C = A;

    while(!B.vacio())
    {
        //si el elemento está en B
        if(B.buscar(C.elemento()))
            //elimino el elemento de C
            C.eliminar(B.elemento());
    }

    equilibrarAbb(C);
    return C;
}

