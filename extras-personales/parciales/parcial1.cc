#include <iostream>
#include <vector>
#include <string>
#include <ctime> // Para calcular los años desde el estreno
using namespace std;

// ======================================================
// =============== ESTRUCTURAS PRINCIPALES ==============
// ======================================================

// Estructura Película
struct Pelicula {
    string nombre;
    int anio_estreno;
    bool subtitulada; // true: sí, false: no
};

// Estructura Actor
struct Actor {
    string nombre;
    string nacionalidad;
    Pelicula peliculas[3];
};

// ======================================================
// ================= PROTOTIPOS =========================
// ======================================================

Actor SolicitarInformacion();
void Imprimir(const vector<Actor>& info_actores);
bool VerificarNominacion(const Pelicula& pelicula);
void VerificarNominaciones(const vector<Actor>& info_actores);
void BuscarPelicula(const vector<Actor>& info_actores);
void ModificarActor(vector<Actor>& info_actores);
int CalcularAnios(int anio_estreno);
void Menu();

// ======================================================
// ===================== MAIN ===========================
// ======================================================

int main() {
    Menu();
    return 0;
}

// ======================================================
// ============ FUNCIONES PRINCIPALES ===================
// ======================================================

// Solicita datos de un actor y sus películas
Actor SolicitarInformacion() {
    Actor actor;
    cout << "\nIngrese el nombre del actor: ";
    getline(cin, actor.nombre);
    cout << "Ingrese la nacionalidad del actor: ";
    getline(cin, actor.nacionalidad);

    cout << "\n--- Ingrese los datos de hasta 3 películas ---\n";
    int conteo = 0;
    bool continuar = true;

    while (conteo < 3 && continuar) {
        cout << "\nPelicula #" << conteo + 1 << endl;
        cout << "Nombre: ";
        getline(cin, actor.peliculas[conteo].nombre);
        cout << "Año de estreno: ";
        cin >> actor.peliculas[conteo].anio_estreno;
        cout << "¿Está subtitulada? (1 = Sí, 0 = No): ";
        cin >> actor.peliculas[conteo].subtitulada;
        cin.ignore();

        conteo++;
        if (conteo < 3) {
            cout << "¿Desea ingresar otra película? (1 = Sí, 0 = No): ";
            cin >> continuar;
            cin.ignore();
        }
    }
    return actor;
}

// Imprime todos los actores y sus películas
void Imprimir(const vector<Actor>& info_actores) {
    cout << "\n======= INFORMACIÓN REGISTRADA =======\n";
    for (const auto& actor : info_actores) {
        cout << "\nActor: " << actor.nombre << endl;
        cout << "Nacionalidad: " << actor.nacionalidad << endl;

        for (const auto& pelicula : actor.peliculas) {
            if (pelicula.nombre.empty()) continue;
            cout << "\n  Película: " << pelicula.nombre;
            cout << "\n  Año de estreno: " << pelicula.anio_estreno;
            cout << "\n  Subtitulada: " << (pelicula.subtitulada ? "Sí" : "No") << endl;
        }
        cout << "--------------------------------------\n";
    }
}

// Calcula los años desde el estreno de la película
int CalcularAnios(int anio_estreno) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int anio_actual = 1900 + ltm->tm_year;
    return anio_actual - anio_estreno;
}

// Verifica si una película puede ser nominada
bool VerificarNominacion(const Pelicula& pelicula) {
    int antiguedad = CalcularAnios(pelicula.anio_estreno);
    return (antiguedad > 10 && pelicula.subtitulada);
}

// Pregunta por películas y muestra si están nominadas
void VerificarNominaciones(const vector<Actor>& info_actores) {
    cout << "\n======= VERIFICACIÓN DE NOMINACIONES =======\n";
    for (const auto& actor : info_actores) {
        for (const auto& pelicula : actor.peliculas) {
            if (pelicula.nombre.empty()) continue;

            cout << "\n¿Desea verificar si la película '" << pelicula.nombre << "' está nominada? (1 = Sí, 0 = No): ";
            int opcion;
            cin >> opcion;
            if (opcion == 1) {
                if (VerificarNominacion(pelicula)) {
                    cout << "La película '" << pelicula.nombre << "' está nominada.\n";
                } else {
                    cout << "La película '" << pelicula.nombre << "' no está nominada.\n";
                }
            }
        }
    }
    cin.ignore();
}

// Busca una película por nombre
void BuscarPelicula(const vector<Actor>& info_actores) {
    cout << "\nIngrese el nombre de la película a buscar: ";
    string nombre_buscar;
    getline(cin, nombre_buscar);

    bool encontrado = false;
    for (const auto& actor : info_actores) {
        for (const auto& pelicula : actor.peliculas) {
            if (pelicula.nombre == nombre_buscar) {
                cout << "\nPelícula encontrada:\n";
                cout << "Actor: " << actor.nombre << endl;
                cout << "Año de estreno: " << pelicula.anio_estreno << endl;
                encontrado = true;
            }
        }
    }
    if (!encontrado)
        cout << "\nPelícula no encontrada.\n";
}

// Permite modificar los datos de un actor (solo nombre y nacionalidad)
void ModificarActor(vector<Actor>& info_actores) {
    cout << "\nIngrese el nombre del actor a modificar: ";
    string nombre;
    getline(cin, nombre);

    for (auto& actor : info_actores) {
        if (actor.nombre == nombre) {
            cout << "\nActor encontrado. Ingrese los nuevos datos:\n";
            cout << "Nuevo nombre: ";
            getline(cin, actor.nombre);
            cout << "Nueva nacionalidad: ";
            getline(cin, actor.nacionalidad);
            cout << "\nDatos modificados correctamente.\n";
            return;
        }
    }
    cout << "\nNo se encontró un actor con ese nombre.\n";
}

// Menú principal del programa
void Menu() {
    vector<Actor> info_actores;
    int opcion;
    bool salir = false;

    do {
        cout << "\n========== MENÚ PRINCIPAL ==========\n";
        cout << "1. Solicitar datos de actor\n";
        cout << "2. Imprimir información\n";
        cout << "3. Buscar película\n";
        cout << "4. Verificar nominación de premio\n";
        cout << "5. Modificar información de actor\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                info_actores.push_back(SolicitarInformacion());
                break;
            case 2:
                Imprimir(info_actores);
                break;
            case 3:
                BuscarPelicula(info_actores);
                break;
            case 4:
                VerificarNominaciones(info_actores);
                break;
            case 5:
                ModificarActor(info_actores);
                break;
            case 6:
                salir = true;
                cout << "\nGracias por usar el programa.\n";
                break;
            default:
                cout << "\nOpción no válida.\n";
                break;
        }
    } while (!salir);
}
