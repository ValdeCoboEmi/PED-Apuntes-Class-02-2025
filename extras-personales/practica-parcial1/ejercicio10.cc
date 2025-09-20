#include <iostream>

// =====================================================
// 10. Array dinámico
// - Preguntar al usuario cuántos números ingresará.
// - Crear arreglo dinámico con new.
// - Calcular suma, promedio y mayor.
// - Liberar memoria al final.
// =====================================================

int main()
{
    int n;
    std::cout << "Cantidad de numeros: ";
    std::cin >> n;

    int *arr = new int[n]; // Reserva dinámica.

    for (int i = 0; i < n; i++)
    {
        std::cout << "Valor " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int suma = 0;
    int mayor = arr[0];

    for (int i = 0; i < n; i++)
    {
        suma += arr[i];
        if (arr[i] > mayor)
            mayor = arr[i];
    }

    std::cout << "Suma: " << suma << "\n";
    std::cout << "Promedio: " << (float)suma / n << "\n";
    std::cout << "Mayor: " << mayor << "\n";

    delete[] arr; // Liberar memoria.
    return 0;
}
