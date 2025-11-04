#include <iostream>

struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

// Nodo del árbol binario
struct Nodo
{
    struct Tiobe indice;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Tiobe SolicitarDatos();

// Funcion que devuelve un puntero
Nodo *CrearNodo(const Tiobe &informacion);

void InsertarNodo(Nodo *&abb, const Tiobe &informacion);

// Recorridos
void RecorridoInorden(Nodo *abb);
void RecorridoPreorden(Nodo *abb);
void RecorridoPostorden(Nodo *abb);

int main()
{
    struct Nodo *abb = nullptr;
    bool continuar = true;
    do
    {

        struct Tiobe informacion_tiobe = SolicitarDatos();

        CrearNodo(informacion_tiobe);

        InsertarNodo(abb, informacion_tiobe);

        std::cout << "\nDigite la opcion para continuar ingresando o no: " << std::endl;
        std::cout << "1. Continuar" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Digite la opcion: ";
        std::cin >> continuar;

    } while (continuar);

    std::cout << "Recorrido in orden: \n";
    RecorridoInorden(abb);

    std::cout << "Recorrido PostOrden: \n";
    RecorridoPostorden(abb);

    std::cout << "Recorrido Preorden: \n";
    RecorridoPreorden(abb);

    return 0;
}

// SOLICITAR DATOS
struct Tiobe SolicitarDatos()
{
    struct Tiobe datos_indice;
    std::cout << "Ingrese el lenguaje de programacion: ";
    std::cin >> datos_indice.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos_indice.puntaje;
    return datos_indice;
}

// Crear un nodo, se crea con un puntero, porque no queremos que se desaparezca porque al hacerlo de esta manera
// No se guarda en el stack sino en el heap
Nodo *CrearNodo(const Tiobe &informacion)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->indice = informacion;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

// Insertar un nodo en el árbol
void InsertarNodo(Nodo *&abb, const Tiobe &informacion)
{
    if (abb == nullptr)
    {
        abb = CrearNodo(informacion);
        return;
    }

    // Recursividad Directa
    if (informacion.puntaje < abb->indice.puntaje)
        InsertarNodo(abb->izquierdo, informacion);
    else
        InsertarNodo(abb->derecho, informacion);
}

// Recorridos
void RecorridoInorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    RecorridoInorden(abb->izquierdo);
    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
    RecorridoInorden(abb->derecho);
}

void RecorridoPreorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
    RecorridoPreorden(abb->izquierdo);
    RecorridoPreorden(abb->derecho);
}

void RecorridoPostorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    RecorridoPostorden(abb->izquierdo);
    RecorridoPostorden(abb->derecho);
    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
}