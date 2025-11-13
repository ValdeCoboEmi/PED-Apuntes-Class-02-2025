#include <iostream>
#include <set>

// Estructura que guarda la información de cada lenguaje
struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

// Comparador para ordenar por lenguaje de programcion
struct CompTiobe
{
    bool operator()(const Tiobe &a, const Tiobe &b) const
    {
        return a.lenguaje_programacion < b.lenguaje_programacion;
    }
};

// Prototipos
struct Tiobe SolicitarDatos();
void Imprimir(const std::set<Tiobe, CompTiobe> &abb_tiobe);
void BuscarLenguaje(const std::set<Tiobe, CompTiobe> &registro,  std::string criterio);

int main()
{
    std::set<Tiobe, CompTiobe> abb_tiobe;
    struct Tiobe informacion;
    bool continuar = true;

    do
    {
        // Pedimos los datos del lenguaje
        informacion = SolicitarDatos();
        abb_tiobe.insert(informacion);

        // Preguntamos si se desea seguir ingresando más datos
        std::cout << "\nDigite la opcion para continuar ingresando o no: " << std::endl;
        std::cout << "1. Continuar" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Digite la opcion: ";
        std::cin >> continuar;

    } while (continuar);

    Imprimir(abb_tiobe);

    std::string criterio;
    std::cout << "\nNombre del lenguaje a busacr: ";
    std::cin >> criterio;
    BuscarLenguaje(abb_tiobe, criterio);

    return 0;
}

// Función para solicitar los datos de cada lenguaje
struct Tiobe SolicitarDatos()
{
    struct Tiobe datos_indice;
    std::cout << "Ingrese el lenguaje de programacion: ";
    std::cin >> datos_indice.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos_indice.puntaje;
    return datos_indice;
}

void Imprimir(const std::set<Tiobe, CompTiobe> &abb_tiobe)
{
    if (abb_tiobe.empty())
    {
        std::cout << "\nNo hay registros.\n";
        return;
    }
    std::cout << "\n\nLos registros son: \n";
    for (const auto &i : abb_tiobe)
    {
        std::cout << "Nombre del lenguaje: " << i.lenguaje_programacion << ", puntuacion: " << i.puntaje << "\n";
    }
}


void BuscarLenguaje(const std::set<Tiobe, CompTiobe> &registro,  std::string criterio){
    //Si no esta
    //Si esta vacio mostrar un mensaje
    //Si esta 
    if (registro.empty())
    {
        std::cout << "\nNo hay lenguajes de programacion.\n";
        return;
    }

    Tiobe tmp{criterio, 0};
    auto it = registro.find(tmp);
    if (it != registro.end())
    {
        std::cout << "\nEncontrado:\n";
        std::cout << "Lenguaje: " << it->lenguaje_programacion << "\n";
        std::cout << "Puntaje: " << it->puntaje << "\n";
    }
    else
    {
        std::cout << "\nNo se encontro el visitante.\n";
    }

}
