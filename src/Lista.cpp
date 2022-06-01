#include "Lista.h"

template <typename T>
Lista<T>::Lista()
{
    this->cantidadElementos = 0;
    this->primero = NULL;
}

template <typename T>
void Lista<T>::agregarLista(int i, const T & elemento)
{
    unsigned int posActual = 1;
    if (i >= 1 && i < this->longLista() + 1)
    {
        Nodo * nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = NULL;

        if (this->primero == NULL)
            this->primero = nuevoNodo;
        else
        {
            Nodo * aux = this->primero;

            // Avanza hasta la posición objetivo
            while (i > posActual)
            {
                posActual++;
                aux = aux.siguiente;
            }

            // Si no es el último, el siguiente pasará a ser del nuevo nodo
            if (aux.siguiente != NULL)
                nuevoNodo.siguiente = aux.siguiente;

            aux.siguiente = nuevoNodo;
        }

        this->cantidadElementos++;
    }
}

template <typename T>
bool Lista<T>::vaciaLista() const
{
    return this->primero == NULL;
}

template <typename T>
void Lista<T>::agregarFinalLista(const T & elemento)
{
    this->agregarLista(this->longLista() + 1, elemento);
}

template <typename T>
void Lista<T>::agregarPrimerLista(const T & elemento)
{
    this->agregarLista(1, elemento);
}

template <typename T>
unsigned int Lista<T>::longLista() const
{
    return this->cantidadElementos;
}
