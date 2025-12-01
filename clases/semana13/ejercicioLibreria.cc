#include <iostream>
#include <map>
#include <string>
using namespace std;

// ===========================================================
//              ESTRUCTURAS
// ===========================================================
struct Libro
{
    string titulo;
    string autor;
    int anio = 0;
};

struct Libreria
{
    string nombre;
    map<string, Libro> libros; // (ID del libro → Libro)
};

// ===========================================================
//              FUNCIONES
// ===========================================================

// Agregar un libro a una librería
void agregarLibro(map<string, Libreria> &librerias)
{
    string idLib;
    cout << "Ingrese ID de la libreria: ";
    cin >> idLib;

    if (librerias.find(idLib) == librerias.end())
    {
        cout << "La libreria no existe.\n";
        return;
    }

    string idLibro;
    cout << "ID del libro nuevo: ";
    cin >> idLibro;

    // Validar si ya existe
    if (librerias[idLib].libros.find(idLibro) != librerias[idLib].libros.end())
    {
        cout << "Ya existe un libro con ese ID.\n";
        return;
    }

    Libro nuevo;
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, nuevo.titulo);

    cout << "Autor: ";
    getline(cin, nuevo.autor);

    cout << "Año: ";
    cin >> nuevo.anio;

    librerias[idLib].libros[idLibro] = nuevo;
    cout << "Libro agregado correctamente.\n";
}

// Actualizar un libro (solo actualizar, no crear)
void actualizarLibro(map<string, Libreria> &librerias)
{
    string idLib;
    cout << "ID de la libreria: ";
    cin >> idLib;

    if (librerias.find(idLib) == librerias.end())
    {
        cout << "Libreria no encontrada.\n";
        return;
    }

    string idLibro;
    cout << "ID del libro a actualizar: ";
    cin >> idLibro;

    auto &libros = librerias[idLib].libros;

    if (libros.find(idLibro) == libros.end())
    {
        cout << "No existe ese libro, no se puede actualizar.\n";
        return;
    }

    Libro &lib = libros[idLibro];

    cout << "Nuevo titulo: ";
    cin.ignore();
    getline(cin, lib.titulo);

    cout << "Nuevo autor: ";
    getline(cin, lib.autor);

    cout << "Nuevo año: ";
    cin >> lib.anio;

    cout << "Libro actualizado correctamente.\n";
}

// Mostrar las librerías y sus libros
void mostrar(const map<string, Libreria> &librerias)
{
    for (const auto &par : librerias)
    {
        cout << "\n📚 Libreria: " << par.first << " (" << par.second.nombre << ")\n";

        if (par.second.libros.empty())
        {
            cout << "   - No hay libros.\n";
            continue;
        }

        for (const auto &l : par.second.libros)
        {
            cout << "   ID: " << l.first
                 << " | Titulo: " << l.second.titulo
                 << " | Autor: " << l.second.autor
                 << " | Año: " << l.second.anio << "\n";
        }
    }
}

// Mover un libro de una librería a otra
void moverLibro(map<string, Libreria> &librerias)
{
    string origen, destino, idLibro;

    cout << "ID de libreria origen: ";
    cin >> origen;

    cout << "ID de libreria destino: ";
    cin >> destino;

    cout << "ID del libro a mover: ";
    cin >> idLibro;

    // Validar origen
    if (librerias.find(origen) == librerias.end())
    {
        cout << "Libreria origen no existe.\n";
        return;
    }

    // Validar destino
    if (librerias.find(destino) == librerias.end())
    {
        cout << "Libreria destino no existe.\n";
        return;
    }

    auto &librosOrigen = librerias[origen].libros;
    auto &librosDestino = librerias[destino].libros;

    // Validar libro en origen
    if (librosOrigen.find(idLibro) == librosOrigen.end())
    {
        cout << "El libro no existe en la libreria origen.\n";
        return;
    }

    // Ver si ya existe en destino
    if (librosDestino.find(idLibro) != librosDestino.end())
    {
        cout << "Ya existe un libro con ese ID en la libreria destino.\n";
        return;
    }

    // MOVER LIBRO
    librosDestino[idLibro] = librosOrigen[idLibro]; // Copiar
    librosOrigen.erase(idLibro);                    // Eliminar del origen

    cout << "Libro movido correctamente.\n";
}

// ===========================================================
//                      MAIN
// ===========================================================
int main()
{
    map<string, Libreria> librerias;

    // Crear librerías de ejemplo
    librerias["lb1"] = {"Central", {}};
    librerias["lb2"] = {"Norte", {}};

    int op;

    do
    {
        cout << "\n===== MENU LIBRERIAS =====\n";
        cout << "1. Agregar libro\n";
        cout << "2. Actualizar libro\n";
        cout << "3. Mostrar\n";
        cout << "4. Mover libro\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            agregarLibro(librerias);
            break;
        case 2:
            actualizarLibro(librerias);
            break;
        case 3:
            mostrar(librerias);
            break;
        case 4:
            moverLibro(librerias);
            break;
        case 5:
            cout << "Adios!\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (op != 5);

    return 0;
}
