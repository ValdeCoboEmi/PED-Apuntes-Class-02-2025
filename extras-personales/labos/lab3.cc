#include <iostream>
using namespace std;

void sumarRef(int &stock, int cantidad);
void restarPtr(int *stock, int cantidad);
void SimularOperacionValor(int stock, int cantidad, char op);

int main()
{
    int cantidad = 0, stock = 0;
    char op;
    int opcion;

    cout << "\n";
    cout << "Ingrese la cantidad del stock de su tienda: ";
    cin >> stock;
    cout << "\n";
    do
    {
        cout << "=======================MENU============================" << endl;
        cout << "Ingrese la opcion que desea realizar: " << endl;
        cout << "1- Ingreso real al inventario" << endl;
        cout << "2- salida real del inventario" << endl;
        cout << "3- Simulacion de ingresos/retiro" << endl;
        cout << "4 - Salir" << endl;
        cout << "Digite la opcion del menu: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            /* Ingreso real al inventario */
            sumarRef(stock, cantidad);

            cout << "El stock disponible es: " << stock << endl;
            break;
        case 2:
            cout << "Ingrese la cantidad de stock que desea retirar: ";
            cin >> cantidad;
            /* salida real del inventario */
            restarPtr(&stock, cantidad);
            break;
        case 3:
            /* Simulacion de ingresos/retiro */
            /* Simulacion de ingresos/retiro */
            cout << "Ingrese la opcion que desea utilizar ingreseo (i) o retiro (r): ";
            cin >> op;
            cout << "La cantidad que desea: ";
            cin >> cantidad;
            SimularOperacionValor(stock, cantidad, op);
            // If para ver la original
            if (op == 'i')
            {
                cout << "La cantidad del stock real del ingreso es: " << stock << "\n";
            }
            else if (op == 'r')
            {
                cout << "La cantidad del stock real del retiro es: " << stock << "\n";
            }
            break;
        case 4:
            /* salida temprana */
            cout << "\n";
            cout << " ADIOSSSSSSSSSSSSSSSSSSSs \n";
            return 1;
            break;

        default:
            cout << "\n";
            cout << "Ingrese una opcion valida del menu (1-4)" << endl;
            break;
        }

        cout << "\n";
    } while (opcion != 4);

    return 0;
}

void sumarRef(int &stock, int cantidad)
{
    cout << "Ingrese la cantidad de stock que desea agregar: ";
    cin >> cantidad;
    stock = stock + cantidad;
}

void restarPtr(int *stock, int cantidad)
{
    if (stock != nullptr)
    {
        *stock -= cantidad;
        cout << "Stock actualizado: " << *stock << endl;
    }
    else
    {
        cout << "Error: stock es un puntero nulo." << endl;
    }
}

// Funcion SimularOperacionesValores
void SimularOperacionValor(int stock, int cantidad, char op)
{
    if (op == 'i')
    {
        cout << "La cantidad del stock despues del ingreso simulado es: " << stock + cantidad << "\n";
    }
    else if (op == 'r')
    {
        cout << "La cantidad del stock despues del retiro simulado es: " << stock - cantidad << "\n";
    }
    else
    {
        cout << "Has seleccionado una opcion no valida";
    }
}