/*
Grafos, son nodos donde estan unidos por medio de un camino donde posee una aristas y puede tener un ciclo

Tipos de grafo:

Grafo dirigido: Cada aristas está asignada a un par ordenado de nodos, tienen una direccion asignada
Grafo no dirigido: Las aristas no tienen direccion. La relacion entre nodos es bidireccional y simetrica

Grado de un vertice de un grafo:
    -No dirigdo: es el numero de aristas conectadas a ese nodo
    -Dirigido: Se divide en grado de entrada (numero de aristas que ingresan al nodo) y grado de salida (numero de aristas que salen del nodo)

FORMAS DE REPRESENTACION
    MATRIZ DE ADYACENCIA (Se trabaja con 0 y 1 para indicar si hay camino o no)
    LISTA DE ADYACENCIA (Solo se entrelaza si hay lista)

Se puede usar unordered_map para representar la forma de lista de adyacencia
donde se tiene que clave = nodo y el valor seria la aristas (Conexiones) donde la arista tendra un list<valor>
se puede igual forma hacer con vector o map
*/

// EJERCICIO GRAFO DIRIGIDO

#include <iostream>
#include <unordered_map>
#include <list>

// typedef crea un Alias, pero ya por c++11 ya no se ocupa sino con using
// typedef std::unordered_map<char, std::list<char>> GrafoListaAdj;

// ALIAS -> PASCAL CASE
// La otra forma de crear un alias es con el using
using GrafoListaAdj = std::unordered_map<char, std::list<char>>;

void AgregarAristas(GrafoListaAdj &grafo_list_adj, char origen, char destino);
void Imprimir(const GrafoListaAdj &grafo_list_adj);

int main()
{

    GrafoListaAdj lista_adj;
    AgregarAristas(lista_adj, 'a', 'c');
    AgregarAristas(lista_adj, 'a', 'd');

    AgregarAristas(lista_adj, 'c', 'd');

    AgregarAristas(lista_adj, 'd', 'b');

    Imprimir(lista_adj);

    return 0;
}

void AgregarAristas(GrafoListaAdj &grafo_list_adj, char origen, char destino)
{

    // NO FUNCIONA PORQUE EL DESTINO grafo_list_adj.insert({origen, destino});
    // TAMPOCO ES ASI grafo_list_adj.emplace(origen, destino);

    // GRAFO DIRIGIDO
    grafo_list_adj[origen].push_back(destino);

    /*
        PARA UN GRAFO NO DIRIGIDO SERIA:
        grafo_list_adj[origen].push_back(destino);
        grafo_list_adj[destino].push_back(origen);
    */
}

void Imprimir(const GrafoListaAdj &grafo_list_adj)
{
    for (const auto &umap : grafo_list_adj)
    {
        std::cout << "Nodo origen (Clave): " << umap.first << "\n";
        std::cout << "Destino: " << "\n";
        for (const auto &lista_valor : umap.second)
        {
            std::cout << "Nodo: " << lista_valor << "\n";
        }
        std::cout << "\n";
    }
}