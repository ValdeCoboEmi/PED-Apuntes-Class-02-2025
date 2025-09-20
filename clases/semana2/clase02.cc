#include <iostream>
#include <vector>  // Para usar vectores dinámicos
#include <utility> // Para usar std::pair
#include <ctime>   // Para obtener el año

/* Ejercicio Practico clases
1. Programa que permita gestionar información relacionada con álbumes musicales.
Tomar en cuenta que cada cantante puede tener varios álbumes.
    Para cada álbum se almacena:
        - nombre
        - año de lanzamiento
        - canciones (vector de pares: título + número de canción)
        - antigüedad (años desde su lanzamiento)
    Para cada cantante se almacena:
        - nombre
        - nacionalidad
        - vector de álbumes

Funcion que se tiene realizar por el momento:
    SolicitarDatos: registrar la informacion del almun y del cantante
    Imprimir: funcion para imprimir
    CalcularAnios: funcion para caucluar la antiguedad
*/

// ==================== ESTRUCTURAS ====================

struct Album
{
    std::string nombre_album;
    int anio_lanzamiento;
    std::vector<std::pair<std::string, int>> canciones;
    int antiguedad;
};

struct Cantante
{
    std::string nombre;
    std::string nacionalidad;
    std::vector<struct Album> albums; // Un cantante tiene varios álbumes
};

// ==================== DECLARACIÓN DE FUNCIONES ====================

Cantante SolicitarDatosGenerales();
void ImprimirDatos(std::vector<struct Cantante> info_cantantes);
int CalcularAnios(int anio_lanzamiento);
void BuscarCantante(std::vector<struct Cantante> info_cantantes, std::string nombre_buscar);

// ==================== FUNCIÓN PRINCIPAL ====================

int main()
{
    std::vector<struct Cantante> info_cantantes;
    std::string nombre_buscar;
    bool continuar = true;
    int opcion;

    do
    {
        // Pedimos los datos del cantante y sus álbumes
        info_cantantes.push_back(SolicitarDatosGenerales());

        std::cout << "Desea agregar otro cantante? (1 = Si, 0 = No): ";
        std::cin >> opcion;

        if (opcion == 0)
        {
            continuar = false;
        }
        std::cin.ignore();
    } while (continuar);

    // Mostramos todo lo registrado
    ImprimirDatos(info_cantantes);

    bool continuar = true;

    do
    {

        // Pedir para la busqueda
        std::cout << "Ingrese el nombre del cantante a buscar: ";
        std::getline(std::cin, nombre_buscar);
        std::cin.ignore();
        
        BuscarCantante(info_cantantes, nombre_buscar);

        std::cout << "Desea hacer otra busqueda? (1 = Si, 0 = No): ";
        std::cin >> opcion;

        if (opcion == 0)
        {
            continuar = false;
        }
        std::cin.ignore();
    } while (continuar);
    return 0;
}

// ==================== FUNCIONES ====================

// Calcular la antigüedad de un álbum
int CalcularAnios(int anio_lanzamiento)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    // Se le tiene que sumar el 1900 porque comienza en ese año el ltm entonces
    int year = 1900 + ltm->tm_year;
    return year - anio_lanzamiento;
}

// Solicitar datos de un cantante y sus álbumes
Cantante SolicitarDatosGenerales()
{
    Cantante cantante;
    Album album;
    int opcion, opcion_canciones;

    std::cout << "\nIngrese el nombre del cantante: ";
    std::getline(std::cin, cantante.nombre);

    std::cout << "Ingrese la nacionalidad del cantante: ";
    std::getline(std::cin, cantante.nacionalidad);

    do
    {
        std::cout << "\nIngrese el nombre del album: ";
        std::getline(std::cin, album.nombre_album);

        std::cout << "Ingrese el anio del album: ";
        std::cin >> album.anio_lanzamiento;
        std::cin.ignore();

        // Calcular antigüedad automáticamente
        album.antiguedad = CalcularAnios(album.anio_lanzamiento);

        // Agregar canciones al álbum
        album.canciones.clear();
        do
        {
            std::string cancion;
            int num_cancion;

            std::cout << "Ingrese el nombre de la cancion: ";
            std::getline(std::cin, cancion);
            std::cout << "Ingrese el numero de la cancion: ";
            std::cin >> num_cancion;

            album.canciones.push_back({cancion, num_cancion});

            std::cout << "Desea anadir otra cancion? (1 = Si, 0 = No): ";
            std::cin >> opcion_canciones;
            std::cin.ignore();
        } while (opcion_canciones == 1);

        // Guardar el álbum en el vector del cantante
        cantante.albums.push_back(album);

        std::cout << "Desea anadir otro album a este cantante? (1 = Si, 0 = No): ";
        std::cin >> opcion;
        std::cin.ignore();
    } while (opcion == 1);

    return cantante;
}

// Imprimir datos de todos los cantantes y sus álbumes
void ImprimirDatos(std::vector<Cantante> info_cantantes)
{
    std::cout << "\n======= INFORMACION REGISTRADA =======\n";
    std::cout << "-----------------------------------\n";
    for (auto cantante : info_cantantes)
    {
        std::cout << "\nCantante: " << cantante.nombre << "\n";
        std::cout << "Nacionalidad: " << cantante.nacionalidad << "\n";

        for (auto album : cantante.albums)
        {
            std::cout << "\n   Album: " << album.nombre_album << "\n";
            std::cout << "   Anio de lanzamiento: " << album.anio_lanzamiento << "\n";
            std::cout << "   Antiguedad: " << album.antiguedad << " anios\n";
            std::cout << "   Cantidad de canciones del album: " << album.canciones.size() << "\n";
            std::cout << "   Canciones: \n";
            for (auto c : album.canciones)
            {
                std::cout << "      #" << c.second << " - " << c.first << "\n";
            }
        }
        std::cout << "-----------------------------------\n";
    }
    std::cout << "=====================================\n";
}

void BuscarCantante(std::vector<struct Cantante> info_cantantes, std::string nombre_buscar)
{
    bool encontrado = false;
    for (const auto cantante : info_cantantes)
    {
        if (cantante.nombre == nombre_buscar)
        {
            std::cout << "\n======= BUSQUEDA ENCONTRADA =======\n";
            std::cout << "\nSus datos del cantante son: \n";
            std::cout << "Cantante: " << cantante.nombre << "\n";
            std::cout << "Nacionalidad: " << cantante.nacionalidad << "\n";

            for (auto album : cantante.albums)
            {
                std::cout << "\n   Album: " << album.nombre_album << "\n";
                std::cout << "   Anio de lanzamiento: " << album.anio_lanzamiento << "\n";
                std::cout << "   Antiguedad: " << album.antiguedad << " anios\n";
                std::cout << "   Cantidad de canciones del album: " << album.canciones.size() << "\n";
                std::cout << "   Canciones: \n";
                for (auto c : album.canciones)
                {
                    std::cout << "      #" << c.second << " - " << c.first << "\n";
                }
            }

            encontrado = true;
        }
    }

    if (!(encontrado))
    {
        std::cout << "\n======= BUSQUEDA NO ENCONTRADA =======\n";
    }
}