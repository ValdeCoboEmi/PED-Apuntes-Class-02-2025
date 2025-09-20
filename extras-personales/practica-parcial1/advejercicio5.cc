#include <iostream>
#include <cstring>

using namespace std;

// ==========================================================
// 5. Banco (simulación simple)
// - Struct Cuenta: numeroCuenta, nombreTitular, saldo
// - Arreglo dinámico de cuentas
// - Funciones: depositar, retirar, transferir, mostrar saldo total
// ==========================================================

struct Cuenta
{
    int numeroCuenta;
    char nombreTitular[50];
    float saldo;
};

void MostrarCuentas(Cuenta *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i].numeroCuenta << " - " << arr[i].nombreTitular << " - $" << arr[i].saldo << endl;
}

int BuscarCuenta(Cuenta *arr, int n, int num)
{
    for (int i = 0; i < n; i++)
        if (arr[i].numeroCuenta == num)
            return i;
    return -1;
}

int main()
{
    int n;
    cout << "Cantidad de cuentas: ";
    cin >> n;

    Cuenta *cuentas = new Cuenta[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Numero de cuenta: ";
        cin >> cuentas[i].numeroCuenta;
        cout << "Nombre titular: ";
        cin >> cuentas[i].nombreTitular;
        cuentas[i].saldo = 0;
    }

    char opcion;
    do
    {
        cout << "\nOpciones: D=Depositar, R=Retirar, T=Transferir, M=Mostrar, S=Salir: ";
        cin >> opcion;

        if (opcion == 'D' || opcion == 'd')
        {
            int num;
            float monto;
            cout << "Cuenta: ";
            cin >> num;
            int idx = BuscarCuenta(cuentas, n, num);
            if (idx != -1)
            {
                cout << "Monto a depositar: ";
                cin >> monto;
                cuentas[idx].saldo += monto;
            }
        }
        else if (opcion == 'R' || opcion == 'r')
        {
            int num;
            float monto;
            cout << "Cuenta: ";
            cin >> num;
            int idx = BuscarCuenta(cuentas, n, num);
            if (idx != -1)
            {
                cout << "Monto a retirar: ";
                cin >> monto;
                if (cuentas[idx].saldo >= monto)
                    cuentas[idx].saldo -= monto;
                else
                    cout << "Fondos insuficientes.\n";
            }
        }
        else if (opcion == 'T' || opcion == 't')
        {
            int origen, dest;
            float monto;
            cout << "Cuenta origen: ";
            cin >> origen;
            cout << "Cuenta destino: ";
            cin >> dest;
            int idxO = BuscarCuenta(cuentas, n, origen);
            int idxD = BuscarCuenta(cuentas, n, dest);
            if (idxO != -1 && idxD != -1)
            {
                cout << "Monto a transferir: ";
                cin >> monto;
                if (cuentas[idxO].saldo >= monto)
                {
                    cuentas[idxO].saldo -= monto;
                    cuentas[idxD].saldo += monto;
                }
                else
                    cout << "Fondos insuficientes.\n";
            }
        }
        else if (opcion == 'M' || opcion == 'm')
        {
            MostrarCuentas(cuentas, n);
            float total = 0;
            for (int i = 0; i < n; i++)
                total += cuentas[i].saldo;
            cout << "Saldo total del banco: $" << total << endl;
        }

    } while (opcion != 'S' && opcion != 's');

    delete[] cuentas;
    return 0;
}
