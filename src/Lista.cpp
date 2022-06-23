#include "Lista.h"

template <typename T>
Lista<T>::Lista()
{
    this->cantidadElementos = 0;
    this->actual = NULL;
}

template <typename T>
void Lista<T>::agregar(int i, const T &elemento)
{
    if (i >= 1 && i <= this->longitud() + 1)
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;

        if (this->actual == NULL) // Primer elemento de la lista
        {
            nuevoNodo->anterior = NULL;
            nuevoNodo->siguiente = NULL;
            this->actual = nuevoNodo;
            this->indiceActual = 1;

            this->primero = nuevoNodo;
            this->ultimo = nuevoNodo;
        }
        else
        {
            while (i != this->indiceActual)
            {
                // Si la posición a colocar es mayor al indice actual, avanza una posición
                if (i > this->indiceActual)
                {
                    // Verificar si existe por separado por la opción de agregar al final
                    if (this->actual.siguiente != NULL)
                        this->actual = this->actual.siguiente;
                    this->indiceActual++;
                }

                // Si la posición a colocar es menor al indice actual y existe un anterior, retrocede una posición
                if (i < this->indiceActual && this->actual.anterior != NULL)
                {
                    this->actual = this->actual.anterior;
                    this->indiceActual--;
                }
            }

            if (this->indiceActual == this->longitud() + 1) // Si se agrega al final
            {
                nuevoNodo->anterior = this->actual;
                nuevoNodo->siguiente = NULL;
                this->actual.siguiente = nuevoNodo;
                this->actual = nuevoNodo;

                this->ultimo = nuevoNodo;
            }
            else if (this->indiceActual == 1) // Si se agrega al comienzo
            {
                nuevoNodo->siguiente = this->actual;
                nuevoNodo->anterior = NULL;
                this->actual.anterior = nuevoNodo;
                this->actual = nuevoNodo;

                this->primero = primero;
            }
            else // Si se agregar en un punto medio
            {
                nuevoNodo->siguiente = this->actual;
                nuevoNodo->anterior = this->actual.anterior;
                this->actual.anterior = nuevoNodo;
                this->actual = nuevoNodo;
            }
        }

        this->cantidad++;
    }
}

template <typename T>
bool Lista<T>::esVacia() const
{
    return this->cantidadElementos == 0;
}

template <typename T>
void Lista<T>::agregarFinal(const T &elemento)
{
    if (this->ultimo == NULL) // Si no hay elementos en la lista
        this->agregar(1, elemento);
    else
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->anterior = this->ultimo;
        nuevoNodo->siguiente = NULL;

        this->ultimo = nuevoNodo;
    }
}

template <typename T>
void Lista<T>::agregarPrimero(const T &elemento)
{
    if (this->primero == NULL) // Si no hay elemento en la lista
        this->agregar(1, elemento);
    else
    {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = this->primero;

        this->primero = nuevoNodo;
    }
}

template <typename T>
unsigned int Lista<T>::longitud() const
{
    return this->cantidad;
}

template <typename T>
void Lista<T>::eliminar(int i)
{
    if (i >= 1 && i <= this->longitud())
    {
        while (i != this->indiceActual)
        {
            if (i < this->indiceActual)
            {
                this->actual = this->actual.anterior;
                this->indiceActual--;
            }

            if (i > this->indiceActual)
            {
                this->actual = this->actual.siguiente;
                this->indiceActual++;
            }
        }

        if (i == this->longitud())
        {
            Nodo * aux = this->actual;
            this->actual = this->actual.anterior;
            this->actual.siguiente = NULL;
            delete aux;

            this->ultimo = this->actual;
        }
        else if (i == 1)
        {
            Nodo * aux = this->actual;
            this->actual = this->actual.siguiente;
            this->actual.anterior = NULL;
            delete aux;

            this->primero = this->actual;
        }
        else
        {
            Nodo * aux = this->actual;
            aux.anterior.siguiente = aux.siguiente;
            aux.siguiente.anterior = aux.anterior;
            this->actual = aux.siguiente;
            delete aux;
        }

        this->cantidad--;
    }
}

template <typename T>
const T & Lista<T>::obtenerElemento(const int i) const
{
    if (i >= 1 && i <= this->longitud())
    {
        while (i != this->indiceActual)
        {
            if (i < this->indiceActual)
            {
                this->actual = this->actual.anterior;
                this->indiceActual--;
            }

            if (i > this->indiceActual)
            {
                this->actual = this->actual.siguiente;
                this->indiceActual++;
            }
        }

        return this->actual.elemento;
    }
    else
        return NULL;
}

template <typename T>
bool Lista<T>::existeEnLista(const T & elemento) const
{
    Nodo *aux = this->primero;
    while (aux.siguiente != NULL)
    {
        if (aux.elemento == elemento)
            return true;
        else
            aux = aux.siguiente;
    }

    return false;
}