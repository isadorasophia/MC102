/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 09b - Concurso Público para Professor da UNICAMP */

#include <stdio.h>
#include <stdlib.h>

/* Ordena a preferencia de cada membro */
void ordenaPreferencia(int *preferencia, double *notas, int K);
/* Descobre o maior indice de um dado vetor */
int indiceMaior(double *vet, int K);
/* Ordena a classificacao final dos candidatos */
void ordenaClassificacao(int preferencia[][30], int *classificacao, double
*medias, int K);
/* Retorna o numero de vezes que um dado elemento aparece em um vetor */
int buscaIgual(int preferencia[][30], int elemento, int K);

int main () {
    int K, i, j, preferencia[5][30], *classificacao;
    double *notas[5], *medias;

    /* Numero K de candidatos */
    scanf("%d", &K);

    /* Aloca memoria necessaria nos vetores */
    for (i = 0; i < 5; i++) {
        notas[i] = malloc(K * sizeof(double));
    }
    classificacao = malloc(K * sizeof (int));
    medias = malloc(K * sizeof(double));

    /* Le matriz de notas dos candidatos */
    for (i = 0; i < 5; i++)
        for (j = 0; j < K; j++)
            scanf("%lf", &notas[i][j]);

    /* Calcula a nota media de cada candidato */
    for (j = 0; j < K; j++) {
        for (i = 0; i < 5; i++) {
            medias[j] += notas[i][j];
            /* Caso seja o ultimo elemento, divide pelo total */
            if (i == 4)
                medias[j] = medias[j]/5;
        }
    }
    
    /* Calcula a ordem de preferencia de cada membro por linha da matriz */
    for (i = 0; i < 5; i++)
        ordenaPreferencia(&preferencia[i][0], &notas[i][0], K);
    
    /* Calcula a classificacao final */
    ordenaClassificacao(preferencia, classificacao, medias, K);
   
    /* Imprime resultados */
    printf("Nota Media:");
    for (i = 0; i < K; i++)
        printf(" %.1f", medias[i]);

    printf("\n\nPreferencia:\n");
    for(i = 0; i < 5; i++) {
        printf("Membro %d:", i + 1);
        for(j = 0; j < K; j++)
            printf(" %d", preferencia[i][j]);
        printf("\n");
    }
   
    printf("\nClassificacao:");
    for(i = 0; i < K; i++)
        printf(" %d", classificacao[i]);
    printf("\n");

    /* Libera espaco criado */
    for (i = 0; i < 5; i++) {
        free(notas[i]);
    }
    free(medias);
    free(classificacao);

    return 0;
}

/* Ordena a preferencia de candidatos de cada membro */
void ordenaPreferencia(int *preferencia, double *notas, int K) {
    int i, max;
    for (i = 0; i < K; i++) {
        /* Encontra a posicao do candidato de maior nota */
        max = indiceMaior(notas, K);
        /* Desconsidera-se a nota do candidato ja computado */
        notas[max] = -1;
        /* Aloca tal candidato no vetor final de ordem de preferencia */
        preferencia[i] = max + 1;
    }
}

/* Descobre o maior indice de um dado vetor */
int indiceMaior(double *vet, int K) {
    int j, max = 0;
    /* Encontra a posicao do maior elemento do vetor */
    for (j = 1; j < K; j++)
        if (vet[max] < vet[j])
            max = j;
        return max;
}

/* Ordena a classificacao final dos candidatos */
void ordenaClassificacao(int preferencia[][30], int *classificacao, double
*medias, int K) {
    int i, j, w, maior, POSmaior = 0, POSclass = 0, achou;
    int preferenciaAUX[5][30];
    
    /* Preenche matriz auxiliar para rearranjar resultados */
    for (i = 0; i < 5; i++)
        for (j = 0; j < K; j++)
            preferenciaAUX[i][j] = preferencia[i][j];
    
    /* Ordena a classificacao final ate que todos os candidatos sejam
     * computados na classificacao */
    while (POSclass < K) {
        maior = buscaIgual(preferenciaAUX, preferenciaAUX[0][0], K);
        POSmaior = 0;
        for (i = 0; i < 5; i++) {
            /* Verifica se a frequencia eh maior. Se a frequencia eh igual,
             * checa a maior nota. */
            if ((buscaIgual(preferenciaAUX, preferenciaAUX[i][0], K) > maior) 
            || ((buscaIgual(preferenciaAUX, preferenciaAUX[i][0], K) ==
            maior) && (medias[preferenciaAUX[i][0] - 1] >
            medias[preferenciaAUX[POSmaior][0] - 1]))) {
                maior = buscaIgual(preferenciaAUX, preferenciaAUX[i][0], K);
                POSmaior = i;
            }
            /* Caso a nota tambem seja igual, verifica a primeira inscricao */
            else if ((buscaIgual(preferenciaAUX, preferenciaAUX[i][0], K) ==
            maior) && (medias[preferenciaAUX[i][0] - 1] ==
            medias[preferenciaAUX[POSmaior][0] - 1])) {
                if (preferenciaAUX[i][0] < preferenciaAUX[POSmaior][0]) {
                    maior = buscaIgual(preferenciaAUX, preferenciaAUX[i][0], K);
                    POSmaior = i;
                }
            }
        }
        /* Aloca o candidato no vetor de classificacao */
        classificacao[POSclass] = preferenciaAUX[POSmaior][0];
        /* Computa a posicao */
        POSclass++;        
        /* Rearranja matriz, eliminando o candidato ja computado */
        for (i = 0; i < 5; i++) {
            achou = 1;
            for (j = 0; (j < K) && achou; j++) {
                if (classificacao[POSclass - 1] == preferenciaAUX[i][j]) {
                    /* Rearrajna elementos */
                    for (w = 0; w < K - j - 1; w++)
                        preferenciaAUX[i][j + w] = preferenciaAUX[i][j + w + 1];
                    achou = 0;
                }
            }
        }
    }
    return;
}

/* Retorna o numero de vezes que um dado elemento aparece em um vetor */
int buscaIgual(int preferencia[][30], int elemento, int K) {
    int i, quant = 0;

    /* Encontra na matriz a quantidade de elementos "elemento" */
    for (i = 0; i < 5; i++)
        if (preferencia[i][0] == elemento)
            quant++;
        
    return quant;
}