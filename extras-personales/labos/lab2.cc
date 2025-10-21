#include <iostream>
#include <string>
#include <vector>

// Estructuras
struct Libro
{
    std::string titulo;
    std::string autor;
    int anio;
    int unidades_vendidas;
    float precio_unitario;
    float recaudacion_total;
};

// Declaraciones de las funciones
Libro SolicitarDatos();
float CalcularRecaudacion(float precio_unitario, int unidades_vendidas);
void MostrarLibros(const std::vector<struct Libro> &libros);

int main()
{
    std::vector<struct Libro> info_libros;
    bool continuar = true;
    int opcion;

    do
    {
        info_libros.push_back(SolicitarDatos());
        std::cout << "Desea ingresar un nuevo libro? 1.Si 2.No \nOpcion: ";
        std::cin >> opcion;
        std::cin.ignore();
        if (opcion == 2)
            continuar = false;

    } while (continuar);

    MostrarLibros(info_libros);

    return 0;
}

// Calcular la recaudacion total
float CalcularRecaudacion(float precio_unitario, int unidades_vendidas)
{
    return precio_unitario * unidades_vendidas;
}

// solicitando datos del libro
Libro SolicitarDatos()
{
    Libro libro;

    std::cout << "Ingrese el titulo del libro: ";
    std::getline(std::cin, libro.titulo);

    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, libro.autor);

    std::cout << "Ingrese el anio de publicacion: ";
    std::cin >> libro.anio;

    std::cout << "Ingrese las unidades vendidas: ";
    std::cin >> libro.unidades_vendidas;

    std::cout << "Ingrese el precio unitario: ";
    std::cin >> libro.precio_unitario;

    std::cin.ignore();

    // Calcular la recaudación total
    libro.recaudacion_total = CalcularRecaudacion(libro.precio_unitario, libro.unidades_vendidas);
    return libro;
}

// Mostrar la informacion de los libros
void MostrarLibros(const std::vector<struct Libro> &libros)
{
    std::cout << "\n======= INFORMACION REGISTRADA =======\n";
    std::cout << "Total de libros registrados: " << libros.size() << "\n";
    std::cout << "A continuacion se muestra la informacion de cada libro:\n";
    std::cout << "---------------------------------------\n";

    for (auto libro : libros)
    {
        std::cout << "\nTitulo del libro: " << libro.titulo << "\n";
        std::cout << "Autor: " << libro.autor << "\n";
        std::cout << "Anio del libro: " << libro.anio << "\n";
        std::cout << "Unidades vendidas: " << libro.unidades_vendidas << "\n";
        std::cout << "Precio unitario: " << libro.precio_unitario << "\n";
        std::cout << "Recaudacion total: " << libro.recaudacion_total << "\n";
        std::cout << "---------------------------------------\n";
    }
}