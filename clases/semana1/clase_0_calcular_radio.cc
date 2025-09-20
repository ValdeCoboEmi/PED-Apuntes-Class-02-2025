#include <iostream>
#include <cmath>
#include <iomanip>
// DECLARACION DE LA FUNCION
double CalcularAreaCirculo(double radio);
const float kPi = 3.1416;

// FUNCION MAIN
int main()
{
    // DECLARACION DE LAS VARIABLES
    double radio, area;
    // SE LE SOLICITA EL RADIO Y SE GUARDA
    std::cout << "Bienvenido, ingrese el radio del circulo para calcular su area: ";
    std::cin >> radio;

    // SE LLAMA LA FUNCION Y SE GUARDA LO QUE RETORNA
    area = CalcularAreaCirculo(radio);
    // MENSAJE DE SALIDA
    std::cout << "El area del circulo es: " << std::fixed << std::setprecision(2) << area << "\n";

    return 0;
}

// FUNCION DE CALCULAR DEFINICION
double CalcularAreaCirculo(double radio)
{
    double area;
    area = pow(radio, 2) * kPi;
    return area;
}