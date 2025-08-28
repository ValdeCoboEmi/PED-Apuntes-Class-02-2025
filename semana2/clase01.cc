#include <iostream>
#include <string>
#include <cstdlib> // Librería para funciones de números aleatorios (rand, srand)
#include <ctime>   // Librería para obtener el tiempo actual (time)
#include <vector>  // Librería para vectores dinámicos
#include <utility> // Librería para usar std::pair

// ---------------------------------------------------------------
// EJERCICIO: GESTIÓN DE CUPONES DE PREMIOS
// ---------------------------------------------------------------
// Este programa permite:
// 1. Generar cupones de premios con un prefijo personalizado (3 letras)
//    y un número aleatorio entre 100 y 999.
// 2. Verificar si un cupón tiene premio o no, dependiendo de si el
//    número aleatorio es par (tiene premio) o impar (no tiene).
// 3. Guardar e imprimir toda la información en un struct con vectores.
// ---------------------------------------------------------------

struct InformacionPersona
{
    std::string nombre_personas; // Nombre del usuario
};

// Definición de un struct para almacenar toda la información de un usuario
struct InformacionCupon
{
    int cant_cupones; // Cantidad de cupones que quiere el usuario
    // Vector de pares: <cupón generado, resultado del premio>
    std::vector<std::pair<std::string, std::string>> cupones_premio;
    struct InformacionPersona inf_persona; // Incluye el struct de información personal
};

// Declaración de funciones que se implementarán más adelante
std::string GenerarCuponAleatorio(std::string letrasPersonalizadas);
std::string VerificacionDeLongitud();
std::string VerificacionDePremioDelCupon(std::string cupon);
struct InformacionCupon SolicitarDatosGenerales();
void ImprimirDatos(std::vector<struct InformacionCupon> inf_cupones);

int main()
{
    // Inicializar la semilla de números aleatorios con el tiempo actual.
    // Esto evita que en cada ejecución se generen los mismos números.
    srand(time(0));

    // Declaramos un vector que almacenará varios structs de tipo InformacionCupon
    std::vector<struct InformacionCupon> inf_cupones;
    bool continuar = true;
    int opcion;

    // Bucle para permitir ingresar múltiples personas y sus cupones hasta que el usuario decida salir
    do
    {
        // Pedimos al usuario sus datos y los almacenamos en el vector
        inf_cupones.push_back(SolicitarDatosGenerales());

        // Preguntamos si quiere continuar agregando más personas
        std::cout << "¿Desea agregar otra persona? (1 = Sí, 0 = No): ";
        std::cin >> opcion;

        // Salir del bucle si la opción es 0
        if (opcion == 0)
        {
            continuar = false; 
        }
    } while (continuar);

    // Imprimimos toda la información almacenada
    ImprimirDatos(inf_cupones);

    return 0;
}

// ---------------------------------------------------------------
// FUNCIÓN: GenerarCuponAleatorio
// Genera un cupón con un prefijo de 3 letras + un número aleatorio entre 100 y 999.
// ---------------------------------------------------------------
std::string GenerarCuponAleatorio(std::string prefijo)
{
    std::string cupon; // Variable para guardar el cupón

    // Generamos un número aleatorio entre 100 y 999
    int random = 100 + (rand() % 900);

    // Concatenamos el prefijo con el número aleatorio
    cupon = prefijo + std::to_string(random);

    // Retornamos el cupón generado
    return cupon;
}

// ---------------------------------------------------------------
// FUNCIÓN: VerificacionDePremioDelCupon
// Verifica si el número del cupón es par o impar.
// Si es par → "Tienes premio", si es impar → "No tienes premio".
// ---------------------------------------------------------------
std::string VerificacionDePremioDelCupon(std::string cupon)
{
    // Extraemos la parte numérica del cupón (ejemplo: "ABC108" → "108").
    // substr(3,3) significa: desde la posición 3, tomar 3 caracteres.
    std::string num_extraido = cupon.substr(3, 3);

    // Convertimos el número extraído (string) a entero.
    int num = stoi(num_extraido);

    // Verificamos si el número es par o impar
    if ((num % 2) == 0)
    {
        return "Tienes premio felicidad! \n"; // Caso número par
    }
    else
    {
        return "No tienes premio :( \n"; // Caso número impar
    }
}

// ---------------------------------------------------------------
// FUNCIÓN: VerificacionDeLongitud
// Solicita al usuario un prefijo de exactamente 3 letras.
// Si el usuario no cumple, se vuelve a pedir hasta que sea correcto.
// ---------------------------------------------------------------
std::string VerificacionDeLongitud()
{
    std::string prefijo;

    std::cout << "Bienvenido al programa para generar cupon aleatorio, agregue el prefijo: ";
    std::cin >> prefijo;

    // Validamos si tiene exactamente 3 letras
    if (prefijo.length() != 3)
    {
        std::cout << "El prefijo no tiene 3 letras, no cumple con lo solicitado, porfavor vuelva a intentarlo. \n";
        // Llamamos recursivamente a la función para volver a pedir un prefijo válido
        return VerificacionDeLongitud();
    }
    else
    {
        // Si el prefijo es válido (3 letras), lo retornamos
        return prefijo;
    }
}

// ---------------------------------------------------------------
// FUNCIÓN: SolicitarDatosGenerales
// Pide al usuario su nombre y la cantidad de cupones que quiere.
// Luego genera cada cupón con su verificación de premio.
// ---------------------------------------------------------------
struct InformacionCupon SolicitarDatosGenerales()
{
    struct InformacionCupon cupon; // Creamos una variable de tipo struct

    // Pedimos el nombre de la persona
    std::cout << "Ingrese el nombre de la persona: ";
    std::cin >> cupon.inf_persona.nombre_personas;

    // Pedimos la cantidad de cupones a generar
    std::cout << "Ingrese la cantidad de cupones que desea: ";
    std::cin >> cupon.cant_cupones;

    // Generamos y almacenamos cada cupón en el vector dentro del struct
    for (int i = 0; i < cupon.cant_cupones; i++)
    {
        // Obtenemos un prefijo válido de 3 letras y generamos el cupón
        std::string cupon_generado = GenerarCuponAleatorio(VerificacionDeLongitud());

        // Verificamos si el cupón tiene premio y lo almacenamos junto con el cupón
        cupon.cupones_premio.push_back({cupon_generado, VerificacionDePremioDelCupon(cupon_generado)});
    }

    // Retornamos toda la información del struct
    return cupon;
}

// ---------------------------------------------------------------
// FUNCIÓN: ImprimirDatos
// Recorre el vector de structs y muestra toda la información generada.
// ---------------------------------------------------------------
void ImprimirDatos(std::vector<struct InformacionCupon> inf_cupones)
{
    // Recorremos todos los elementos del vector de structs, es un for anidado
    // El primer for esta con la estructura de for each, donde toma cada elemento del vector uno por uno3
    std::cout << "\n";
    for (auto cupon : inf_cupones)
    {
        std::cout << "--------------" << std::endl;

        // Imprimimos datos generales de la persona
        std::cout << "Nombre de la persona: " << cupon.inf_persona.nombre_personas << "\n";
        std::cout << "Cantidad de cupones: " << cupon.cant_cupones << "\n";
        std::cout << "Cupones generados son: " << "\n";
        std::cout << "--------------" << std::endl;

        // Recorremos los cupones generados de tipo vector<pair>,  y mostramos cupón + el premio
        for (auto c : cupon.cupones_premio)
        {
            std::cout << "Cupon generado: " << c.first << " -- Premio: " << c.second;
        }
        std::cout << "--------------" << std::endl;
    }
    // Mensaje final
    std::cout << "Tenga un feliz dia.\n"
              << std::endl;
}