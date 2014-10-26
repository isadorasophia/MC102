/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 13b - Fruit Crush Saga - Part III */

#include <stdio.h>
#include <math.h>

#define tamJOGO 51

/* Prototipo das funcoes */
void detecta(char escolha, int x, int y, int M, int N, char jogo[][tamJOGO],
             int *score);
void gravidade(int x, int y, int M, int N, char jogo[][tamJOGO]);
void troca (char *a, char *b);

int main () {
    char jogo[tamJOGO][tamJOGO], escolha;
    int x, y, score, scoreTOTAL = 0;
    int M, N, J, i, j;

    /* M = linhas, N = colunas, J = numero de jogadas */
    scanf("%d %d %d", &M, &N, &J);

    /* Le tabuleiro */
    for (i = 0; i < M; i++)
        scanf("%s", &jogo[i][0]);

    /* Computa cada jogada e seu respectivo efeito no tabuleiro */
    for (j = 0; j < J; j++) {
        /* Le e ajusta para coordenadas da matriz */
        scanf("%d %d", &x, &y);
        x--;
        y--;
       
        escolha = jogo[x][y];
        
        /* Verifica se a jogada eh nao nula */
        if (escolha != '.') {
            score = 0;
        
            /* Detecta elementos da matriz que sao eliminados */
            detecta(escolha, x, y, M, N, jogo, &score);
            
            /* Atualiza score total conforme o score da jogada */
            scoreTOTAL += score * score;

            /* Aplica a acao da gravidade para cada coluna de frutas */
            for (i = 1; i <= N; i++) {
                gravidade(M - 1, N - i, M, N, jogo);
            }
        }
    }

    /* Exibe score e tabuleiro final */
    printf("Score: %d\n", scoreTOTAL);
    for (i = 0; i < M; i++) {
        printf("%s\n", jogo[i]);
    }

    return 0;
}

/* Detecta as frutas que devem ser eliminadas conforme a jogada feita */
void detecta(char escolha, int x, int y, int M, int N, char jogo[][tamJOGO],
            int *score) {
    /* Caso as coordenadas excedam o limite da matriz, funcao se finaliza */
    if ((x >= M) || (x < 0) || (y >= N) || (y < 0))
        return;

    /* Se a fruta nao coincidir com a escolha inicial, nao havera eliminacao ou
     * continuidade e a funcao se finaliza */
    if (escolha != jogo[x][y])
        return;
    
    /* Elimina fruta e acrescenta score */
    jogo[x][y] = '.';
    *score += 1;

    /* Avalia frutas vizinhas candidatas a serem eliminadas */
    detecta(escolha, x + 1, y, M, N, jogo, score);
    detecta(escolha, x - 1, y, M, N, jogo, score);
    detecta(escolha, x, y + 1, M, N, jogo, score);
    detecta(escolha, x, y - 1, M, N, jogo, score); 
}

/* Desce as frutas ainda nao eliminadas */
void gravidade(int x, int y, int M, int N, char jogo[][tamJOGO]) {
    int i;
    
    /* Caso tenha atingido a casa limite, a funcao se finaliza */
    if (x <= 0)
        return;
    
    /* Desce a fruta diante de uma posicao eliminada */
    if ((jogo[x - 1][y] != '*') && (jogo[x][y] == '.')) {
        /* Desce a fruta conforme quantidade total de frutas eliminadas */
        for (i = 0; ((x + i) < M) && (jogo[x + i][y] == '.'); i++)
            troca(&jogo[x + i][y], &jogo[x + i - 1][y]);
    }

    /* Avalia frutas que devem continuar a descer */
    gravidade(x - 1, y, M, N, jogo);
}

/* Troca o conteudo de dois enderecos dados */
void troca (char *a, char *b) {
    char aux;
    
    aux = *b;
    *b = *a;
    *a = aux;
}