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

//definicion de estructura
struct Cantante{
    std::string nombre;
    std::string nacionalidad;
};

struct Album{
    std::string nombre_album;
    int anio_lanzamiento;
    std::vector<std::pair<std::string, int>> canciones;
    int antiguedad; //Edad del album fecha actual - fecha de lanzamiento
    struct Cantante cantante;
};

int main()
{

    return 0;
}