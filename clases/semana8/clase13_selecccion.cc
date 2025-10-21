#include <iostream>

// Declaración de las funciones
void imprimir(int arreglo[], int n);
void ordenarSeleccion(int arreglo[], int n);

int main()
{
    // Declarar e inicializar el arreglo
    int arreglo[] = {4, 8, 9, 55, 6, 1, 3};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    // Imprimir el arreglo sin ordenar
    std::cout << "Arreglo sin ordenar: ";
    imprimir(arreglo, n);

    // Ordenar el arreglo usando el método de selección
    ordenarSeleccion(arreglo, n);

    // Imprimir el arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    imprimir(arreglo, n);

    return 0;
}

// Definición de la función para ordenar el arreglo usando el método de selección
void OrdenarSeleccion(int arreglo[], int n)
{
    // Solo necesitamos recorrer hasta el penúltimo elemento
    for (int i = 0; i < n - 1; i++)
    {
        // Inicializamos la posición del menor elemento en el índice i
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            // Si encontramos un valor menor, actualizamos la posición del menor
            if (arreglo[j] < arreglo[minPos])
            {
                minPos = j;
            }
        }

        // Intercambiamos los valores
        std::swap(arreglo[i], arreglo[minPos]);
    }
}

// Definición de la función para imprimir el arreglo
void Imprimir(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
