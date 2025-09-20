#include <iostream>
#include <cstring>

using namespace std;

// ==========================================================
// 4. Registro de estudiantes con ordenamiento
// - Struct Estudiante: carnet, nombre, promedio
// - Arreglo dinámico de estudiantes
// - Funciones: ingresar estudiantes, ordenar por promedio, mostrar mejor y peor
// ==========================================================

struct Estudiante
{
    char carnet[20];
    char nombre[50];
    float promedio;
};

void LeerEstudiantes(Estudiante *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Carnet: ";
        cin >> arr[i].carnet;
        cout << "Nombre: ";
        cin >> arr[i].nombre;
        cout << "Promedio: ";
        cin >> arr[i].promedio;
    }
}

void OrdenarPorPromedio(Estudiante *arr, int n)
{
    // Burbuja descendente
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].promedio < arr[j + 1].promedio)
            {
                Estudiante temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    int n;
    cout << "Cantidad de estudiantes: ";
    cin >> n;
    Estudiante *arr = new Estudiante[n];

    LeerEstudiantes(arr, n);
    OrdenarPorPromedio(arr, n);

    cout << "Mejor promedio: " << arr[0].nombre << " " << arr[0].promedio << endl;
    cout << "Peor promedio: " << arr[n - 1].nombre << " " << arr[n - 1].promedio << endl;

    delete[] arr;
    return 0;
}
