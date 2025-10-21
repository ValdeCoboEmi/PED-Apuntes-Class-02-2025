#include <iostream>

int LinearSearch(const int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i; // Retorna el índice si encuentra el valor
        }
    }
    return -1; // Retorna -1 si no encuentra el valor
}

int BinarySearch(const int arr[], int low, int high, int key)
{
    while (low <= high)
    {                                     // Mientras el índice bajo sea menor o igual al alto, es decir, mientras haya elementos en el arreglo
        int mid = low + (high - low) / 2; // Calcula el índice medio o central
        if (arr[mid] == key)
        {               // Si el valor en el índice medio es igual al valor buscado
            return mid; // Retorna el índice si encuentra el valor
        }
        if (arr[mid] < key)
        {                  // Si el valor en el índice medio es menor al valor buscado
            low = mid + 1; // Busca en la mitad derecha
        }
        else
        {
            high = mid - 1; // Busca en la mitad izquierda
        }
    }
    return -1; // Retorna -1 si no encuentra el valor
}

int main(int argc, char *argv[])
{
    const int arr[] = {2, 3, 4, 10, 40};     // Arreglo de prueba
    int size = sizeof(arr) / sizeof(arr[0]); // Tamaño del arreglo
    int key = 10;                            // Valor a buscar

    // Búsqueda lineal
    int linear_result = LinearSearch(arr, size, key);
    std::cout << "Búsqueda Lineal: ";
    (linear_result == -1) ? std::cout << "No encontrado\n" : std::cout << "Elemento encontrado en índice " << linear_result << "\n";

    // Busqueda binaria
    int binary_result = BinarySearch(arr, 0, size - 1, key);
    std::cout << "Búsqueda Binaria: ";
    (binary_result == -1) ? std::cout << "No encontrado\n" : std::cout << "Elemento encontrado en índice " << binary_result << "\n";

    return 0;
}