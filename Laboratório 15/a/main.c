/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 15a - Transferencia de Bitcoins */

#include <stdio.h>
#include <math.h>

/* Prototipos de funcoes */
void makeInt(char*, int);
void arranjo(char*, int*, int, int*, int);
int soma(int*, char*, int, int, int, int);

int main () {
    char entrada[10];
    int analise[8], ok = 0, safeNumber;

    scanf(" %s %d", entrada, &safeNumber);
    
    /* Transforma valores da entrada em inteiros */
    makeInt(entrada, 9);

    /* Realiza todas os arranjos e verifica se eh possivel realizar a
     * transferencia */
    arranjo(entrada, analise, 0, &ok, safeNumber);

    if (ok)
        printf("Transferencia aceita\n");
    else
        printf("Transferencia abortada\n");

    return 0;
}

/* Transforma valores de char em inteiros analogos */
void makeInt(char vetor[], int tam) {
    int i;

    for (i = 0; i < tam; i++)
        vetor[i] -= 48;
}

/* Arranja o vetor analise de modo a randomizar as posicoes de soma (+1),
 * subtracao (-1) ou de juncao (0) dos valores da entrada */
void arranjo(char entrada[], int analise[], int pos, int *ok, 
            int safeNumber) {
    int i;
    
    /* Caso tenha finalizado um arranjo, verifica se a soma confere */
    if (pos == 8) {
        if (soma(analise, entrada, 8, 0, 0, 0) == safeNumber)
            (*ok) = 1;
    }
    
    /* Randomiza os valores da analise enquanto nao encontrar a soma adequada */
    else
        for (i = -1; i <= 1 && (*ok == 0); i++) {
            analise[pos] = i;
            arranjo(entrada, analise, pos + 1, ok, safeNumber);
        }
}

/* Retorna a soma total dos valores randomizados da entrada */
int soma(int analise[], char entrada[], int pos, int k, int temp, int sum) {
    /* Atualiza temp como o resultado da juncao predefinida dos valores da
     * entrada */
    temp += entrada[pos] * pow(10, k);
    k++;
    
    /* Caso esteja na primeira posicao, retorna a soma com o valor de temp */
    if (pos == 0)
        return sum + temp;
    
    /* Adiciona o valor de temp e reinicia seus respectivos valores */
    if (analise[pos - 1] == 1) {
        sum += temp;
        k = 0;
        temp = 0;
    }

    /* Subtrai o valor de temp e reinicia seus respectivos valores */
    else if (analise[pos - 1] == -1) {
        sum -= temp;
        k = 0;
        temp = 0;
    }

    /* Chama a funcao novamente para retornar a soma */
    return soma(analise, entrada, pos - 1, k, temp, sum);
}