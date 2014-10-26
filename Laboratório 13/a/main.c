/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 13a - JMob */

#include <stdio.h>

/* Prototipo de funcao */
void verifica_mobile(int *peso_total, int *equilibrado);

int main () {
    int peso_total = 0, equilibrado = 1;
   
    /* Funcao determina o peso total e se cada mobile esta equilibrada */
    verifica_mobile(&peso_total, &equilibrado);

    if (equilibrado)
        printf("Mobile equilibrado\n");
    else
        printf("Mobile desequilibrado\n");
    printf("Peso total: %d\n", peso_total);

    return 0;
}

/* Funcao responsavel por construir as mobiles - computa o peso total e 
 * verifica se cada mobile esta equilibrada */
void verifica_mobile(int *peso_total, int *equilibrado) {
    int Pe, De, Pd, Dd;

    scanf("%d %d %d %d", &Pe, &De, &Pd, &Dd);

    /* Atualiza peso de acordo com dados lidos */
    *peso_total += Pe + Pd;

    /* Descobre os pesos das extremidades conectadas a outras barras */
    if (Pe == 0) {
        /* Descobre o peso da mobile em Pe de acordo com a diferenca de pesos 
         * totais */
        Pe = *peso_total;
        verifica_mobile(peso_total, equilibrado);
        Pe = *peso_total - Pe;
    }
    if (Pd == 0) {
        /* Descobre o peso da mobile em Pd de acordo com a diferenca de pesos 
         * totais */
        Pd = *peso_total;
        verifica_mobile(peso_total, equilibrado);
        Pd = *peso_total - Pd;
    }
    
    /* Verifica se a mobile esta equilibrada */
    if (De * Pe != Pd * Dd)
        *equilibrado = 0;
    
    return;
}