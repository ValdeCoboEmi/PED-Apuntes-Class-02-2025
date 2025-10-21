#include <iostream>

/*
    Tiempo de complejidad es el tiempo de ejecucion del algoritmo, es decir el numero de operaciones
    que realiza un algoritmo oara completar su tarea. El algoritmo que realiza la tarea en el menor
    numero de operaciones se considera el mas eficiente en terminos de complejidad temporal

    La complejidad especial la cual hace referencia al consumo de memoria que cambia linealmente con las variaciones
    en la cantidad de datos de entrada. En notacion (Big O) por ejemplo O(n)

    Complejidad cuadratica: Ocurre en algoritmos con bucles doblemente anidados, donde el tiempo de ejecucion
    crece proporcionalmente al cuadrado del tamaño de la entrada

    complejidad logaritmica: A medida que aumenta la canidad de datos, las operaciones crecen muchos más lentamente
    Estos algoritmos suelen usar la técnica de Divide y Venceras, como la búsqueda binaria, que divide el problema
    a la mitad en cada paso

    O(n^1), es mucho mas lento y extenso
    O log(n), lo hace mas rapido

    Los 3 metodos de ordenamientos son al cuadrado

    ? --Ordenamiento de burbuja (Bubble Sort)--
    Pasos:

    *1) Comparar valores adyacentes (pares)
    *2) Intercambia de posicion los valores hasta obtener el orden requerrido
    *3) Cada uno va avanzando de posición hasta arriba

    Donde los valores ordenados por un criterio van subiendo y subiendo

    ? --Ordenamiento por insercion (Insertion sort)--
    Asume que el primer elemento ya está ordenado

    *1) El primer elemento comprueba si el elemento adyacente a la iquierda es menor
    *2) Continua verificando si el elemento de la izquierda es mayor al actual y
    cambia si es asi *3) Se sigue repitiendo ese mismo proceso hasta que todos los
    elementos queden ordenados

    Extrae el siguiente elemento y va comparadno con cada uno de los
    siguientes en la lista, si se cumple la condicion de ser mayor lo mueve a la
    derecha (el mayor) e inserta el que escogimos a la izquierda de ese mayor, el
    elemento "x" que compara con los demas, va avanzando en una posición compara de
    dos lados el siguiente y el anterior

    ? --Metodo de seleccion (Selection sort)--
    *1) Busca el elemento menor y se coloca en la primera posicion
    *2) Se repite eso mismo hasta terminar de ordenarlo por completo

    Problema: Este tipo de proceso se itera demasiadas veces para que tenga
    un efecto, conviritendolo en ineficiente

    Se toma un elemento minimo, ya que, va iterando en orden se asume que el
    primero de la lista es el minimo, compara el elemento actual escogido con el
    siguiente, si es menor al minimo, entonces, convierte a ese menor en el minimo y
    sigue comparando al encontrar una coincidencia de menor entocnes se convierte en
    el nuevo elemento minimo a coparar en caso no exista un menor, entonces mueve al
    actual menor al principio, "lo mueve al inicio" es decir, a la posición del
    elemento comparado

*/

//METODO DE INSERCCION
#include <iostream>

void insercion(int arreglo[], int n);
void imprimirArreglo(int arreglo[], int n);

int main()
{
    // Declarar e inicializar el arreglo
    int arreglo[] = {4, 1, 65, 12, 10};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    // Imprimir arreglo sin ordenar
    std::cout << "Arreglo sin ordenar: ";
    imprimirArreglo(arreglo, n);

    // Ordenar el arreglo usando el método de inserción
    insercion(arreglo, n);

    // Imprimir arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    imprimirArreglo(arreglo, n);

    return 0;
}

// Definición de la función de inserción
void insercion(int arreglo[], int n)
{
    // Comienza desde el segundo elemento
    for (int i = 1; i < n; i++)
    {
        // Valor a insertar
        int aux = arreglo[i];
        int j = i - 1;

        // Mover los elementos mayores que 'aux' hacia la derecha2
        while (j >= 0 && arreglo[j] > aux)
        {
            // Desplazar hacia la derecha
            j--;
            arreglo[j + 1] = arreglo[j];
        }

        // Insertar el valor en su posición correcta
        arreglo[j + 1] = aux;
    }
}

// Definición de la función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
