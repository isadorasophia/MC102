/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 02b - Pedra - Papel - Tesoura - Lagarto - Spock */

#include <stdio.h>
int main () {
    int n, s, l, PONTs, PONTl;
    /* Sendo s para a jogada de Sheldon e l para a jogada de Leonard, e PONT*
a contagem de suas respectivas pontuacoes */
    
    scanf("%d",  &n);
    /* Insere-se o numero de partidas */

    for (PONTs = 0, PONTl = 0; n > 0; n --) {
        scanf("%d %d", &s, &l);
        /* Onde insere-se a escolha de Sheldon e Leonard, respectivamente */
    
        /* Para casos de empate */
        if (s == l) {
            printf ("Empate\n");
        }
        
        /* Entre Tesoura e Papel */
        else if ((s == 3) && (l == 2)) {
            printf ("Sheldon: Tesoura corta Papel\n");
            PONTs++;
        }
        else if ((s == 2) && (l == 3)) {
            printf("Leonard: Tesoura corta Papel\n"); 
            PONTl++;
        }

        /* Entre Papel e Pedra */
        else if ((s == 2) && (l == 1)) {
            printf("Sheldon: Papel embrulha Pedra\n");
            PONTs++;
        }
        else if ((s == 1) && (l ==2)) {
            printf("Leonard: Papel embrulha Pedra\n");
            PONTl++;
        }

        /* Entre Pedra e Lagarto */
        else if ((s == 1) && (l == 4)) {
            printf("Sheldon: Pedra amassa Lagarto\n");
            PONTs++;
        }
        else if ((s == 4) && (l == 1)) {
            printf("Leonard: Pedra amassa Lagarto\n");
            PONTl++;
        }

        /* Entre Lagarto e Spock */
        else if ((s == 4) && (l == 5)) {
            printf("Sheldon: Lagarto envenena Spock\n");
            PONTs++;
        }
        else if ((s == 5) && (l == 4)) {
            printf("Leonard: Lagarto envenena Spock\n");
            PONTl++;
        }

        /* Entre Spock e Tesoura */
        else if ((s == 5) && (l == 3)) {
            printf("Sheldon: Spock quebra Tesoura\n");
            PONTs++;
        }
        else if ((s == 3) && (l == 5)) {
            printf("Leonard: Spock quebra Tesoura\n");
            PONTl++;
        }

        /* Entre Tesoura e Lagarto */
        else if ((s == 3) && (l == 4)) {
            printf("Sheldon: Tesoura decepa Lagarto\n");
            PONTs++;
        }
        else if ((s == 4) && (l == 3)) {
            printf("Leonard: Tesoura decepa Lagarto\n");
            PONTl++;
        }

        /* Entre Lagarto e Papel */
        else if ((s == 4) && (l == 2)) {
            printf("Sheldon: Lagarto come Papel\n");
            PONTs++;
        }
        else if ((s == 2) && (l == 4)) {
            printf("Leonard: Lagarto come Papel\n");
            PONTl++;
        }

        /* Entre Papel e Spock */
        else if ((s == 2) && (l == 5)) {
            printf("Sheldon: Papel refuta Spock\n");
            PONTs++;
        }
        else if ((s == 5) && (l == 2)) {
            printf("Leonard: Papel refuta Spock\n");
            PONTl++;
        }
    
        /* Entre Spock e Pedra */
        else if ((s == 5) && (l == 1)) {
            printf("Sheldon: Spock vaporiza Pedra\n");
            PONTs++;
        }
        else if ((s == 1) && (l == 5)) {
            printf("Leonard: Spock vaporiza Pedra\n");
            PONTl++;
        }

        /* Entra Pedra e Tesoura */
        else if ((s == 1) && (l == 3)) {
            printf("Sheldon: Pedra quebra Tesoura\n");
            PONTs++;
        }
        else if ((s == 3) && (l == 1)) {
            printf("Leonard: Pedra quebra Tesoura\n");
            PONTl++;
        }
    }

    printf("Sheldon %d x %d Leonard\n", PONTs, PONTl);
    /* Imprime-se a pontuacao final obtida das partidas */

    return 0;
}