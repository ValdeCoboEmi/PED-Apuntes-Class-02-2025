/*
    Crea un programa en C++ que haga uso de la librería stack para trabajar con una pila.
    El objetivo es almacenar las letras de tu nombre en la pila y luego imprimirlas en orden normal al despilar.
*/
#include <iostream>
#include <stack>

// Función recursiva para imprimir en orden normal
void ImprimirPilaDespilada(std::stack<char> pila_nombre)
{
    if (pila_nombre.empty())
        return; // Caso base

    char letra = pila_nombre.top(); // Tomar cima
    pila_nombre.pop();              // Quitarla

    ImprimirPilaDespilada(pila_nombre); // Llamada recursiva
    std::cout << letra;                 // Imprimir después → mantiene orden original
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

    std::cout << "Nombre al despilar (orden normal): ";
    ImprimirPilaDespilada(pila_nombre);
    std::cout << std::endl;

    return 0;
}
