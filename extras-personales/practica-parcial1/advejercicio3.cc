#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==========================================================
// 3. Matriz dinámica con operaciones
// - Crear matriz cuadrada dinámica n x n
// - Funciones: llenar aleatorio, suma diagonal principal y secundaria, transponer, liberar memoria
// ==========================================================

void LlenarMatriz(int **mat, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % 50 + 1;
}

void ImprimirMatriz(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int SumaDiagonalPrincipal(int **mat, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += mat[i][i];
    return suma;
}

int SumaDiagonalSecundaria(int **mat, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += mat[i][n - 1 - i];
    return suma;
}

void TransponerMatriz(int **mat, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
}

int main()
{
    srand(time(0));
    int n;
    cout << "Dimension de la matriz: ";
    cin >> n;

    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[n];

    LlenarMatriz(mat, n);
    cout << "Matriz generada:\n";
    ImprimirMatriz(mat, n);

    cout << "Suma diagonal principal: " << SumaDiagonalPrincipal(mat, n) << endl;
    cout << "Suma diagonal secundaria: " << SumaDiagonalSecundaria(mat, n) << endl;

    TransponerMatriz(mat, n);
    cout << "Matriz transpuesta:\n";
    ImprimirMatriz(mat, n);

    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
    return 0;
}
