#include <cstddef>
#include "../include/Fila.h"

template <typename T>
Fila<T>::Fila()
{
    this->cantidadElementos = 0;
    this->primero = NULL;
}

template <typename T>
Fila<T>::~Fila()
{
    while (this->primero != NULL)
    {
        eliminarPrimero();
    }
}

template <typename T>
void Fila<T>::agregar(const T & elemento)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo.elemento = elemento;

    if (this->primero == NULL)
    {
        nuevoNodo.siguiente = NULL;
        this->primero = nuevoNodo;
    }
    else
    {
        Nodo *aux = this->primero;
        nuevoNodo.siguiente = aux;
        this->primero = nuevoNodo;
    }

    this->cantidadElementos++;
}

template <typename T>
void Fila<T>::eliminarPrimero()
{
    Nodo *aux = this->primero;

    if (aux->siguiente != NULL)
        this->primero = aux->siguiente;
    else
        this->primero = NULL;

    delete aux;

    this->cantidadElementos--;
}

template <typename T>
bool Fila<T>::esVacia() const
{
    return this->primero == NULL;
}

template <typename T>
unsigned int Fila<T>::longitud() const
{
    return this->cantidadElementos;
}

template <typename T>
const T & Fila<T>::consultarElemento() const
{
    return this->primero->elemento;
}
