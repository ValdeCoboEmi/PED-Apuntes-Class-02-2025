#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Visitante
{
    string documento;
    string nombre;
    string categoria;
};

// Comparador para ordenar por documento
struct CompVisitante
{
    bool operator()(const Visitante &a, const Visitante &b) const
    {
        return a.documento < b.documento;
    }
};

void registrarVisitante(set<Visitante, CompVisitante> &registro)
{
    Visitante v;
    cout << "Documento: ";
    cin >> v.documento;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, v.nombre);
    cout << "Categoria: ";
    getline(cin, v.categoria);

    if (v.documento.empty())
    {
        cout << "Documento vacio, no se puede registrar.\n";
        return;
    }

    auto res = registro.insert(v);
    if (!res.second)
    {
        cout << "Ya existe un visitante con ese documento.\n";
    }
    else
    {
        cout << "Visitante registrado.\n";
    }
}

void buscarVisitante(const set<Visitante, CompVisitante> &registro)
{
    string doc;
    cout << "Documento a buscar: ";
    cin >> doc;

    Visitante tmp{doc, "", ""};
    auto it = registro.find(tmp);
    if (it != registro.end())
    {
        cout << "Encontrado:\n";
        cout << "Documento: " << it->documento << "\n";
        cout << "Nombre: " << it->nombre << "\n";
        cout << "Categoria: " << it->categoria << "\n";
    }
    else
    {
        cout << "No se encontro el visitante.\n";
    }
}

void eliminarVisitante(set<Visitante, CompVisitante> &registro)
{
    string doc;
    cout << "Documento a eliminar: ";
    cin >> doc;

    Visitante tmp{doc, "", ""};
    auto it = registro.find(tmp);
    if (it != registro.end())
    {
        registro.erase(it);
        cout << "Visitante eliminado.\n";
    }
    else
    {
        cout << "No se encontro el visitante.\n";
    }
}

void mostrarVisitantes(const set<Visitante, CompVisitante> &registro)
{
    if (registro.empty())
    {
        cout << "No hay visitantes registrados.\n";
        return;
    }
    cout << "Visitantes registrados:\n";
    for (const auto &v : registro)
    {
        cout << v.documento << " - " << v.nombre << " - " << v.categoria << "\n";
    }
}

void mostrarDesdeDocumento(const set<Visitante, CompVisitante> &registro)
{
    string doc;
    cout << "Mostrar visitantes desde el documento: ";
    cin >> doc;

    Visitante tmp{doc, "", ""};
    auto it = registro.lower_bound(tmp);
    if (it == registro.end())
    {
        cout << "No hay visitantes con documento mayor o igual a ese.\n";
        return;
    }
    cout << "Visitantes desde " << doc << ":\n";
    for (; it != registro.end(); ++it)
    {
        cout << it->documento << " - " << it->nombre << " - " << it->categoria << "\n";
    }
}

void mostrarCantidad(const set<Visitante, CompVisitante> &registro)
{
    cout << "Total de visitantes: " << registro.size() << "\n";
}

void limpiarRegistro(set<Visitante, CompVisitante> &registro)
{
    registro.clear();
    cout << "Registro limpiado.\n";
}

int main()
{
    set<Visitante, CompVisitante> registro;
    int opcion;

    do
    {
        cout << "\n--- MENU VISITANTES (SET) ---\n";
        cout << "1. Registrar visitante\n";
        cout << "2. Buscar visitante\n";
        cout << "3. Eliminar visitante\n";
        cout << "4. Mostrar todos\n";
        cout << "5. Mostrar desde documento X\n";
        cout << "6. Mostrar cantidad\n";
        cout << "7. Limpiar registro\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarVisitante(registro);
            break;
        case 2:
            buscarVisitante(registro);
            break;
        case 3:
            eliminarVisitante(registro);
            break;
        case 4:
            mostrarVisitantes(registro);
            break;
        case 5:
            mostrarDesdeDocumento(registro);
            break;
        case 6:
            mostrarCantidad(registro);
            break;
        case 7:
            limpiarRegistro(registro);
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