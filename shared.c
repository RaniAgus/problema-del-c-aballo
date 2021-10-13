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

int intentos = 0;

bool pertenece(int tamanio, t_posicion posicion);
bool recorrer(t_tablero tablero, t_posicion caballo);
bool recorrer_recursivo(t_tablero tablero, t_posicion caballo, int iteracion);
bool es_ultima_iteracion(t_tablero tablero, int iteracion);
t_posicion mover(t_posicion posicion, int i);
bool esta_libre(t_tablero tablero, t_posicion posicion);
int mostrar(t_tablero tablero);

bool recorrer(t_tablero tablero, t_posicion pos_inicial) 
{   
    bool resuelto = recorrer_recursivo(tablero, pos_inicial, 1);
    if (resuelto)
    {
        printf("[%d,%d] -> %'d intentos\n", pos_inicial.x, pos_inicial.y, intentos + 1);
    }
    else 
    {
        printf("[%d,%d] -> No se pudo recorrer!\n", pos_inicial.x, pos_inicial.y);
    }

    return resuelto;
}

bool recorrer_recursivo(t_tablero tablero, t_posicion caballo, int iteracion) 
{
    if (!esta_libre(tablero, caballo)) 
    {
        return false;
    }

    tablero.items[caballo.x][caballo.y] = iteracion;  
    if (es_ultima_iteracion(tablero, iteracion)) 
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 8; i++) 
        {
            if (recorrer_recursivo(tablero, mover(caballo, i), iteracion + 1)) 
            {
                return true;
            }
        }
        tablero.items[caballo.x][caballo.y] = 0;
        intentos++;
        return false;
    }
}

bool es_ultima_iteracion(t_tablero tablero, int iteracion) 
{
    return iteracion == tablero.jugadas;
}

t_posicion mover(t_posicion caballo, int index) 
{
    return (t_posicion) 
    { 
        .x = caballo.x + movimientos[index].x, // (1 +  (index % 2)) * (index % 4 < 2 ? 1 : -1)
        .y = caballo.y + movimientos[index].y  // (1 + !(index % 2)) * (index % 8 < 4 ? 1 : -1)
    };
}

bool esta_libre(t_tablero tablero, t_posicion posicion) 
{
    return pertenece(tablero.tamanio, posicion)
        && tablero.items[posicion.x][posicion.y] == 0;
}

bool pertenece(int tamanio, t_posicion posicion) 
{
    return 0 <= posicion.x && posicion.x < tamanio
        && 0 <= posicion.y && posicion.y < tamanio;
}

int mostrar(t_tablero tablero) 
{   
    for (int x = 0; x < tablero.tamanio; x++) 
    {
        for (int y = 0; y < tablero.tamanio; y++) 
        {
            printf("%6d", tablero.items[x][y]);
        }
        printf("\n\n");
    }
}