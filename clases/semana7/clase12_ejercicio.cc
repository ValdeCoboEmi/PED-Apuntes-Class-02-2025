/*
    Crear cola usando la liberia queue y encolar los datos de las estructuras

    -funcion para soliciar los datos (struct)

    -utilizar el metodo push para inserar los struct de Persona

    -funcion de impirmir el tamaño de la cola y el elemento que esta al frente de la cola, que imprima los valores
    cada 3 segundos, utilizar funciones sleep(), a la vez hacer uso de pop()

    -En el main incluir un do while para consultar al usuario si desea seguir o no agregando personas a la cola,
    al parar el bucle se debe ejecutar la funcion imprimir
*/

#include <iostream>
#include <queue>
#include <windows.h> 

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    // Fecha de nacimiento
    int fNac;
};

// Sobrecarga del operador << para Persona
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    os << p.nombre << ", fecha de nacimiento: " << p.fNac;
    return os;
}

// Sobrecarga del operador << para queue<Persona>
std::ostream& operator<<(std::ostream& os, std::queue<Persona> q) {
    os << "Tamaño de la cola: " << q.size() << "\n";
    while (!q.empty()) {
        os << q.front() << "\n";  // usa la sobrecarga de Persona
        q.pop();
    }
    return os;
}

struct Persona SolicitarDatos();
void Imprimir(std::queue<Persona> Personas);

int main()
{
    bool continuar = 0;

    std::queue<Persona> Personas;

    do
    {
        Personas.push(SolicitarDatos());

        std::cout << "\nDesea ingresar otra persona (Si: 0, No: 1), Digite la opcion: ";
        std::cin >> continuar;
    } while (!continuar);

    std::cout << "-------------------------------------------\n";
    Imprimir(Personas);

    std::cout << "-------------------------------------------\n";
    std::cout << "Adiossssito\n";

    return 0;
}

struct Persona SolicitarDatos()
{
    struct Persona p;
    std::cout << "Ingresa un nombre: ";
    std::cin >> p.nombre;
    std::cout << "Ingresa la fecha de Nac: ";
    std::cin >> p.fNac;
    return p;
}

void Imprimir(std::queue<Persona> Personas)
{
    std::cout << "El tamanio de la cola es: " << Personas.size() << "\n";
    while (!Personas.empty())
    {
        std::cout << Personas.front().nombre << ", fecha de nacimiento: " << Personas.front().fNac << "\n"; // Mostrar el primero
        Personas.pop(); // Quitar el primero
        Sleep(3000); //3 segundos
    }
}