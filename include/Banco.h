#include <iostream>
#include "Lista.h"
#include "BancoTypes.h"

class Banco
{
public:
    Banco();
    ~Banco();
    void agregarCliente(const std::string nombre, const short edad, const short operacion, const short destinatario, const int monto, const bool tieneCuenta);
    void atenderCliente();
    void abrirColaEspecial();
    void cerrarCola(int cola);
    void listarOperaciones();
    short colasEspecialesAbiertas();
private:
    struct Criterio
    {
        Operacion tipo;
        bool tieneCuenta;
    };

    struct ColaEspecial
    {
        Lista<Cliente> *cola;
        Criterio *criterio;
    };


    short cantidadColas;
    Lista<Cliente> *colaEntrada;
    ColaEspecial *colaEspecial1;
    ColaEspecial *colaEspecial2;
    Lista<Cliente> *atendidos;

    void reordenarClientes(ColaEspecial *colaDestino);
};
