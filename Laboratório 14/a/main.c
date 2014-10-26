/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 14a - Gerenciador de memoria */

#include <stdio.h>

/* Prototipo de funcao */
void alocaMemoria(char, int*, int*);

int main () {
    char comando;
    /* D representa memorias disponiveis e I representa as memorias ocupadas */
    int countD = 1, countI = 0;

    scanf(" %c", &comando);
    alocaMemoria(comando, &countD, &countI);

    /* Caso o numero de memorias disponiveis seja igual ao numero de memorias 
     * ocupadas */
    if (countD == countI)
        printf("Alocacao total\n");
    
    /* Caso o numero de memorias disponiveis seja maior que o numero de 
     * memorias ocupadas */
    else if (countD > countI)
        printf("Alocacao parcial\n");
    
    /* Caso o numero de memorias disponiveis seja menor que o numero de 
     * memorias ocupadas */
    else
        printf("Alocacao invalida\n");
    
    return 0;
}

/* Funcao responsavel por contabilizar a memoria criada e ocupada */
void alocaMemoria(char comando, int *countD, int *countI) {
    /* Caso crie um novo espaco de memoria */
    if (comando == 'D')
        (*countD)++;

    /* Caso ocupe um espaco de memoria */
    else if (comando == 'I')
        (*countI)++;
    
    /* Caso atinja o fim ou a memoria tenha se excedido */
    if ((*countD < *countI) || (comando == '#'))
        return;
    
    scanf(" %c", &comando);
    alocaMemoria(comando, countD, countI);
}