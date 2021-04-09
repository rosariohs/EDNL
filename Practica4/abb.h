/* Implementación del TAD "Árbol binario de búsqueda" mediante una estructura dinámica recursiva */

#ifndef ABB_H
#define ABB_H

#include <cassert>
#include "abin.h"

template <typename T>
class Abb {
public:
    Abb(); // constructor

    const Abb& buscar(const T& e) const;
    void insertar(const T& e);
    void eliminar(const T& e);
    bool vacio() const;

    //Observadores:
    const T& elemento() const;
    const Abb& izqdo() const;
    const Abb& drcho() const;

    Abb(const Abb& A); // ctor. de copia
    Abb& operator =(const Abb& A); // asig. árboles

    operator Abin<T>();

    void buscarYPodar(const T& e);
    void rellenar(typename Abin<T>::nodo , Abin<T> &);

    ~Abb(); // destructor

    friend class abin;

private:
    struct arbol
    {
        T elto;
        Abb izq, der;
        arbol(const T& e): elto(e) {}
    };
    arbol* r; // raíz del árbol
    T borrarMin();
    void copiar(const Abb& A);
};

template <typename T>
inline Abb<T>::Abb() : r(0) {}

template <typename T>
inline bool Abb<T>::vacio() const
{
    return r == 0;
}

template <typename T>
const Abb<T>& Abb<T>::buscar(const T& e) const
{
    if (r == 0) // árbol vacío, e no encontrado
        return *this;
    else if (e < r->elto) // buscar en subárbol izqdo.
        return r->izq.buscar(e);
    else if (r->elto < e) // buscar en subárbol drcho.
        return r->der.buscar(e);
    else // encontrado e en la raíz
        return *this;
}

template <typename T>
void Abb<T>::insertar(const T& e)
{
    if (r == 0) // árbol vacío
        r = new arbol(e);
    else if (e < r->elto) // insertar en el subárbol izqdo.
        r->izq.insertar(e);
    else if (r->elto < e) // insertar en el subárbol drcho.
        r->der.insertar(e);
}

template <typename T>
void Abb<T>::eliminar(const T& e)
{
    if (r != 0) // árbol no vacío
    {
        if (e < r->elto) // quitar e del subárbol izqdo.
            r->izq.eliminar(e);
        else if (r->elto < e) // quitar e del subárbol drcho.
            r->der.eliminar(e);
        else if (r->izq.r == 0 && r->der.r == 0) // quitar e de la raíz // 1. Raíz es hoja
        {
            delete(r);
            r = 0; // el árbol queda vacío
        }
        else if (r->der.r == 0) // 2. Raíz sólo tiene hijo izqdo.
        {
            arbol* a = r->izq.r;
            r->izq.r = 0; // impide destruir el subárbol izqdo.
            delete(r);
            r = a;
        }
        else if (r->izq.r == 0) // 3. Raíz sólo tiene hijo drcho.
        {
            arbol* a = r->der.r;
            r->der.r = 0; // impide destruir el subárbol drcho.
            delete(r);
            r = a;
        }
        else// 4. Raíz tiene dos hijos
            r->elto = r->der.borrarMin(); // Eliminar el mínimo del subárbol derecho y sustituir el elemento de la raíz por éste.
    }
}

// Elimina el nodo que almacena el menor elemento
// del árbol. Devuelve el elemento del nodo eliminado. (Método privado)
template <typename T>
T Abb<T>::borrarMin()
{
    if (r->izq.r == 0) // subárbol izquierdo vacío
    {
        T e = r->elto;
        arbol* hd = r->der.r;
        r->der.r = 0; // impide destruir el subárbol drcho.
        delete(r); // sustituir r por el subárbol drcho.
        r = hd;
        return e;
    }
    else
        return r->izq.borrarMin();
}

template <typename T>
inline const T& Abb<T>::elemento() const
{
    assert(r != 0);
    return r->elto;
}

template <typename T>
inline const Abb<T>& Abb<T>::izqdo() const
{
    assert(r != 0);
    return r->izq;
}

template <typename T>
inline const Abb<T>& Abb<T>::drcho() const
{
    assert(r != 0);
    return r->der;
}

template <typename T>
inline Abb<T>::Abb(const Abb<T>& A): r(0)
{
    copiar(A);
}

template <typename T>
Abb<T>& Abb<T>::operator =(const Abb<T>& A)
{
    if (this != &A) // evitar autoasignación
    {
        this->~Abb(); // vaciar el árbol
        copiar(A);
    }
return *this;
}

template <typename T>
Abb<T>::~Abb()
{
    if (r != 0) // árbol no vacío
    {
        delete r; // llama a r->izq.~Abb() y a r->der.~Abb()
        r = 0; // el árbol queda vacío
    }
}

// Método privado
template <typename T>
void Abb<T>::copiar(const Abb<T>& A) // Copia el árbol a en *this
{
    if (A.r != 0) // árbol no vacío
    {
        r = new arbol(A.r->elto); // copiar raíz
        r->izq.copiar(A.r->izq); // copiar subárbol izqdo.
        r->der.copiar(A.r->der); // copiar subárbol drcho.
    }
}

/*
* 1. Implementa una nueva operación del TAD Abb que tomando un elemento del mismo
*    elimine al completo el subárbol que cuelga de él.
*/
template <typename T>
void Abb<T>::buscarYPodar(const T& e)
{
    if (r != 0) // si el arbol r es nulo, no tiene sentido buscar
    {
        if (e < r->elto) // buscar en subárbol izqdo
            r->izq.buscarYPodar(e);
        else if (r->elto < e) // buscar en subárbol drcho
            return r->der.buscarYPodar(e);
        else // si *this es un subarbol cuya raiz almacena el elemento "e" se procede a borrarlo
        {
            delete r;
            r=0;
        }
    }
}



/*
* 2. Añade al TAD Abb un operador de conversión para obtener un árbol binario a partir
*    de un ABB, template <typename T> Abb<T>::operator Abin<T>() const;. Es
*    necesario declararlo como amigo de la clase Abin. Este operador nos permitirá obtener
*    una copia de un ABB y tratarlo como un árbol binario, por ejemplo para realizar un
*    recorrido del mismo.
*/

template <typename T>
Abb<T>::operator Abin<T>()
{
    Abin<T> tmp;

    if (r != 0)    //si el arbol no está vacío
    {
        tmp.insertarRaizB(r->elto);
        rellenar(tmp.raizB(), tmp);
    }
    return tmp;
}


template<typename T>
void Abb<T>::rellenar(typename Abin<T>::nodo n, Abin<T> &A)
{
    if (r->izq.r != 0)
    {
        A.insertarHijoIzqdoB(n,r->izq.r->elto);
        r->izq.rellenar(A.hijoIzqdoB(n), A);
    }
    if (r->der.r != 0)
    {
        A.insertarHijoDrchoB(n,r->der.r->elto);
        r->der.rellenar(A.hijoDrchoB(n), A);
    }
}




#endif
