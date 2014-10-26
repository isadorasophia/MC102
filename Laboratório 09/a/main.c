/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 09a - Oliver Queen is alive! */

#include <stdio.h>
int main () {
    int D, T, mapa[30][30], i, j, S;
    int vivo = 1, achou = 1;
    int sentido;

    scanf("%d %d", &D, &T);
    
    for (i = 0; i < D; i++)
        for (j = 0; j < D; j++)
            scanf(" %d", &mapa[i][j]);

    /* Sentido da peca:
     * 1 = norte | -1 = sul | 2 = leste | -2 = oeste */
    sentido = 2;
    
    /* Faz o movimento no mapa antes que o tempo acabe */
    for (S = 0, i = 0, j = 0; (S < T) && vivo && achou; S++) {
        /* Checa a cor da posicao */
        switch (mapa[i][j]) {
            /* Cor branca = frente */
            case 0:
                /* Marca a posicao com a nova cor adequada */
                mapa[i][j] = 1;
                /* Confere o sentido da peca para ir para frente */
                switch (sentido) {
                    case 1:
                        i--;
                        break;
                    case -1:
                        i++;
                        break;
                    case 2:
                        j++;
                        break;
                    case -2:
                        j--;
                        break;
                }
                break;
            /* Cor azul = esquerda */
            case 1:
                /* Marca a posicao com a nova cor adequada */
                mapa[i][j] = 2;
                /* Confere o sentido da peca para ir para esquerda, adequando o 
                 * novo sentido */
                switch (sentido) {
                    case 1:
                        j--;
                        sentido = -2;
                        break;
                    case -1:
                        j++;
                        sentido = 2;
                        break;
                    case 2:
                        i--;
                        sentido = 1;
                        break;
                    case -2:
                        i++;
                        sentido = -1;
                        break;
                }
                break;
            /* Cor verde = direita */
            case 2:
                /* Marca a posicao com a nova cor adequada */
                mapa[i][j] = 0;
                /* Confere o sentido da peca para ir para direita, adequando o 
                 * novo sentido */
                switch(sentido) {
                    case 1:
                        j++;
                        sentido = 2;
                        break;
                    case -1:
                        j--;
                        sentido = -2;
                        break;
                    case 2:
                        i++;
                        sentido = -1;
                        break;
                    case -2:
                        i--;
                        sentido = 1;
                        break;
                }
                break;
            /* Cor vermelha = morre */
            case 3:
                vivo = 0;
                break;
            /* Encontra dispositivo */
            case 4:
                achou = 0;
                break;
        }
        /* Verifica se tocou em parede externa */
        if ((i >= D) || (i < 0) || (j >= D) || (j < 0))
            vivo = 0;
    }

    if (achou == 0)
        printf("Oliver destroi o dispositivo em %d segundos\n", S - 1);
    else if (vivo == 0)
        printf("Oliver morre\n");
    else
        printf("Oliver nao chega ao dispositivo a tempo\n");

    return 0;
}