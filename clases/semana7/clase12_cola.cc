/*
    Una cola es una estructura la cual es una lista que puede almacenar elementos
    donde se puede acceder a los datos por uno de los dos extremenos

    Caracteristica:
    - Un elemento se inserta en la cola (parte final) de la lista y se suprime
    por la frente (parte inicial, cabeza o frente) de la lista

    -Se eliminan de la cola en el mismo orden en que se almacena, una cola
    es una estructura de tipo FIFO (first in/first out, primero en entra-primero en salir)

    Funciones:
    -Encolar: inserta un elemento en el final de la cola
    -Desencolar: Elimina y devuelve el elemento de la cabeza o frente de la cola
    -Vacia: Comprueba si la cola está vacía antes de eliminar un elemento
    -Frente: Devuelve el valor del elemento en el frente de la cola
    -Final: Devuelve el valor del elemento en el final de la cola

    Tipos:
    Cola simple: elementos se eliminan en el mismo orden que se almacena
    Cola circular/anillo: los elementos pueden manipularse desde el frente y la ultima posicion conecta con la primera posicion
    Cola de prioidad: los elementos se insertan en cualquier posicion y se remueven solo por el frente

    *Libreria Queue
    Funciones:
    -push(elemento)
    pop(): eliminar el primer elementno de la cola
    front(): primer elemento
    back(): devuelve el ultimo elemento
    empty(): Si la cola esta vacia
    size(): si la cantidad de elemento de la cola
*/

#include <iostream>

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    //Fecha de nacimiento
    int fNac;
};

struct Nodo
{
    struct Persona inf;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *frenteCola = nullptr;
struct Nodo *finalCola = nullptr;

// Declaracion de funciones / creacion de prototipo
bool Vacia();
void Insertar(struct Persona p);
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();

int main(int argc, char *argv[])
{
    struct Persona p;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Ingresa un nombre ";
        std::cin >> p.nombre;
        std::cout << "Ingresa la fecha de Nac";
        std::cin >> p.fNac;
        Insertar(p);
    }
    std::cout << " --------------- " << std::endl;
    Imprimir();

    return 0;
}

// Operación vacia
bool Vacia()
{
    if (frenteCola == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(struct Persona p)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Asignacion del valor que ingresa el usuario
    nuevoNodo->inf = p;
    nuevoNodo->siguiente = nullptr;
    if (frenteCola == nullptr)
    {
        frenteCola = nuevoNodo;
    }
    else
    {
        finalCola->siguiente = nuevoNodo;
    }
    // Se establece el final de la cola con el nuevo nodo agregado
    finalCola = nuevoNodo;
}

// Desencolar -- inicio de la lista
void Eliminar()
{
    if (!Vacia())
    {
        struct Nodo *temporal = frenteCola;
        if (frenteCola == finalCola)
        {
            frenteCola = nullptr;
            finalCola = nullptr;
        }
        else
        {
            frenteCola = temporal->siguiente;
        }
        delete temporal;
    }
}

// Imprimir elementos de la cola
void Imprimir()
{
    struct Nodo *temporal = frenteCola;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la cola " << temporal->inf.nombre << " - " << temporal->inf.fNac << " dir propia " << temporal << " dir nod sig " << temporal->siguiente << std::endl;
        temporal = temporal->siguiente;
    }
}

void ImprimirFrente()
{
    struct Nodo *temporal = frenteCola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento frente en la cola " << temporal->inf.nombre << std::endl;
    }
}

void ImprimirFinal()
{

    struct Nodo *temporal = finalCola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento final en la cola " << temporal->inf.nombre << std::endl;
    }
}