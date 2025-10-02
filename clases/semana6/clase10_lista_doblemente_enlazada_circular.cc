#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void InsertarInicio(struct Nodo *&lista, int n);
void InsertarFinal(struct Nodo *&lista, int n);
void InsertarDespues(struct Nodo *&lista, int valorBuscado, int nuevoValor);

void EliminarInicio(struct Nodo *&lista);
void EliminarFinal(struct Nodo *&lista);
void EliminarPorValor(struct Nodo *&lista, int valor);

Nodo *Buscar(struct Nodo *&lista, int valor);

void Imprimir(struct Nodo *&lista);

int main()
{
    struct Nodo *lista = nullptr;

    InsertarInicio(lista, 300);
    InsertarInicio(lista, 400);
    InsertarFinal(lista, 200);
    InsertarFinal(lista, 100);

    Imprimir(lista);
    std::cout << "------\n";

    InsertarDespues(lista, 300, 350); // insertar después de 300
    Imprimir(lista);
    std::cout << "------\n";

    EliminarInicio(lista);
    Imprimir(lista);
    std::cout << "------\n";

    EliminarFinal(lista);
    Imprimir(lista);
    std::cout << "------\n";

    EliminarPorValor(lista, 300);
    Imprimir(lista);

    return 0;
}

void InsertarInicio(struct Nodo *&lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;
        lista->anterior = lista;
    }
    else
    {
        struct Nodo *ultimo = lista->anterior;

        nuevoNodo->siguiente = lista;
        nuevoNodo->anterior = ultimo;

        ultimo->siguiente = nuevoNodo;
        lista->anterior = nuevoNodo;

        lista = nuevoNodo;
    }
}

void InsertarFinal(struct Nodo *&lista, int n)
{
    if (lista == nullptr)
    {
        InsertarInicio(lista, n);
        return;
    }
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.elemento = n;

    struct Nodo *ultimo = lista->anterior;

    nuevoNodo->siguiente = lista;
    nuevoNodo->anterior = ultimo;

    ultimo->siguiente = nuevoNodo;
    lista->anterior = nuevoNodo;
}

void InsertarDespues(struct Nodo *&lista, int valorBuscado, int nuevoValor)
{
    if (lista == nullptr)
        return;

    struct Nodo *temporal = lista;
    do
    {
        if (temporal->datos.elemento == valorBuscado)
        {
            struct Nodo *nuevoNodo = new Nodo;
            nuevoNodo->datos.elemento = nuevoValor;

            struct Nodo *sig = temporal->siguiente;

            nuevoNodo->siguiente = sig;
            nuevoNodo->anterior = temporal;

            temporal->siguiente = nuevoNodo;
            sig->anterior = nuevoNodo;
            return;
        }
        temporal = temporal->siguiente;
    } while (temporal != lista);
}

void EliminarInicio(struct Nodo *&lista)
{
    if (lista == nullptr)
        return;

    if (lista->siguiente == lista) // solo un nodo
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        struct Nodo *ultimo = lista->anterior;
        struct Nodo *borrar = lista;

        lista = lista->siguiente;
        lista->anterior = ultimo;
        ultimo->siguiente = lista;

        delete borrar;
    }
}

void EliminarFinal(struct Nodo *&lista)
{
    if (lista == nullptr)
        return;

    if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        struct Nodo *ultimo = lista->anterior;
        struct Nodo *penultimo = ultimo->anterior;

        penultimo->siguiente = lista;
        lista->anterior = penultimo;

        delete ultimo;
    }
}

void EliminarPorValor(struct Nodo *&lista, int valor)
{
    if (lista == nullptr)
        return;

    struct Nodo *temporal = lista;
    do
    {
        if (temporal->datos.elemento == valor)
        {
            if (temporal == lista)
                EliminarInicio(lista);
            else if (temporal->siguiente == lista)
                EliminarFinal(lista);
            else
            {
                struct Nodo *ant = temporal->anterior;
                struct Nodo *sig = temporal->siguiente;

                ant->siguiente = sig;
                sig->anterior = ant;

                delete temporal;
            }
            return;
        }
        temporal = temporal->siguiente;
    } while (temporal != lista);
}

Nodo *Buscar(struct Nodo *&lista, int valor)
{
    if (lista == nullptr)
        return nullptr;

    struct Nodo *temporal = lista;
    do
    {
        if (temporal->datos.elemento == valor)
            return temporal;

        temporal = temporal->siguiente;
    } while (temporal != lista);

    return nullptr;
}

void Imprimir(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            std::cout << "Valor: " << temporal->datos.elemento
                      << " Dir: " << temporal
                      << " Sig: " << temporal->siguiente
                      << " Ant: " << temporal->anterior
                      << std::endl;
            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        std::cout << "Lista vacia\n";
    }
}
