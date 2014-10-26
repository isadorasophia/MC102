#include <stdio.h>
int main () {
    int N, posicao = 1, inutil = 1, j = 0, i, dicas[100], usados[100];

    scanf("%d", &N);

    for (i=0; i < N; i++)
        scanf("%d", &dicas[i]);

    /* Aqui ele comecara a seguir o caminho do tesouro */
    do {
        /* Em que j eh a posicao do armazenamento do vetor do numero posicao 
        da dica */
        usados[j] = posicao;
        
        posicao = dicas[posicao - 1];

        for(i=0; i < j; i++) {
            if (usados[i] == posicao)
                inutil = 0;
        }
        j++;
    } while ((dicas[posicao - 1] != posicao) && (inutil) && (j < N));
    /* Enquanto a dica nao for igual a posicao dela mesma ou condicao para nao 
existir - se inutil for igual a 0, eh porque o caminho ja se tornou inutil e 
nao havera tesouro, pois ele dara voltas ao mesmo lugar */

    if (dicas[posicao - 1] == posicao)
        printf("Tesouro encontrado em %d\n", posicao);

    else
        printf("Nao existe tesouro\n");

    return 0;
}