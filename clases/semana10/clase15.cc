/*
    Arbol binario - maximo de hijo 2 - orden 2
    Arbol ternario/general - más de 3 - orden mas de 3

    El orden de un arbol nos dice que es el grado maximo de hijo que puede (por ejemplo si es 3, entonces todos tiene que tener 3, no mas pero si menos,
    si nos indica la indicacion de arbol binario nos dice el orden que es 2, entonces ahi es la unica que nos dice)
    El grado de un nodo es el numero de hijos directos de un nodo
    El grado de un arbol, es el maximo entre todos sus nodos

    Nivel de un nodo: distancia en la que se encuentra el nodo con respecto a la raiz

    Altura de un arbol: Es el numero maximo de nodos de una rama, el nivel mas alto desde la raiz mas uno

    Peso de un nodo: numeros de descendientes (o nodos del subarbol) que tiene el nodo

    Peso de un arbol: es el numero total de nodos que tiene un arbol

    Longitud de un nodo: es el numero de caminos que deben ser recorridos para llegar a un nodo


    orden del arbol 3
    nodo raiz A
    peso del arbol 10
    peso del nodo D
    Longitud de nodo H 2
    grado del arbol 3
    Grado del nodo F: 2
    Subarboles se identifica 5
    nodos hojas 5
    Nodos hermanos: E-I-j-g-h, {B,C,D}-{E,F}-{I,J}

    *arbol binario
    Arbol que tiene maximo 2 nodos
        binario de busqueda (BST) - Tipos
            Arbol AVL
            Arbol Rojo-negro

    *Estructura de arboles binarios
    -Equilibrado: La altura de la rama izquierda es igual a la
    rama de la derecha para cada uno de los nodos y difiere
    como máximo en 1. Ayuda a mantener las operaciones
    rápidas (O(log n)). Ejemplo AVL Tree, Red-Black Tree.

    -Degenerado: Solo existe un nodo hoja y cada nodo no
    hoja solo tiene un hijo. Es equivalente a una lista enlazada.
    Las operaciones como búsqueda se vuelven O(n)

    -Lleno: Cada nodo, la altura del subárbol izquierdo es igual
    al derecho. La búsqueda es O(log n) porque un árbol lleno
    puede estar balanceado.

    -Completo: EI árbol está lleno hasta el penúltimo nivel y el
    último nivel tiene más nodos a la izquierda. Algunas
    operaciones como recorrido son vuelven O(n) mientras que
    búsqueda, inserción y eliminación son O(log n).

    *OPERACIONES ARBOL BINARIO BUSQEUDA
    INSERCION:
    Es un árbol ordenado, el valor del hijo izquierdo
    es menor que su nodo padre y el valor de un
    hijo derecho es mayor que el valor de su nodo
    padre. Por tanto, se sigue 10 mismo para los
    subárboles.

    Es útil para representar datos en formato
    ordenado 10 cual facilita la realización de las
    de inserción, búsqueda, operaciones eliminación y 
    recorrido.

    ABB, permite implementar árboles de búsqueda
    binarios equilibrados como árboles AVL, árboles
    rojos y negros, entre otros.


*/