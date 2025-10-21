#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Comidas {
    string nombre;
    float calorias;
};

// Prototipos
void insercion(vector<Comidas> &Comiditas);
Comidas solicitarInformacion();
void imprimirArreglo(const vector<Comidas> &Comiditas);

int main() {
    vector<Comidas> Comiditas;
    bool continuar = true;
    int opcion;

    do {
        // Pedimos los datos de la comida
        Comiditas.push_back(solicitarInformacion());

        cout << "\n¿Desea agregar otra comida? (1 = Sí, 0 = No): ";
        cin >> opcion;
        cout << "\n";
        cin.ignore();

        if (opcion == 0)
            continuar = false;

    } while (continuar);

    // Imprimir arreglo sin ordenar
    cout << "Arreglo sin ordenar:\n";
    imprimirArreglo(Comiditas);

    // Ordenar el arreglo usando el método de inserción
    insercion(Comiditas);

    // Imprimir arreglo ordenado
    cout << "\nArreglo ordenado por calorías:\n";
    imprimirArreglo(Comiditas);

    return 0;
}

// Método de ordenamiento por inserción (por calorías)
void insercion(vector<Comidas> &Comiditas) {
    int n = Comiditas.size();
    for (int i = 1; i < n; i++) {
        Comidas aux = Comiditas[i];
        int j = i - 1;

        // Mover elementos mayores que aux.calorias hacia la derecha
        while (j >= 0 && Comiditas[j].calorias > aux.calorias) {
            Comiditas[j + 1] = Comiditas[j];
            j--;
        }
        Comiditas[j + 1] = aux;
    }
}

// Imprime los elementos del vector
void imprimirArreglo(const vector<Comidas> &Comiditas) {
    for (auto c : Comiditas) {
        cout << "Nombre de la comida: " << c.nombre
             << " - Calorías: " << c.calorias << "\n";
    }
    cout << endl;
}

// Pide al usuario la información de una comida
Comidas solicitarInformacion() {
    Comidas comidita;
    cout << "Ingrese el nombre de la comida: ";
    cin >> comidita.nombre;
    cout << "Ingrese las calorías de la comida: ";
    cin >> comidita.calorias;
    return comidita;
}
