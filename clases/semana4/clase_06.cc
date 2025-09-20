#include <iostream>

/*
========================================
         BLOQUES DE MEMORIA EN C++
========================================

📌 Memoria Estática (Static Storage)
- Contiene variables globales y estáticas.
- Se reserva ANTES de que inicie el programa y se libera al finalizar el programa.
- No se puede liberar manualmente.
- Ejemplo: 'static int x;' o variables globales.

📌 Pila (Stack)
- Contiene variables locales y parámetros de funciones.
- Se reserva automáticamente cuando una función inicia
  y se libera automáticamente al salir de la función.
- No requiere manejo manual.

📌 Montículo (Heap)
- Se usa para la memoria dinámica: se reserva manualmente
  durante la ejecución con 'new' y se libera con 'delete'.
- Es responsabilidad del programador liberar esta memoria,
  de lo contrario se produce una fuga de memoria (memory leak).

Resumen:
┌───────────────┬────────────┬───────────────┐
│ Tipo memoria  │ Reserva    │ Liberación    │
├───────────────┼────────────┼───────────────┤
│ Estática      │ automática │ automática    │
│ Stack         │ automática │ automática    │
│ Heap           │ manual      │ manual (delete) │
└───────────────┴────────────┴───────────────┘
*/

int main()
{
    // =======================
    // 📍 VARIABLES EN STACK
    // =======================
    // Estas variables se reservan en la pila (stack)
    // y se liberan automáticamente cuando termine main()
    
    int numero = 99; // Ocupa 4 bytes en stack
    int lista_numeros[5] = {1, 2, 46, 7, 8}; // Ocupa 20 bytes en stack (5*4 bytes)
    
    int* ptr_lista = lista_numeros; // Apunta al inicio del arreglo (también en stack)

    std::cout << "Direccion de 'numero' (stack): " << &numero << "\n";
    std::cout << "Direccion de 'lista_numeros' (stack): " << &lista_numeros << "\n\n";



    // ============================
    // 📍 VARIABLE EN HEAP (new)
    // ============================
    // Aquí reservamos memoria dinámica en el montículo (heap).
    // 'new' devuelve la dirección de memoria reservada.
    // Esta memoria NO se libera automáticamente.

    int* ptr = new int; // Reserva espacio para un int en heap

    if (ptr == nullptr)
    {
        // new lanza excepción si falla, pero por si acaso comprobamos:
        std::cout << "ERROR: no se pudo asignar memoria\n";
    }
    else
    {
        std::cout << "Memoria reservada en heap para 'ptr'.\n";
        std::cout << "Direccion almacenada en 'ptr' (heap): " << ptr << "\n";
        std::cout << "Direccion de 'ptr' (stack): " << &ptr << "\n\n";
    }



    // ===================================
    // RECORRIDO DE ARREGLO EN STACK
    // ===================================
    std::cout << "Direcciones de cada elemento de 'lista_numeros' (stack):\n";
    while (ptr_lista < lista_numeros + 5)
    {
        std::cout << " - " << ptr_lista << "\n";
        ptr_lista++;
    }
    std::cout << "\n";



    // ===================================
    // LIBERAR MEMORIA DEL HEAP (delete)
    // ===================================
    // Aquí liberamos la memoria que reservamos manualmente con new.
    // Esto elimina el bloque de memoria del heap.
    
    std::cout << "Liberando memoria dinámica (heap)...\n";
    delete ptr; // Libera la memoria del heap
    ptr = nullptr; // Buenas prácticas: evitar puntero colgante

    std::cout << "Memoria liberada.\n";


    std::cout << "ASignar memoria con arreglo\n";

    int *ptr_arreglo = new int[5];

    for (int i = 0; i < 5; i++)
    {
        ptr_arreglo[i] = 1;
        std::cout << &ptr_arreglo << " - "<<  ptr_arreglo[i] << std::endl;
    }
    
    delete []ptr_arreglo;

    return 0; // Aquí se liberará automáticamente la memoria del stack
}