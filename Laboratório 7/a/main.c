/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 07a - The Voice - Blind Auditions */

#include <stdio.h>
int main () {
    int N, i, j, escolha, pare = 1, POStime1 = 0, POStime2 = 0, POStime3
= 0, POStime4 = 0;
    int jurados[100][4], participantes[100][4], time1[100], time2[100],
time3[100], time4[100];

    /* Le numero de participantes */
    scanf("%d", &N);

    /* Le reacao dos jurados e preferencia dos candidatos */
    for (i = 0; i < N; i++) {
        for (j = 0; j < 4; j++)
            scanf("%d", &jurados[i][j]);
        for (j = 0; j < 4; j++)
            scanf("%d", &participantes[i][j]);
    }
   
    /* Computa o time de cada candidato */
    for (i = 0; i < N; i++) {
        /* Verifica cada time conforme a ordem de escolha */
        for (j = 0; (j < 4) && (pare); j++) {
            escolha = participantes[i][j];
           
            /* Caso o time de preferencia seja positivo, acrescenta o candidato
             * nesse time */
            if (jurados[i][escolha - 1]) {
                /* Finaliza verificacao deste candidato */
                pare = 0;
                
                if (escolha == 1) {
                    time1[POStime1] = i + 1;
                    POStime1++;
                }
                else if (escolha == 2) {
                    time2[POStime2] = i + 1;
                    POStime2++;
                }
                else if (escolha == 3) {
                    time3[POStime3] = i + 1;
                    POStime3++;
                }
                else if (escolha == 4) {
                    time4[POStime4] = i + 1;
                    POStime4++;
                }
            }
        }
        pare = 1;
    }
    
    /* Expressa resultados */
    printf("Time 1:");
    if (POStime1) {
        for (i = 0; i < POStime1; i++) {
            printf(" %d", time1[i]);
        }
    }
    else
        printf(" Nenhum participante");
    
    printf("\nTime 2:");
    if (POStime2) {
        for (i = 0; i < POStime2; i++) {
            printf(" %d", time2[i]);
        }
    }
    else
        printf(" Nenhum participante");
    
    printf("\nTime 3:");
    if (POStime3) {
        for (i = 0; i < POStime3; i++) {
            printf(" %d", time3[i]);
        }
    }
    else
        printf(" Nenhum participante");
    
    printf("\nTime 4:");
    if (POStime4) {
        for (i = 0; i < POStime4; i++) {
            printf(" %d", time4[i]);
        }
    }
    else
        printf(" Nenhum participante");

    printf("\n");
    
    return 0;
}