#include <cstddef>
#include "../include/Lista.h"

template <typename T>
Lista<T>::Lista()
{
    this->cantidad = 0;
    this->actual = NULL;
}

template <typename T>
Lista<T>::~Lista()
{
    while (this->cantidad > 0)
    {
        eliminar(longitud());
    }
}

template <typename T>
void Lista<T>::agregar(int i, const T &elemento)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo.elemento = elemento;

    if (this->actual == NULL && i == 1) // Primer elemento de la lista
    {
        nuevoNodo.anterior = NULL;
        nuevoNodo.siguiente = NULL;
        this->actual = nuevoNodo;
        this->indiceActual = 1;

        this->primero = nuevoNodo;
        this->ultimo = nuevoNodo;
    }
    else if (i == 1) // Agrega al principio
    {
        nuevoNodo.siguiente = this->primero;
        nuevoNodo.anterior = NULL;
        this->primero->anterior = nuevoNodo;
        this->primero = nuevoNodo;
    }
    else if (i == longitud() + 1) // Agrega al final
    {
        nuevoNodo.anterior = this->ultimo;
        nuevoNodo.siguiente = NULL;
        this->ultimo->siguiente = nuevoNodo;
        this->ultimo = nuevoNodo;
    }
    else if (i > 1 && i <= longitud()) // Punto medio
    {
        moverIndice(i);

        nuevoNodo.siguiente = this->actual;
        nuevoNodo.anterior = this->actual->anterior;
        this->actual->anterior = nuevoNodo;
        this->actual = nuevoNodo;
    }

    // Establecer como último elemento accedido
    this->actual = nuevoNodo;
    this->indiceActual = i;

    this->cantidad++;
}

template <typename T>
bool Lista<T>::esVacia() const
{
    return this->cantidadElementos == 0;
}

template <typename T>
void Lista<T>::agregarFinal(const T &elemento)
{
    agregar(longitud() + 1, elemento);
}

template <typename T>
void Lista<T>::agregarPrimero(const T &elemento)
{
    agregar(1, elemento);
}

template <typename T>
unsigned int Lista<T>::longitud() const
{
    return this->cantidad;
}

template <typename T>
void Lista<T>::eliminar(int i)
{
    if (longitud() == 1 && i == 1) // Único elemento de la lista
    {
        Nodo *aux = this->actual;
        delete aux;
        this->actual = this->primero = this->ultimo = NULL;
    }
    else if (i == 1) // Primero elemento
    {
        Nodo *aux = this->primero;
        this->primero = aux->siguiente;
        this->primero->anterior = NULL;
        delete aux;

        this->actual = this->primero;
    }
    else if (i == longitud()) // Último elemento
    {
        Nodo *aux = this->ultimo;
        this->ultimo = aux->anterior;
        this->ultimo->siguiente = NULL;
        delete aux;

        this->actual = this->ultimo;
    }
    else if (i > 1 && i < longitud()) // Punto medio
    {
        moverIndice(i);

        Nodo * aux = this->actual;
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        this->actual = aux->siguiente;
        delete aux;
    }

    this->indiceActual = i;
    this->cantidad--;
}

template <typename T>
const T & Lista<T>::obtenerElemento(const int i) const
{
    if (i == 1)
    {
        this->actual = this->primero;
        this->indiceActual = i;
        return this->actual->elemento;
    }
    else if (i == longitud())
    {
        this->actual = this->ultimo;
        this->indiceActual = i;
        return this->actual->elemento;
    }
    else if (i > 1 && i < longitud())
    {
        moverIndice(i);
        return this->actual->elemento;
    }
    else
        return NULL;
}

template <typename T>
bool Lista<T>::existeEnLista(const T & elemento) const
{
    Nodo *aux = this->primero;
    while (aux->siguiente != NULL)
    {
        if (aux->elemento == elemento)
            return true;
        else
            aux = aux->siguiente;
    }

    return false;
}

template <typename T>
void Lista<T>::moverIndice(const int i)
{
    while (i != this->indiceActual)
    {
        if (i < this->indiceActual)
        {
            this->actual = this->actual->anterior;
            this->indiceActual--;
        }

        if (i > this->indiceActual)
        {
            this->actual = this->actual->siguiente;
            this->indiceActual++;
        }
    }
}
