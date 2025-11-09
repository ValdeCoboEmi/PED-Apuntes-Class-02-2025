#include <iostream>
#include <string>
#include <set>

// Estructura que guarda la información de cada lenguaje
struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

// Comparador personalizado para ordenar los elementos del set
struct CompararPorPuntaje
{
    bool operator()(const Tiobe &a, const Tiobe &b) const
    {
        return a.puntaje < b.puntaje;
    }
};

// Función para solicitar los datos de un lenguaje
Tiobe SolicitarDatos()
{
    Tiobe datos;
    std::cout << "\nIngrese el lenguaje de programacion: ";
    std::cin >> datos.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos.puntaje;
    return datos;
}

// Mostrar todos los lenguajes (equivale al recorrido INORDEN)
void MostrarInorden(const std::set<Tiobe, CompararPorPuntaje> &indice)
{
    for (const auto &elem : indice)
    {
        std::cout << "[" << elem.puntaje << " : " << elem.lenguaje_programacion << "] ";
    }
    std::cout << "\n";
}

// Buscar un lenguaje por puntaje
void BuscarLenguaje(const std::set<Tiobe, CompararPorPuntaje> &indice, float puntaje)
{
    for (const auto &elem : indice)
    {
        if (elem.puntaje == puntaje)
        {
            std::cout << "\nLenguaje encontrado: " << elem.lenguaje_programacion
                      << " con puntaje " << elem.puntaje << "\n";
            return;
        }
    }
    std::cout << "\nNo se encontro ningun lenguaje con ese puntaje.\n";
}

// Eliminar un lenguaje por puntaje
void EliminarLenguaje(std::set<Tiobe, CompararPorPuntaje> &indice, float puntaje)
{
    for (auto it = indice.begin(); it != indice.end(); ++it)
    {
        if (it->puntaje == puntaje)
        {
            indice.erase(it);
            std::cout << "\nLenguaje eliminado correctamente.\n";
            return;
        }
    }
    std::cout << "\nNo se encontro ningun lenguaje con ese puntaje.\n";
}

// ------------------------ MENÚ PRINCIPAL ------------------------
int main()
{
    std::set<Tiobe, CompararPorPuntaje> indice; // Árbol ordenado (set)
    int opcion;

    do
    {
        std::cout << "\n=============================================\n";
        std::cout << "        MENU PRINCIPAL - INDICE TIOBE\n";
        std::cout << "=============================================\n";
        std::cout << "1. Insertar nuevo lenguaje\n";
        std::cout << "2. Mostrar todos (Inorden)\n";
        std::cout << "3. Buscar lenguaje por puntaje\n";
        std::cout << "4. Eliminar lenguaje por puntaje\n";
        std::cout << "0. Salir\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            Tiobe nuevo = SolicitarDatos();
            indice.insert(nuevo);
            std::cout << "\nLenguaje agregado correctamente.\n";
            break;
        }
        case 2:
        {
            std::cout << "\nRecorrido (Inorden):\n";
            MostrarInorden(indice);
            break;
        }
        case 3:
        {
            float puntaje;
            std::cout << "\nIngrese el puntaje a buscar: ";
            std::cin >> puntaje;
            BuscarLenguaje(indice, puntaje);
            break;
        }
        case 4:
        {
            float puntaje;
            std::cout << "\nIngrese el puntaje a eliminar: ";
            std::cin >> puntaje;
            EliminarLenguaje(indice, puntaje);
            break;
        }
        case 0:
            std::cout << "\n Saliendo del programa...\n";
            break;
        default:
            std::cout << "\nOpcion no valida.\n";
        }

    } while (opcion != 0);

    return 0;
}
