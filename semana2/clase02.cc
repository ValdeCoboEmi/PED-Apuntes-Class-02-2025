#include <iostream>
#include <vector>  // Librería para vectores dinámicos
#include <utility> // Librería para usar std::pair

/* Sistema de gestion de albumes musicales
    1. Se bsuca desarrollar un programa que permita gestionar informacion relacionado con albumes musicales. Para cada album,
    se utilizara una estructura que almacene el nombre del album, año de lanzamiento, un vector de canciones (cada una con titulo
    y numero de cancion), y la antiguedad (edad) del album, ademas se definina una estructura anidada para los datos del cantante,
    incluyendo su nombre y nacionalidad.

    Funciones: AL FINALIZAR CADA FUNCION UN COMMIT
    SolicitarDatos: registrar la informacion del almun y del cantante
    Imprimir: funcion para imprimir

    CalcularAntiguedad: calcular la edad
    */

// definicion de estructura
struct Cantante
{
    std::string nombre;
    std::string nacionalidad;
};

struct Album
{
    std::string nombre_album;
    int anio_lanzamiento;
    std::vector<std::pair<std::string, int>> canciones;
    int antiguedad; // Edad del album fecha actual - fecha de lanzamiento
    struct Cantante cantante;
};

// Declaración de funciones que se implementarán más adelante
struct Album SolicitarDatosGenerales();
void ImprimirDatos(std::vector<struct Album> info_albumnes);

int main()
{
    std::vector<struct Album> info_albumnes;
    bool continuar = true;
    int opcion;

    // Bucle para permitir ingresar múltiples albumnes, hasta que el usuario quiera
    do
    {
        // Pedimos al usuario los datos y los almacenamos en el vector de albumnes
        info_albumnes.push_back(SolicitarDatosGenerales());

        // Preguntamos si quiere continuar agregando más personas
        std::cout << "¿Desea agregar otra persona? (1 = Si, 0 = No): ";
        std::cin >> opcion;

        // Salir del bucle si la opción es 0
        if (opcion == 0)
        {
            continuar = false;
        }
    } while (continuar);

    return 0;
}

struct Album SolicitarDatosGenerales()
{
    // creacion de la estructura de album
    struct Album album;
    int opcion;
    std::string cancion;
    int num_cancion;

    // Solicitar los datos del nombre y del añio, del album
    std::cout << "Ingrese el nombre del album: ";
    std::cin >> album.nombre_album;

    std::cout << "Ingrese el anio del album: ";
    std::cin >> album.anio_lanzamiento;

    // Proceso de guardar las canciones
    do
    {
        // Solicitar
        std::cout << "Ingrese el nombre de la cancion: ";
        std::cin >> cancion;
        std::cout << "Ingrese el numero de la cancion: ";
        std::cin >> num_cancion;

        album.canciones.push_back({cancion, num_cancion});

        std::cout << "Desea añadir otra cancion, si (0), no (1): ";
        std::cin >> opcion;

    } while (opcion != 1);

    // Solicitar los datos del cantante y almacenarlo
    std::cout << "Ingrese el nombre del cantante: ";
    std::cin >> album.cantante.nombre;

    std::cout << "Ingrese la nacionalidad del cantante: ";
    std::cin >> album.cantante.nacionalidad;

    return album;
}

void ImprimirDatos(std::vector<struct Album> info_albumnes)
{
    // Recorremos todos los elementos del vector de structs, es un for anidado
    // El primer for esta con la estructura de for each, donde toma cada elemento del vector uno por uno3
    std::cout << "\n";
    for (auto album : info_albumnes)
    {
        std::cout << "--------------" << std::endl;

        // Imprimimos datos generales de la persona
        std::cout << "Nombre del cantante: " << album.cantante.nombre << "\n";
        std::cout << "Nacionalidad del cantante: " << album.cantante.nacionalidad << "\n";
        std::cout << "Album: " << album.nombre_album << "\n";
        std::cout << "Anio de lanzamiento: " << album.anio_lanzamiento << "\n";
        std::cout << "Antiguedad: " << album.antiguedad << "\n";
        std::cout << "Canciones del albu,: \n";
        std::cout << "--------------" << std::endl;

        // Recorremos los cupones generados de tipo vector<pair>,  y mostramos cupón + el premio
        for (auto c : album.canciones)
        {
            std::cout << "Numero de la cancion: " << c.second << "° -- Nombre de la cancion: " << c.first;
        }
        std::cout << "--------------" << std::endl;
    }
    // Mensaje final
    std::cout << "Tenga un feliz dia.\n"
              << std::endl;
}