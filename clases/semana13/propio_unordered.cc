#include <iostream>
#include <string>
#include <unordered_map>

struct Alumno
{
    std::string carnet;
    std::string nombre;
    std::string carrera;
    int edad;
};

Alumno SolicitarDatos();
void Imprimir(const std::unordered_map<std::string, Alumno> &mapa);
bool Buscar(const std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet);
void Eliminar(std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet);
bool Actualizar(std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet);

int main()
{
    std::unordered_map<std::string, Alumno> mapa;
    bool continuar = true;
    int opcion;
    std::string carnet;

    while (continuar)
    {
        std::cout << "\n===== MENU PRINCIPAL =====\n";
        std::cout << "1. Agregar alumno\n";
        std::cout << "2. Buscar alumno\n";
        std::cout << "3. Actualizar alumno\n";
        std::cout << "4. Eliminar alumno\n";
        std::cout << "5. Mostrar todos\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            Alumno a = SolicitarDatos();
            mapa.emplace(a.carnet, a);
            std::cout << "Alumno agregado correctamente.\n";
            break;
        }

        case 2:
            std::cout << "Ingrese el carnet del alumno a buscar: ";
            std::getline(std::cin, carnet);
            Buscar(mapa, carnet);
            break;

        case 3:
            std::cout << "Ingrese el carnet del alumno a actualizar: ";
            std::getline(std::cin, carnet);
            if (!Actualizar(mapa, carnet))
                std::cout << "No se encontro el alumno.\n";
            break;

        case 4:
            std::cout << "Ingrese el carnet del alumno a eliminar: ";
            std::getline(std::cin, carnet);
            Eliminar(mapa, carnet);
            break;

        case 5:
            Imprimir(mapa);
            break;

        case 0:
            continuar = false;
            break;

        default:
            std::cout << "Opcion no valida.\n";
        }
    }

    return 0;
}

Alumno SolicitarDatos()
{
    Alumno a;

    std::cout << "\nIngrese el carnet del alumno: ";
    std::getline(std::cin, a.carnet);

    std::cout << "Ingrese el nombre del alumno: ";
    std::getline(std::cin, a.nombre);

    std::cout << "Ingrese la carrera: ";
    std::getline(std::cin, a.carrera);

    std::cout << "Ingrese la edad: ";
    std::cin >> a.edad;
    std::cin.ignore();

    return a;
}

void Imprimir(const std::unordered_map<std::string, Alumno> &mapa)
{
    std::cout << "\n===== LISTADO DE ALUMNOS =====\n";

    for (const auto &i : mapa)
    {
        std::cout << "Carnet: " << i.second.carnet << "\n";
        std::cout << "Nombre: " << i.second.nombre << "\n";
        std::cout << "Carrera: " << i.second.carrera << "\n";
        std::cout << "Edad: " << i.second.edad << "\n";
        std::cout << "-----------------------------\n";
    }
}

bool Buscar(const std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet)
{
    auto it = mapa.find(carnet);

    if (it != mapa.end())
    {
        std::cout << "\nAlumno encontrado:\n";
        std::cout << "Nombre: " << it->second.nombre << "\n";
        std::cout << "Carrera: " << it->second.carrera << "\n";
        std::cout << "Edad: " << it->second.edad << "\n";
        return true;
    }

    std::cout << "\nAlumno no encontrado.\n";
    return false;
}

bool Actualizar(std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet)
{
    auto it = mapa.find(carnet);

    if (it != mapa.end())
    {
        std::cout << "\n--- Nuevos datos del alumno ---\n";

        std::cout << "Nuevo nombre: ";
        std::getline(std::cin, it->second.nombre);

        std::cout << "Nueva carrera: ";
        std::getline(std::cin, it->second.carrera);

        std::cout << "Nueva edad: ";
        std::cin >> it->second.edad;
        std::cin.ignore();

        std::cout << "Alumno actualizado correctamente.\n";
        return true;
    }

    return false;
}

void Eliminar(std::unordered_map<std::string, Alumno> &mapa, const std::string &carnet)
{
    if (mapa.erase(carnet))
        std::cout << "Alumno eliminado correctamente.\n";
    else
        std::cout << "No se pudo eliminar (no existe).\n";
}
