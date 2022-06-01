#ifndef LISTA
#define LISTA

template <typename T>
class Lista
{
public:
    Lista();
    ~Lista();
    unsigned int longLista() const;
    void agregarLista(int i, const T & elemento);
    void eliminarLista(int i);
    const T & elementoLista(int i) const;
    void agregarFinalLista(const T & elemento);
    void agregarPrimeroLista(const T & elemento);
    bool vaciaLista() const;
    bool verificarElemento(const T & elemento) const;
private:
    unsigned int cantidadElementos;
    struct Nodo
    {
        T elemento;
        Nodo * siguiente;
    };
    Nodo * primero;
}

#endif // LISTA
