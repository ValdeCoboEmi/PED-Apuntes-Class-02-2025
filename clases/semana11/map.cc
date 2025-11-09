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
    std::cout << "\nIngrese el lenguaje de programacion: ";
    std::cin >> datos.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos.puntaje;
    return datos;
}

// Mostrar todos los lenguajes (recorrido Inorden del árbol)
void MostrarInorden(const std::map<float, std::string> &indice)
{
    // El map ya está ordenado automáticamente por las claves (puntajes)
    for (const auto &par : indice)
    {
        std::cout << "[" << par.first << " : " << par.second << "] ";
    }
    std::cout << "\n";
}

// Buscar un lenguaje por puntaje (clave)
void BuscarLenguaje(const std::map<float, std::string> &indice, float puntaje)
{
    auto it = indice.find(puntaje); // Búsqueda eficiente O(log n)
    if (it != indice.end())
    {
        std::cout << "\nLenguaje encontrado: " << it->second
                  << " con puntaje " << it->first << "\n";
    }
    else
    {
        std::cout << "\nNo se encontró ningún lenguaje con ese puntaje.\n";
    }
}

// Eliminar un lenguaje por puntaje
void EliminarLenguaje(std::map<float, std::string> &indice, float puntaje)
{
    size_t borrado = indice.erase(puntaje); // Elimina por clave directamente
    if (borrado > 0)
        std::cout << "\nLenguaje eliminado correctamente.\n";
    else
        std::cout << "\nNo se encontró ningún lenguaje con ese puntaje.\n";
}

// ------------------------ MENÚ PRINCIPAL ------------------------
int main()
{
    // map funciona como un árbol rojo-negro ordenado por la clave (puntaje)
    std::map<float, std::string> indice;
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
            indice[nuevo.puntaje] = nuevo.lenguaje_programacion;
            std::cout << "\nLenguaje agregado correctamente.\n";
            break;
        }
        case 2:
        {
            std::cout << "\nRecorrido (Inorden del arbol):\n";
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
            std::cout << "\nSaliendo del programa...\n";
            break;
        default:
            std::cout << "\nOpción no válida.\n";
        }

    } while (opcion != 0);

    return 0;
}
