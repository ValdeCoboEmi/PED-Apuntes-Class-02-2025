/*
    TODO --- Continuación: Árboles --- TODO

    ?--- Tipos de árboles --?
    * ABB
    * AVL
    * Red-Black
    Descripción breve y rápida 

    ?-- Estructuras de árboles binarios --?
    * Equilibrado
    * Degenerado
    * LLeno
    * Completo
    Rcordando definiciones

    ?-- Operaciones en árboles --?
    * Inserción
    * Recorrer
    * Eliminar
    * Buscar
    Para eliminar primero necesitamos comprender recorrer
    
    ?-- Operación de recorrido en un ABB --?
    * Recorrido in-orden
        Recorre en la forma:
            SubIzqrd - Raiz - SubDrch 
    * Recorrido pre-orden
        Recorre en la forma:    
            Raiz - SubIzqrd - SubDrch
    * Recorrido post-orden
        Recorre en la forma:
            SubIzqrd - SubDrch - Raiz

    ?-- Operación de eliminar en un ABB --?
    * Caso general: Eliminar un nodo en un ABB, un nodo puede tener:
        Cero hijos: Es una hoja
        Un hijo: Tiene solo hizo izquierdo o derecho
        Dos hijos: Tienen ambos hijos

    * Caso 1: Nodo sin hijos (hoja)
        Si el nodo no tiene hijos solo se elimina
        El padre del nodo deja de apuntar a el
    Caso sencillo: No afecta la estructura del arbol

    * Caso 2: Nodo co un hijo
        Si el nodo tiene solo un hijo, ese hijo toma su lugar
        El padre del nodo eliminado se conecta directamente con el hijo del nodo
    Si el nodo es eliminado es la raiz, el hijo paasa a ser la nueva raiz del arbol
    Afectando la estructura del arbol

    * Caso 3: Nodo con dos hijos
        Si el nodo tiene dos hijos se busca un nodo que lo reemplaze sin alterar el odrden del arbol
        Se puede emplear cualquiera de las dos alternativas mediante el rrecorido in-orden del arbol
            Sucesor in-orden: (El menor del subarbol derecho)
            Predecesor in-orden: (El mayor del subarbol izquierdo)
    El valor del sucesor o predecesor se copia en el nodo a eliminar y luego se borra ese nodo auxilar,
    que tendrá a lo sumo un hjo, afectando la estrucutra del arbol
*/