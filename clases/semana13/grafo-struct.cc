#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

// ----------------------- STRUCT DE ANIMAL -----------------------
struct Animal {
    std::string nombreComun;
    std::string nombreCientifico;
    int tiempoVida;
};

// Grafo: ID del animal → lista de IDs conectados
using Grafo = std::unordered_map<int, std::list<int>>;

// Almacén de Animales por ID
using AlmacenAnimales = std::unordered_map<int, Animal>;

// ----------------------- PROTOTIPOS -----------------------------
void AgregarAnimal(AlmacenAnimales &almacen, int id);
void AgregarConexion(Grafo &g, int a, int b);
void EliminarAnimal(Grafo &g, AlmacenAnimales &almacen, int id);
void EliminarConexion(Grafo &g, int a, int b);
bool BuscarAnimal(const AlmacenAnimales &almacen, int id);
void ImprimirGrafo(const Grafo &g, const AlmacenAnimales &almacen);
std::vector<int> CaminoMasCorto(const Grafo &g, int inicio, int fin);
void UnirGrafos(Grafo &dest, const Grafo &src);
void Menu();

// ----------------------------------------------------------------
int main() {
    Menu();
    return 0;
}

// -------------------- AGREGAR ANIMAL ----------------------------
void AgregarAnimal(AlmacenAnimales &almacen, int id) {
    if (almacen.count(id)) {
        std::cout << "Ese ID ya existe.\n";
        return;
    }

    Animal a;
    std::cout << "Nombre comun: ";
    std::cin.ignore();
    std::getline(std::cin, a.nombreComun);

    std::cout << "Nombre cientifico: ";
    std::getline(std::cin, a.nombreCientifico);

    std::cout << "Tiempo estimado de vida (años): ";
    std::cin >> a.tiempoVida;

    almacen[id] = a;

    std::cout << "Animal agregado correctamente.\n";
}

// -------------------- AGREGAR CONEXIÓN --------------------------
void AgregarConexion(Grafo &g, int a, int b) {
    g[a].push_back(b);
    std::cout << "Conexion agregada: " << a << " -> " << b << "\n";
}

// -------------------- ELIMINAR ANIMAL ---------------------------
void EliminarAnimal(Grafo &g, AlmacenAnimales &almacen, int id) {
    if (!almacen.count(id)) {
        std::cout << "Ese ID no existe.\n";
        return;
    }

    almacen.erase(id);
    g.erase(id);

    for (auto &par : g)
        par.second.remove(id);

    std::cout << "Animal eliminado correctamente.\n";
}

// -------------------- ELIMINAR CONEXIÓN -------------------------
void EliminarConexion(Grafo &g, int a, int b) {
    g[a].remove(b);
    std::cout << "Conexion eliminada.\n";
}

// -------------------- BUSCAR ANIMAL -----------------------------
bool BuscarAnimal(const AlmacenAnimales &almacen, int id) {
    return almacen.count(id);
}

// -------------------- IMPRIMIR GRAFO ----------------------------
void ImprimirGrafo(const Grafo &g, const AlmacenAnimales &almacen) {
    for (const auto &par : g) {
        int id = par.first;

        if (almacen.count(id)) {
            const Animal &a = almacen.at(id);
            std::cout << "\nID " << id << ": " << a.nombreComun
                      << " (" << a.nombreCientifico
                      << ", vida: " << a.tiempoVida << " años)\n";
        } else {
            std::cout << "\nID " << id << ": <sin informacion>\n";
        }

        std::cout << "  Conectado con: ";
        for (int dest : par.second)
            std::cout << dest << " ";
        std::cout << "\n";
    }
}

// -------------------- CAMINO MÁS CORTO (BFS) --------------------
std::vector<int> CaminoMasCorto(const Grafo &g, int inicio, int fin) {
    std::queue<int> q;
    std::unordered_map<int, int> padre;
    std::unordered_map<int, bool> visitado;

    q.push(inicio);
    visitado[inicio] = true;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();

        if (actual == fin) break;

        for (int vecino : g.at(actual)) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                padre[vecino] = actual;
                q.push(vecino);
            }
        }
    }

    if (!padre.count(fin)) return {};

    std::vector<int> camino;
    int nodo = fin;

    while (nodo != inicio) {
        camino.push_back(nodo);
        nodo = padre[nodo];
    }
    camino.push_back(inicio);

    std::reverse(camino.begin(), camino.end());
    return camino;
}

// -------------------- UNIR GRAFOS -------------------------------
void UnirGrafos(Grafo &dest, const Grafo &src) {
    for (auto &par : src)
        for (int destNode : par.second)
            dest[par.first].push_back(destNode);
}

// --------------------------- MENÚ -------------------------------
void Menu() {
    Grafo g1, g2;
    AlmacenAnimales almacen1, almacen2;

    int opcion;

    do {
        std::cout << "\n===== MENU GRAFO DE ANIMALES =====\n";
        std::cout << "1. Agregar animal\n";
        std::cout << "2. Agregar conexion\n";
        std::cout << "3. Eliminar animal\n";
        std::cout << "4. Eliminar conexion\n";
        std::cout << "5. Buscar animal\n";
        std::cout << "6. Camino mas corto\n";
        std::cout << "7. Imprimir grafo\n";
        std::cout << "8. Unir grafos (g2 → g1)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione opcion: ";
        std::cin >> opcion;

        int id1, id2;

        switch (opcion) {
            case 1:
                std::cout << "ID del animal: ";
                std::cin >> id1;
                AgregarAnimal(almacen1, id1);
                break;

            case 2:
                std::cout << "ID origen: ";
                std::cin >> id1;
                std::cout << "ID destino: ";
                std::cin >> id2;
                AgregarConexion(g1, id1, id2);
                break;

            case 3:
                std::cout << "ID del animal a eliminar: ";
                std::cin >> id1;
                EliminarAnimal(g1, almacen1, id1);
                break;

            case 4:
                std::cout << "ID origen: ";
                std::cin >> id1;
                std::cout << "ID destino: ";
                std::cin >> id2;
                EliminarConexion(g1, id1, id2);
                break;

            case 5:
                std::cout << "ID a buscar: ";
                std::cin >> id1;
                std::cout << (BuscarAnimal(almacen1, id1) ? "Existe\n" : "No existe\n");
                break;

            case 6: {
                std::cout << "Inicio: ";
                std::cin >> id1;
                std::cout << "Fin: ";
                std::cin >> id2;

                auto path = CaminoMasCorto(g1, id1, id2);
                if (path.empty())
                    std::cout << "No hay camino.\n";
                else {
                    std::cout << "Camino mas corto: ";
                    for (int n : path) std::cout << n << " ";
                    std::cout << "\n";
                }
                break;
            }

            case 7:
                ImprimirGrafo(g1, almacen1);
                break;

            case 8:
                UnirGrafos(g1, g2);
                std::cout << "Grafos unidos.\n";
                break;

            case 0:
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);
}
