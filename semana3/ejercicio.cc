#include <iostream>

/* Crea una funcion que intercambie los valores de dos variables ingresadas por
el usuario por ejemplo, si el usuario introduce 5 como primer valor y 10 como segundo valor

Ejemplo de salida
    Primera variabel: 10
    Segunda variable: 5

Realiza este ejercicio de dos fromas
1.Usando punteros *
2. Usuando referencias &
3. Sin usuar punteros (Paso por valor) */

void CambiarValoresPorValor(int num1, int num2);
void CambiarValoresPorPuntero(int *num1, int *num2);
void CambiarValoresPorReferencia(int &num1, int &num2);

int main()
{
    int num1 = 0, num2 = 0;

    std::cout << "Ingrese el primer numero: ";
    std::cin >> num1;

    std::cout << "Ingrese el segundo numero: ";
    std::cin >> num2;

    std::cout << "\n";
    std::cout << "Numeros originales: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";

    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Cambio por valor: ";

    std::cout << "\n";
    CambiarValoresPorValor(num1, num2);
    std::cout << "\n";

    std::cout << "Cambio de variable ya afuera: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";

    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Cambio por puntero: ";

    std::cout << "\n";
    CambiarValoresPorPuntero(&num1, &num2);
    std::cout << "\n";
    std::cout << "Cambio de variable ya afuera: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";

    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Cambio por referencia: ";
    std::cout << "\n";
    CambiarValoresPorReferencia(num1, num2);
    std::cout << "\n";
    std::cout << "Cambio de variable ya afuera: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";
    std::cout << "\n";
    return 0;
}

void CambiarValoresPorValor(int num1, int num2)
{
    int num1Temporal = num1;
    num1 = num2;
    num2 = num1Temporal;
    std::cout << "\n";
    std::cout << "Cambio de variable dentro de la funcion: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";
}

void CambiarValoresPorPuntero(int *num1, int *num2)
{
    int num1Temporal = *num1;
    *num1 = *num2;
    *num2 = num1Temporal;
    std::cout << "\n";
    std::cout << "Cambio de variable del puntero dentro de la funcion: \n";
    std::cout << "Num1: " << *num1 << "\n";
    std::cout << "Num2: " << *num2 << "\n";
}

void CambiarValoresPorReferencia(int &num1, int &num2)
{
    int num1Temporal = num1;
    num1 = num2;
    num2 = num1Temporal;
    std::cout << "\n";
    std::cout << "Cambio de variable dentro de la funcion: \n";
    std::cout << "Num1: " << num1 << "\n";
    std::cout << "Num2: " << num2 << "\n";
}
