#include <iostream>
#include <string>

// Estructura que guarda la información de cada lenguaje
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

// Prototipos
struct Tiobe SolicitarDatos();
Nodo *CrearNodo(const Tiobe &informacion);
void InsertarNodo(Nodo *&abb, const Tiobe &informacion);
void RecorridoInorden(Nodo *abb);
void RecorridoPreorden(Nodo *abb);
void RecorridoPostorden(Nodo *abb);
Nodo *BuscarMenor(Nodo *abb);
void BuscarNodo(Nodo *&abb, float puntaje, Nodo *&padre);
void BorrarNodo(Nodo *&abb, float puntaje_borrar);

// ------------------------ MENÚ PRINCIPAL ------------------------
int main()
{
    Nodo *abb = nullptr; // Árbol vacío
    int opcion;           // Para el menú

    do
    {
        // Menú visual con separadores
        std::cout << "\n=============================================\n";
        std::cout << "        MENU PRINCIPAL - INDICE TIOBE\n";
        std::cout << "=============================================\n";
        std::cout << "1. Insertar nuevo lenguaje\n";
        std::cout << "2. Mostrar recorrido INORDEN\n";
        std::cout << "3. Mostrar recorrido PREORDEN\n";
        std::cout << "4. Mostrar recorrido POSTORDEN\n";
        std::cout << "5. Buscar lenguaje por puntaje\n";
        std::cout << "6. Eliminar lenguaje por puntaje\n";
        std::cout << "0. Salir\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // Insertar un nuevo nodo
            Tiobe nuevo = SolicitarDatos();
            InsertarNodo(abb, nuevo);
            std::cout << "\nLenguaje agregado correctamente.\n";
            break;
        }
        case 2:
        {
            std::cout << "\nRecorrido INORDEN (izq - raiz - der):\n";
            RecorridoInorden(abb);
            std::cout << "\n";
            break;
        }
        case 3:
        {
            std::cout << "\nRecorrido PREORDEN (raiz - izq - der):\n";
            RecorridoPreorden(abb);
            std::cout << "\n";
            break;
        }
        case 4:
        {
            std::cout << "\nRecorrido POSTORDEN (izq - der - raiz):\n";
            RecorridoPostorden(abb);
            std::cout << "\n";
            break;
        }
        case 5:
        {
            // Buscar por puntaje
            float puntaje;
            std::cout << "\nIngrese el puntaje del lenguaje a buscar: ";
            std::cin >> puntaje;

            Nodo *padre = nullptr;
            Nodo *aux = abb;
            BuscarNodo(aux, puntaje, padre);

            if (aux)
                std::cout << "\nLenguaje encontrado: " << aux->indice.lenguaje_programacion
                          << " con puntaje " << aux->indice.puntaje << "\n";
            else
                std::cout << "\nNo se encontro ningun lenguaje con ese puntaje.\n";

            break;
        }
        case 6:
        {
            // Eliminar por puntaje
            float puntaje;
            std::cout << "\nIngrese el puntaje del lenguaje a eliminar: ";
            std::cin >> puntaje;

            BorrarNodo(abb, puntaje);
            std::cout << "\nSi existia, el lenguaje fue eliminado correctamente.\n";
            break;
        }
        case 0:
            std::cout << "\nSaliendo del programa...\n";
            break;

        default:
            std::cout << "\nOpcion no valida, intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}

// ---------------------------------------------------------------
// Función para solicitar los datos de cada lenguaje
struct Tiobe SolicitarDatos()
{
    Tiobe datos_indice;
    std::cout << "\nIngrese el lenguaje de programacion: ";
    std::cin >> datos_indice.lenguaje_programacion;
    std::cout << "Ingrese el puntaje: ";
    std::cin >> datos_indice.puntaje;
    return datos_indice;
}

// Crear un nuevo nodo con la información recibida
// Se usa 'new' para que quede guardado en memoria dinámica
Nodo *CrearNodo(const Tiobe &informacion)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->indice = informacion;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

// Insertar un nodo dentro del árbol
void InsertarNodo(Nodo *&abb, const Tiobe &informacion)
{
    if (abb == nullptr)
    {
        abb = CrearNodo(informacion);
        return;
    }

    if (informacion.puntaje < abb->indice.puntaje)
        InsertarNodo(abb->izquierdo, informacion);
    else
        InsertarNodo(abb->derecho, informacion);
}

// Recorrido Inorden (Izquierda - Raíz - Derecha)
void RecorridoInorden(Nodo *abb)
{
    if (!abb)
        return;

    RecorridoInorden(abb->izquierdo);
    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
    RecorridoInorden(abb->derecho);
}

// Recorrido Preorden (Raíz - Izquierda - Derecha)
void RecorridoPreorden(Nodo *abb)
{
    if (!abb)
        return;

    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
    RecorridoPreorden(abb->izquierdo);
    RecorridoPreorden(abb->derecho);
}

// Recorrido Postorden (Izquierda - Derecha - Raíz)
void RecorridoPostorden(Nodo *abb)
{
    if (!abb)
        return;

    RecorridoPostorden(abb->izquierdo);
    RecorridoPostorden(abb->derecho);
    std::cout << "[" << abb->indice.puntaje << " : " << abb->indice.lenguaje_programacion << "] ";
}

// Buscar un nodo por su puntaje
void BuscarNodo(Nodo *&abb, float puntaje, Nodo *&padre)
{
    while (abb != nullptr && abb->indice.puntaje != puntaje)
    {
        padre = abb;
        if (puntaje < abb->indice.puntaje)
            abb = abb->izquierdo;
        else
            abb = abb->derecho;
    }
}

// Buscar el nodo con el menor valor (más a la izquierda)
Nodo *BuscarMenor(Nodo *abb)
{
    while (abb && abb->izquierdo != nullptr)
        abb = abb->izquierdo;
    return abb;
}

// Eliminar un nodo del árbol
void BorrarNodo(Nodo *&abb, float puntaje_borrar)
{
    Nodo *padre = nullptr;
    Nodo *aux = abb;
    BuscarNodo(aux, puntaje_borrar, padre);

    if (!aux)
        return;

    // Caso 1: nodo hoja
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
    // Caso 2: dos hijos
    else if (aux->izquierdo && aux->derecho)
    {
        Nodo *sucesor = BuscarMenor(aux->derecho);
        aux->indice = sucesor->indice;
        BorrarNodo(aux->derecho, sucesor->indice.puntaje);
    }
    // Caso 3: un solo hijo
    else
    {
        Nodo *hijo = (aux->izquierdo) ? aux->izquierdo : aux->derecho;

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
