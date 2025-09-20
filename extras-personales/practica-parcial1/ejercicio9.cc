#include <iostream>

// =====================================================
// 9. Punteros con arreglos estáticos
// - Declarar un arreglo de 5 enteros.
// - Recorrer y mostrar usando un puntero.
// - Calcular suma usando el puntero en vez de índices.
// =====================================================

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    int *p = arr; // Un arreglo se comporta como puntero.

    int suma = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Elemento " << i << ": " << *(p + i) << "\n";
        suma += *(p + i); // Acceder al valor desplazando el puntero.
    }

    std::cout << "Suma total: " << suma << "\n";

    return 0;
}
