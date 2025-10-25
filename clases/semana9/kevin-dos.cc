#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Luchadores
{
    std::string nombre;
    float peso;
};

struct Luchadores SolicitarDatos();
void imprimir(std::vector<struct Luchadores> info_luchadores);
void OrdenarBurbuja(std::vector<struct Luchadores> &info_luchadores);
void BuscarDatos(std::vector<struct Luchadores> info_luchadores);
bool CompararPorPeso(const Luchadores &a, const Luchadores &b);
void BuscarPorNombre(std::vector<struct Luchadores> info_luchadores, std::string nombre);

int main()
{

    std::vector<struct Luchadores> info_luchadores;

    int opc;
    float peso_buscado;
    std::string nombre_buscado;
    bool busqueda;
    do
    {

        info_luchadores.push_back(SolicitarDatos());

        std::cout << "Desea anadir otro luchador a la lista?: (1. SI | 0. NO)" << std::endl;
        std::cin >> opc;

        std::cin.ignore();

    } while (opc != 0);

    std::sort(info_luchadores.begin(), info_luchadores.end(), CompararPorPeso);

    imprimir(info_luchadores);

    std::cout << "Ingrese el peso a buscar: " << std::endl;
    std::cin >> peso_buscado;

    // Implementacion del bynary_search
    // Puede meterse dentro de una funcion booleana de busqueda
    busqueda = std::binary_search(info_luchadores.begin(), info_luchadores.end(), Luchadores{"", peso_buscado}, CompararPorPeso);

    std::cout << "----- Resultados encontrados ----- " << std::endl;

    // Imprimir resultado con un ternario
    std::cout << ((busqueda) ? "Tienes luchadores con ese peso" : "No tienes luchadores con ese peso") << std::endl;

    std::cout << "Ingrese el nombre a buscar: " << std::endl;
    std::cin >> nombre_buscado;

    BuscarPorNombre(info_luchadores, nombre_buscado);

    // int opc_menu;

    // do
    // {
    //     std::cout << "----- MENU DE OPCIONES -----" << std::endl
    //               << "Ingrese la opcion de la accion que desea realizar " << std::endl
    //               << "1. Ingresar datos " << std::endl
    //               << "2. Buscar datos " << std::endl
    //               << "3. Imprimir datos " << std::endl
    //               << "0. Salir del programa " << std::endl;
    //     std::cin >> opc_menu;
    //     std::cin.ignore();

    //     switch (opc_menu)
    //     {
    //     case 1:

    //         int opc;
    //         do
    //         {

    //             info_luchadores.push_back(SolicitarDatos());

    //             std::cout << "Desea anadir otro luchador a la lista?: (1. SI | 0. NO)" << std::endl;
    //             std::cin >> opc;

    //         } while (opc != 0);
    //         break;

    //     case 2:
    //         BuscarDatos(info_luchadores);
    //         break;

    //     case 3:
    //         OrdenarBurbuja(info_luchadores);

    //         imprimir(info_luchadores);
    //         break;

    //     default:
    //     std::cout << "Ingrese una opcion valida " << std::endl;
    //         break;
    //     }

    // } while (opc_menu != 0);

    return 0;
}

struct Luchadores SolicitarDatos()
{

    struct Luchadores luchador;

    std::cout << "Ingrese el nombre del luchador: " << std::endl;
    getline(std::cin, luchador.nombre);

    std::cout << "Ingrese el peso del luchador: " << std::endl;
    std::cin >> luchador.peso;

    std::cin.ignore();

    return luchador;
}

void OrdenarBurbuja(std::vector<struct Luchadores> &info_luchadores)
{
    int n = info_luchadores.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (info_luchadores[j].peso > info_luchadores[j + 1].peso)
            {
                std::swap(info_luchadores[j], info_luchadores[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void imprimir(std::vector<struct Luchadores> info_luchadores)
{

    std::cout << "\n";
    std::cout << "-----------------------------------------------------" << std::endl;
    for (auto l : info_luchadores)
    {
        std::cout << "Nombre: " << l.nombre << " | " << " Peso: " << l.peso << " lbs" << std::endl;
    }
}

void BuscarDatos(std::vector<struct Luchadores> info_luchadores)
{

    float peso;

    bool encontrado = false;

    std::cout << "Ingrese el peso que desea buscar: " << std::endl;
    std::cin >> peso;

    for (int i = 0; i < info_luchadores.size(); i++)
        if (info_luchadores[i].peso == peso)
        {
            std::cout << "Nombre: " << info_luchadores[i].nombre << " | " << " Peso: " << info_luchadores[i].peso << " lbs" << std::endl;
            encontrado = true;
        }

    if (encontrado)
    {
        std::cout << "No se encontraron coincidencias. " << std::endl;
    }
}

bool CompararPorPeso(const Luchadores &a, const Luchadores &b)
{

    return a.peso < b.peso;
}

void BuscarPorNombre(std::vector<struct Luchadores> info_luchadores, std::string nombre)
{

    // Predicado para la funcion find_if
    // Es una funcion anonima (LANDA)
    auto predicado = [nombre](const Luchadores &luchador)
    {
        return luchador.nombre == nombre;
    };

    // Buscar al luchador por nombre exacto
    auto it = std::find_if(info_luchadores.begin(), info_luchadores.end(), predicado);

    // Devuelve un iterador al elemento encontrado o info_luchadores.end si no se encuentra
    if (it != info_luchadores.end())
    {
        std::cout << "Luchador encontrado. " << std::endl;
        std::cout << "Nombre: " << it->nombre << " | " << " Peso: " << it->peso << " lbs" << std::endl;
    }
    else
    {
        std::cout << "Luchador no encontrado con ese nombre " << std::endl;
    }
}