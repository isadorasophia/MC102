/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 03b - Fringe */

#include <stdio.h>

int main () {
    int M, S, atual, anterior, NUMascendente = 0, NUMdescendente = 0, fase = 1;

    /* Le numero de mols e fator S */
    scanf("%d %d", &M, &S);
    
    /* Le o primeiro conjunto que sera descartado */
    scanf("%d", &atual);
    
    /* Associa-se o atual a uma variavel anterior para efeito identificacao de
     * fim de uma fase ascendente para descendente ou vice-versa */
    anterior = atual;
    
    /* Descarta-se o primeiro conjunto */
    while (atual == anterior) {
        scanf("%d", &atual);
    }
    
    anterior = atual;
    
    /* Em que NUMascendente/NUMdescendente significa o valor do periodo -
     * computa-se o ultimo elemento do looping anterior */
    if (atual == 1)
        NUMascendente++;
    if (atual == 0)
        NUMdescendente++;
    
    /* Inicia-se a leitura em si, ate que ela eh finalizada com um -1\n */
    do {
        scanf("%d", &atual);
        
        /* Eh realizado uma sequencia de leitura de uma nova fase, ate que o
         * elemento se altere - verificando o elemento lido e o incrementando-o
         * adequeadamente */
        while (anterior == atual) {
            if ((anterior == atual) && (atual == 1)) {
                NUMascendente++;
            }
            if ((anterior == atual) && (atual == 0)) {
                NUMdescendente++;
            }
            scanf("%d", &atual);
        }
        
        /* Eh verificado se deve ser computado um novo fator S ou se esse deve
         * ser reiniciado, no caso de periodos diferentes */
        if (atual != -1) {
            if (NUMascendente == NUMdescendente) {
                fase++;
            }
            if (NUMascendente != NUMdescendente) {
                fase = 1;
            }
        }
        
        /* Eh realizado a leitura do novo elemento introduzido, reiniciando sua
         * contagem de periodo */
        if (atual == 1) {
            NUMascendente = 1;
        }
        if (atual == 0) {
            NUMdescendente = 1;
        }
        
        /* Eh feita a atualizacao da variavel de referencia, anterior */
        if (atual != -1)
            anterior = atual;
    } while (atual != -1);
        
    /* Progama le o numero de fases e verifica se o portal abre,
     * multiplicando o numero de mols pelo periodo (salvo em NUMdescendente ou
     * NUMascendente, dependendo do periodo terminado) */
    if (fase >=S) {
        if (anterior == 1)
            M = M * NUMdescendente;
        if (anterior == 0)
            M = M * NUMascendente;
        printf ("%d mols\n", M);
    }

    /* Se nao houver fases o suficiente, o portal nao abre */
    if (fase < S) {
        printf ("Portal nao abriu\n");
    }

    return 0;
}