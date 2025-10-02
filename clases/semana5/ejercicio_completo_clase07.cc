#include <iostream>

// Struct de la informacion que se guardara en la lista
struct Datos
{
    int numero;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void Imprimir();
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);

int main(int argc, char *argv[])
{
    InsertarIntermedio(3, 2);
    InsertarInicio(1);
    InsertarFinal(10);
    // EliminarFinal();
    Imprimir();

    return 0;
}

// Insertar nodo al inicio de la lista
void InsertarInicio(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.numero = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al inicio
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}

// Insertar nodo al final de la lista
void InsertarFinal(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;

    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Variable auxiliar almacena el nodo actual
        struct Nodo *temporal = lista;
        // Agregar un nodo al final
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}

void InsertarIntermedio(int n, int posicion)
{

    // Validación de la posición
    if (posicion <= 0)
    {
        std::cout << "Posicion invalida. Debe ser mayor a 0." << std::endl;
        return;
    }

    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;

    // Si la lista está vacía o la posición es la primera
    if (posicion == 1 || lista == nullptr)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
        return;
    }

    struct Nodo *temporal = lista;
    int contador = 1;

    // Iteramos hasta encontrar el nodo antes de la posición deseada
    while (temporal != nullptr && contador < posicion - 1)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    // Si llegamos al final de la lista sin encontrar la posición, es un error
    if (temporal == nullptr)
    {
        std::cout << "Posicion fuera de rango." << std::endl;
        delete nuevoNodo;
        return;
    }

    // Inserción del nuevo nodo en la posición deseada
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio()
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacía" << std::endl;
        return;
    }

    struct Nodo *temporal = lista;
    lista = lista->siguiente;
    delete temporal;
}

void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        // Recorrer los nodos para encontrar el ultimo
        if (temporal->siguiente != nullptr)
        {
            while (temporal->siguiente != nullptr)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacena el penultimo nodo sera quien apunte nullptr
            temporal2->siguiente = nullptr;
            // Se libera la memoria del nodo ultimo
            delete temporal;
            temporal = nullptr;
        }
        else // Si unicamente se encontraba un nodo en la lista
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarIntermedio(int posicion)
{
    // Validación de la posición
    if (posicion <= 0 || lista == nullptr)
    {
        std::cout << "Posición inválida o lista vacía." << std::endl;
        return;
    }

    // Caso cuando se quiere eliminar el primer nodo
    if (posicion == 1)
    {
        struct Nodo *temporal = lista;
        // La cabeza de la lista avanza al siguiente nodo
        lista = lista->siguiente;
        // Se elimina el nodo anterior
        delete temporal;
        return;
    }

    struct Nodo *temporal = lista;
    struct Nodo *temporal2 = nullptr;
    int contador = 1;

    // Iteramos hasta encontrar el nodo antes de la posición a eliminar
    while (temporal != nullptr && contador < posicion)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        contador++;
    }

    // Si la posición es mayor que el tamaño de la lista, es un error
    if (temporal == nullptr)
    {
        std::cout << "Posición fuera de rango." << std::endl;
        return;
    }

    // Se conecta el nodo anterior con el siguiente del nodo a eliminar
    temporal2->siguiente = temporal->siguiente;

    // Eliminamos el nodo
    delete temporal;
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std::cout << "Lista " << temporal->datos.numero << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}