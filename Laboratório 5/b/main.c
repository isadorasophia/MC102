/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 05b - Killing the Messenger*/

#include <stdio.h>
int main () {
    int R, O, i, k, silencia, pare = 1;
    char mRNA[101], oligo[26];

    /* Le as bases nitrogenadas de mRNA e de oligonucleotideo, bem como as
     * quantidades totais */
    scanf("%d %d", &R, &O);
    scanf("%s", mRNA);
    scanf("%s", oligo);

    /* Verifica se silencia enquanto nao atinge a casa limite */
    for (i = 0; i <= R - O && (pare); i++) {
        silencia = 1;
        /* Eh checado se silencia, comparando as bases nitrogenadas na ordem
         * adequada */
        for (k = 0; k < O && (silencia); k++) {
            if ((oligo[O - 1 - k] == 'A') && (mRNA[i + k] != 'U'))
                silencia = 0;
            if ((oligo[O - 1 - k] == 'U') && (mRNA[i + k] != 'A'))
                silencia = 0;
            if ((oligo[O - 1 - k] == 'C') && (mRNA[i + k] != 'G'))
                silencia = 0;
            if ((oligo[O - 1 - k] == 'G') && (mRNA[i + k] != 'C'))
                silencia = 0;
            /* Sinaliza que ja silenciou */
            if ((k == O - 1) && (silencia))
                pare = 0;
        }
    }

    if (silencia)
        printf("Silenciado em %d\n", i);

    else
        printf("Nao silenciado\n");

    return 0;
}