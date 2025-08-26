#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time()
#include <vector>
#include <utility>

// EJjercicio de funciones con y sin parametro

/*
    Gestion de cupones de primerios
    Es un sistema moderno de promociones y fidelizacion de clientes, la gestion eficiente y automatizada de cupones de premios es fundamental para incentivar
    las compras y aumentar la satisfaccion del consumidor. Este programa implemneta una solución sencilla para la generación, asignación y canje de cupones de
    descuento personalidas

    1. Generación del cupón con letras personalizadas y un número aleatorio entre 100 y 999.
    Escribir una funcion que genere cupones de premios el cual debe estar compuesto por letras ingresadas por el usuario y valores numéricos en
    el rango de (100-999).

    2. Verificacion de premio del cupon
    Escribir una funcion que permita recibir el identificar del cupon y asignar si tiene premio segun si es el numero aleatorio generado tomar
    cuenta lo siguiente, si es par o impar y asignar la cadena de texto tiene premio o no tiene premio.
*/

struct InformacionCupon
{
    int cant_cupones;
    std::string nombre_personas;
    std::vector<std::pair<std::string, std::string>> cupones_premio;
};

std::string GenerarCuponAleatorio(std::string letrasPersonalizadas);
std::string VerificacionDeLongitud();
std::string VerificacionDePremioDelCupon(std::string cupon);
struct InformacionCupon SolicitarDatosGenerales();
void ImprimirDatos(std::vector<struct InformacionCupon> inf_cupones);

int main()
{
    // Para que ocupe el tiempo de la maquina para asi no se ponga siempre la misma
    srand(time(0));

    // Variable de tipo Struct
    std::vector<struct InformacionCupon> inf_cupones;

    // Almacenar el struct en el vector inf_cupones
    inf_cupones.push_back(SolicitarDatosGenerales());
    ImprimirDatos(inf_cupones);

    return 0;
}

std::string GenerarCuponAleatorio(std::string prefijo)
{
    // DECLARAR VARIABLES
    std::string cupon;
    // GENERAR EL NUMERO ALEATORIO

    // Se coloca de esta forma para que este del rango del 100 al 999
    int random = 100 + (rand() % 900);

    // Concatenar el prefijo y el numero aleatorio
    cupon = prefijo + std::to_string(random);

    // SE retorna el cupon
    return cupon;
}

std::string VerificacionDePremioDelCupon(std::string cupon)
{
    // Extraer la parte numerica del cupon AGO 108
    std::string num_extraido = cupon.substr(3, 3);
    // CONVERTIR DE ENTERO A STRING
    int num = stoi(num_extraido);
    // VERIFICAR
    if ((num % 2) == 0)
    {
        return "Tienes premio felicidad! \n";
    }
    else
    {
        return "No tienes premio :( \n";
    }
}

std::string VerificacionDeLongitud()
{
    std::string prefijo;
    // Solicitud de prefijo
    std::cout << "Bienvenido al programa para generar cupon aleatorio, agregue el prefijo: ";
    std::cin >> prefijo;

    // VALIDAR SI TIENE 3 LETRAS O No
    if (prefijo.length() != 3)
    {
        std::cout << "El prefijo no tiene 3 letras, no cumple con lo solicitado, porfavor vuelva a intentarlo. \n";
        return VerificacionDeLongitud();
    }
    else
    {
        return prefijo;
    }
}

struct InformacionCupon SolicitarDatosGenerales()
{
    struct InformacionCupon cupon;
    // SOLICITAR NOMBRE DE LA PERSONA
    std::cout << "Ingrese el nombre de la persona: ";
    std::cin >> cupon.nombre_personas;

    // SOLICITAR LA CANT DE CUPONES A GENERAR
    std::cout << "Ingrese la cantidad de cupones que desea: ";
    std::cin >> cupon.cant_cupones;

    // ALMACENAR EN struct

    for (int i = 0; i < cupon.cant_cupones; i++)
    {
        // Se llama la funcion y se guarda lo retornado
        // cupones_generado[i] = GenerarCuponAleatorio(VerificacionDeLongitud());
        // cupon.cupones_generado.push_back(GenerarCuponAleatorio(VerificacionDeLongitud()));
        std::string cupon_generado = GenerarCuponAleatorio(VerificacionDeLongitud());
        cupon.cupones_premio.push_back({cupon_generado, VerificacionDePremioDelCupon(cupon_generado)});
    }

    return cupon;
}

void ImprimirDatos(std::vector<struct InformacionCupon> inf_cupones)
{
    for (auto cupon : inf_cupones)
    {
        std::cout << "\n" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "Nombre de la persona: " << cupon.nombre_personas << "\n";
        std::cout << "Cantidad de cupones: " << cupon.cant_cupones << "\n";
        std::cout << "--------------" << std::endl;

        for (auto c : cupon.cupones_premio)
        {
            std::cout << "Cupon generados: " << c.first << " -- Premio: " << c.second << "\n";
        }
    }

    std::cout << "Tenga un feliz dia.\n";

    std::cout << std::endl;
}