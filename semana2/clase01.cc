#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time()

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
void VerificacionDePremioDelCupon(std::string cupon);

int main()
{
    //Declaracion de las variables
    std::string prefijo, cupon;
    //Solicitud de prefijo
    std::cout << "Bienvenido al programa para generar cupon aleatorio, agregue el prefijo: ";
    std::cin >> prefijo;

    //Se llama la funcion y se guarda lo retornado
    cupon = GenerarCuponAleatorio(prefijo);

    //Se imprime el cupon generado
    std::cout << "El cupon generado es " << cupon << "\n";

    //Funcion de verificacion si tiene premio
    VerificacionDePremioDelCupon(cupon);

    std::cout << "Tenga un feliz dia.\n"; 

    return 0;
}

std::string GenerarCuponAleatorio(std::string prefijo)
{
    //DECLARAR VARIABLES
    std::string cupon;
    // GENERAR EL NUMERO ALEATORIO
    // Para que ocupe el tiempo de la maquina para asi no se ponga siempre la misma
    srand(time(0));
    // Se coloca de esta forma para que este del rango del 100 al 999
    int random = 100 + (rand() % 999);

    //Concatenar el prefijo y el numero aleatorio
    cupon = prefijo + std::to_string(random);

    //SE retorna el cupon
    return cupon;
}

void VerificacionDePremioDelCupon(std::string cupon){
    //Extraer la parte numerica del cupon AGO 108
    std::string num_extraido = cupon.substr(3,3);
    //CONVERTIR DE ENTERO A STRING
    int num = stoi(num_extraido);
    //VERIFICAR
    if((num % 2) == 0){
        std::cout << "Tienes premio felicidad! \n";
    }
    else{
        std::cout << "No tienes premio :( \n";
    }
}