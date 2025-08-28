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