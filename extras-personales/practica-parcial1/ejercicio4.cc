#include <iostream>
#include <cstring>

// =====================================================
// 4. Cadenas con funciones y arrays
// Trabaja con char[] (no con string).
// - Verificar si es un palíndromo.
// - Convertir todas las letras a mayúsculas.
// - Contar cuántas vocales y consonantes tiene.
// =====================================================

// Verifica si una cadena es palíndromo comparando extremos.
bool EsPalindromo(const char cadena[])
{
    int i = 0;
    int j = strlen(cadena) - 1;
    while (i < j)
    {
        if (cadena[i] != cadena[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Convierte cada letra a mayúscula restando 32 en ASCII.
void ConvertirMayusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] -= 32;
        }
    }
}

// Recorre la cadena contando vocales y consonantes.
void ContarVocalesConsonantes(const char cadena[], int &vocales, int &consonantes)
{
    vocales = 0;
    consonantes = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char c = tolower(cadena[i]);
        if (c >= 'a' && c <= 'z')
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vocales++;
            }
            else
            {
                consonantes++;
            }
        }
    }
}

int main()
{
    char texto[50];
    std::cout << "Ingrese una palabra: ";
    std::cin >> texto;

    if (EsPalindromo(texto))
    {
        std::cout << "Es palindromo.\n";
    }
    else
    {
        std::cout << "No es palindromo.\n";
    }

    ConvertirMayusculas(texto);
    std::cout << "En mayusculas: " << texto << "\n";

    int v, c;
    ContarVocalesConsonantes(texto, v, c);
    std::cout << "Vocales: " << v << " Consonantes: " << c << "\n";

    return 0;
}
