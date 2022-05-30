#ifndef FILA
#define FILA
template <typename T>

class Fila
{
public:
    Fila();
    void agregarFila(T elemento);
    void eliminarFila();
    bool vaciaFila();
    unsigned int longFila();
    T consultarValor();
private:

};

#endif // FILA
