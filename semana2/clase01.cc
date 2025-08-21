#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time()
#include <vector>

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

std::string GenerarCuponAleatorio(std::string letrasPersonalizadas);
std::string VerificacionDeLongitud();
void VerificacionDePremioDelCupon(std::string cupon);

int main()
{
    // Para que ocupe el tiempo de la maquina para asi no se ponga siempre la misma
    srand(time(0));

    // Declaracion de las variables
    std::string prefijo;
    int cantidad_cupones = 0;
    std::vector<std::string> cupones_generado(cantidad_cupones);

    // SOLICITAR LA CANT DE CUPONES A GENERAR
    std::cout << "Ingrese la cantidad de cupones que desea: ";
    std::cin >> cantidad_cupones;

    // ALMACENAR EN UN ARREGLO

    for (int i = 0; i < cantidad_cupones; i++)
    {
        // Se llama la funcion y se guarda lo retornado
        // cupones_generado[i] = GenerarCuponAleatorio(VerificacionDeLongitud());
        cupones_generado.push_back(GenerarCuponAleatorio(VerificacionDeLongitud()));
    }

    std::cout << std::endl;
    std::cout << "Tus " << cantidad_cupones << " cupones generados son los siguientes: \n";

    std::cout << "--------------" << std::endl;
    
    for (int i = 0; i < cantidad_cupones; i++)
    {

        // Se imprime el cupon generado
        std::cout << "El cupon generado es: " << cupones_generado[i] << "\n";

        // Funcion de verificacion si tiene premio
        VerificacionDePremioDelCupon(cupones_generado[i]);

        std::cout << "--------------" << std::endl;
    }

    std::cout << "Tenga un feliz dia.\n";

    std::cout << std::endl;

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

void VerificacionDePremioDelCupon(std::string cupon)
{
    // Extraer la parte numerica del cupon AGO 108
    std::string num_extraido = cupon.substr(3, 3);
    // CONVERTIR DE ENTERO A STRING
    int num = stoi(num_extraido);
    // VERIFICAR
    if ((num % 2) == 0)
    {
        std::cout << "Tienes premio felicidad! \n";
    }
    else
    {
        std::cout << "No tienes premio :( \n";
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