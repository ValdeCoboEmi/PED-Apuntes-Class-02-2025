#include <iostream>

// =====================================================
// 8. Punteros simples
// - Declarar un entero x y un puntero px que apunte a él.
// - Mostrar dirección de memoria y valor usando puntero.
// - Modificar el valor de x a través del puntero.
// =====================================================

int main()
{
    int x = 10;
    int *px = &x; // px guarda la dirección de x.

    std::cout << "Direccion de x: " << px << "\n";
    std::cout << "Valor de x usando puntero: " << *px << "\n";

    *px = 20; // Se cambia el valor de x desde el puntero.

    std::cout << "Nuevo valor de x: " << x << "\n";

    return 0;
}
