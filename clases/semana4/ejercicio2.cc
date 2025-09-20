#include <iostream>

/*
    Escribir un programa que solicite los precios de n cantidad de productos. Almacenados en un arreglo (float)
    los sume y obtenga el promedio:

    a- utilizarr arreglo  y los operadores de new/delete
    b. solicitar al usuario los datos (precio)
    c. mostrar el resultado del promedio
*/

void SolicitarPrecios(float *arreglo_precio, int cantidad);

int main()
{
    int cantidad = 6;
    float prom = 0;
    float *arreglo_precio = new float[cantidad];

    std::cout << "Ingrese la cantidad que quiere ingresar: ";
    std::cin >> cantidad;

    SolicitarPrecios(arreglo_precio, cantidad);

    std::cout << "Resultados: \n";

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "Precio del producto :" << *(arreglo_precio + i) << " - En el dir memoria: " << arreglo_precio + i << "\n";
        prom += *(arreglo_precio + i);
    }

    std::cout << "El promedio de los producto es: " << (prom/cantidad) << "\n";

    delete []arreglo_precio;
    return 0;
}

void SolicitarPrecios(float *arreglo_precio, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "Ingrese el " << i + 1 << " precio del producto : ";
        std::cin >> *(arreglo_precio + i);
    }
}