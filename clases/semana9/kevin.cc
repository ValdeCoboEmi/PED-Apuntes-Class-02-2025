#include <iostream>
#include <string>
#include <list>
#include <algorithm>

struct Luchadores
{
    std::string nombre;
    float peso;
};

struct Luchadores SolicitarDatos();
void imprimir(std::list<struct Luchadores> info_luchadores);
void OrdenarBurbuja(std::list<struct Luchadores> &info_luchadores);
void BuscarDatos(std::list<struct Luchadores> info_luchadores);
bool CompararPorPeso(const Luchadores &a, const Luchadores &b);
void BuscarPorNombre(std::list<struct Luchadores> info_luchadores, std::string nombre);
void BuscarPorPeso(std::list<struct Luchadores> info_luchadores, float peso);

int main()
{

    std::list<struct Luchadores> info_luchadores;

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

    info_luchadores.sort(CompararPorPeso);

    imprimir(info_luchadores);

    std::cout << "Ingrese el peso a buscar: " << std::endl;
    std::cin >> peso_buscado;

    BuscarPorPeso(info_luchadores, peso_buscado);

    std::cout << "Ingrese el nombre a buscar: " << std::endl;
    std::cin >> nombre_buscado;

    BuscarPorNombre(info_luchadores, nombre_buscado);

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

bool CompararPorPeso(const Luchadores &a, const Luchadores &b)
{

    return a.peso < b.peso;
}

void BuscarPorNombre(std::list<struct Luchadores> info_luchadores, std::string nombre)
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

void BuscarPorPeso(std::list<struct Luchadores> info_luchadores, float peso)
{

    // Predicado para la funcion find_if
    // Es una funcion anonima (LANDA)
    auto predicado = [peso](const Luchadores &luchador)
    {
        return luchador.peso == peso;
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

void imprimir(std::list<struct Luchadores> info_luchadores)
{

    std::cout << "\n";
    std::cout << "-----------------------------------------------------" << std::endl;
    for (auto l : info_luchadores)
    {
        std::cout << "Nombre: " << l.nombre << " | " << " Peso: " << l.peso << " lbs" << std::endl;
    }
}