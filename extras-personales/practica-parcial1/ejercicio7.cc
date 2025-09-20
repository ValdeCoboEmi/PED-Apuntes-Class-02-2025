#include <iostream>
#include <cstdlib>
#include <ctime>

// =====================================================
// 7. Arreglo estático
// - Arreglo de 10 enteros aleatorios.
// - Encontrar máximo, mínimo y promedio.
// =====================================================

int EncontrarMaximo(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int EncontrarMinimo(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

float CalcularPromedio(int arr[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += arr[i];
    return (float)suma / n;
}

int main()
{
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Maximo: " << EncontrarMaximo(arr, 10) << "\n";
    std::cout << "Minimo: " << EncontrarMinimo(arr, 10) << "\n";
    std::cout << "Promedio: " << CalcularPromedio(arr, 10) << "\n";

    return 0;
}
