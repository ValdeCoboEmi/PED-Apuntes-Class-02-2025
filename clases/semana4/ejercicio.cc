/// EJEMPLO DE SALIDA
/*
    Valor: 10 Direccion:
    Valor: 20 Direccion:
    Valor: 30 Direccion:
    Valor: 40 Direccion:
    Valor: 50 Direccion:
    Suma total: 150

Realizarlo de estas dos formas
    - Usando indices, implementar el recorrido utilizando un ciclo for, sin emplear
    punteros

    - Usando punteros, implementar el recorrido un puntero y un ciclo while,
    sin hacer uso de incides, *(ptr + _)
*/

#include <iostream>

int main()
{
    int arreglo_nums[5] = {10, 20, 30, 40, 50};
    int *ptr = arreglo_nums;
    int sumSinPuntero = 0, sumConPuntero = 0;
    int j = 0;

    std::cout << "Sin puntero utilizando indices y for \n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Valor: " << arreglo_nums[i] << " Direccion: " << &arreglo_nums[i] << std::endl;
        sumSinPuntero += arreglo_nums[i];
    }
    std::cout << "Suma total: " << sumSinPuntero;

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Con puntero, sin indice y con while \n";
    while (j < 5)
    {
        std::cout << "Valor: " << *(ptr + j) << " Direccion: " << ptr + j << std::endl;
        sumConPuntero += *(ptr + j);
        j++;
    }
    std::cout << "Suma total: " << sumConPuntero;

    return 0;
}
