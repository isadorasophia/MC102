/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 04b - Semanada */

#include <stdio.h>
int main () {
    int D, R, digitos[100], valorfinal[100], maiordigito, POSmaiordigito = 0, i,
k, j;

    /* Le a quantidade de numeros que o usuario ira digitar e a quantidade que
     * sera retirada */
    scanf("%d %d", &D, &R);

    /* Usuario digita todos os digitos */
    for (i = 0; i < D; i++)
        scanf("%d", &digitos[i]);

    /* Reinicia inteira */
    i = 0;

    /* Em que k representa a posicao do vetor do valor final, esse com D - R
     * casas */
    for (k = 0; k < D - R; k++) {
        /* Pressupoe um maior valor qualquer para comparar e descobrir o maior
         * digito, ou apenas alocar o valor que ocupara no vetor final */
        maiordigito = digitos[i];
        
        /* Descobre i, que sera a posicao ao encontrar o maior digito, sendo
         * i tambem responsavel por percorrer o vetor dos digitos ate a posicao
         * limite.
         * OBS: i deve ser menor ou igual que o maximo de caracteres que serao
         * retirados somado aos ja retirados - ou seja, a posicao limite */
        while ((i <= R + k) && (maiordigito != 9)) {
            /* Percorre o vetor ate encontrar o maior digito possivel */
            if (digitos[i] > maiordigito) {
                maiordigito = digitos[i];
                POSmaiordigito = i;
            }
            i++;
        }
         
        /* Posiciona o maior digito encontrado no vetor final */
        valorfinal[k] = maiordigito;

        /* Onde deve iniciar o novo processo, a partir da posicao apos o numero
         * utilizado para preencher o vetor final */
        i = POSmaiordigito + 1;
        
        /* Iguala a i caso ja tenha excedido a casa limite, para dar
         * continuidade ao processo sem a funcao anterior */
        POSmaiordigito = i;
    }

    /* Imprime, por fim, o maior valor - percorrendo o vetor final */
    printf("Maior valor: ");

    for (j = 0; j < D - R; j++)
        printf("%d", valorfinal[j]);

    printf("\n");

    return 0;
}