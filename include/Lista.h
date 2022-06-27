template <typename T>
class Lista
{
public:
    Lista();
    ~Lista();
    unsigned int longitud() const;
    void agregar(const int i, const T & elemento);
    void eliminar(const int i);
    const T & obtenerElemento(const int i) const;
    void agregarFinal(const T & elemento);
    void agregarPrimero(const T & elemento);
    bool esVacia() const;
    bool existeEnLista(const T & elemento) const;
private:
    unsigned int cantidad;
    struct Nodo
    {
        T elemento;
        Nodo * anterior;
        Nodo * siguiente;
    };

    // La lista va a mantener el puntero a la última posición accedida
    Nodo * actual;
    unsigned int indiceActual;

    // Para las funciones agregarPrimero y agregarFinal
    Nodo * primero;
    Nodo * ultimo;

    void moverIndice(const int i);
};
