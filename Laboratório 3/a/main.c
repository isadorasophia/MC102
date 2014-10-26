/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 03a - Composicao de senha */

#include <stdio.h>
int main () {
    char n;
    int NUMnotas = 0;
    double SOMAcompasso = 0;

    do {
        /* O usuario insere a letra correspondente a nota (A, B, C, D, E, F, 
         * G, H) ou ao fim do compasso (\n), armazenado em n */
        scanf("%c", &n);
        
        /* Como o usuario nao demarcou o fim do compasso (\n), soma-se o valor 
         * correspondente da sua nota digitada */
        if (n != '\n') {
            
            /* Utiliza-se este comando para contar o numero de notas total de 
             * um compasso */
            NUMnotas++;
    
            /* Assim, le-se a letra que o usuario digitou segundo a tabela 
             * ASCII, e a corresponde com o valor a ser somado no compasso a 
             * partir dos comandos a seguir, no formato LETRA (nota) - VALOR */
            
            /* A - 1 */
            if (n == 65) {
                SOMAcompasso = SOMAcompasso + (1);
            }    

            /* B - 1/2 */
            if (n == 66) {
                SOMAcompasso = SOMAcompasso + ((float)1/2);
            }
    
            /* C - 1/4 */
            if (n == 67) {
                SOMAcompasso = SOMAcompasso + ((float)1/4);
            }
    
            /* D - 1/8 */
            if (n == 68) {
                SOMAcompasso = SOMAcompasso + ((float)1/8);
            }
            
            /* E - 1/16 */
            if (n == 69) {
                SOMAcompasso = SOMAcompasso + ((float)1/16);
            }
            
            /* F - 1/32 */
            if (n == 70) {
                SOMAcompasso = SOMAcompasso + ((float)1/32);
            }
            
            /* G - 1/64 */
            if (n == 71) {
                SOMAcompasso = SOMAcompasso + ((float)1/64);
            }

            /* H - 1/128 */
            if (n == 72) {
                SOMAcompasso = SOMAcompasso + ((float)1/128);
            }
        }
        
        /* Caso o usuario digite \n, o compasso terminou e deve-se computar os 
         * resultados para serem expressados na senha */
        if (n == '\n') {
          
            /* Caso a soma das notas do compasso dee um, imprimira o numero de 
             * letras do compasso */
            if (SOMAcompasso == 1) {
                printf("%d", NUMnotas);
            }
            
            /* Caso a soma nao dee um, o progama imprimira apenas 0 a senha */
            if (SOMAcompasso != 1) {
                printf("0");
            }
            
            /* Eh necessario zerar o numero de notas do compasso anterior assim 
             * como sua respectiva soma para realizar uma nova contagem e um 
             * novo compasso */
            NUMnotas = 0;
            SOMAcompasso = 0;
        }
    } while (n != '*');
    
    /* O usuario decide a finalizacao do progama ao inserir o digito '*', 
     * concluindo a senha e interrompendo o loop */

    printf("\n");
        
    return 0;
}