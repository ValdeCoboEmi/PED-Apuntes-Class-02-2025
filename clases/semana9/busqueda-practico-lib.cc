#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

struct Estudiante
{
    string nombre;
    int anioNacimiento;
    int calcularEdad(int anioActual) const
    {
        return anioActual - anioNacimiento;
    }
};

// --- Funciones ---
Estudiante agregarEstudianteManual(const string &nombre, int anioNacimiento)
{
    Estudiante e;
    e.nombre = nombre;
    e.anioNacimiento = anioNacimiento;
    return e;
}

void ordenarPorEdad(list<Estudiante> &lista, int anioActual)
{
    lista.sort([anioActual](const Estudiante &a, const Estudiante &b)
               { return a.calcularEdad(anioActual) > b.calcularEdad(anioActual); });
}

void buscarPorNombre(list<Estudiante> &lista, const string &nombreBuscado, int anioActual)
{
    auto cmp = [](const Estudiante &a, const Estudiante &b)
    {
        return a.nombre < b.nombre;
    };
    lista.sort(cmp);

    Estudiante clave{nombreBuscado, 0};
    auto it = lower_bound(lista.begin(), lista.end(), clave, cmp);

    if (it != lista.end() && it->nombre == nombreBuscado)
    {
        cout << "Coincidencias encontradas para \"" << nombreBuscado << "\":\n";
        for (auto jt = it; jt != lista.end() && jt->nombre == nombreBuscado; ++jt)
        {
            cout << " - Nombre: " << jt->nombre
                 << " | Año de nacimiento: " << jt->anioNacimiento
                 << " | Edad: " << jt->calcularEdad(anioActual) << " años\n";
        }
        cout << endl;
    }
    else
    {
        cout << "No se encontró el estudiante \"" << nombreBuscado << "\".\n\n";
    }
}

void mostrarEstudiantes(const list<Estudiante> &lista, int anioActual)
{
    cout << "----- LISTA DE ESTUDIANTES -----\n";
    for (const auto &e : lista)
    {
        cout << "Nombre: " << e.nombre
             << " | Año de nacimiento: " << e.anioNacimiento
             << " | Edad: " << e.calcularEdad(anioActual) << " años\n";
    }
    cout << "--------------------------------\n\n";
}

int main()
{
    list<Estudiante> estudiantes;
    int anioActual = 2025;

    // Agregamos estudiantes directamente
    estudiantes.push_back(agregarEstudianteManual("Bob", 2002));
    estudiantes.push_back(agregarEstudianteManual("Carlo", 2000));
    estudiantes.push_back(agregarEstudianteManual("Beatriz", 2004));
    estudiantes.push_back(agregarEstudianteManual("Ana", 2003));

    // Mostramos la lista original
    cout << "Lista original:\n";
    mostrarEstudiantes(estudiantes, anioActual);

    // Ordenamos por edad
    ordenarPorEdad(estudiantes, anioActual);
    cout << "Después de ordenar por edad (de mayor a menor):\n";
    mostrarEstudiantes(estudiantes, anioActual);

    // Buscamos por nombre usando lower_bound
    cout << "Buscando a 'Ana'...\n";
    buscarPorNombre(estudiantes, "Ana", anioActual);

    cout << "Buscando a 'Luis'...\n";
    buscarPorNombre(estudiantes, "Luis", anioActual);

    return 0;
}