#include <iostream>

// =====================================================
// 11. Struct + array dinámico
// - Struct Producto: codigo, nombre, precio.
// - Leer arreglo dinámico de productos.
// - Mostrar todos los productos.
// - Encontrar el más caro.
// =====================================================

struct Producto
{
    int codigo;
    char nombre[50];
    float precio;
};

void LeerProductos(Producto arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Codigo: ";
        std::cin >> arr[i].codigo;
        std::cout << "Nombre: ";
        std::cin >> arr[i].nombre;
        std::cout << "Precio: ";
        std::cin >> arr[i].precio;
    }
}

void MostrarProductos(Producto arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i].codigo << " - " << arr[i].nombre << " - " << arr[i].precio << "\n";
    }
}

int ProductoMasCaro(Producto arr[], int n)
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].precio > arr[idx].precio)
            idx = i;
    }
    return idx;
}

int main()
{
    int n;
    std::cout << "Cantidad de productos: ";
    std::cin >> n;

    Producto *productos = new Producto[n];

    LeerProductos(productos, n);
    std::cout << "\nLista de productos:\n";
    MostrarProductos(productos, n);

    int idx = ProductoMasCaro(productos, n);
    std::cout << "Producto mas caro: " << productos[idx].nombre << " con $" << productos[idx].precio << "\n";

    delete[] productos;
    return 0;
}
