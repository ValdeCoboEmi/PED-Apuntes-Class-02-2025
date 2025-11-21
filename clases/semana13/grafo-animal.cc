#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using Grafo = std::unordered_map<std::string, std::list<std::string>>;

// ------------------------- PROTOTIPOS -------------------------
void AgregarAnimal(Grafo &g, const std::string &animal);
void AgregarConexion(Grafo &g, const std::string &a, const std::string &b);
void EliminarAnimal(Grafo &g, const std::string &animal);
void EliminarConexion(Grafo &g, const std::string &a, const std::string &b);
bool BuscarAnimal(const Grafo &g, const std::string &animal);
void ImprimirGrafo(const Grafo &g);
std::vector<std::string> CaminoMasCorto(const Grafo &g, const std::string &inicio, const std::string &fin);
void UnirGrafos(Grafo &destino, const Grafo &origen);
void Menu();

// --------------------------------------------------------------
int main()
{
    Menu();
    return 0;
}

// --------------------------------------------------------------
// AGREGA UN ANIMAL (NODO)
void AgregarAnimal(Grafo &g, const std::string &animal)
{
    if (!g.count(animal))
    {
        g[animal] = {};
        std::cout << "Animal agregado correctamente.\n";
    }
    else
    {
        std::cout << "El animal ya existe.\n";
    }
}

// --------------------------------------------------------------
// AGREGA UNA CONEXIÓN (ARISTA)
void AgregarConexion(Grafo &g, const std::string &a, const std::string &b)
{
    if (!g.count(a))
        g[a] = {};
    if (!g.count(b))
        g[b] = {};

    g[a].push_back(b); // Grafo dirigido
    std::cout << "Conexion agregada: " << a << " -> " << b << "\n";
}

// --------------------------------------------------------------
// ELIMINAR ANIMAL
void EliminarAnimal(Grafo &g, const std::string &animal)
{
    if (!g.count(animal))
    {
        std::cout << "El animal no existe.\n";
        return;
    }

    g.erase(animal); // quita nodo

    // borrar conexiones que apuntaban a él
    for (auto &par : g)
    {
        par.second.remove(animal);
    }

    std::cout << "Animal eliminado correctamente.\n";
}

// --------------------------------------------------------------
// ELIMINAR CONEXIÓN
void EliminarConexion(Grafo &g, const std::string &a, const std::string &b)
{
    if (!g.count(a))
    {
        std::cout << "No existe el animal origen.\n";
        return;
    }
    g[a].remove(b);
    std::cout << "Conexion eliminada.\n";
}

// --------------------------------------------------------------
// BUSCAR SI UN ANIMAL EXISTE
bool BuscarAnimal(const Grafo &g, const std::string &animal)
{
    return g.count(animal) > 0;
}

// --------------------------------------------------------------
// IMPRIMIR GRAFO
void ImprimirGrafo(const Grafo &g)
{
    for (const auto &par : g)
    {
        std::cout << par.first << " -> ";
        for (auto &dest : par.second)
        {
            std::cout << dest << " ";
        }
        std::cout << "\n";
    }
}

// --------------------------------------------------------------
// BFS PARA ENCONTRAR CAMINO MÁS CORTO
std::vector<std::string> CaminoMasCorto(const Grafo &g, const std::string &inicio, const std::string &fin)
{
    if (!g.count(inicio) || !g.count(fin))
    {
        return {};
    }

    std::queue<std::string> q;
    std::unordered_map<std::string, std::string> padre;
    std::unordered_set<std::string> visitado;

    q.push(inicio);
    visitado.insert(inicio);

    while (!q.empty())
    {
        std::string actual = q.front();
        q.pop();

        if (actual == fin)
            break;

        for (const auto &vecino : g.at(actual))
        {
            if (!visitado.count(vecino))
            {
                visitado.insert(vecino);
                padre[vecino] = actual;
                q.push(vecino);
            }
        }
    }

    if (!padre.count(fin))
    {
        return {}; // No hay camino
    }

    std::vector<std::string> camino;
    std::string nodo = fin;

    while (nodo != inicio)
    {
        camino.push_back(nodo);
        nodo = padre[nodo];
    }
    camino.push_back(inicio);

    std::reverse(camino.begin(), camino.end());
    return camino;
}

// --------------------------------------------------------------
// UNIR DOS GRAFOS
void UnirGrafos(Grafo &destino, const Grafo &origen)
{
    for (auto &par : origen)
    {
        for (auto &dest : par.second)
        {
            destino[par.first].push_back(dest);
        }
    }
}

// --------------------------------------------------------------
// MENÚ PRINCIPAL
void Menu()
{
    Grafo g1, g2;
    int opcion;

    do
    {
        std::cout << "\n========= MENU GRAFO DE ANIMALES =========\n";
        std::cout << "1. Agregar animal\n";
        std::cout << "2. Agregar conexion\n";
        std::cout << "3. Eliminar animal\n";
        std::cout << "4. Eliminar conexion\n";
        std::cout << "5. Buscar animal\n";
        std::cout << "6. Camino mas corto entre dos animales\n";
        std::cout << "7. Imprimir grafo\n";
        std::cout << "8. Unir grafos (g2 -> g1)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione opcion: ";
        std::cin >> opcion;

        std::string a, b;

        switch (opcion)
        {
        case 1:
            std::cout << "Nombre del animal: ";
            std::cin >> a;
            AgregarAnimal(g1, a);
            break;

        case 2:
            std::cout << "Animal origen: ";
            std::cin >> a;
            std::cout << "Animal destino: ";
            std::cin >> b;
            AgregarConexion(g1, a, b);
            break;

        case 3:
            std::cout << "Animal a eliminar: ";
            std::cin >> a;
            EliminarAnimal(g1, a);
            break;

        case 4:
            std::cout << "Animal origen: ";
            std::cin >> a;
            std::cout << "Animal destino: ";
            std::cin >> b;
            EliminarConexion(g1, a, b);
            break;

        case 5:
            std::cout << "Animal a buscar: ";
            std::cin >> a;
            std::cout << (BuscarAnimal(g1, a) ? "Existe\n" : "No existe\n");
            break;

        case 6:
        {
            std::cout << "Inicio: ";
            std::cin >> a;
            std::cout << "Fin: ";
            std::cin >> b;
            auto camino = CaminoMasCorto(g1, a, b);
            if (camino.empty())
            {
                std::cout << "No hay camino.\n";
            }
            else
            {
                std::cout << "Camino mas corto: ";
                for (auto &n : camino)
                    std::cout << n << " ";
                std::cout << "\n";
            }
            break;
        }

        case 7:
            ImprimirGrafo(g1);
            break;

        case 8:
            std::cout << "Se unira g2 -> g1 (primero llena g2 en el codigo si deseas).\n";
            UnirGrafos(g1, g2);
            break;

        case 0:
            std::cout << "Saliendo...\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);
}
