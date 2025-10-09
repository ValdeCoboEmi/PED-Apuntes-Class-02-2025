/*
    Crea un programa en C++ que haga uso de la librería stack para trabajar con una pila.
    El objetivo es almacenar las letras de tu nombre en la pila y luego imprimirlas al despilar.
*/
#include <iostream>
#include <stack>

// Función para imprimir y vaciar la pila
void ImprimirPilaDespilada(std::stack<char> pila_nombre)
{
    // Mientras la pila no esté vacía
    while (!pila_nombre.empty())
    {
        std::cout << pila_nombre.top(); // Mostrar la cima
        pila_nombre.pop();              // Quitar el elemento
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<char> pila_nombre;
    int n;
    char letra;

    std::cout << "Ingrese el numero de letras que tiene tu nombre: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Ingrese la letra de la posicion " << i + 1 << ": ";
        std::cin >> letra;
        pila_nombre.push(letra);
    }

    std::cout << "Nombre al despilar: ";
    ImprimirPilaDespilada(pila_nombre);

    return 0;
}
