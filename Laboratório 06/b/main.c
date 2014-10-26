/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 06b - Fruit Crush Saga II */

#include <stdio.h>
int main () {
    char jogo[51][51];
    int jogada [20][2], M, N, JOG, I, J, i, j, k, jog, escolha, posicao = 1,
score = 0, nulo = 1;

    /* M = linhas, N = colunas, JOG = numero de jogadas */
    scanf("%d %d %d", &M, &N, &JOG);

    /* Le tabuleiro */
    for (i = 0; i < M; i++) {
        scanf("%s", jogo[i]);
    }

    /* Le jogadas */
    for (jog = 0; jog < JOG; jog++) {
        scanf("%d %d", &jogada[jog][0], &jogada[jog][1]);
    }
    
    /* Realiza as eliminacoes conforme cada jogada */
    for (jog = 0; jog < JOG; jog++) {
        /* Arruma a posicao da jogada conforme matriz */
        I = jogada[jog][0] - 1;
        J = jogada[jog][1] - 1;
       
        escolha = jogo[I][J];
        
        /* Evita o caso em que o jogador escolhe posicao eliminada */
        if (escolha == '.')
            nulo = 0;
        
        /* Elimina proprio elemento e desce as posicoes */
        for (k = 0; (k <= I) && (nulo); k++) {
            if (k != I)
                jogo[I - k][J] = jogo[I - k - 1][J];
            else if (k == I)
                jogo[0][J] = '.';
       }
            
        /* Elimina posicoes iguais acima */
        while ((jogo[I][J] == escolha) && (nulo)) {
            posicao++;
            for (k = 0; (k < I); k++)
                jogo[I - k][J] = jogo[I - k - 1][J];
        }
        
        /* Elimina posicoes iguais abaixo */
        for (i = 0; (I + i + 1 < M) && (jogo[I + i + 1][J] == escolha); i++) {
            posicao++;
            for (k = 0; k <= I + i; k++)
                jogo[I + i + 1 - k][J] = jogo[I + i - k][J];
        }
        
        /* Elimina posicoes iguais a esquerda */
        for (j = 0; (j < J) && (jogo[I][J - j - 1] == escolha); j++) {
            posicao++;
            for (k = 0; k <= I; k++) {
                if (k != I)
                    jogo[I - k][J - j - 1] = jogo[I - k - 1][J - j - 1];
                else if (k == I)
                    jogo[0][J - j - 1] = '.';
            }
        }
        
        /* Elimina posicoes iguais a direita */
        for (j = 0; (J + j + 1 < N) && (jogo[I][J + j + 1] == escolha); j++) {
            posicao++;
            for (k = 0; k <= I; k++) {
                if (k != I)
                    jogo[I - k][J + j + 1] = jogo[I - k - 1][J + j + 1];
                else if (k == I)
                    jogo[0][J + j + 1] = '.';
            }
        }
       
        /* Computa na pontuacao */
        if (nulo)
            score += posicao * posicao;
        
        nulo = 1;
        posicao = 1;
    }

    printf("Score: %d\n", score);
    /* Exibe tabuleiro final */
    for (i = 0; i < M; i++) {
        printf("%s\n", jogo[i]);
    }
    
    return 0;
}
