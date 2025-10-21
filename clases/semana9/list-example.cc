#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Declaramos una lista de enteros
    list<int> numeros;

    // Agregamos elementos
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_front(5);

    cout << "Lista inicial: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // Insertar un elemento en una posición específica
    auto it = numeros.begin();
    ++it;                   // avanzamos una posición
    numeros.insert(it, 15); // insertamos 15 después del primer elemento

    cout << "Después de insertar 15: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // Eliminar elementos
    numeros.remove(20); // elimina el número 20
    cout << "Después de eliminar 20: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // Ordenar y revertir la lista
    numeros.sort();
    numeros.reverse();

    cout << "Lista ordenada y luego invertida: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // Tamaño y extremos
    cout << "Primer elemento: " << numeros.front() << endl;
    cout << "Último elemento: " << numeros.back() << endl;
    cout << "Total de elementos: " << numeros.size() << endl;

    // Vaciar la lista
    numeros.clear();
    if (numeros.empty())
    {
        cout << "La lista está vacía." << endl;
    }

    return 0;
}