#include <iostream>
#include <vector>
#include <string>

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
    vector<Comida> comidasPorCalorias = comidas; // copia del vector original
    ordenarPorCalorias(comidasPorCalorias);
    cout << "\n--- Arreglo ordenado por calorías ---\n";
    imprimirArreglo(comidasPorCalorias);

    // --- Ordenar por nombre ---
    vector<Comida> comidasPorNombre = comidas; // otra copia
    ordenarPorNombre(comidasPorNombre);
    cout << "\n--- Arreglo ordenado por nombre ---\n";
    imprimirArreglo(comidasPorNombre);

    return 0;
}

// --- Ordenamiento por inserción (por calorías) ---
void ordenarPorCalorias(vector<Comida> &comidas)
{
    const int n = comidas.size();
    for (int i = 1; i < n; ++i)
    {
        Comida actual = comidas[i];
        int j = i - 1;

        while (j >= 0 && comidas[j].calorias > actual.calorias)
        {
            comidas[j + 1] = comidas[j];
            --j;
        }
        comidas[j + 1] = actual;
    }
}

// --- Ordenamiento por inserción (por nombre) ---
void ordenarPorNombre(vector<Comida> &comidas)
{
    const int n = comidas.size();
    for (int i = 1; i < n; ++i)
    {
        Comida actual = comidas[i];
        int j = i - 1;

        // Comparar alfabéticamente usando string::compare
        while (j >= 0 && comidas[j].nombre > actual.nombre)
        {
            comidas[j + 1] = comidas[j];
            --j;
        }
        comidas[j + 1] = actual;
    }
}

// --- Imprimir vector ---
void imprimirArreglo(const vector<Comida> &comidas)
{
    for (const auto &c : comidas)
    {
        cout << "Comida: " << c.nombre
             << " | Calorías: " << c.calorias << "\n";
    }
}

// --- Solicitar datos ---
Comida solicitarInformacion()
{
    Comida c;
    cout << "Ingrese el nombre de la comida: ";
    cin >> c.nombre;
    cout << "Ingrese las calorías: ";
    cin >> c.calorias;
    return c;
}
