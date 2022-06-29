#include <iostream>
#include "./include/Banco.h"

using namespace std;

Banco *banco;
short respuestaTerminal = 0;

void ingresarCliente()
{
    string nombreCliente;
    short edadCliente;
    short numOperacion;
    short numDestinatario;
    int monto;
    short tieneCuenta;

    cout << "Ingrese el nombre del cliente:" << endl;
    cin.ignore();
    getline(cin, nombreCliente);

    cout << "Ingrese la edad del cliente:" << endl;
    cin >> edadCliente;

    cout << "Que operacion va a realizar?" << endl;
    cout << "1. Retiro" << endl << "2. Deposito" << endl << "3. Transferencia" << endl << "4. Pago" << endl;
    cout << ">> "; cin >> numOperacion;
    while (numOperacion > 4)
    {
        cout << "Operacion invalida, por favor ingrese una operacion valida:" << endl;
        cout << ">> "; cin >> numOperacion;
    }

    cout << "Tipo de destinatario:" << endl;
    cout << "1. Persona" << endl << "2. Banco" << endl << "3. Impuesto" << endl;
    cout << ">> "; cin >> numDestinatario;
    while (numDestinatario > 3)
    {
        cout << "Destinatario invalido, por favor ingrese un destinatario valido:" << endl;
        cout << ">> "; cin >> numDestinatario;
    }

    cout << "Ingrese el monto de la operacion:" << endl;
    cout << "$ "; cin >> monto;

    cout << "El cliente tiene cuenta en el banco?" << endl;
    cout << "1. Si" << endl << "2. No" << endl;
    cout << ">> "; cin >> tieneCuenta;

    banco->agregarCliente(nombreCliente, edadCliente, numOperacion, numDestinatario, monto, tieneCuenta == 1 ? true : false);
    cout << "Cliente agregado!" << endl;
}

void cerrarCola()
{
    if (banco->colasEspecialesAbiertas() > 0)
    {
        short colaACerrar;
        cout << "Que cola desea cerrar? (" << banco->colasEspecialesAbiertas() << " abiertas actualmente):" << endl;
        cout << ">> "; cin >> colaACerrar;
        if (colaACerrar > 0 && colaACerrar <= banco->colasEspecialesAbiertas())
            banco->cerrarCola(colaACerrar);
        else
            cout << "Numero de cola invalido." << endl;
    }
}

void listarOperaciones()
{
    unsigned int montoMinimo;
    unsigned int montoMaximo;

    cout << "Ingrese el monto minimo para el listado:" << endl;
    cout << ">> "; cin >> montoMinimo;

    cout << "Ingrese el monto maximo para el listado:" << endl;
    cout << ">> "; cin >> montoMaximo;

    banco->listarOperaciones(montoMinimo, montoMaximo);
}

int main()
{
    banco = new Banco();
    while (respuestaTerminal != 6)
    {
        cout << endl;
        cout << "//////// BANCO CREDICASH ////////" << endl;
        cout << "1. Ingresar nuevo cliente" << endl;
        cout << "2. Atender próximo cliente" << endl;
        cout << "3. Abrir nueva cola especial" << endl;
        cout << "4. Cerrar cola especial" << endl;
        cout << "5. Listar operaciones segun rango de montos" << endl;
        cout << "6. Salir" << endl;
        cout << ">> "; cin >> respuestaTerminal;
        cout << endl;

        switch (respuestaTerminal)
        {
            case 1:
                ingresarCliente();
                break;
            case 2:
                banco->atenderCliente();
                break;
            case 3:
                banco->abrirColaEspecial();
                break;
            case 4:
                cerrarCola();
                break;
            case 5:
                listarOperaciones();
                break;
            default:
                break;
        }
    }
    delete banco;

    return 0;
}
