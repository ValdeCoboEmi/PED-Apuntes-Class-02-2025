# Google C++ Style 

## Archivos
- Cabeceras: `snake_case.h`  
- Implementación: `snake_case.cpp`  

## Clases / Structs
- PascalCase  
```cpp
class Player { };
struct Estudiante { };
````

## Funciones / Métodos

* PascalCase

```cpp
void PrintArray();
int CalculateScore();
```

## Variables / Miembros

* camelCase

```cpp
int playerHealth;
float bombTimer;
char playerName[50];
```

## Constantes globales

* kMayúsculaInicial

```cpp
const int kMaxPlayers = 4;
const float kPi = 3.14159;
```

## Arreglos

* Nombre plural, camelCase

```cpp
int playerScores[10];
char playerNames[5][50];
```

## Punteros

* Nombre descriptivo, camelCase

```cpp
int* playerScorePtr;
char* playerNamePtr;
int** contactsList;
```

## Enumeraciones

* PascalCase, valores con kMayúsculaInicial

```cpp
enum GameState { kMainMenu, kPlaying, kGameOver };
```

## Comentarios

* Explican **qué hace**, no repetir código

```cpp
// Llenar arreglo con números aleatorios
for (int i = 0; i < size; i++) arr[i] = rand() % 100 + 1;
```


