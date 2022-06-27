template <typename T>
class Fila
{
public:
    Fila();
    ~Fila();
    void agregar(const T & elemento);
    void eliminarPrimero();
    bool esVacia() const;
    unsigned int longitud() const;
    const T & consultarElemento() const;
private:
    unsigned int cantidadElementos;
    struct Nodo
    {
        T elemento;
        Nodo * siguiente;
    };
    Nodo * primero;
};
