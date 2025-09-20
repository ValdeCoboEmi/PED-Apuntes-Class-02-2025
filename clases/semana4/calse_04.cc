#include <iostream>

int main()
{
    // declarar un arreglo

    int arreglo_numeros[3] = {2, 200, 1};

    int *ptr = arreglo_numeros;

    std::cout << "Peso tipo de dato int: " << sizeof(int) << "\n";

    // Direccion_elemento = direccion_arreglo + (indice * sizeof(tipo_dato))
    // 0x9aa7bffd10 + (1 * 4 bytes)
    //  0x9aa7bffd10 + 4
    //  0x9aa7bffd14

    std::cout << "Dir. memoria arreglo_num, sin referencia: " << arreglo_numeros << "\n";
    std::cout << "Dir. memoria arreglo_num, del muy arreglo sin indicar que indice: " << &arreglo_numeros << "\n";
    std::cout << "Dir. memoria arreglo_num[0]: " << &arreglo_numeros[0] << "\n";
    std::cout << "Valor: " << *(arreglo_numeros) << "\n";
    std::cout << "Dir. memoria arreglo_num[1]: " << &arreglo_numeros[1] << "\n";
    std::cout << "Valor: " << *(arreglo_numeros + 1) << "\n";
    std::cout << "Dir. memoria arreglo_num[2]: " << &arreglo_numeros[2] << "\n";
    std::cout << "Valor: " << *(arreglo_numeros + 2) << "\n";

    std:: cout << "\n";
    std::cout << "Dir. memoria arreglo_num[2] con puntero: " << ptr + 2 << "\n";
    std::cout << "Valor: " << *(ptr + 2) << "\n";

    return 0;
}