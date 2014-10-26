/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 08a - Amigos dos amigos */
#include <stdio.h>

/* Le uma matriz */
void leMatriz (int tam, int matriz[][100]);
/* Confere se um elemento eh inedito em um vetor */
int confereRepetido(int NUMteste, int tam, int vetor[]);
/* Ordena um vetor */
void ordenaVetor(int vetor[], int tam);

int main () {
    int N, U, i, j, ok, usuarios[100][100], sugestao[99], NUMsugestao = 0;

    scanf("%d %d", &N, &U);

    leMatriz(N, usuarios);

    /* Confere os amigos do usuario U */
    for (i = 0; i < N; i++) {
        /* Caso seja amigo, confere amigos desse amigo do usuario U */
        if (usuarios[U][i]) {
            for (j = 0; j < N; j++) {
                /* Caso seja amigo desse amigo do usuario U, confere se o U ja 
                 * o tem adicionado */
                if (usuarios[j][i]) {
                    ok = confereRepetido (j, NUMsugestao, sugestao);
                    /* Caso nao seja amigo de U ou ja nao tenha sido 
                     * acrescentado como sugestao, acrescenta ao vetor 
                     * sugestoes */
                    if ((usuarios[U][j] == 0) && ok) {
                        sugestao[NUMsugestao] = j;
                        NUMsugestao++;
                    }
                }
            }
        }
    }

    /* Ordena o vetor */
    ordenaVetor(sugestao, NUMsugestao);
    
    /* Caso tenha elementos no vetor, imprimira as sugestoes */
    if (NUMsugestao) {
        printf("Sugestao de amigos:");
        for (i = 0; i < NUMsugestao; i++)
            printf(" %d", sugestao[i]);
    }

    else
        printf("Sem sugestao de novos amigos");

    printf("\n");

    return 0;
}

/* Le uma matriz */
void leMatriz(int tam, int matriz[][100]) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++)
            scanf(" %d", &matriz[i][j]);
    }    
        
    return;
}

/* Confere se um elemento eh inedito em um vetor */
int confereRepetido(int NUMteste, int tam, int vetor[]) {
    int i, ok = 1;
    
    /* Caso encontre um elemento igual, torna o retorno falso */
    for (i = 0; (i < tam) && ok; i++) {
        if (vetor[i] == NUMteste)
            ok = 0;
    }
        
    return ok;
}

/* Ordena um vetor */
void ordenaVetor(int vetor[], int tam) {
    int i, j, aux, POSmenor;
    
    for (j = 0; j < tam; j++) {
        POSmenor = j;
        /* Encontra o menor numero a partir de j */
        for (i = j; i < tam; i++) {
            if (vetor[i] < vetor[POSmenor])
                POSmenor = i;
        }
        /* Aloca tal menor numero na posicao j e arrasta os demais para frente 
         * */
        for (i = POSmenor; i - 1 >= j; i--) {
            aux = vetor[i];
            vetor[i] = vetor[i - 1];
            vetor[i - 1] = aux;
        }
    }
    
    return;
}