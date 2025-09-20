#include <iostream>

// =====================================================
// 5. Structs básicos
// Struct Estudiante con: nombre, edad y promedio.
// Leer 3 estudiantes e imprimir el mejor promedio.
// =====================================================

struct Estudiante
{
    char nombre[50];
    int edad;
    float promedio;
};

int main()
{
    Estudiante estudiantes[3];

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Nombre: ";
        std::cin >> estudiantes[i].nombre;
        std::cout << "Edad: ";
        std::cin >> estudiantes[i].edad;
        std::cout << "Promedio: ";
        std::cin >> estudiantes[i].promedio;
    }

    int idx = 0;
    for (int i = 1; i < 3; i++)
    {
        if (estudiantes[i].promedio > estudiantes[idx].promedio)
        {
            idx = i;
        }
    }

    std::cout << "Mejor promedio: " << estudiantes[idx].nombre << " con " << estudiantes[idx].promedio << "\n";

    return 0;
}
