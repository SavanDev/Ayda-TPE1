#include <iostream>
using namespace std;

short respuestaTerminal;

int main()
{
    cout << "//////// BANCO CREDICASH ////////" << endl;
    cout << "1. Ingresar nuevo cliente" << endl;
    cout << "2. Atender próximo cliente" << endl;
    cout << "3. Abrir nueva cola especial" << endl;
    cout << "4. Cerrar cola especial" << endl;
    cout << "5. Listar operaciones segun rango de montos" << endl;
    cin >> respuestaTerminal;
    return 0;
}