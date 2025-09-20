#include <iostream>
#include <cstdlib>
#include <ctime>

// =====================================================
// 12. Matrices con punteros dobles
// - Crear matriz dinámica n x m.
// - Llenarla con números aleatorios entre 1 y 50.
// - Calcular suma de cada fila.
// - Liberar memoria al final.
// =====================================================

void MatrizDinamica(int n, int m)
{
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = rand() % 50 + 1;
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        int suma = 0;
        for (int j = 0; j < m; j++)
        {
            suma += mat[i][j];
        }
        std::cout << "Suma fila " << i << ": " << suma << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int n, m;
    std::cout << "Filas: ";
    std::cin >> n;
    std::cout << "Columnas: ";
    std::cin >> m;

    MatrizDinamica(n, m);

    return 0;
}
