template <typename T>
class Arbol
{
public:
    Arbol();
    ~Arbol();
    void agregar();
    bool esVacio();
    T raiz();
    T subIzquierdo();
    T subDerecho();
    bool existeElemento();
    int cantidadElementos();
    int profundidad();

private:
    struct Nodo
    {
        T raiz;
        Nodo *izquierda;
        Nodo *derecha;
    };
};
