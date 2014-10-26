/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 15b - DON'T PANIC - Part II */

#include <stdio.h>
#include <stdlib.h>

/* Prototipo de funcoes */
int findEnd(int*, int);
int findPesoMax(int*, int, int);
int findPesoMin(int*, int, int, int);
void transposicao(int*, int, int);

int main () {
    int *pilha, *pilhaAUX, n, i;
    int limInferior = 0, limSuperior = 0, pesoMin = 0;

    scanf("%d", &n);
    
    pilha = malloc((n + 1) * sizeof(int));
    pilha[0] = 0;
    
    pilhaAUX = malloc((n + 1) * sizeof(int));
    pilhaAUX[0] = 0;

    for(i = 1; i < n + 1; i++) {
        scanf("%d", &pilha[i]);
        pilhaAUX[i] = pilha[i];
    }
    
    /* Encontra o limite inferior - ou seja, a posicao limite da permutacao */
    limInferior = findEnd(pilha, n);
    
    /* Caso a permutacao nao esteja ordenada */
    if (limInferior) {
        /* Encontra o limite superior com o vetor auxiliar */
        limSuperior = findPesoMax(pilhaAUX, limInferior, limSuperior);
        
        /* Encontra o peso minimo */
        pesoMin = findPesoMin(pilha, limInferior, 0, limSuperior);
    }

    printf("Limitante inferior: %d\nPeso: %d\nLimitante superior: %d\n",
            limInferior, pesoMin, limSuperior);

    free(pilha);
    free(pilhaAUX);

    return 0;
}

/* Retorna a posicao limite de uma permutacao - caso ela ja esteja ordenada,
 * retorna 0 */
int findEnd(int pilha[], int last) {
    int i = 1;
    
    /* Caso o elemento corresponda a sua posicao final, ja esta ordenado e nao
     * cabe inclui-lo na permutacao */
    if (pilha[last] == last) {
        /* Continua a percorrer a permutacao ate encontrar um elemento nao
         * ordenado */
        while (pilha[last] - i == pilha[last - i] && i < last)
            i++;
        return last - i;
    }
    
    /* Caso nenhum elemento ja esteja em sua posicao final, o limite eh o
     * proprio tamanho da permutacao */
    return last;
}

/* Retorna o limite superior atraves do algoritmo anterior de ordenacao */
int findPesoMax(int pilha[], int n, int peso) {
    int i = 1, j;
    int I, J = 0;
    
    /* Caso o vetor esteja ordenado, finaliza funcao */
    if (n == 0)
        return peso;
    
    /* Encontra a posicao do primeiro breakpoint */
    while (pilha[i] + 1 == pilha[i + 1])
        i++;
    I = i + 1;
    
    /* Encontra onde o strip deve ser encaixado */
    for (j = I; !(J) && j <= n; j++)
        /* Caso o strip deva ser encaixado depois desse valor */
        if (pilha[1] - 1 == pilha[j]) {
            J = j + 1;
            /* Como encontrou um valor menor, talvez seja possivel eliminar
             * mais de um breakpoint, sendo entao necessario verificar */
            for (i = I; i < j; i++)
                if (pilha[i] + 1 == pilha[J])
                    /* Atualiza posicao da transposicao de modo a remover dois
                     * breakpoints */
                    I = i + 1;
        }
        /* Caso o strip deva ser encaixado antes desse valor */
        else if (pilha[I - 1] + 1 == pilha[j]) {
            J = j;
        }
    
    /* Realiza a transposicao de prefixos */
    transposicao(pilha, I, J);
    
    /* Atualiza peso de acordo com o numero de panquecas que foram movidas */
    peso += J - 1;

    /* Chama a funcao novamente ate ordenar a permutacao */
    return findPesoMax(pilha, findEnd(pilha, n), peso);
}

/* Encontra o peso minimo necessario para ordenar dada permutacao */
int findPesoMin(int pilha[], int last, int pesoAtual, int pesoMin) {
    int i, j, I, J;
    
    /* Caso o vetor esteja ordenado, retorna o peso minimo */
    if (last == 0) {
        if (pesoAtual < pesoMin)
            return pesoAtual;
        return pesoMin;
    }

    /* Analisa todas as formas de combinacoes para transposicao de prefixo */
    for (i = 2; i <= last; i++)
        for (j = i + 1; j <= last + 1; j++) {
            I = i;
            J = j;
            
            transposicao(pilha, I, J);
            pesoAtual += J - 1;
            /* Caso tal transposicao indique a possibilidade de encontrar um
             * peso menor, continua com a chamada recursiva */
            if (findEnd(pilha, last) + pesoAtual < pesoMin)
                pesoMin = findPesoMin(pilha, findEnd(pilha, last), pesoAtual,
                          pesoMin);
            /* Retorna ao valor anterior da permutacao e do peso para dar
             * continuidade a analise */
            transposicao(pilha, J - I + 1, J);
            pesoAtual -= J - 1;
        }
    
    return pesoMin;
}

/* Transpoe dois prefixos dado dois parametros (i, j) */
void transposicao(int pilha[], int i, int j) {
    int *prefixo, k;
    
    prefixo = malloc((j - i) * sizeof(int));
    
    /* Armazena um dos prefixos e realiza o realocamento de valores */
    for (k = 0; k < j - i; k++)
        prefixo[k] = pilha[i + k];
    for (k = 1; k < i; k++)
        pilha[j - k] = pilha[i - k];
    for (k = 0; k < j - i; k++)
        pilha[1 + k] = prefixo[k];
    
    free(prefixo);
}