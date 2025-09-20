#include <iostream>

// =====================================================
// 6. Funciones con structs
// - leerEstudiante() que devuelve un Estudiante.
// - mejorPromedio() que recibe arreglo y retorna índice.
// =====================================================

struct Estudiante
{
    char nombre[50];
    int edad;
    float promedio;
};

Estudiante LeerEstudiante()
{
    Estudiante e;
    std::cout << "Nombre: ";
    std::cin >> e.nombre;
    std::cout << "Edad: ";
    std::cin >> e.edad;
    std::cout << "Promedio: ";
    std::cin >> e.promedio;
    return e;
}

// Busca el índice del estudiante con mayor promedio.
int MejorPromedio(Estudiante arr[], int n)
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].promedio > arr[idx].promedio)
        {
            idx = i;
        }
    }
    return idx;
}

int main()
{
    Estudiante estudiantes[3];
    for (int i = 0; i < 3; i++)
    {
        estudiantes[i] = LeerEstudiante();
    }

    int idx = MejorPromedio(estudiantes, 3);
    std::cout << "El mejor promedio es de: " << estudiantes[idx].nombre << " con " << estudiantes[idx].promedio << "\n";

    return 0;
}
