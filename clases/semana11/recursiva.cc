#include <iostream>

int CalcularFactorial(int n);
int CalcularPotencia(int potencia, int n);
int VerificarPar(int n);
int VerificarImpar(int n);

int main()
{
    // int n, pontencia;

    // std::cout << "\nIngrese el numero: ";
    // std::cin >> n;

    // std::cout << "Ingrese a que potencia la quiere: ";
    // std::cin >> pontencia;

    // std::cout << "\nLa potencia de " << n << "^" << pontencia << " es: " << CalcularPotencia(pontencia, n);

    std::cout << "Verificar par o impar numero 5: " << VerificarPar(5);

    return 0;
}

int CalcularFactorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * CalcularFactorial(n - 1);
    }
}

// Ejercicio de hacer exponente de una base
int CalcularPotencia(int potencia, int n)
{
    if (potencia == 0)
    {
        return 1;
    }
    else
    {
        return n * CalcularPotencia(potencia - 1, n);
    }
}
int VerificarPar(int n)
{
    if (n < 0)
        n = -n; // Manejar negativos
    if (n == 0)
        return 0; // Es par
    else
        return VerificarImpar(n - 1);
}

int VerificarImpar(int n)
{
    if (n < 0)
        n = -n; // Manejar negativos
    if (n == 0)
        return 1; // No es impar
    else
        return VerificarPar(n - 1);
}