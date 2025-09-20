#include <iostream>

void PasoPorValor(int taza);
void PasoPorPuntero(int *taza);
void PasoPorReferencia(int &taza);

int main()
{
    /* int num = 500;

    int *ptr = &num;

    //si un puntero no apunta a ninguna variable se hace que apunte a null
    int *ptrNull = nullptr;

    //cambiar el valor por medio del puntero de la varible referenciada, y cambiandolo normalmente
    *ptr = 800;
    num = 1000;

    std::cout << "\n";

    //Se obtiene la ubicacion de donde esta guardada el num = 500, vamos a obtener la misma direccion porque es te same sin utilizar puntero
    std::cout << "Dir. memoria num " << ptr << "- " << &num << "\n";
    //Se obtiene la ubicacion de donde esta guardada el puntero de la referencia
    std::cout << "Dir. memoria ptr " << &ptr << "\n";
    //se obtiene el valor de la referencia
    std::cout << "Valor de num: " << *ptr << "\n";

    std::cout << "\n";

    //caso del null
    std::cout << "Dir. memoria para ptrNull" << ptrNull << "\n";
    //Se obtiene la ubicacion de donde esta guardada el puntero de la referencia
    std::cout << "Dir. memoria ptrNull " << &ptrNull << "\n"; */

    // EJERCICIO
    int taza = 0;
    std::cout << "contenido de la taza: " << taza << "\n";                             // 0
    PasoPorValor(taza);                                                                // 100
    std::cout << "Contenido de la taza despues de paso por valor: " << taza << "\n";   // 0
    PasoPorPuntero(&taza);                                                             // 100
    std::cout << "Contenido de la taza despues de paso por puntero: " << taza << "\n"; // 100
    PasoPorReferencia(taza);
    std::cout << "Contenido de la taza despues de paso por referencia: " << taza << "\n"; // 200
    PasoPorValor(taza);                                                                // 300
    std::cout << "Contenido de la taza despues de paso por valor: " << taza << "\n";   // 200
    return 0;
}

void PasoPorValor(int taza)
{
    taza = taza + 100;
    std::cout << "Contenido de la taza: " << taza << "\n";
}

void PasoPorPuntero(int *taza)
{
    *taza = *taza + 100;
    std::cout << "Contenido de la taza: " << *taza << "\n";
}

void PasoPorReferencia(int &taza)
{
    taza = taza + 100;
    std::cout << "Contenido tazas: " << taza << "\n";
}