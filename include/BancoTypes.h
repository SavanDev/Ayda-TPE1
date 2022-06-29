#include <iostream>

enum Operacion
{
    Retiro,
    Deposito,
    Transferencia,
    Pago
};

enum Destinatario
{
    Persona,
    Bancario,
    Impuesto
};

struct Cliente
{
    std::string nombre;
    short edad;
    Operacion operacion;
    Destinatario destinatario;
    int monto;
    bool tieneCuenta;

    bool operator==(const Cliente& other) const
    {
        return nombre == other.nombre &&
        edad == other.edad &&
        operacion == other.operacion &&
        destinatario == other.destinatario &&
        monto == other.monto &&
        tieneCuenta == other.tieneCuenta;
    }
};
