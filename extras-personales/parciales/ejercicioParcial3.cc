#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// =======================================================
//                STRUCT PLAYER
// =======================================================
struct Player
{
    int id;
    string name;
    int level;
    string clas;
    int power;

    // Permite que set<Player> ordene automáticamente por ID
    bool operator<(const Player &other) const
    {
        return id < other.id;
    }
};

// =======================================================
//           PROTOTIPOS DE FUNCIONES
// =======================================================
void AddPlayer(set<Player> *players,
               unordered_map<int, Player> *fastAccess,
               map<string, set<int>> *classMap);

void RemovePlayer(set<Player> *players,
                  unordered_map<int, Player> *fastAccess,
                  map<string, set<int>> *classMap);

void UpdatePlayer(set<Player> *players,
                  unordered_map<int, Player> *fastAccess,
                  map<string, set<int>> *classMap);

void ShowPlayers(const set<Player> &players);

void FilterByPower(const set<Player> &players);

void ShowTop3(const set<Player> &players);

void SearchLevel(const set<Player> &players);

// =======================================================
//            AGREGAR NUEVO JUGADOR
// =======================================================
void AddPlayer(set<Player> *players,
               unordered_map<int, Player> *fastAccess,
               map<string, set<int>> *classMap)
{
    Player p;

    cout << "\n--- Agregar jugador ---\n";
    cout << "ID: ";
    cin >> p.id;

    // Verificar si el ID ya existe
    if (fastAccess->count(p.id))
    {
        cout << "ERROR: Ya existe un jugador con ese ID.\n";
        return;
    }

    cout << "Nombre: ";
    cin >> p.name;
    cout << "Nivel: ";
    cin >> p.level;
    cout << "Clase: ";
    cin >> p.clas;
    cout << "Poder: ";
    cin >> p.power;

    // Insertar en las estructuras
    players->insert(p);
    (*fastAccess)[p.id] = p;
    (*classMap)[p.clas].insert(p.id);

    cout << "Jugador agregado exitosamente.\n";
}

// =======================================================
//            ELIMINAR JUGADOR POR ID
// =======================================================
void RemovePlayer(set<Player> *players,
                  unordered_map<int, Player> *fastAccess,
                  map<string, set<int>> *classMap)
{
    cout << "\n--- Eliminar jugador ---\n";
    int id;
    cout << "Ingrese ID: ";
    cin >> id;

    if (!fastAccess->count(id))
    {
        cout << "Jugador no encontrado.\n";
        return;
    }

    // Obtener el jugador antes de eliminarlo
    Player p = (*fastAccess)[id];

    // Eliminar de todas las estructuras
    classMap->at(p.clas).erase(p.id);
    fastAccess->erase(id);
    players->erase(p);

    cout << "Jugador eliminado correctamente.\n";
}

// =======================================================
//               ACTUALIZAR JUGADOR
// =======================================================
void UpdatePlayer(set<Player> *players,
                  unordered_map<int, Player> *fastAccess,
                  map<string, set<int>> *classMap)
{
    cout << "\n--- Actualizar jugador ---\n";
    int id;
    cout << "Ingrese ID: ";
    cin >> id;

    if (!fastAccess->count(id))
    {
        cout << "Jugador no encontrado.\n";
        return;
    }

    // Obtener copia del jugador y eliminar su versión anterior
    Player p = (*fastAccess)[id];
    players->erase(p);
    classMap->at(p.clas).erase(id);

    // Pedir nuevos datos
    cout << "Nuevo nombre: ";
    cin >> p.name;
    cout << "Nuevo nivel: ";
    cin >> p.level;
    cout << "Nueva clase: ";
    cin >> p.clas;
    cout << "Nuevo poder: ";
    cin >> p.power;

    // Insertar versión actualizada
    players->insert(p);
    (*fastAccess)[id] = p;
    (*classMap)[p.clas].insert(id);

    cout << "Jugador actualizado correctamente.\n";
}

// =======================================================
//               MOSTRAR TODOS LOS JUGADORES
// =======================================================
void ShowPlayers(const set<Player> &players)
{
    cout << "\n--- Lista de jugadores (ordenados por ID) ---\n";

    for (const auto &p : players)
    {
        cout << "ID: " << p.id
             << " | Nombre: " << p.name
             << " | Nivel: " << p.level
             << " | Clase: " << p.clas
             << " | Poder: " << p.power << "\n";
    }
}

// =======================================================
//         FILTRAR JUGADORES POR PODER MINIMO
// =======================================================
void FilterByPower(const set<Player> &players)
{
    int limit;
    cout << "\nPoder mínimo: ";
    cin >> limit;

    cout << "\nJugadores con poder > " << limit << ":\n";

    for (const auto &p : players)
    {
        if (p.power > limit)
        {
            cout << p.name << " (Poder: " << p.power << ")\n";
        }
    }
}

// =======================================================
//            TOP 3 JUGADORES MÁS FUERTES
// =======================================================
void ShowTop3(const set<Player> &players)
{
    cout << "\n--- TOP 3 Jugadores más fuertes ---\n";

    vector<Player> v(players.begin(), players.end());

    // Ordenar de mayor a menor según "power"
    sort(v.begin(), v.end(), [](const Player &a, const Player &b)
         { return a.power > b.power; });

    for (int i = 0; i < 3 && i < v.size(); i++)
    {
        cout << i + 1 << ". "
             << v[i].name << " (Poder: " << v[i].power << ")\n";
    }
}

// =======================================================
//        BUSCAR SI EXISTE UN NIVEL (binary_search)
// =======================================================
void SearchLevel(const set<Player> &players)
{
    vector<int> levels;

    // Copiar niveles
    for (const auto &p : players)
    {
        levels.push_back(p.level);
    }

    sort(levels.begin(), levels.end());

    int val;
    cout << "\nIngrese nivel a buscar: ";
    cin >> val;

    bool exists = binary_search(levels.begin(), levels.end(), val);

    cout << "El nivel " << val << (exists ? " SÍ" : " NO")
         << " existe.\n";
}

// =======================================================
//                        MAIN
// =======================================================
int main()
{

    // Estructuras principales (NO globales)
    set<Player> players;
    unordered_map<int, Player> fastAccess;
    map<string, set<int>> classMap;

    // Precarga de jugadores
    vector<Player> preload = {
        {1, "Auron", 25, "Guerrero", 300},
        {2, "Legolas", 40, "Arquero", 430},
        {3, "Kratos", 60, "Guerrero", 900},
        {4, "Merlina", 50, "Mago", 550},
        {5, "Zelda", 45, "Mago", 480}};

    // Insertar en estructuras usando referencias
    for (auto &p : preload)
    {
        players.insert(p);
        fastAccess[p.id] = p;
        classMap[p.clas].insert(p.id);
    }

    int opc;

    do
    {

        cout << "\n========= GESTOR DE JUGADORES =========\n";
        cout << "1. Agregar jugador\n";
        cout << "2. Eliminar jugador\n";
        cout << "3. Actualizar jugador\n";
        cout << "4. Mostrar jugadores\n";
        cout << "5. Filtrar por poder\n";
        cout << "6. Top 3 más fuertes\n";
        cout << "7. Buscar nivel (binary_search)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            AddPlayer(&players, &fastAccess, &classMap);
            break;
        case 2:
            RemovePlayer(&players, &fastAccess, &classMap);
            break;
        case 3:
            UpdatePlayer(&players, &fastAccess, &classMap);
            break;
        case 4:
            ShowPlayers(players);
            break;
        case 5:
            FilterByPower(players);
            break;
        case 6:
            ShowTop3(players);
            break;
        case 7:
            SearchLevel(players);
            break;

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opción inválida.\n";
        }

    } while (opc != 0);

    return 0;
}
