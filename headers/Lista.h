#ifndef LISTA
#define LISTA
template <typename T>

class Lista
{
public:
    Lista();
    unsigned int longLista(const Lista l) const;
    void agregarLista(int i, T elemento);
    void eliminarLista(int i);
    T elementoLista(int i) const;
    void agregarFinalLista(T elemento);
    void agregarPrimeroLista(T elemento);
    bool vaciaLista() const;
    bool verificarElemento(T elemento) const;
private:

}

#endif // LISTA
