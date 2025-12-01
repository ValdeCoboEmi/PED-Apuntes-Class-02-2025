/*
===========================================================
        RESUMEN COMPLETO DE std::map EN C++ (PARCIAL)
===========================================================

★ Qué es:
    - Contenedor ordenado por clave.
    - Implementado como árbol rojo-negro.
    - Inserción, búsqueda y borrado: O(log n)
    - Claves únicas.

-----------------------------------------------------------
1. DECLARACIÓN
-----------------------------------------------------------
#include <map>
#include <string>
using namespace std;

map<int,int> m1;
map<string,int> frecuencia;
map<char,string> tabla;

-----------------------------------------------------------
2. INSERTAR
-----------------------------------------------------------
// Forma segura
m1.insert({3,100});
m1.insert(make_pair(4,200));

// Usando operador []
m1[10] = 50; // si la clave no existe → la crea

-----------------------------------------------------------
3. ACCEDER A VALORES
-----------------------------------------------------------
int a = m1[3];   // inserta valor por defecto si NO existe
int b = m1.at(3); // lanza excepción si no existe

-----------------------------------------------------------
4. BUSCAR
-----------------------------------------------------------
auto it = m1.find(3);
if (it != m1.end()) {
    cout << it->first << " → " << it->second;
}

// saber si existe
//if (m1.count(5)) { existe }
/*
-----------------------------------------------------------
5. BORRAR
-----------------------------------------------------------
m1.erase(3);          // borrar por clave
m1.erase(it);         // borrar por iterador
m1.erase(m1.begin()); // borrar el primero
*/
//-----------------------------------------------------------
// 6. RECORRER (EN ORDEN)
//-----------------------------------------------------------
// for (auto &par : m1) {
//    cout << par.first << " " << par.second << endl;
//}
/*
-----------------------------------------------------------
7. TAMAÑO Y ESTADO
-----------------------------------------------------------
m1.size();
m1.empty();
m1.clear();

-----------------------------------------------------------
8. ITERADORES ÚTILES
-----------------------------------------------------------
m1.begin();   // menor clave
m1.end();     // fin
m1.rbegin();  // mayor clave
m1.rend();
*/
//-----------------------------------------------------------
// 9. lower_bound / upper_bound / equal_range
//-----------------------------------------------------------
// ≥ clave
// auto it1 = m1.lower_bound(5);

// > clave
// auto it2 = m1.upper_bound(5);

// rango con valores igual a clave (solo útil en multimap)
// auto r = m1.equal_range(5);

//-----------------------------------------------------------
// 10. ORDEN PERSONALIZADO
//-----------------------------------------------------------
// struct cmp {
//       bool operator()(const string &a, const string &b) const {
//        return a > b;  // orden descendente
//    }
//};

/*
map<string,int,cmp> ordenado_desc;

-----------------------------------------------------------
11. TIPOS RELACIONADOS
-----------------------------------------------------------
// Permite claves repetidas
multimap<int,string> mm;

// No ordenado, tabla hash, acceso O(1)
unordered_map<string,int> dic;

-----------------------------------------------------------
12. ¿CUÁNDO USAR map?
-----------------------------------------------------------
✓ Cuando necesitas elementos ORDENADOS.
✓ Cuando quieres inserciones/búsquedas O(log n).
✗ No usar si necesitas velocidad máxima (usar unordered_map).

-----------------------------------------------------------
RESUMEN DE COSTOS
-----------------------------------------------------------
 Operación          Costo
 ----------------------------
 insert            O(log n)
 acceso []         O(log n)
 erase             O(log n)
 find              O(log n)
 count             O(log n)
 recorrer          O(n)
 lower_bound       O(log n)
 upper_bound       O(log n)

===========================================================
*/
