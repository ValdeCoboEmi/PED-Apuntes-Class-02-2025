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
    struct Nodo *anterior;
};

// Declaración de funciones
void InsertarInicio(struct Nodo **lista, int n);
void InsertarFinal(struct Nodo **lista, int n);
void InsertarIntermedio(struct Nodo **lista, int n, int pos);
void Imprimir(struct Nodo **lista);
void EliminarInicio(struct Nodo **lista);
void EliminarFinal(struct Nodo **lista);
// Propuesta similar para borrar valor intermedio de diferentes formas
void EliminarIntermedio(struct Nodo **lista, int n);
void EliminarNodoValor(struct Nodo **lista, int n);
void EliminarPos(struct Nodo **lista, int n);

int main(int argc, char *argv[])
{
    // Reserva memoria
    struct Nodo *lista = nullptr;

    InsertarInicio(&lista, 7);
    InsertarInicio(&lista, 100);
    InsertarInicio(&lista, 40);

    // Imprimir manualmente el primer valor
    std::cout << "Dir. memoria: " << lista
              << "Dir. memoria sig:  " << lista->siguiente
              << "Dir. memoria ant: " << lista->anterior
              << "Valor: " << lista->datos.numero << std::endl;

    // Imprimir manualmente el tercer valor
    std::cout << "Dir. memoria: " << lista->siguiente->siguiente
              << "Dir memoria sig: " << lista->siguiente->siguiente->siguiente
              << "Dir. memoria ant: " << lista->siguiente->siguiente->anterior
              << "Valor: " << lista->siguiente->siguiente->datos.numero << std::endl;

    Imprimir(&lista);

    return 0;
}

// Insertar nodos al inicio de la lista
void InsertarInicio(struct Nodo **lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (*lista == nullptr)
    {
        *lista = nuevoNodo;
    }
    else
    {
        // conexion del nuevo nodo con la lista
        nuevoNodo->siguiente = *lista;
        (*lista)->anterior = nuevoNodo;
        // asignar el nuevonodo a la cabeza de la lista
        *lista = nuevoNodo;
    }
}

// Insertar nodos al final de la lista
void InsertarFinal(struct Nodo **lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;

    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (*lista == nullptr)
    {
        *lista = nuevoNodo;
    }
    else
    {
        struct Nodo *temporal = *lista;
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        // conexiones de nuevonodo a temporal
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}

// Insertar intermedio
void InsertarIntermedio(struct Nodo **lista, int n, int posicion)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = *lista;
    struct Nodo *temporal2;

    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    // Conexiones del nuevoNodo con la lista
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}

// Borrar el primer nodo de la lista
void EliminarInicio(struct Nodo **lista)
{
    struct Nodo *temporal = *lista;

    if (*lista != nullptr)
    {
        if ((*lista)->siguiente != nullptr)
        {
            *lista = temporal->siguiente;
            delete temporal;
            temporal = nullptr;
            (*lista)->anterior = nullptr;
        }
        else
        {
            delete *lista;
            *lista = nullptr;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

// Borrar el ultimo nodo de la lista
void EliminarFinal(struct Nodo **lista)
{
    struct Nodo *temporal = *lista;
    // struct Nodo *temporal2;

    if (*lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (temporal->siguiente != nullptr)
            {
                temporal = temporal->siguiente;
            }

            temporal->anterior->siguiente = temporal->anterior;
            temporal->anterior->siguiente = nullptr;

            // temporal2 = temporal->anterior;
            // temporal2->siguiente = nullptr;
            delete temporal;
            temporal = nullptr;
        }
        else
        {
            delete *lista;
            *lista = nullptr;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarIntermedio(struct Nodo **lista, int posicion)
{
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = *lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    // Conexiones del nuevoNodo con la lista
    temporal2->siguiente = temporal3;
    temporal3->anterior = temporal2;
    delete temporal;
    temporal = nullptr;
}

void EliminarPos(struct Nodo **lista, int pos)
{
    struct Nodo *aux = *lista;
    int i = 1;
    while (aux != nullptr && i < pos)
    {
        aux = aux->siguiente;
        i++;
    }
    if (aux != nullptr)
    {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;
        aux = nullptr;
    }
    else
    {
        std::cout << "No se encontro";
    }
}

void EliminarNodoValor(struct Nodo **lista, int val)
{
    struct Nodo *aux = *lista;
    while (aux != nullptr && aux->datos.numero != val)
    {
        aux = aux->siguiente;
    }

    if (aux != nullptr)
    {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;
        aux = nullptr;
    }
    else
    {
        std::cout << "No se encontro";
    }
}

void Imprimir(struct Nodo **lista)
{
    struct Nodo *temporal = *lista;
    if (temporal != nullptr)
    {
        // Imprimir cuando se inserta al final de la lista
        while (temporal != nullptr)
        {
            std::cout << "Lista " << temporal->datos.numero
                      << " Direccion " << temporal
                      << " Dir siguiente " << temporal->siguiente
                      << " Dir anterior " << temporal->anterior << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
}