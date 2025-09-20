#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    2. Suma de vectores
    - Crea dos arreglos de tamaño n.
    - Implementa funciones para:
        - Llenar ambos arreglos con números enteros.
        - Calcular la suma elemento a elemento en un tercer arreglo.
        - Calcular el producto escalar de los dos vectores.
*/

// Constante global para el tamaño del vector
const int kSize = 5;

// Llena un arreglo con enteros aleatorios
void FillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20 + 1; // Números entre 1 y 20
    }
}

// Imprime un arreglo en pantalla
void PrintArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Suma elemento a elemento de dos arreglos
void SumArrays(const int arr1[], const int arr2[], int result[], int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = arr1[i] + arr2[i];
    }
}

// Calcula el producto escalar de dos arreglos
int DotProduct(const int arr1[], const int arr2[], int size)
{
    int product = 0;
    for (int i = 0; i < size; i++)
    {
        product += arr1[i] * arr2[i];
    }
    return product;
}

int main()
{
    srand(time(0));

    int vector_a[kSize], vector_b[kSize], sum[kSize];

    FillArray(vector_a, kSize);
    FillArray(vector_b, kSize);

    std::cout << "Vector A: ";
    PrintArray(vector_a, kSize);

    std::cout << "Vector B: ";
    PrintArray(vector_b, kSize);

    SumArrays(vector_a, vector_b, sum, kSize);
    std::cout << "Suma elemento a elemento: ";
    PrintArray(sum, kSize);

    int dot_product = DotProduct(vector_a, vector_b, kSize);
    std::cout << "Producto escalar: " << dot_product << "\n";

    return 0;
}
