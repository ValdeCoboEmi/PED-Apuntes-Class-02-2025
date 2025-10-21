#include <algorithm>
#include <iostream>

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 22;
    bool found = std::binary_search(arr, arr + n, key);

    if (found)
        std::cout << "Elemento " << key << " encontrado en el arreglo.\n";
    else
        std::cout << "Elemento " << key << " no encontrado.\n";

    return 0;
}