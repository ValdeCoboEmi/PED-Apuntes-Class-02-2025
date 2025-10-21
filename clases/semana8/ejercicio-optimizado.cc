#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Comida {
    string nombre;
    float calorias;
};

// --- Prototipos ---
void ordenarPorInsercion(vector<Comida> &comidas);
Comida solicitarInformacion();
void imprimirArreglo(const vector<Comida> &comidas);

int main() {
    vector<Comida> comidas;
    int opcion;

    do {
        comidas.push_back(solicitarInformacion());

        cout << "\nDesea agregar otra comida? (1 = Si, 0 = No): ";
        cin >> opcion;
        cout << "\n";

    } while (opcion == 1);

    cout << "\n--- Arreglo sin ordenar ---\n";
    imprimirArreglo(comidas);

    ordenarPorInsercion(comidas);

    cout << "\n--- Arreglo ordenado por calorias ---\n";
    imprimirArreglo(comidas);

    return 0;
}

// --- Ordenamiento por inserción ---
void ordenarPorInsercion(vector<Comida> &comidas) {
    const int n = comidas.size();

    for (int i = 1; i < n; ++i) {
        Comida actual = comidas[i];
        int j = i - 1;

        // Desplazar elementos mayores hacia la derecha
        while (j >= 0 && comidas[j].calorias > actual.calorias) {
            comidas[j + 1] = comidas[j];
            --j;
        }

        comidas[j + 1] = actual;
    }
}

// --- Imprimir vector ---
void imprimirArreglo(const vector<Comida> &comidas) {
    for (const auto &c : comidas) {
        cout << "Comida: " << c.nombre
             << " | Calorías: " << c.calorias << "\n";
    }
}

// --- Solicitar datos ---
Comida solicitarInformacion() {
    Comida c;
    cout << "Ingrese el nombre de la comida: ";
    cin >> c.nombre;
    cout << "Ingrese las calorías: ";
    cin >> c.calorias;
    return c;
}
