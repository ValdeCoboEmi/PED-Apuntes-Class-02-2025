#include <iostream>
using namespace std;

struct Productos
{
    string nombre_producto;
    float precio_unitario;
    int cantidad_inventario;
    float total_money;
};

struct Node
{
    Productos producto;
    Node *next;
    Node *prev;
};

// Liberar memoria de la lista
void free(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Funcion de ccalcular valor total
float CalcularValorTotal(float precio_unitario, int cantidad_inventario)
{
    return (precio_unitario * cantidad_inventario);
}

void agregarProducto(Node *&head, const Productos &nuevoProducto)
{
    Node *newNode = new Node();
    newNode->producto = nuevoProducto;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void MostrarListaInicioAFin(Node *cabeza)
{
    Node *actual = cabeza;
    while (actual != nullptr)
    {
        std::cout << "Producto: " << actual->producto.nombre_producto << std::endl;
        std::cout << "Cantidad: " << actual->producto.cantidad_inventario << std::endl;
        std::cout << "Precio: " << actual->producto.precio_unitario << std::endl;
        std::cout << "Total: " << actual->producto.total_money << std::endl;
        std::cout << "-----------------------" << std::endl;
        actual = actual->next;
    }
}

int main()
{
    Node *lista1 = nullptr;
    int opcion = 0;

    do
    {
        int num = 0;

        cout << "\n-------------------\n";
        cout << "1. Ingresar datos de los productos\n";
        cout << "2. Visualizar los productos\n";
        cout << "3. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            Productos nuevoProducto;
            cout << "Ingrese el nombre del producto: ";
            cin >> nuevoProducto.nombre_producto;
            cout << "Ingrese el precio unitario: ";
            cin >> nuevoProducto.precio_unitario;
            cout << "Ingrese la cantidad en inventario: ";
            cin >> nuevoProducto.cantidad_inventario;
            nuevoProducto.total_money = CalcularValorTotal(nuevoProducto.precio_unitario, nuevoProducto.cantidad_inventario);

            agregarProducto(lista1, nuevoProducto);
        }
        break;

        case 2:
            std::cout << "------PRODUCTOS-------" << std::endl;
            MostrarListaInicioAFin(lista1);
            break;

        case 3:

            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opción invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);

    // Liberar memoria al salir por si el usuario olvidó hacerlo
    free(lista1);
    return 0;
}