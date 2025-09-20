#include <iostream>
#include <cstring>

using namespace std;

// ==========================================================
// 1. Sistema de gestión de inventario
// - Struct Producto: id, nombre, precio, cantidad.
// - Arreglo dinámico de productos.
// - Funciones: agregar productos, buscar por id, actualizar cantidad,
//   calcular valor total del inventario.
// ==========================================================

struct Producto
{
    int id;
    char nombre[50];
    float precio;
    int cantidad;
};

// Leer datos de un producto
Producto LeerProducto()
{
    Producto p;
    cout << "ID: ";
    cin >> p.id;
    cout << "Nombre: ";
    cin >> p.nombre;
    cout << "Precio: ";
    cin >> p.precio;
    cout << "Cantidad: ";
    cin >> p.cantidad;
    return p;
}

// Buscar producto por ID, devuelve índice o -1 si no se encuentra
int BuscarPorID(Producto *arr, int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].id == id)
            return i;
    }
    return -1;
}

// Calcular valor total del inventario
float ValorTotal(Producto *arr, int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i].precio * arr[i].cantidad;
    }
    return total;
}

int main()
{
    int n;
    cout << "Cuantos productos desea ingresar? ";
    cin >> n;

    Producto *inventario = new Producto[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nProducto " << i + 1 << ":\n";
        inventario[i] = LeerProducto();
    }

    int id_buscar;
    cout << "\nIngrese ID de producto a buscar: ";
    cin >> id_buscar;
    int idx = BuscarPorID(inventario, n, id_buscar);
    if (idx != -1)
    {
        cout << "Producto encontrado: " << inventario[idx].nombre << ", Cantidad: " << inventario[idx].cantidad << endl;
        cout << "Actualizar cantidad a: ";
        cin >> inventario[idx].cantidad;
    }
    else
    {
        cout << "Producto no encontrado.\n";
    }

    cout << "Valor total del inventario: $" << ValorTotal(inventario, n) << endl;

    delete[] inventario;
    return 0;
}
