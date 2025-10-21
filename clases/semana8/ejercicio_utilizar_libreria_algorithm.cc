#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 👈 Necesario para sort()

using namespace std;

struct Comidas
{
    string nombre;
    float calorias;
};

// Prototipos
void ordenarComidas(vector<Comidas> &Comiditas); // Paso por referencia
Comidas solicitarInformacion();
void imprimirArreglo(const vector<Comidas> &Comiditas);

int main()
{
    vector<Comidas> Comiditas;
    bool continuar = true;
    int opcion;

    do
    {
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

    // Ordenar el arreglo usando <algorithm>
    ordenarComidas(Comiditas);

    // Imprimir arreglo ordenado
    cout << "\nArreglo ordenado por calorías:\n";
    imprimirArreglo(Comiditas);

    return 0;
}

// Usa std::sort de <algorithm> para ordenar por calorías
void ordenarComidas(vector<Comidas> &Comiditas)
{
    sort(Comiditas.begin(), Comiditas.end(),
        [](const Comidas &a, const Comidas &b)
        {
            return a.calorias < b.calorias;
        });
}

// Imprime los elementos del vector
void imprimirArreglo(const vector<Comidas> &Comiditas)
{
    for (auto c : Comiditas)
    {
        cout << "Nombre de la comida: " << c.nombre
             << " - Calorías: " << c.calorias << "\n";
    }
    cout << endl;
}

// Pide al usuario la información de una comida
Comidas solicitarInformacion()
{
    Comidas comidita;
    cout << "Ingrese el nombre de la comida: ";
    cin >> comidita.nombre;
    cout << "Ingrese las calorías de la comida: ";
    cin >> comidita.calorias;
    return comidita;
}
