#include <iostream>

// LISTAS ESTAN COMPUESTAS DE NODOS, ESE NODO CONTIENE INFORMACION (ID; ETC)
// Lista simplemente entrelazada

struct Datos
{
    int numero;
};

// Nodo para guardar la informacion principal que tiene un puntero para el next
struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente; // Sirve para apuntar al siguiente y no perder
};

struct Nodo *lista = nullptr;

// Declaracion de funciones
void InsertarInicio(int);
void InsertarFinal(int);
void EliminarInicio();
void EliminarFinal();
void Imprimir();

int main()
{
    InsertarInicio(100);
    InsertarFinal(10);
    InsertarInicio(10);
    InsertarInicio(40);
    InsertarFinal(50);

    EliminarInicio();
    
    EliminarFinal();

    Imprimir();
    return 0;
}

void InsertarInicio(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;

    // variable auxiliar almacena el nodo actual
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;

    // Si la lista esta vacia se agrega el primer nodo
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

void InsertarFinal(int n)
{
    struct Nodo *nuevoNodo = new Nodo;

    struct Nodo *temporal = lista;
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        // Borra el elemento
        lista = temporal->siguiente;
        // lbera la memoria
        delete temporal;
        temporal = nullptr;
    }
    else if (temporal->siguiente == nullptr)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        // Si el nodo no es el ultimo
        if (temporal->siguiente != nullptr)
        {
            // Se realiza la iteraciones hasta encontra el
            while (temporal->siguiente != nullptr)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacema el penultimo nodo sera quien apunte nullptr
            temporal2->siguiente = nullptr;
            // Se libera la memoria del nodo ultimo
            delete temporal;
            temporal = nullptr;
        }

        // Si unicamente se encontraba un nodo en la lista
        else
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

void Imprimir()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std::cout << "Valores de la lista : " << temporal->datos.numero << "\n"
                      << "Direccion memoria: " << temporal << " dir nodo siguiente: " << temporal->siguiente << "\n";
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "La lista esta vacia\n";
    }
}