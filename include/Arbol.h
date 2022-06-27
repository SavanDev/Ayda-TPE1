template <typename T>
class Arbol
{
public:
    Arbol();
    ~Arbol();

private:
    struct Nodo
    {
        T raiz;
        Nodo *izquierda;
        Nodo *derecha;
    };
};