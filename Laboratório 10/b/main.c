/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 10b - DON'T PANIC - Part 1 */

#include <stdio.h>
#include <stdlib.h>

/* Verifica se o vetor esta ordenado e executa uma sequencia de ordenacao */
int movePanquecas(int pilha[], int n, int *peso);

/* Arrasta elementos da Strip ate newPOS */
void arrasta(int vet[], int tam, int lastStrip, int newPOS);

int main () {
    int peso = 0, n, *pilha;
    int i;

    scanf("%d", &n);
    
    pilha = malloc(n * sizeof(int));
   
    for(i = 0; i < n; i++)
        scanf("%d", &pilha[i]);

    /* Continua a ordenar ate que ele esteja ordenado */
    while(!movePanquecas(pilha, n, &peso));

    printf("Peso: %d\n", peso);
    
    free(pilha);

    return 0;
}

/* Retorna se o vetor esta ordenado (1) ou nao (0) - e realiza uma sequencia
 * de ordenacao*/
int movePanquecas(int pilha[], int n, int *peso) {
    int ordenado = 1, newPOS = 0, lastStrip;
    int i, j, k;

    /* Imprime vetor */
    printf("(");
    for (i = 0; i < n; i++) {
        /* Caso seja o ultimo elemento, fecha os parenteses */
        if (i == n - 1)
            printf("%d)\n", pilha[i]);
        else
            printf("%d ", pilha[i]);
    }
    
    /* Verifica se o vetor esta ordenado */
    for (i = 0; (i < n - 1) && (ordenado); i++) {
        if (pilha[i] + 1 != pilha[i + 1]) {
            /* Vetor nao esta ordenado */
            ordenado = 0;
            /* Posicao do ultimo elemento do strip */
            lastStrip = i;
        }
    }

    /* Caso o vetor esteja ordenado, finaliza funcao */
    if (ordenado)
        return ordenado;

    /* Encontra onde o strip deve ser encaixado */
    for (j = i; !(newPOS) && j < n; j++) {
        /* Caso Strip deva ser encaixado após esse elemento */
        if (pilha[0] - 1 == pilha[j]) {
            newPOS = j;
            /* Como encontrou um elemento menor, talvez seja possivel eliminar
             * mais de um breakpoint, sendo entao necessario verificar */
            for (k = i; k < j; k++)
                if (pilha[k] + 1 == pilha[j + 1])
                    /* Atualiza posicao da lastStrip de modo a remover dois
                     * breakpoints */
                    lastStrip = k;
        }
        
        /* Caso Strip deva ser encaixado antes desse elemento */
        else if (pilha[lastStrip] + 1 == pilha[j]) {
            newPOS = j - 1;
        }
    }

    /* Arrasta elementos do Strip para nova posicao */
    arrasta(pilha, n, lastStrip + 1, newPOS);
    
    /* Atualiza peso baseado no numero de panquecas que foram movidas */
    (*peso) += newPOS + 1;
    
    return ordenado;
}

/* Arrasta elementos da strip ate newPOS */
void arrasta(int vet[], int tam, int lastStrip, int newPOS) {
    int j, aux;

    /* Rearranja vetor ate ter rearranjado toda a Strip */
    while(lastStrip) {
        aux = vet[0];
        for (j = 0; j < newPOS; j++)
            vet[j] = vet[j + 1];
        vet[newPOS] = aux;
        lastStrip--;
    }
}
   