#include <iostream>

void OrdenarBurbuja(int arreglo[], int n);
void Imprimirarreglo(int arreglo[], int n);

int main()
{
    // Definimos un arregloeglo de ejemplo
    int arreglo[] = {5, 3, 8, 4, 2};
    // Tamaño del arregloeglo
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    std::cout << "arreglo sin ordenar: ";
    Imprimirarreglo(arreglo, n);

    // Ordenamos el arregloeglo usando el método burbuja
    OrdenarBurbuja(arreglo, n);

    std::cout << "arreglo ordenado: ";
    Imprimirarreglo(arreglo, n);

    return 0;
}

// Función para realizar el ordenamiento por burbuja
void OrdenarBurbuja(int arreglo[], int n)
{
    // Contador para el número de pasos realizados
    int pasos = 0;
    // Contador de intercambios
    int intercambios = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Incrementamos el contador de pasos en cada comparación
            pasos++;
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arreglo[j] > arreglo[j + 1])
            {
                // Intercambio de elementos
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                // Incrementamos el contador de intercambios
                intercambios++;
            }
        }
    }
    std::cout << "Numero total de pasos: " << pasos << std::endl;
    std::cout << "Numero total de intercambios: " << intercambios << std::endl;
}

// Función para imprimir el arregloeglo
void Imprimirarreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
