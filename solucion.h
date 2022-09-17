#ifndef PROBLEMA_DEL_C_ABALLO
#define PROBLEMA_DEL_C_ABALLO

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

typedef struct 
{ 
    int x; 
    int y; 
} 
t_posicion;

typedef struct 
{ 
    int** items; 
    int tamanio;
    int jugadas;
} 
t_tablero;

t_posicion movimientos[] = 
{
    {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

extern unsigned long long int intentos;

bool pertenece(int tamanio, t_posicion posicion);
bool recorrer(t_tablero tablero, t_posicion caballo);
bool recorrer_recursivo(t_tablero tablero, t_posicion caballo, int iteracion);
bool es_ultima_iteracion(t_tablero tablero, int iteracion);
t_posicion mover(t_posicion posicion, int i);
bool esta_libre(t_tablero tablero, t_posicion posicion);
int mostrar(t_tablero tablero);

#endif // PROBLEMA_DEL_C_ABALLO
