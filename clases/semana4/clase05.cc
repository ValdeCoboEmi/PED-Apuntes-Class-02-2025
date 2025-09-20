#include <iostream>
#include <string>

// Declarar estructura
struct Atleta
{
    std::string nombre;
    float altura;
    float peso;
    float imc;
};

//Declaracion de las funcioens
float calcularIMC(float peso, float altura);
struct Atleta solicitarDatos();

int main()
{
    // Declarar variable local de struct atleta
    Atleta atleta;

    // Declarar un puntero local de struct atleta
    Atleta *ptr_atleta = &atleta;

    // Inicializamos el struct usando la función
    atleta = solicitarDatos();

    // Calculamos el IMC usando la función
    ptr_atleta->imc = calcularIMC(ptr_atleta->peso, ptr_atleta->altura);

    // Mostramos los datos
    std::cout << "\n--- Datos del atleta ---\n";
    std::cout << "Nombre: " << ptr_atleta->nombre << "\n";
    std::cout << "Altura: " << ptr_atleta->altura << " m\n";
    std::cout << "Peso: " << ptr_atleta->peso << " kg\n";
    std::cout << "IMC: " << ptr_atleta->imc << "\n";

    return 0;
}

// Funcion para calcular el imc, IMC = peso / (altura * altura)
float calcularIMC(float peso, float altura)
{
    return peso / (altura * altura);
}


// Función que solicita los datos
Atleta solicitarDatos()
{
    Atleta a;

    std::cout << "Ingrese el nombre del atleta: ";
    std::getline(std::cin, a.nombre);

    std::cout << "Ingrese la altura (en metros): ";
    std::cin >> a.altura;

    std::cout << "Ingrese el peso (en kilogramos): ";
    std::cin >> a.peso;

    // Limpiar el buffer del salto de línea que deja std::cin
    std::cin.ignore();

    return a;
}