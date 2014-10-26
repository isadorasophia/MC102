/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 14b - Liber8 */

#include <stdio.h>
#include <stdlib.h>

/* Prototipo de funcao */
void BOOM (int, int, int, int, char**);

int main () {
    char **mapa;
    int N, M, x, y, i;

    scanf("%d %d %d %d", &N, &M, &x, &y);

    /* Aloca memoria da matriz do mapa */
    mapa = malloc(N * sizeof(char*));
    for (i = 0; i < N; i++)
        mapa[i] = malloc((M + 1) * sizeof(char));

    for (i = 0; i < N; i++)
        scanf(" %s", mapa[i]);

    /* Ajusta as coordenadas na matriz */
    x--;
    y--;
    
    /* Realiza a explosao das coordenadas indicadas */
    BOOM(N, M, x, y, mapa);
    
    /* Imprime a situacao do mapa apos a explosao */
    for (i = 0; i < N; i++)
        printf("%s\n", mapa[i]);

    /* Desaloca a memoria */
    for (i = 0; i < N; i++)
        free(mapa[i]);
    free (mapa);
    
    return 0;
}

/* Realiza a explosao conforme instruncao do local indicado pelas coordenadas */
void BOOM(int N, int M, int x, int y, char **mapa) {
    int i, j;
    char raio;
   
    /* Caso exceda os limites do mapa */
    if ((x < 0) || (y < 0) || (x >= N) || (y >= M))
        return;

    /* Caso o local ja tenha sido eliminado */
    else if ((mapa[x][y] == 'x') || (mapa[x][y] == 'B'))
        return;
    
    /* Caso seja um local livre e que deve ser explodido */
    else if (mapa[x][y] == '.') {
        mapa[x][y] = 'x';
        return;
    }

    /* Caso seja uma bomba */
    else {
        /* Computa raio da bomba, convertendo o valor do char */
        raio = mapa[x][y] - 48;
        mapa[x][y] = 'B';
        /* Explode os locais do raio da bomba */
        for (i = 0; i <= raio; i++) {
            for (j = 0; j <= raio; j++) {
                BOOM(N, M, x + i, y + j, mapa);
                BOOM(N, M, x + i, y - j, mapa);
                BOOM(N, M, x - i, y + j, mapa);
                BOOM(N, M, x - i, y - j, mapa);
            }
        }
    }
}