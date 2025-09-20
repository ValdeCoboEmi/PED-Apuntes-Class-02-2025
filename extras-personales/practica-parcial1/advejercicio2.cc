#include <iostream>
#include <cstring>

using namespace std;

// ==========================================================
// 2. Agenda de contactos
// - Struct Contacto: nombre, telefono, correo
// - Uso de puntero a puntero (Contacto**) para lista dinámica
// - Funciones: agregar, mostrar, buscar por nombre, eliminar contacto
// ==========================================================

struct Contacto
{
    char nombre[50];
    char telefono[20];
    char correo[50];
};

// Mostrar todos los contactos
void MostrarContactos(Contacto **lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << lista[i]->nombre << ", " << lista[i]->telefono << ", " << lista[i]->correo << endl;
    }
}

// Buscar contacto por nombre
int BuscarContacto(Contacto **lista, int n, const char *nombre)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(lista[i]->nombre, nombre) == 0)
            return i;
    }
    return -1;
}

// Agregar contacto al final
Contacto **AgregarContacto(Contacto **lista, int &n, Contacto nuevo)
{
    Contacto **temp = new Contacto *[n + 1];
    for (int i = 0; i < n; i++)
        temp[i] = lista[i];
    temp[n] = new Contacto;
    *temp[n] = nuevo;
    n++;
    delete[] lista;
    return temp;
}

// Eliminar contacto por índice
Contacto **EliminarContacto(Contacto **lista, int &n, int idx)
{
    if (idx < 0 || idx >= n)
        return lista;
    delete lista[idx];
    for (int i = idx; i < n - 1; i++)
    {
        lista[i] = lista[i + 1];
    }
    n--;
    Contacto **temp = new Contacto *[n];
    for (int i = 0; i < n; i++)
        temp[i] = lista[i];
    delete[] lista;
    return temp;
}

int main()
{
    int n = 0;
    Contacto **lista = nullptr;
    char opcion;

    do
    {
        cout << "\nOpciones: A=Agregar, M=Mostrar, B=Buscar, E=Eliminar, S=Salir: ";
        cin >> opcion;
        if (opcion == 'A' || opcion == 'a')
        {
            Contacto nuevo;
            cout << "Nombre: ";
            cin >> nuevo.nombre;
            cout << "Telefono: ";
            cin >> nuevo.telefono;
            cout << "Correo: ";
            cin >> nuevo.correo;
            lista = AgregarContacto(lista, n, nuevo);
        }
        else if (opcion == 'M' || opcion == 'm')
        {
            MostrarContactos(lista, n);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            char nombre[50];
            cout << "Nombre a buscar: ";
            cin >> nombre;
            int idx = BuscarContacto(lista, n, nombre);
            if (idx != -1)
            {
                cout << "Contacto encontrado: " << lista[idx]->nombre << ", " << lista[idx]->telefono << ", " << lista[idx]->correo << endl;
            }
            else
            {
                cout << "No encontrado.\n";
            }
        }
        else if (opcion == 'E' || opcion == 'e')
        {
            char nombre[50];
            cout << "Nombre a eliminar: ";
            cin >> nombre;
            int idx = BuscarContacto(lista, n, nombre);
            lista = EliminarContacto(lista, n, idx);
        }
    } while (opcion != 'S' && opcion != 's');

    for (int i = 0; i < n; i++)
        delete lista[i];
    delete[] lista;

    return 0;
}
