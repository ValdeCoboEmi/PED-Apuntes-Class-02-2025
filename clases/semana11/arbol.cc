#include <iostream>
#include <string>

// Estructura para almacenar información académica del estudiante
struct InformacionAcademica
{
    // La "clave" del nodo (raíz del árbol)
    float cum;
    std::string nombre_estudiante;
};

// Nodo del árbol binario
struct Nodo
{
    struct InformacionAcademica inf;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

// Funcion que devuelve un puntero 
Nodo *CrearNodo(const InformacionAcademica &informacion);

void InsertarNodo(Nodo *&abb, const InformacionAcademica &informacion);

// Recorridos
void RecorridoInorden(Nodo *abb);
void RecorridoPreorden(Nodo *abb);
void RecorridoPostorden(Nodo *abb);

// Funcion que devuelve un puntero 
Nodo *BuscarMenor(Nodo *abb);

void BuscarNodo(Nodo *&abb, float cum_a_buscar, Nodo *&padre);
void BorrarNodo(Nodo *&abb, float cum_a_borrar);

int main()
{
    // Árbol binario de busqueda inicialmente vacío
    Nodo *abb = nullptr;
    InformacionAcademica info;

    // Ingreso de datos de 5 estudiantes
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Ingresa el CUM del estudiante: ";
        std::cin >> info.cum;
        std::cin.ignore();
        std::cout << "Ingresa el nombre del estudiante: ";
        std::getline(std::cin, info.nombre_estudiante);
        InsertarNodo(abb, info);
    }

    // Recorridos del árbol
    std::cout << "\nRecorrido Inorden: ";
    RecorridoInorden(abb);

    BorrarNodo(abb, 8.8);

    return 0;
}

// Crear un nodo a partir de la información académica
Nodo *CrearNodo(const InformacionAcademica &informacion)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->inf = informacion;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

// Insertar un nodo en el árbol
void InsertarNodo(Nodo *&abb, const InformacionAcademica &informacion)
{
    if (abb == nullptr)
    {
        abb = CrearNodo(informacion);
        return;
    }

    if (informacion.cum < abb->inf.cum)
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
    std::cout << "[" << abb->inf.cum << " : " << abb->inf.nombre_estudiante << "] ";
    RecorridoInorden(abb->derecho);
}

// Buscar un nodo
void BuscarNodo(Nodo *&abb, float cum_a_buscar, Nodo *&padre)
{
    while (abb != nullptr && abb->inf.cum != cum_a_buscar)
    {
        padre = abb;
        if (cum_a_buscar < abb->inf.cum)
            abb = abb->izquierdo;
        else
            abb = abb->derecho;
    }
}

// Buscar el nodo menor (sucesor)
Nodo *BuscarMenor(Nodo *abb)
{
    while (abb && abb->izquierdo != nullptr)
        abb = abb->izquierdo;
    return abb;
}

// Borrar un nodo
void BorrarNodo(Nodo *&abb, float cum_a_borrar)
{
    Nodo *padre = nullptr;
    Nodo *aux = abb;
    BuscarNodo(aux, cum_a_borrar, padre);
    // Si es nulo
    if (!aux)
        return;

    // Si es un nodo hoja
    if (!aux->izquierdo && !aux->derecho)
    {
        if (aux == abb)
            abb = nullptr;
        else if (padre->izquierdo == aux)
            padre->izquierdo = nullptr;
        else
            padre->derecho = nullptr;
        delete aux;
    }
    // Si es un nodo con dos hijos
    else if (aux->izquierdo && aux->derecho)
    {
        Nodo *sucesor = BuscarMenor(aux->derecho);
        aux->inf = sucesor->inf;
        BorrarNodo(aux->derecho, sucesor->inf.cum);
    }
    // Si es un nodo con un solo hijo
    else
    {
        Nodo *hijo = ((aux->izquierdo) ? aux->izquierdo : aux->derecho);
        if (aux != abb)
        {
            if (aux == padre->izquierdo)
                padre->izquierdo = hijo;
            else
                padre->derecho = hijo;
        }
        else
            abb = hijo;
        delete aux;
    }
}
