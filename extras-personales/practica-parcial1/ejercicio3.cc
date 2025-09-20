/*
    3. Matrices y funciones
    - Trabaja con una matriz estática de 5x5.
    - Implementa funciones que:
        - Llenen la matriz con números aleatorios.
        - Calculen la suma de cada fila y de cada columna.
        - Encuentren la fila con la mayor suma.
        - Trasponer la matriz.
*/

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

// Constantes globales
const int kRows = 5; // Número de filas
const int kCols = 5; // Número de columnas

// Función: para Llenar la matriz con números aleatorios entre 1 y 50.
void FillMatrix(int matrix[kRows][kCols])
{
    for (int i = 0; i < kRows; i++)
    {
        for (int j = 0; j < kCols; j++)
        {
            // Generamos un número aleatorio entre 1 y 50
            matrix[i][j] = rand() % 50 + 1;
        }
    }
}

// Función que imprime la matriz
void PrintMatrix(const int matrix[kRows][kCols])
{
    for (int i = 0; i < kRows; i++)
    {
        for (int j = 0; j < kCols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

// funcion para calcular la suma de cada fila y la guarda en un arreglo.
void RowSums(const int matrix[kRows][kCols], int row_sums[kRows])
{
    for (int i = 0; i < kRows; i++)
    {
        int sum = 0; // Inicializamos suma de la fila
        for (int j = 0; j < kCols; j++)
        {
            sum += matrix[i][j]; // Sumamos cada elemento de la fila
        }
        row_sums[i] = sum; // Guardamos la suma de la fila
    }
}

// Función de calcular la suma de cada columna y la guarda en un arreglo.
void ColSums(const int matrix[kRows][kCols], int col_sums[kCols])
{
    for (int j = 0; j < kCols; j++)
    {
        int sum = 0; // Inicializamos suma de la columna
        for (int i = 0; i < kRows; i++)
        {
            sum += matrix[i][j]; // Sumamos cada elemento de la columna
        }
        col_sums[j] = sum; // Guardamos la suma de la columna
    }
}

// Función que encuentra la fila con la mayor suma y devuelve su índice.
int RowWithMaxSum(const int row_sums[kRows])
{
    int max_sum = row_sums[0]; // Guardamos la primera suma como referencia
    int max_index = 0;         // Guardamos el índice de la fila

    for (int i = 1; i < kRows; i++)
    {
        if (row_sums[i] > max_sum)
        {
            max_sum = row_sums[i]; // Actualizamos la mayor suma
            max_index = i;         // Guardamos la fila correspondiente
        }
    }
    return max_index; // Retornamos la fila con mayor suma
}

// Funcion de Transpone la matriz (convierte filas en columnas)
void TransposeMatrix(int matrix[kRows][kCols])
{
    // Solo recorremos la mitad superior para no intercambiar dos veces
    for (int i = 0; i < kRows; i++)
    {
        for (int j = i + 1; j < kCols; j++)
        {
            // Intercambiamos valores [i][j] con [j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main()
{
    srand(time(0)); // Inicializamos para numeros aleatorio

    int matrix[kRows][kCols]; // Declaración de la matriz 5x5

    // Llenamos la matriz con números aleatorios
    FillMatrix(matrix);

    std::cout << "Matriz original:\n";
    PrintMatrix(matrix);
    std::cout << "\n";

    // Calculamos suma de filas
    int row_sums[kRows];
    RowSums(matrix, row_sums);
    std::cout << "Suma de cada fila:\n";
    for (int i = 0; i < kRows; i++)
    {
        std::cout << "Fila " << i << ": " << row_sums[i] << "\n";
    }
    std::cout << "\n";

    // Calculamos suma de columnas
    int col_sums[kCols];
    ColSums(matrix, col_sums);
    std::cout << "Suma de cada columna:\n";
    for (int j = 0; j < kCols; j++)
    {
        std::cout << "Columna " << j << ": " << col_sums[j] << "\n";
    }
    std::cout << "\n";

    // Encontramos la fila con mayor suma
    int max_row = RowWithMaxSum(row_sums);
    std::cout << "La fila con la mayor suma es: Fila " << max_row << " con suma = " << row_sums[max_row] << "\n\n";

    // Transponemos la matriz

    TransposeMatrix(matrix);
    std::cout << "Matriz transpuesta:\n";
    PrintMatrix(matrix);

    return 0;
}
