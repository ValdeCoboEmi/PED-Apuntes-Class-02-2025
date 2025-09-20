/*
    1. Crea un programa que:
    - Genere un arreglo de 20 números aleatorios entre 1 y 100.
    - Implemente funciones para:
            - Contar cuántos son pares e impares.
            - Encontrar el segundo mayor y el segundo menor.
        - Invertir el arreglo (sin usar otro arreglo auxiliar).
*/

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

// Constante global para el tamaño del arreglo
const int kSize = 20;

// Declaraciones de funciones
void CountEvenOdd(const int arr[], int size, int &even_count, int &odd_count);
void FindSecondMinMax(const int arr[], int size, int &second_min, int &second_max);
void ReverseArray(int arr[], int size);

int main()
{
    // Inicializamos
    srand(time(0));

    // Declaración del arreglo
    int arr[kSize];

    // Llenar con números aleatorios entre 1 y 100
    for (int i = 0; i < kSize; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // Mostrar el arreglo generado
    std::cout << "Arreglo generado:\n";
    for (int i = 0; i < kSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    // Contar pares e impares
    int even_count, odd_count;
    CountEvenOdd(arr, kSize, even_count, odd_count);
    std::cout << "Cantidad de pares: " << even_count << "\n";
    std::cout << "Cantidad de impares: " << odd_count << "\n\n";

    // Encontrar segundo menor y segundo mayor
    int second_min, second_max;
    FindSecondMinMax(arr, kSize, second_min, second_max);
    std::cout << "Segundo menor: " << second_min << "\n";
    std::cout << "Segundo mayor: " << second_max << "\n\n";

    // Invertir el arreglo
    ReverseArray(arr, kSize);
    std::cout << "Arreglo invertido:\n";
    for (int i = 0; i < kSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

// Función que cuenta pares e impares
void CountEvenOdd(const int arr[], int size, int &even_count, int &odd_count)
{
    even_count = 0;
    odd_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }
}

// Función que encuentra el segundo menor y segundo mayor
void FindSecondMinMax(const int arr[], int size, int &second_min, int &second_max)
{
    // Inicializamos valores extremos
    int min_val = 101; // Mayor que el rango (1-100)
    int max_val = 0;   // Menor que el rango
    second_min = 101;
    second_max = 0;

    // Encontrar mínimo y máximo primero
    // Aqui lo que se hace es que se va guardando el menor dentro del arreglo lo mismo pasa con el mayor se va guardando
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    // Encontrar segundo mínimo y segundo máximo
    // se hace lo mismo que arriba pero ahora tambien tomando en cuenta el primer valor obtenido de mayor y menor
    // pero sin el igual para que no sea verdadero y no guarde eso
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < second_min && arr[i] > min_val)
        {
            second_min = arr[i];
        }
        if (arr[i] > second_max && arr[i] < max_val)
        {
            second_max = arr[i];
        }
    }
}

// Función que invierte el arreglo en su lugar
void ReverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}