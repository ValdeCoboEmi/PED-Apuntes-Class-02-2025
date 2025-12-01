/*
=================================================================
                    EXTRA SUPER ÚTIL PARA EL PARCIAL
          Cosas típicas que ponen en exámenes con std::map
=================================================================

---------------------------------------------------------------
A) EL OPERADOR [] CREA ELEMENTOS (¡TRAMPA CLÁSICA!)
---------------------------------------------------------------
map<int,int> m;
cout << m[5]; 
// Esto CREA la clave 5 con valor 0 si NO existía.
// Ahora size() = 1, aunque no tuviste intención de insertarlo.

// Mejor usar find() o count() si no quieres insertarlo por error.

---------------------------------------------------------------
B) COMPARAR map Y unordered_map (pregunta típica)
---------------------------------------------------------------
map:
    - Árbol rojo-negro (ordenado).
    - Claves únicas.
    - O(log n) inserción / búsqueda / borrado.
    - Recorre siempre en orden.

unordered_map:
    - Tabla hash (no ordenado).
    - O(1) promedio.
    - Mucho más rápido normalmente.
    - No sirve si necesitas orden.

---------------------------------------------------------------
C) INSERT NO SOBREESCRIBE, [] SÍ SOBREESCRIBE
---------------------------------------------------------------
map<int,int> m;
m.insert({3, 10});
m.insert({3, 20});   // NO sobrescribe → se ignora.
m[3] = 30;           // SÍ sobrescribe el valor → 30.

---------------------------------------------------------------
D) BUSCAR EL ELEMENTO MÁS PEQUEÑO O MÁS GRANDE
---------------------------------------------------------------
map<int,string> m;

auto menor = m.begin();     // first = menor clave
auto mayor = prev(m.end()); // last = mayor clave

cout << menor->first;
cout << mayor->first;

---------------------------------------------------------------
E) USAR map COMO CONTADOR DE FRECUENCIAS
---------------------------------------------------------------
string s = "banana";
map<char,int> freq;

for (char c : s)
    freq[c]++;

for (auto &p : freq)
    cout << p.first << ": " << p.second << endl;
// a:3 b:1 n:2

---------------------------------------------------------------
F) map DE map (muy común en parciales)
---------------------------------------------------------------
map<string, map<string, int>> datos;

datos["Juan"]["Matematica"] = 8;
datos["Juan"]["Prog"] = 10;
datos["Ana"]["Prog"] = 9;

// Recorrido:
for (auto &persona : datos) {
    cout << persona.first << endl;
    for (auto &materia : persona.second) {
        cout << "  " << materia.first << " = " << materia.second << endl;
    }
}

---------------------------------------------------------------
G) USAR map PARA ORDENAR AUTOMÁTICAMENTE
---------------------------------------------------------------
// Cuenta y ordena palabras sin esfuerzo:
vector<string> v = {"uva", "manzana", "banana", "banana", "uva"};

map<string,int> cnt;

for (auto &x : v)
    cnt[x]++;

for (auto &p : cnt)
    cout << p.first << " -> " << p.second << endl;

// banana -> 2
// manzana -> 1
// uva -> 2

---------------------------------------------------------------
H) COMO FUNCIONA find() EN UN map VACÍO
---------------------------------------------------------------
map<int,int> m;

if (m.find(1) == m.end()) {
    // NO existe
}

---------------------------------------------------------------
I) lower_bound Y upper_bound EJEMPLO REAL
---------------------------------------------------------------
map<int,string> m;
m[1] = "a";
m[3] = "b";
m[5] = "c";

auto it = m.lower_bound(3);
// it → clave 3

auto it2 = m.lower_bound(4);
// it2 → clave 5 (primer ≥ 4)

auto it3 = m.upper_bound(3);
// it3 → clave 5 (primer > 3)

---------------------------------------------------------------
J) QUÉ PASA SI BORRAS MIENTRAS RECORRES
---------------------------------------------------------------
map<int,int> m = {{1,10},{2,20},{3,30}};

// Forma CORRECTA
for (auto it = m.begin(); it != m.end(); ) {
    if (it->first == 2)
        it = m.erase(it); // devuelve siguiente iterador
    else
        ++it;
}

---------------------------------------------------------------
K) COMPLEJIDAD QUE SIEMPRE PIDEN
---------------------------------------------------------------
Todas las operaciones principales de map:
    - insert        O(log n)
    - erase         O(log n)
    - find          O(log n)
    - operator[]    O(log n)
    - traversal     O(n)

---------------------------------------------------------------
L) map ORDENADO AL REVÉS (muy común)
---------------------------------------------------------------
map<int,int,greater<int>> m_desc;
// Ahora se ordena de mayor a menor automáticamente.

---------------------------------------------------------------
M) ITERAR SOLO UN RANGO DEL MAP
---------------------------------------------------------------
auto it1 = m.lower_bound(10);
auto it2 = m.upper_bound(20);

for (auto it = it1; it != it2; ++it) {
    // claves están en [10,20]
}

=================================================================
FIN DEL RESUMEN EXTRA
=================================================================
*/