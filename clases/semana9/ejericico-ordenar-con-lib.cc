#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 👈 Para std::sort

using namespace std;

struct Comida
{
    string nombre;
    float calorias;
};

// --- Prototipos ---
void ordenarPorCalorias(vector<Comida> &comidas);
void ordenarPorNombre(vector<Comida> &comidas);
Comida solicitarInformacion();
void imprimirArreglo(const vector<Comida> &comidas);

int main()
{
    vector<Comida> comidas;
    int opcion;

    do
    {
        comidas.push_back(solicitarInformacion());

        cout << "\n¿Desea agregar otra comida? (1 = Sí, 0 = No): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == 1);

    cout << "\n--- Arreglo sin ordenar ---\n";
    imprimirArreglo(comidas);

    // --- Ordenar por calorías ---
    vector<Comida> comidasPorCalorias = comidas;
    ordenarPorCalorias(comidasPorCalorias);
    cout << "\n--- Arreglo ordenado por calorías ---\n";
    imprimirArreglo(comidasPorCalorias);

    // --- Ordenar por nombre ---
    vector<Comida> comidasPorNombre = comidas;
    ordenarPorNombre(comidasPorNombre);
    cout << "\n--- Arreglo ordenado por nombre ---\n";
    imprimirArreglo(comidasPorNombre);

    return 0;
}

// --- Ordenar usando std::sort (por calorías) ---
void ordenarPorCalorias(vector<Comida> &comidas)
{
    sort(comidas.begin(), comidas.end(),
         [](const Comida &a, const Comida &b)
         {
             return a.calorias < b.calorias; // menor a mayor calorías
         });
}

// --- Ordenar usando std::sort (por nombre) ---
void ordenarPorNombre(vector<Comida> &comidas)
{
    sort(comidas.begin(), comidas.end(),
         [](const Comida &a, const Comida &b)
         {
             return a.nombre < b.nombre; // orden alfabético A-Z
         });
}

// --- Imprimir el vector ---
void imprimirArreglo(const vector<Comida> &comidas)
{
    for (const auto &c : comidas)
    {
        cout << "Comida: " << c.nombre
             << " | Calorías: " << c.calorias << "\n";
    }
}

// --- Pedir datos al usuario ---
Comida solicitarInformacion()
{
    Comida c;
    cout << "Ingrese el nombre de la comida: ";
    cin >> c.nombre;
    cout << "Ingrese las calorías: ";
    cin >> c.calorias;
    return c;
}
