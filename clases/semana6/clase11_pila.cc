/*
Una pila (stack) es una lista lineal donde la inserción y borrado se hacen solo en un extremo llamado cima o tope.

Funciona con la regla LIFO (Last In, First Out), es decir, el último en entrar es el primero en salir.
Son estructuras lineales como los arreglos, con elementos en posiciones sucesivas y un único
sucesor/predecesor, excepto el primero y el último.

Solo se ocupa el insertar al inicio, porque sino no sera una pila

Funciones de una pila:

Crear: inicializa la pila.
Vacía: verifica si no tiene elementos.
Llena: verifica si alcanzó su límite.
Contar: devuelve la cantidad de elementos.
Push: inserta un elemento en la cima.
Pop: elimina el elemento de la cima.
Tope: muestra el elemento en la cima sin quitarlo.

*/

#include <iostream>
#include <stack> //Libreria de pila, que ya estan todos las funciones push, pop, peek o top, isEmpty, size 

struct Datos
{
    int numero;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

// Declarando funciones
void Insertar(struct Nodo *&pila, int n);
void Eliminar(struct Nodo *&pila);

// Porque el parametro de imprimir es puntero simple ?
// REFERENCIA DE LA REFERENCIA o sea el doble es cuando modificamos pero como aqui solo leemos no es necesario
void Imprimir(struct Nodo *pila);

// Es necesario el parametro si o no ?
// Si es si quien es el parametro ?
// Es necesario el uso de ** o *&, porque si o no?
// Lo mismo pasa solo necesitamos saber pero no modificamos el elemento
bool Vacia(struct Nodo *pila);
void UltimoElemento(struct Nodo *pila);

// Un nodo tiene un dato, el cual es el elemento y  otro nodo al que apunta

int main(int argc, char *argv[])
{
    struct Nodo *pila = nullptr;
    int valor;

    std::cout << "\n";
    Vacia(pila) ? std::cout << "La pila esta vacia \n" : std::cout << "La pila no esta vacia";
    std::cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingrese un valor ";
        std::cin >> valor;
        Insertar(pila, valor);
    }

    std::cout << "------------------" << std::endl;
    Imprimir(pila);
    std::cout << "\n";
    Vacia(pila) ? std::cout << "La pila esta vacia \n" : std::cout << "La pila no esta vacia\n";
    std::cout << "\n";
    UltimoElemento(pila);

    return 0;
}

// Operacion Push
void Insertar(struct Nodo *&pila, int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // almacenar el valor ingresado por el usuario
    nuevoNodo->datos.numero = n;
    // Ingresando el nuevo nodo a la pila
    nuevoNodo->siguiente = pila;
    // Asignando que el valor ingresado esta en la cima de la pila
    pila = nuevoNodo;
}

// Operación Pop
void Eliminar(struct Nodo *&pila)
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        // Asignación del nuevo valor que esta en la cima de la pila
        pila = temporal->siguiente;
        delete temporal;
    }
    else
    {
        std::cout << "Pila vacia /n";
    }
}

// Imprimir la pila
void Imprimir(struct Nodo *pila)
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la pila " << temporal->datos.numero
                  << "dir. memoria del nodo" << temporal
                  << " Dir memoria nodo sig " << temporal->siguiente << std::endl;

        temporal = temporal->siguiente;
    }
}

// Operacion Pila vacia
bool Vacia(struct Nodo *pila)
{
    if (pila != nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Operación Top
void UltimoElemento(struct Nodo *pila)
{
    std::cout << "Top (elemento de la cima de la pila): \n";
    std::cout << "Elementos de la pila " << pila->datos.numero
              << " dir. memoria del nodo" << pila
              << " Dir memoria nodo sig " << pila->siguiente << std::endl;
}