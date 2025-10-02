#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

void InsertarInicio(struct Nodo *&lista, int n);
void InsertarFinal(struct Nodo *&lista, int n);
void InsertarIntermedio(struct Nodo *&lista, int, int);
void EliminarInicio(struct Nodo *&lista);
void EliminarFinal(struct Nodo *&lista);
void EliminarIntermedio(struct Nodo *&lista, int);
void Imprimir(struct Nodo *&lista);

int main(int argc, char *argv[])
{
    struct Nodo *lista = nullptr;

    InsertarInicio(lista, 300);

    // std::cout<<lista->datos.elemento;
    // std::cout<<lista->siguiente->datos.elemento;
    Imprimir(lista);

    return 0;
}

void InsertarInicio(struct Nodo *&lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        // Circularidad
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
        // Circularidad
        temporal->siguiente = lista;
    }
}

void InsertarFinal(struct Nodo *&lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        temporal = nuevoNodo;
    }
}

void InsertarIntermedio(struct Nodo *&lista, int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        delete lista;
        lista = temporal->siguiente;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista Vacia";
    }
}
void EliminarFinal(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }

        temporal2->siguiente = lista;
        delete temporal;
        temporal = nullptr;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarIntermedio(struct Nodo *&lista, int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
    delete temporal;
    temporal = nullptr;
}

void Imprimir(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            std::cout << "Lista " << temporal->datos.elemento
                      << " Direccion " << temporal
                      << " Dir siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        std::cout << "Lista vacia";
    }
}
