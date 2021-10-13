#include "shared.c"

void init(t_tablero* tablero, t_posicion* caballo, int argc, char** argv);

int main(int argc, char** argv) 
{
    t_tablero tablero;
    t_posicion pos_inicial;
    
    init(&tablero, &pos_inicial, argc, argv);

    if(recorrer(tablero, pos_inicial)) mostrar(tablero);

    for (int i = 0; i < tablero.tamanio; i++) 
    {
        free(tablero.items[i]);
    }
    free(tablero.items);

    return EXIT_SUCCESS;
}

void init(t_tablero* tablero, t_posicion* pos_inicial, int argc, char** argv)
{
    setlocale(LC_NUMERIC, "");
    if (argc < 4) 
    {
        puts("Faltan parametros:");
        printf("$ %s [TAMANIO_TABLERO] [POSX] [POSY]\n", *argv);
        exit(EXIT_FAILURE);
    }

    tablero->tamanio = atoi(argv[1]);
    if (tablero->tamanio <= 0) 
    {
        puts("El tamanio del tablero no es valido! Debe ser mayor a cero:");
        printf("$ %s [TAMANIO_TABLERO] [POSX] [POSY]\n", *argv);
        exit(EXIT_FAILURE);
    }
    tablero->jugadas = tablero->tamanio * tablero->tamanio;

    pos_inicial->x = atoi(argv[2]);
    pos_inicial->y = atoi(argv[3]);
    if (!pertenece(tablero->tamanio, *pos_inicial)) 
    {
        puts("La posicion inicial no es valida! Debe estar dentro del tablero:");
        printf("$ %s [TAMANIO_TABLERO] [POSX] [POSY]\n", *argv);
        exit(EXIT_FAILURE);
    }

    tablero->items = calloc(sizeof *(tablero->items), tablero->tamanio);
    for (int i = 0; i < tablero->tamanio; i++) 
    {
        tablero->items[i] = calloc(sizeof **(tablero->items), tablero->tamanio);
    }
}