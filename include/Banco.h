#include <string>

class Banco
{
public:
    void agregarCliente();
    void abrirColaEspecial();
    void cerrarCola(int cola);
    void listarOperaciones();
private:
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
        string nombre;
        short edad;
        Operacion operacion;
        Destinatario destinatario;
        int monto;
        bool tieneCuenta;
    };
    
    struct Criterio
    {
        Operacion tipo;
        bool tieneCuenta;
    };
    
}