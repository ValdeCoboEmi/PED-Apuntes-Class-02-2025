#include <iostream>
#include <string>
#include <map>

// Estructura que guarda la información de cada lenguaje
struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

// Función para solicitar los datos de un lenguaje
Tiobe SolicitarDatos()
{
    Tiobe datos;
    std::cout << "\nIngrese el lenguaje de programación: ";
    std::cin >> datos.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos.puntaje;
    return datos;
}

// Mostrar todos los lenguajes registrados (recorrido del map)
void MostrarLenguajes(const std::map<int, Tiobe> &indice)
{
    if (indice.empty())
    {
        std::cout << "\nNo hay lenguajes registrados.\n";
        return;
    }

    std::cout << "\n--- LISTA DE LENGUAJES ---\n";
    for (const auto &par : indice)
    {
        std::cout << "ID: " << par.first
                  << " | Lenguaje: " << par.second.lenguaje_programacion
                  << " | Puntaje: " << par.second.puntaje << std::endl;
    }
}

// Buscar un lenguaje por su ID
void BuscarLenguaje(const std::map<int, Tiobe> &indice)
{
    int id;
    std::cout << "\nIngrese el ID del lenguaje a buscar: ";
    std::cin >> id;

    auto it = indice.find(id);
    if (it != indice.end())
    {
        std::cout << "\nLenguaje encontrado:\n";
        std::cout << "ID: " << it->first
                  << " | Lenguaje: " << it->second.lenguaje_programacion
                  << " | Puntaje: " << it->second.puntaje << std::endl;
    }
    else
    {
        std::cout << "\nNo se encontró el lenguaje con ese ID.\n";
    }
}

// Eliminar un lenguaje por su ID
void EliminarLenguaje(std::map<int, Tiobe> &indice)
{
    int id;
    std::cout << "\nIngrese el ID del lenguaje a eliminar: ";
    std::cin >> id;

    size_t borrado = indice.erase(id);
    if (borrado)
    {
        std::cout << "\nLenguaje eliminado correctamente.\n";
    }
    else
    {
        std::cout << "\nNo se encontró ningún lenguaje con ese ID.\n";
    }
}

// ------------------------ MENÚ PRINCIPAL ------------------------
int main()
{
    std::map<int, Tiobe> abb_tiobe; // Árbol ordenado por ID
    int opcion;
    bool continuar = true;
    int id_actual = 1; // ID autoincremental

    do
    {
        std::cout << "\n========== MENÚ TIOBE ==========\n";
        std::cout << "1. Insertar lenguaje\n";
        std::cout << "2. Mostrar todos los lenguajes\n";
        std::cout << "3. Buscar lenguaje por ID\n";
        std::cout << "4. Eliminar lenguaje por ID\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            Tiobe nuevo = SolicitarDatos();
            // Insertar solo si el ID no existe (aunque nunca se repetirá si usamos autoincremento)
            abb_tiobe[id_actual] = nuevo;
            std::cout << "\nLenguaje agregado con ID " << id_actual << ".\n";
            id_actual++; // Incrementar el ID para el siguiente ingreso
            break;
        }
        case 2:
            MostrarLenguajes(abb_tiobe);
            break;
        case 3:
            BuscarLenguaje(abb_tiobe);
            break;
        case 4:
            EliminarLenguaje(abb_tiobe);
            break;
        case 0:
            continuar = false;
            std::cout << "\nSaliendo del programa...\n";
            break;
        default:
            std::cout << "\nOpción no válida.\n";
            break;
        }

    } while (continuar);

    return 0;
}
