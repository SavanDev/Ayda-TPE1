#include "../include/Banco.h"

using namespace std;

Banco::Banco()
{
    this->cantidadColas = 1;
    this->colaEntrada = new Lista<Cliente>();
    this->atendidos = new Lista<Cliente>();
}

void Banco::agregarCliente(const std::string nombre, const short edad, const short operacion, const short destinatario, const int monto, const bool tieneCuenta)
{
    Cliente nuevoCliente;

    nuevoCliente.nombre = nombre;
    nuevoCliente.edad = edad;
    nuevoCliente.operacion = static_cast<Operacion>(operacion);
    nuevoCliente.destinatario = static_cast<Destinatario>(destinatario);
    nuevoCliente.monto = monto;
    nuevoCliente.tieneCuenta = tieneCuenta;

    this->colaEntrada->agregarFinal(nuevoCliente);
}

void Banco::abrirColaEspecial()
{
    if (this->colasEspecialesAbiertas() < 2)
    {
        Criterio nuevoCriterio;
        int numOperacion;
        short tieneCuenta;

        cout << "Tipo de operacion para la nueva cola:" << endl;
        cout << "1. Retiro" << endl;
        cout << "2. Deposito" << endl;
        cout << "3. Transferencia" << endl;
        cout << "4. Pago" << endl;
        cout << ">> "; cin >> numOperacion;
        while (numOperacion > 4)
        {
            cout << "Tipo de operacion invalida, intente nuevamente:" << endl;
            cout << ">> "; cin >> numOperacion;
        }
        nuevoCriterio.tipo = static_cast<Operacion>(numOperacion);

        cout << "El cliente debe tener cuenta?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << ">> "; cin >> tieneCuenta;
        while (tieneCuenta > 2)
        {
            cout << "Respuesta invalida, intente nuevamente:" << endl;
            cout << ">> "; cin >> tieneCuenta;
        }

        cout << "Abriendo cola nueva..." << endl;
        if (this->colasEspecialesAbiertas() == 1)
        {
            this->colaEspecial2 = new ColaEspecial;
            this->colaEspecial2->cola = new Lista<Cliente>();
            this->colaEspecial2->criterio = &nuevoCriterio;

            reordenarClientes(colaEspecial2);
        }
        else
        {
            this->colaEspecial1 = new ColaEspecial;
            this->colaEspecial1->cola = new Lista<Cliente>();
            this->colaEspecial1->criterio = &nuevoCriterio;

            reordenarClientes(colaEspecial1);
        }
        this->cantidadColas++;

        cout << "Nueva cola abierta!" << endl;
    }
    else
    {
        cout << "Ya no se puede abrir más colas." << endl;
    }
}

void Banco::cerrarCola(int cola)
{
    if (cola == 1 && this->colaEspecial1 != NULL)
    {
        if (this->colaEspecial1->cola->esVacia())
        {
            delete this->colaEspecial1->cola;
            delete this->colaEspecial1;

            this->cantidadColas--;
            cout << "Cola eliminada!" << endl;
        }
        else
            cout << "La cola no esta vacia." << endl;
    }

    if (cola == 2 && this->colaEspecial2 != NULL)
    {
        if (this->colaEspecial2->cola->esVacia())
        {
            delete this->colaEspecial2->cola;
            delete this->colaEspecial2;

            this->cantidadColas--;
            cout << "Cola eliminada!" << endl;
        }
        else
            cout << "La cola no esta vacia." << endl;
    }
}

void Banco::listarOperaciones()
{

}

short Banco::colasEspecialesAbiertas()
{
    return this->cantidadColas - 1;
}

void Banco::reordenarClientes(ColaEspecial *colaDestino)
{
    if (!this->colaEntrada->esVacia())
    {
        Cliente aux;
        unsigned int index = 1;
        while (index <= this->colaEntrada->longitud())
        {
            aux = this->colaEntrada->obtenerElemento(index);
            if (aux.operacion == colaDestino->criterio->tipo && aux.tieneCuenta == colaDestino->criterio->tieneCuenta)
            {
                colaDestino->cola->agregarFinal(aux);
                this->colaEntrada->eliminar(index);
            }
            else
                index++;
        }
    }
}
