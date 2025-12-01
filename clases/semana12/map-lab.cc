#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Producto
{
    string nombre;
    string categoria;
    double precio;
    int stock;
};

void agregarProducto(map<string, Producto> &inventario)
{
    string codigo;
    cout << "Codigo del producto: ";
    cin >> codigo;

    if (inventario.find(codigo) != inventario.end())
    {
        cout << "Ya existe un producto con ese codigo.\n";
        return;
    }

    Producto p;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, p.nombre);
    cout << "Categoria: ";
    getline(cin, p.categoria);
    cout << "Precio: ";
    cin >> p.precio;
    cout << "Stock: ";
    cin >> p.stock;

    if (p.precio < 0 || p.stock < 0)
    {
        cout << "Precio o stock invalidos.\n";
        return;
    }

    inventario.insert({codigo, p});
    cout << "Producto agregado.\n";
}

void actualizarProducto(map<string, Producto> &inventario)
{
    string codigo;
    cout << "Codigo del producto a actualizar: ";
    cin >> codigo;

    // Buscar sin crear
    auto it = inventario.find(codigo);

    // Si no existe, mostrar mensaje y salir
    if (it == inventario.end()) {
        cout << "No se puede actualizar: el producto con codigo '" 
             << codigo << "' no existe.\n";
        return;
    }

    // Si existe, actualizar sus datos
    Producto &p = it->second;

    cin.ignore();
    cout << "Nombre: ";
    getline(cin, p.nombre);

    cout << "Categoria: ";
    getline(cin, p.categoria);

    cout << "Precio: ";
    cin >> p.precio;

    cout << "Stock: ";
    cin >> p.stock;

    cout << "Producto actualizado correctamente.\n";
}


void buscarProducto(const map<string, Producto> &inventario)
{
    string codigo;
    cout << "Codigo a buscar: ";
    cin >> codigo;

    auto it = inventario.find(codigo);
    if (it != inventario.end())
    {
        const Producto &p = it->second;
        cout << "Producto encontrado:\n";
        cout << "Codigo: " << it->first << "\n";
        cout << "Nombre: " << p.nombre << "\n";
        cout << "Categoria: " << p.categoria << "\n";
        cout << "Precio: " << p.precio << "\n";
        cout << "Stock: " << p.stock << "\n";
    }
    else
    {
        cout << "No se encontro el producto.\n";
    }
}

void eliminarProducto(map<string, Producto> &inventario)
{
    string codigo;
    cout << "Codigo a eliminar: ";
    cin >> codigo;

    auto it = inventario.find(codigo);
    if (it != inventario.end())
    {
        inventario.erase(it);
        cout << "Producto eliminado.\n";
    }
    else
    {
        cout << "No existe un producto con ese codigo.\n";
    }
}

void mostrarInventario(const map<string, Producto> &inventario)
{
    if (inventario.empty())
    {
        cout << "Inventario vacio.\n";
        return;
    }

    cout << "Inventario:\n";
    for (const auto &par : inventario)
    {
        const string &codigo = par.first;
        const Producto &p = par.second;
        cout << codigo << " - " << p.nombre << " - " << p.categoria
             << " - $" << p.precio << " - stock: " << p.stock << "\n";
    }
}

void mostrarDesdeCodigo(const map<string, Producto> &inventario)
{
    string codigo;
    cout << "Mostrar productos desde el codigo: ";
    cin >> codigo;

    auto it = inventario.lower_bound(codigo);
    if (it == inventario.end())
    {
        cout << "No hay productos con codigo mayor o igual a ese.\n";
        return;
    }

    cout << "Productos desde " << codigo << ":\n";
    for (; it != inventario.end(); ++it)
    {
        const auto &p = it->second;
        cout << it->first << " - " << p.nombre << " - " << p.categoria
             << " - $" << p.precio << " - stock: " << p.stock << "\n";
    }
}

void mostrarCantidad(const map<string, Producto> &inventario)
{
    cout << "Total de productos: " << inventario.size() << "\n";
}

void limpiarInventario(map<string, Producto> &inventario)
{
    inventario.clear();
    cout << "Inventario limpiado.\n";
}

int main()
{
    map<string, Producto> inventario;
    int opcion;

    do
    {
        cout << "\n--- MENU INVENTARIO (MAP) ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Crear/actualizar producto\n";
        cout << "3. Buscar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Mostrar inventario\n";
        cout << "6. Mostrar desde codigo X\n";
        cout << "7. Mostrar cantidad\n";
        cout << "8. Limpiar inventario\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarProducto(inventario);
            break;
        case 2:
            actualizarProducto(inventario);
            break;
        case 3:
            buscarProducto(inventario);
            break;
        case 4:
            eliminarProducto(inventario);
            break;
        case 5:
            mostrarInventario(inventario);
            break;
        case 6:
            mostrarDesdeCodigo(inventario);
            break;
        case 7:
            mostrarCantidad(inventario);
            break;
        case 8:
            limpiarInventario(inventario);
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}