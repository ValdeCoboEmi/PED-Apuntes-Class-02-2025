#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Luchador
{
    string nombre;
    float peso;
};

Luchador SolicitarInformacion();
void ImprimirDatos(vector<Luchador> luchadores);

int main()
{
    vector<Luchador> luchadores;
    bool continuar = true;
    int opcion;

    do
    {
        // Pedimos los datos de la comida
        luchadores.push_back(SolicitarInformacion());

        cout << "\n¿Desea agregar otro luchador? (1 = Sí, 0 = No): ";
        cin >> opcion;
        cout << "\n";
        cin.ignore();

        if (opcion == 0)
            continuar = false;

    } while (continuar);

    return 0;
}

Luchador SolicitarInformacion()
{
    Luchador luchador;
    cout << "Ingrese el nombre del luchador: ";
    cin >> luchador.nombre;
    cout << "Ingrese el peso del luchador en lbs: ";
    cin >> luchador.peso;
    return luchador;
}

void ImprimirDatos(vector<Luchador> luchadores)
{
    cout << "Informacion de los Luchadores ingresados: \n\n";

    for (auto luchador : luchadores)
    {
        cout << "Nombre del luchador: " << luchador.nombre
             << " - Peso (lbs): " << luchador.peso << "\n";
        cout << "-----------------------------------------------\n";
    }
}