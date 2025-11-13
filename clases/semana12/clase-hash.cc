// Ejercicio donde vamos a ver en donde se va a guardar
// en la tabla del hash con el nombre, donde se ocupa la tabla ascii:
// Emiliano - 69 + 109 + 105 + 108 + 105 + 97 + 110 + 111 = 814 / 7 = 116.28, Modulo 2

/* Tabla hash donde se guardan valor_asciis como si fuera una base de valor_asciis
y de ahi lo otro que tenes es que si en dado caso se tenga que guardar en el mismo
espacio se hace un lista ya sea lineal o doblemente enlazada, esto en el sentido donde unicamente sirve
para tener como un id y saber donde lo esta guardando */

#include <iostream>
#include <windows.h>

// TAMAÑO DE LA TABLA (DEL ARREGLO)
const int kdimension = 7;

// Estructura para guardar la palabra y su valor ASCII
struct Registro
{
    std::string palabra;
    int valor_ascii;
};

// Nodo doblemente enlazado
struct Nodo
{
    Registro registro;
    Nodo *anterior;
    Nodo *siguiente;
};

// Tabla hash
Nodo *tabla[kdimension] = {nullptr};

// Funcion para solicar datos
Registro SolicitarDatos();

// Prototipos
void Agregar(Registro r);
int FHash(int);
int ConversionASCII(std::string);
Nodo *Buscar(std::string palabra, int clave);
void Buscar(std::string palabra);
void Eliminar(std::string palabra);
void Imprimir();

// --- FUNCIÓN PRINCIPAL ---
int main()
{
    // Configurar la consola para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    /*
    std::string palabra = "Emliano";
    std::cout << "Palabra: " << palabra << " | Conversion ascii: " << ConversionASCII(palabra)
              << " | Donde se va a guardar en la tabla: " << FHash(ConversionASCII(palabra)) << "\n";


    std::string palabra0 = "Emliano";
    std::string palabra1 = "Sofia";
    std::string palabra2 = "Sofia";
    std::string palabra3 = "Andres";
    Agregar(palabra0);
    Agregar(palabra1);
    Agregar(palabra2);
    Agregar(palabra3);
    Imprimir();
    */

    int opcion;
    std::string palabra;
    int valor_ascii;

    do
    {
        std::cout << "\n===== MENU TABLA HASH =====\n";
        std::cout << "1. Agregar palabra\n";
        std::cout << "2. Buscar palabra\n";
        std::cout << "3. Eliminar palabra\n";
        std::cout << "4. Imprimir tabla\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion)
        {
        case 1:
            Agregar(SolicitarDatos());
            break;

        case 2:
            std::cout << "Ingrese la palabra a buscar: ";
            std::getline(std::cin, palabra);
            Buscar(palabra);
            break;

        case 3:
            std::cout << "Ingrese la palabra a eliminar: ";
            std::getline(std::cin, palabra);
            Eliminar(palabra);
            break;

        case 4:
            Imprimir();
            break;

        case 0:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}

Registro SolicitarDatos()
{
    Registro r;
    std::cout << "Ingrese la palabra a agregar: ";
    std::getline(std::cin, r.palabra);
    return r;
}

// --- CONVERSIÓN A ASCII ---
int ConversionASCII(std::string palabra)
{
    int total_ascii = 0;
    for (auto &&i : palabra)
        total_ascii += static_cast<int>(i);

    return total_ascii;
}

// --- FUNCIÓN HASH --- donde retorna el valor del hash y con ese resultado representa el indice de donde se va a guardar
// en el arreglo
int FHash(int valor_ascii)
{
    return valor_ascii % kdimension;
}

// --- AGREGAR PALABRA ---
void Agregar(Registro r)
{
    Nodo *nuevoNodo = new Nodo;
    r.valor_ascii = ConversionASCII(r.palabra);
    int clave = FHash(r.valor_ascii);

    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];

    // Condiciones cuando hay datos, donde se va empujando como si fuera una pila el que va entrando es el primero
    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;

    // Cuando no hay datos y con datos
    tabla[clave] = nuevoNodo;

    std::cout << "Palabra agregada en índice " << clave << " con valor ASCII " << r.valor_ascii << "\n";
}

// --- BUSCAR POR VALOR ASCII ---
Nodo *Buscar(std::string palabra, int clave)
{
    Nodo *actual = tabla[clave];
    while (actual)
    {
        if (actual->registro.palabra == palabra)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// --- BUSCAR PALABRA ---
void Buscar(std::string palabra)
{
    int clave = FHash(ConversionASCII(palabra));
    Nodo *nodo = Buscar(palabra, clave);
    if (nodo)
    {
        std::cout << "Registro encontrado → Posición: " << clave
                  << " | Palabra: " << nodo->registro.palabra
                  << " | Valor ASCII: " << nodo->registro.valor_ascii
                  << std::endl;
    }
    else
    {
        std::cout << "Registro no encontrado\n";
    }
}

// --- ELIMINAR PALABRA ---
void Eliminar(std::string palabra)
{
    int clave = FHash(ConversionASCII(palabra));
    Nodo *nodo = Buscar(palabra, clave);

    if (nodo)
    {
        std::cout << "Eliminando registro → Valor ASCII: "
                  << nodo->registro.valor_ascii << std::endl;

        if (nodo->siguiente)
            nodo->siguiente->anterior = nodo->anterior;

        if (nodo->anterior)
            nodo->anterior->siguiente = nodo->siguiente;
        else
            tabla[clave] = nodo->siguiente;

        delete nodo;
    }
    else
    {
        std::cout << "Registro no encontrado\n";
    }
}

// --- IMPRIMIR TABLA COMPLETA ---
void Imprimir()
{
    std::cout << "\n===== CONTENIDO DE LA TABLA HASH =====\n";
    for (int i = 0; i < kdimension; i++)
    {
        Nodo *temp = tabla[i];
        if (temp)
            std::cout << "\n[Índice " << i << "]\n";

        while (temp)
        {
            std::cout << "  Nodo: " << temp
                      << " | Anterior: " << temp->anterior
                      << " | Palabra: " << temp->registro.palabra
                      << " | Valor ASCII: " << temp->registro.valor_ascii
                      << std::endl;
            temp = temp->siguiente;
        }
    }
}
