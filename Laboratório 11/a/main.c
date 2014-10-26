/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 11a - Copa do Mundo */

#include <stdio.h>
#include <string.h>

#define NUM_GRUPOS 8

struct Selecao {
    char nome[16];
    int pontosAcumulados;
    int golsFeitos;
    int golsSofridos;
    int saldoGols;
};

typedef struct Selecao Selecao;

/* Ordena vetor */
void ordenaGrupo(Selecao *grupo, int tam);

/* Define a posicao do melhor colocado a partir da posicao inicio */
int MelhorColocado(Selecao *grupo, int tam, int inicio);

/* Troca o conteudo de dois enderecos */
void troca (Selecao *a, Selecao *b);

int main () {
    Selecao selecao[NUM_GRUPOS][4], selecao_lida[NUM_GRUPOS][12];
    int i, j, k, numSelecao, achou;
    
    /* Inicializa um dos dados do registro */
    for (i = 0; i < NUM_GRUPOS; i++)
        for (j = 0; j < 12; j++)
            selecao_lida[i][j].pontosAcumulados = 0;

    for (i = 0; i < NUM_GRUPOS; i++) {
        /* Realiza a leitura por jogo - dois times por linha */
        for (j = 0; j < 12; j += 2) {           
            /* Armazena dados fornecidos */
            scanf("%s %d x %d %s", selecao_lida[i][j].nome, 
&selecao_lida[i][j].golsFeitos, &selecao_lida[i][j + 1].golsFeitos, 
selecao_lida[i][j + 1].nome);
            
            /* Com os gols feitos do adversario, computa os gols sofridos */
            selecao_lida[i][j].golsSofridos = selecao_lida[i][j + 1].golsFeitos;
            selecao_lida[i][j + 1].golsSofridos = selecao_lida[i][j].golsFeitos;
            
            /* Verifica quem venceu ou ganhou para computar pontos acumulados */
            if (selecao_lida[i][j].golsFeitos > 
selecao_lida[i][j].golsSofridos) {
                selecao_lida[i][j].pontosAcumulados += 3;
            }
            else if (selecao_lida[i][j].golsFeitos < 
selecao_lida[i][j].golsSofridos) {
                selecao_lida[i][j + 1].pontosAcumulados += 3;
            }
            /* Caso haja empate */
            else {
                selecao_lida[i][j].pontosAcumulados += 1;
                selecao_lida[i][j + 1].pontosAcumulados += 1;
            }
        }
    }

    /* Organiza as informacoes lidas por selecao */
    for (i = 0; i < NUM_GRUPOS; i++) {
        numSelecao = 0;
        for (j = 0; j < 12; j++) {
            achou = 1;
            /* Verifica se ja armazenou a selecao antes */
            for (k = 0; k < numSelecao && achou; k++) {
                if (strcmp(selecao_lida[i][j].nome, 
selecao[i][k].nome) == 0) {
                    /* Como ja havia sido armazenado os dados dessa selecao, 
soh acrescenta */
                    selecao[i][k].golsFeitos += 
selecao_lida[i][j].golsFeitos;
                    selecao[i][k].golsSofridos += 
selecao_lida[i][j].golsSofridos;
                    selecao[i][k].pontosAcumulados += 
selecao_lida[i][j].pontosAcumulados;
                    achou = 0;
                }
            }
            /* Caso selecao nao tenha sido computada antes, armazena no 
registro */
            if (achou) {
                selecao[i][numSelecao] = selecao_lida[i][j];
                numSelecao++;
            }
        }
    }

    /* Organiza dados referentes aos saldo dos gols */
    for (i = 0; i < NUM_GRUPOS; i++)
        for (j = 0; j < 4; j++)
            selecao[i][j].saldoGols = selecao[i][j].golsFeitos - 
selecao[i][j].golsSofridos;

    /* Ordena cada grupo, por ordem do melhor colocado ao pior */
    for (i = 0; i < NUM_GRUPOS; i++)
        ordenaGrupo(&selecao[i][0], 4);
    
    /* Imprime resultados */
    for (i = 0; i < NUM_GRUPOS; i++) {
        printf("Grupo %c:\n", 65 + i);
        for (j = 0; j < 4; j++) {
            printf("%-15s %3d %3d %3d %3d\n", selecao[i][j].nome, 
selecao[i][j].pontosAcumulados, selecao[i][j].golsFeitos, 
selecao[i][j].golsSofridos, selecao[i][j].saldoGols);
        }
        printf("\n");
    }
    
    printf("Oitavas de final:\n");
    for (i = 0; i < NUM_GRUPOS; i += 2) {
        printf("%15s x %s\n", selecao[i][0].nome, selecao[i + 1][1].nome);
        printf("%15s x %s\n", selecao[i + 1][0].nome, selecao[i][1].nome);
    }
            
    return 0;
}

/* Ordena o vetor da melhor selecao colocada a pior */
void ordenaGrupo(Selecao *grupo, int tam) {
    int i, melhor;
    
    for (i = 0; i < tam - 1; i++) {
        melhor = MelhorColocado(grupo, tam, i);
        troca(&grupo[i], &grupo[melhor]);
    }
}

/* Retorna a posicao do melhor colocado a partir da posicao inicio */       
int MelhorColocado(Selecao *grupo, int tam, int inicio) {
    int j, melhor = inicio;
    
    for (j = inicio + 1; j < tam; j++) {
        /* Caso a selecao da posicao j possua mais pontos acumulados */
        if (grupo[melhor].pontosAcumulados < grupo[j].pontosAcumulados)
            melhor = j;
        else if (grupo[melhor].pontosAcumulados == grupo[j].pontosAcumulados) {
            /* Caso a selecao da posicao j possua mais saldo de gols */
            if (grupo[melhor].saldoGols < grupo[j].saldoGols)
                melhor = j;
            else if (grupo[melhor].saldoGols == grupo[j].saldoGols) {
                /* Caso a selecao da posicao j tenha feito mais gols */
                if (grupo[melhor].golsFeitos < grupo[j].golsFeitos)
                    melhor = j;
                else if (grupo[melhor].golsFeitos == grupo[j].golsFeitos) {
                    /* Caso a selecao da posicao j seja lexicograficamente 
                     * menor */
                    if (strcmp(grupo[melhor].nome, grupo[j].nome) > 0)
                        melhor = j;
                }
            }
        }
    }
    
    return melhor;
}

/* Troca o conteudo referente a dois enderecos */
void troca (Selecao *a, Selecao *b) {
    Selecao aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}