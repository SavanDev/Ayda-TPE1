#ifndef FILA
#define FILA

template <typename T>
class Fila
{
public:
    Fila();
    ~Fila();
    void agregarFila(const T & elemento);
    void eliminarFila();
    bool vaciaFila() const;
    unsigned int longFila() const;
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

#endif // FILA
