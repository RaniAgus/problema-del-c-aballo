#include "shared.c"

bool init(t_tablero* tablero, int argc, char** argv);
int reiniciar(t_tablero tablero);

int main(int argc, char** argv) 
{
    t_tablero tablero;
    t_posicion pos_inicial;
    
    bool verbose = init(&tablero, argc, argv);

    for (int i = 0; i < tablero.tamanio; i++)
    {
        for (int j = 0; j < tablero.tamanio; j++)
        {
            if (recorrer(tablero, (t_posicion){ i, j }) && verbose) 
            { 
                mostrar(tablero);
            }
            reiniciar(tablero);
        }
    }

    for (int i = 0; i < tablero.tamanio; i++) 
    {
        free(tablero.items[i]);
    }
    free(tablero.items);

    return EXIT_SUCCESS;
}

bool init(t_tablero* tablero, int argc, char** argv)
{
    setlocale(LC_NUMERIC, "");
    if (argc < 2) 
    {
        puts("Faltan parametros:");
        printf("$ %s [TAMANIO_TABLERO] [-v]\n", *argv);
        exit(EXIT_FAILURE);
    }

    tablero->tamanio = atoi(argv[1]);
    if (tablero->tamanio <= 0) 
    {
        puts("El tamanio del tablero no es valido! Debe ser mayor a cero:");
        printf("$ %s [TAMANIO_TABLERO] [-v]\n", *argv);
        exit(EXIT_FAILURE);
    }
    tablero->jugadas = tablero->tamanio * tablero->tamanio;

    tablero->items = calloc(sizeof *(tablero->items), tablero->tamanio);
    for (int i = 0; i < tablero->tamanio; i++) 
    {
        tablero->items[i] = calloc(sizeof **(tablero->items), tablero->tamanio);
    }

    return argc == 3 && !strcmp(argv[2], "-v");
}

int reiniciar(t_tablero tablero) 
{
    for (int x = 0; x < tablero.tamanio; x++) 
    {
        memset(tablero.items[x], 0, tablero.tamanio * sizeof tablero.items[x][0]);
    }
    intentos = 0;
}