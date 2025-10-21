#include <iostream>
using namespace std;
#include <stack>

struct control_inventario
{
    string nombre_producto;
    int numero_serie;
    float precio;
};

void agregarProducto(stack<control_inventario> &inventario)
{

    control_inventario nuevoProducto;
    stack<control_inventario> tempStack = inventario;

    cout << "Ingrese el numero de serie unico: ";
    cin >> nuevoProducto.numero_serie;

    while (!tempStack.empty())
    {
        if (tempStack.top().numero_serie == nuevoProducto.numero_serie)
        {
            cout << "El numero de serie ya existe. Ingrese un numero de serie unico.\n";
            return;
        }
        tempStack.pop();
    }

    cout << "Ingrese el nombre del producto: ";
    cin >> nuevoProducto.nombre_producto;

    cout << "Ingrese el precio: ";
    cin >> nuevoProducto.precio;

    inventario.push(nuevoProducto);
    cout << "Producto agregado exitosamente.\n";
}

void MostrarInventario(std::stack<control_inventario> inventario)
{
    if (inventario.empty())
    {
        cout << "No hay ningun producto en el inventario.\n";
        return;
    }
    else
    {
        while (!inventario.empty())
        {
            std::cout << "-------------------------------------------------------\n";
            std::cout << "Numero de serie: " << inventario.top().numero_serie << "\n";
            std::cout << "Nombre del producto:" << inventario.top().nombre_producto << " - precio: " << inventario.top().precio << "\n";
            std::cout << "-------------------------------------------------------\n";
            inventario.pop();
        }
    }
}

void EliminarProducto(stack<control_inventario> &pila)
{
    if (pila.empty())
    {
        cout << "La pila está vacía, no se puede eliminar ningún elemento.\n";
        return;
    }
    else
    {
        cout << "Eliminando: " << pila.top().nombre_producto << std::endl;
        pila.pop(); // elimina el elemento superior
        MostrarInventario(pila);
    }
}
int main()
{
    int opcion = 0;
    stack<control_inventario> inventario;
    do
    {
        int num = 0;

        cout << "\n-------------------\n";
        cout << "1. Ingresar datos de los productos\n";
        cout << "2. Visualizar los productos\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarProducto(inventario);

            break;

        case 2:
            MostrarInventario(inventario);
            break;
        case 3:
            // Eliminar el ultimo producto ingresado
            cout << "Eliminando el ultimo producto ingresado...\n";
            EliminarProducto(inventario);
            break;

        case 4:

            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opción invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}