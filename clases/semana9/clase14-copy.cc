#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Luchador
{
    std::string nombre;
    float peso;
};

Luchador SolicitarInformacion();
void ImprimirDatos(const std::vector<Luchador> luchadores);
void OrdenarPorSeleccion(std::vector<Luchador> &luchadores);
void BusquedaPeso(const std::vector<Luchador> luchadores, float peso_a_buscar);
bool CompararPorPeso(const Luchador &a, const Luchador &b);

int main()
{
    std::vector<Luchador> luchadores;
    bool continuar = true;
    int opcion;
    float peso_a_buscar = 0;
    bool busqueda;

    std::cout << "\nBIENVENIDO!\n\n";

    do
    {
        // Pedimos los datos de la comida
        luchadores.push_back(SolicitarInformacion());

        std::cout << "\nDesea agregar otro luchador? (1 = Si, 0 = No): ";
        std::cin >> opcion;
        std::cout << "\n";
        std::cin.ignore();

        if (opcion == 0)
            continuar = false;

    } while (continuar);

    std::cout << "\n\nInformacion de los Luchadores ingresados sin ordenar: \n\n";
    ImprimirDatos(luchadores);

    // OrdenarPorSeleccion(luchadores);
    std::sort(luchadores.begin(), luchadores.end(), CompararPorPeso);

    std::cout << "\n\nInformacion de los Luchadores ingresados con ordenar: \n\n";
    ImprimirDatos(luchadores);

    std::cout << "\n\nIngrese el peso en lbs del luchador que quiere buscar: ";
    std::cin >> peso_a_buscar;
    // BusquedaPeso(luchadores, peso_a_buscar);

    busqueda = std::binary_search(luchadores.begin(), luchadores.end(), Luchador{"", peso_a_buscar}, CompararPorPeso);

    std::cout << ((busqueda) ? "Tienes luchadores con ese peso"
                             : "No se encontro ningun luchador")
              << std::endl;

    return 0;
}

Luchador SolicitarInformacion()
{
    Luchador luchador;
    std::cout << "Ingrese el nombre del luchador: ";
    std::cin >> luchador.nombre;
    std::cout << "Ingrese el peso del luchador en lbs: ";
    std::cin >> luchador.peso;
    return luchador;
}

void ImprimirDatos(const std::vector<Luchador> luchadores)
{
    std::cout << "-----------------------------------------------\n";
    for (auto luchador : luchadores)
    {
        std::cout << "Nombre del luchador: " << luchador.nombre
                  << " - Peso (lbs): " << luchador.peso << "\n";
        std::cout << "-----------------------------------------------\n";
    }
}

// Definición de la función para ordenar el arreglo usando el método de selección
void OrdenarPorSeleccion(std::vector<Luchador> &luchadores)
{
    int n = luchadores.size();
    // Solo necesitamos recorrer hasta el penúltimo elemento
    for (int i = 0; i < n - 1; i++)
    {
        // Inicializamos la posición del menor elemento en el índice i
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            // Si encontramos un valor menor, actualizamos la posición del menor
            if (luchadores[j].peso < luchadores[minPos].peso)
            {
                minPos = j;
            }
        }

        // Intercambiamos los valores
        std::swap(luchadores[i], luchadores[minPos]);
    }
}

void BusquedaPeso(const std::vector<Luchador> luchadores, float peso_a_buscar)
{
    bool encontrado = false;
    for (auto luchador : luchadores)
    {
        if (peso_a_buscar == luchador.peso)
        {
            std::cout << "Nombre del luchador: " << luchador.nombre
                      << " - Peso (lbs): " << luchador.peso << "\n";
            encontrado = true;
        }
        else
        {
        }
    }
    if (!encontrado)
    {
        std::cout << "El luchador no fue encontrado\n";
    }
}

bool CompararPorPeso(const Luchador &a, const Luchador &b)
{
    return a.peso < b.peso;
}