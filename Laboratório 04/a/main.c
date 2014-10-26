#include <stdio.h>
int main () {
    int digitos[15], n, i, soma = 0, k;
    long int multiplicacao[15];

    scanf("%d", &n);

    /* Comando le os digitos que o usuario imprime da senha */
    for (i = 0; i <= n - 1; i++) {
        scanf("%d", &digitos[i]);
    }

    /* Inicia valores nao determinados pelo usuario no vetor */
    for (i = 14; i > n - 1; i--)
        digitos[i]= 11;

    /* Computa-se os dados da multiplicacao */
    for (i = 0; i <= 14; i++) {       
        if (i <= n - 1) {
        /* Multiplicacao = numero de digitos * posicao * numero em si */
            multiplicacao[i] = n * (i + 1) * digitos[i];
            soma += multiplicacao[i];
        }
       
        if (i > n - 1) {
            n++;
            for (k = 0; k <= i; k++) {
                multiplicacao[i] = n * (i + 1) * digitos[i];
                soma += multiplicacao[i];    
            }
        }
        
        /* O usuario ja nao definiu o proximo digito, entao calculemos! */
        if (i > n - 1) {
            /* Descobre o proximo digito da senha atraves do resto */
            digitos[i] = soma % 11;
            /* Caso seja 10, iguale a 0 */
            if (digitos[i] == 10)
                digitos[i] = 0;
        }
    }

    /* Imprime a senha */
    for (i = 0; i <=14; i++)
        printf("%d", digitos[i]);

    printf("\n %ld %ld %ld %ld", multiplicacao[0], multiplicacao[1], 
multiplicacao[2], multiplicacao[3]);

    return 0;
}