/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 12a - CUT++ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101
#define MAX_CAMPO 501

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

/* Funcao responsavel por gerar csv reduzido em arquivo */
void gera_csv_reduzido(char fnamein[], char fnameout[]) {
    FILE *entrada, *saida;
    int *ref_campos;
    int N, i, j, ok = 1, colunas = 1;
    char **info_campo, teste;

    entrada = fopen(fnamein, "r");
    saida = fopen(fnameout, "w");

    /* Checa se os arquivos foram lidos corretamente */
    if ((entrada == NULL) || (saida == NULL))
        return;

    /* Realiza leitura e alocao de dados */
    scanf("%d", &N);
    ref_campos = malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &ref_campos[i]);
    
    /* Computa numero total de colunas de acordo com o numero de campos */
    while (ok) {
        fscanf(entrada, "%c", &teste);
        /* Caso encontre uma virgula, computa como um campo a mais */
        if (teste == ',')
            colunas++;
        /* Caso encontre o fim da linha, finaliza contagem */
        else if (teste == '\n')
            ok = 0;
    }
    
    /* Aloca dinamicamente matriz, sendo cada campo uma linha de string */
    info_campo = malloc(colunas * sizeof(char *));
    for (i = 0; i < colunas; i++)
        info_campo[i] = malloc(MAX_CAMPO * sizeof(char));
    
    /* Retorna endereco de entrada para inicio */
    rewind(entrada);
    
    /* Realiza leitura enquanto arquivo nao atinge o fim do arquivo */
    while (fscanf(entrada, "%c", &teste) != EOF) {
        /* Organiza todos os campos da linha do arquivo na matriz */
        for (i = 0; i < colunas; i++) {
            for (j = 0, ok = 1; (j < MAX_CAMPO) && ok; j++) {
                /* Caso o campo atinja o fim, altera flag e finaliza
                 * string do campo */
                if ((teste == '\n') || (teste == ',')) {
                    ok = 0;
                    info_campo[i][j] = '\0';
                }
                /* Caso nao tenha atingido o fim, copia normalmente */
                else
                    info_campo[i][j] = teste;
                /* Caso ainda nao tenha atingido o fim da linha, inicia
                 * proxima leitura */
                if (teste != '\n')
                    fscanf(entrada, "%c", &teste);
            }
        }
        for (i = 0; i < N; i++) {
            /* Imprime cada campo no arquivo saida */
            fprintf(saida, "%s", info_campo[ref_campos[i] - 1]);
            /* Caso nao seja o ultimo campo da linha, acrescenta ',' */
            if (i != N - 1)
                fprintf(saida, ",");
        }
        /* Acrescenta finalizacao de linha na saida */
        fprintf(saida, "\n");
    }
    
    /* Desaloca memoria */
    for (i = 0; i < colunas; i++)
        free(info_campo[i]);
    free(info_campo);
    
    fclose(entrada);
    fclose(saida);
}