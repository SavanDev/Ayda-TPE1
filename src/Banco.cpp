#include "../include/Banco.h"

using namespace std;

Banco::Banco()
{
    this->cantidadColas = 1;
    this->colaEntrada = new Lista<Cliente>();
    this->atendidos = new Lista<Cliente>();
    this->colaEspecial1 = NULL;
    this->colaEspecial2 = NULL;
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

    if (this->colasEspecialesAbiertas() > 0)
    {
        if (this->colaEspecial1 != NULL && this->colaEspecial1->criterio->tipo == nuevoCliente.operacion && this->colaEspecial1->criterio->tieneCuenta == nuevoCliente.tieneCuenta)
            this->colaEspecial1->cola->agregarFinal(nuevoCliente);
        else if (this->colaEspecial2 != NULL && this->colaEspecial2->criterio->tipo == nuevoCliente.operacion && this->colaEspecial2->criterio->tieneCuenta == nuevoCliente.tieneCuenta)
            this->colaEspecial2->cola->agregarFinal(nuevoCliente);
        else
            this->colaEntrada->agregarFinal(nuevoCliente);
    }
    else
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
        nuevoCriterio.tieneCuenta = tieneCuenta == 1 ? true : false;

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
            this->colaEspecial1 = NULL;

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
            this->colaEspecial2 = NULL;

            this->cantidadColas--;
            cout << "Cola eliminada!" << endl;
        }
        else
            cout << "La cola no esta vacia." << endl;
    }
}

void Banco::listarOperaciones(const int rangoMin, const int rangoMax)
{
    if (!this->atendidos->esVacia())
    {
        Cliente aux;
        unsigned int edadAcum = 0;
        unsigned int clientesAtendidos = 0;
        unsigned int index = 1;
        while (index <= this->atendidos->longitud())
        {
            aux = this->atendidos->obtenerElemento(index);
            if (aux.monto >= rangoMin && aux.monto <= rangoMax)
            {
                mostrarCliente(aux);
                edadAcum += aux.edad;
                clientesAtendidos++;
            }
            index++;
        }

        cout << "Edad promedio: " << (edadAcum / clientesAtendidos) << " años." << endl;
    }
}

void Banco::atenderCliente()
{
    short colaElegida = 1;
    if (this->colasEspecialesAbiertas() > 0)
    {
        cout << "Eliga la cola para atender:" << endl;
        cout << "1. Cola General" << endl;
        if (this->colasEspecialesAbiertas() >= 1)
            cout << "2. Cola Especial 1" << endl;
        if (this-> colasEspecialesAbiertas() == 2)
            cout << "3. Cola Especial 3" << endl;
        cout << ">> "; cin >> colaElegida;
        while (colaElegida > this->cantidadColas || colaElegida < 1)
        {
            cout << "Numero de cola invalida, seleccione otro:" << endl;
            cout << ">> "; cin >> colaElegida;
        }
    }

    Cliente aux;

    if (colaElegida == 1)
    {
        if (!this->colaEntrada->esVacia())
        {
            aux = this->colaEntrada->obtenerElemento(1);
            this->mostrarCliente(aux);

            this->atendidos->agregarFinal(aux);
            this->colaEntrada->eliminar(1);
        }
        else
        cout << "La cola esta vacia." << endl;
    }

    if (colaElegida == 2)
    {
        if (!this->colaEspecial1->cola->esVacia())
        {
            aux = this->colaEspecial1->cola->obtenerElemento(1);
            this->mostrarCliente(aux);

            this->atendidos->agregarFinal(aux);
            this->colaEspecial1->cola->eliminar(1);
        }
        else
            cout << "La cola esta vacia." << endl;
    }

    if (colaElegida == 3)
    {
        if (!this->colaEspecial2->cola->esVacia())
        {
            aux = this->colaEspecial2->cola->obtenerElemento(1);
            this->mostrarCliente(aux);

            this->atendidos->agregarFinal(aux);
            this->colaEspecial2->cola->eliminar(1);
        }
        else
            cout << "La cola esta vacia." << endl;
    }
}

short Banco::colasEspecialesAbiertas()
{
    return this->cantidadColas - 1;
}

// Mueve clientes de la cola de entrada a una especial
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

// Al borrar la clase, elimina cada lista que contiene (la clase Lista se encarga de limpiar cada uno individualmente)
Banco::~Banco()
{
    if (this->colaEspecial1 != NULL)
        delete this->colaEspecial1;

    if (this->colaEspecial2 != NULL)
        delete this->colaEspecial2;

    delete this->colaEntrada;
    delete this->atendidos;
}

void Banco::mostrarCliente(Cliente c)
{
    cout << "////// Cliente: " << c.nombre << " //////" << endl;
    cout << "Edad: " << c.edad << endl;
    switch (c.operacion)
    {
        case Retiro:
            cout << "Operacion: Retiro" << endl;
            break;
        case Deposito:
            cout << "Operacion: Deposito" << endl;
            break;
        case Transferencia:
            cout << "Operacion: Transferencia" << endl;
            break;
        case Pago:
            cout << "Operacion: Pago" << endl;
            break;
    }
    switch (c.destinatario)
    {
        case Persona:
            cout << "Destinatario: Persona" << endl;
            break;
        case Bancario:
            cout << "Destinatario: Banco" << endl;
            break;
        case Impuesto:
            cout << "Destinatario: Impuesto" << endl;
            break;
    }
    cout << "Monto: $ " << c.monto << endl;
    cout << (c.tieneCuenta ? "Tiene cuenta en el banco" : "No tiene cuenta en el banco") << endl;
    cout << "//////////////////" << endl;
}
