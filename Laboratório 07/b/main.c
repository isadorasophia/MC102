/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 07b - Modern Word Search */

int confereVogal (char letra);
int confereLetra (char verifica, int i, int j, int k);
int copiaPalavra (char palavra[], char resposta[][51]);

#include <stdio.h>
int main () {
    int N, M, i, j, k, l, y, continuar, TAMpalavra = 0, achou = 0;
    char palavra[26], cruzada[51][51], resposta[51][51], vogais[6] = "aeiou"; 

    /* Le N linhas, M colunas e a palavra */
    scanf("%d %d %s", &N, &M, palavra);
    
    /* Resulta tamanho da palavra */
    while (palavra[TAMpalavra])
        TAMpalavra++;

    /* Le cruzada */
    for (i = 0; i < N; i++)
        scanf("%s", cruzada[i]);
    
    /* Inicia resposta */
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            resposta[i][j] = '.';
        }
    }

    /* Confere palavras na horizontal */
    for (i = 0; i < N; i++) {
        /* Encontra uma inicial igual a da palavra, para iniciar a checagem */
        for (j = 0; j <= M - TAMpalavra; j++) {
            if ((cruzada[i][j] == palavra[0]) || (cruzada[i][j] == '_') ||
(cruzada[i][j] == '#') || (cruzada[i][j] == '%'))
                continuar = confereLetra(cruzada[i][j], i, j, 0);
                /* Com a primeira letra checada, continua a checar ate completar
                 * palavra */
                for (k = 1; (k < TAMpalavra) && ((cruzada[i][j + k] ==
palavra[k]) || (cruzada[i][j + k] == '_') || (cruzada[i][j + k] == '#') ||
(cruzada[i][j + k] == '%')) && (continuar); k++) {
                    continuar = confereLetra(cruzada[i][j + k], i, j + k, k);
                    /* Palavra encontrada, copia para a resposta */
                    if ((k == TAMpalavra - 1) && (continuar)) {
                        /* Computa quantidade de palavras encontradas */
                        achou++;
                        for (l = 0; l <= k; l++) {
                            resposta[i][j + l] = cruzada[i][j + l];
                        }
                    } 
                }
            }
        }
    }
    
    /* Confere palavras na vertical */
    for (i = 0; i < M; i++) {
        /* Encontra uma inicial igual a da palavra, para iniciar a checagem */
        for (j = 0; j <= N - TAMpalavra; j++) {
            if ((cruzada[j][i] == palavra[0]) || (cruzada[j][i] == '_') ||
(cruzada[j][i] == '#') || (cruzada[j][i] == '%')) 
                continuar = confereLetra(cruzada[i][j], j, i, 0);
                /* Com a primeira letra checada, continua a checar ate completar
                * palavra */
                for (k = 1; (k < TAMpalavra) && ((cruzada[j + k][i] ==
palavra[k]) || (cruzada[j + k][i] == '_') || (cruzada[j + k][i] == '#') ||
(cruzada[j + k][i] == '%')) && (continuar); k++) 
                    continuar = confereLetra(cruzada[j + k][i], j + k, j + k, k);
                    /* Inicia flag */
                    continuar = 0;
                    /* Caso seja _ ou letra igual, continua */
                    if ((cruzada[j + k][i] != '#') && (cruzada [j + k][i] !=
'%'))
                        continuar = 1;
                    /* Confere se a letra da palavra eh uma vogal */
                    else if (cruzada[j + k][i] == '#') {
                        for (y = 0; y < 5; y++) {
                            if (palavra[k] == vogais[y])
                                continuar = 1;
                        }
                    }
                    /* Confere se a letra da palavra nao eh uma vogal */
                    else if (cruzada[j + k][i] == '%') {
                        continuar = 1;
                        for (y = 0; y < 5; y++) {
                            if (palavra[k] == vogais[y])
                                continuar = 0;
                        }
                    }
                    /* Palavra encontrada, copia para a resposta */
                    if ((k == TAMpalavra - 1) && (continuar)) {
                        /* Computa quantidade de palavras encontradas */
                        achou++;
                        for (l = 0; l <= k; l++) {
                            resposta[j + l][i] = cruzada[j + l][i];
                        }
                    }
                }
            }
        }
    }
    
    /* Confere palavras na diagonal */
    for (i = 0; i < M; i++) {
        /* Encontra uma inicial igual a da palavra, para iniciar a checagem */
        for (j = 0; j <= N - TAMpalavra; j++) {
            /* Inicia flag */
            continuar = 0;
            if ((cruzada[j][i] == palavra[0]) || (cruzada[j][i] == '_') ||
(cruzada[j][i] == '#') || (cruzada[j][i] == '%')) {
                /* Caso seja _ ou letra igual, continua */
                if ((cruzada[j][i] != '#') && (cruzada [j][i] != '%'))
                    continuar = 1;
                /* Confere se a primeira letra se trata de uma vogal */
                else if (cruzada[j][i] == '#') {
                    for (y = 0; y < 5; y++) {
                        if (palavra[0] == vogais[y])
                            continuar = 1;
                    }
                }
                /* Confere se a primeira letra nao se trata de uma vogal */
                else if (cruzada[j][i] == '%') {
                    continuar = 1;
                    for (y = 0; y < 5; y++) {
                        if (palavra[0] == vogais[y])
                            continuar = 0;
                    }
                }
                /* Com a primeira letra checada, continua a checar ate completar
                 * palavra */
                for (k = 1; (k < TAMpalavra) && ((cruzada[j + k][i + k] ==
palavra[k]) || (cruzada[j + k][i + k] == '_') || (cruzada[j + k][i + k] == '#')
|| (cruzada[j + k][i + k] == '%')) && (continuar); k++) {
                    /* Inicia flag */
                    continuar = 0;
                    /* Caso seja _ ou letra igual, continua */
                    if ((cruzada[j + k][i + k] != '#') && (cruzada [j + k][i +
k] != '%'))
                        continuar = 1;
                    /* Confere se a letra da palavra eh uma vogal */
                    else if (cruzada[j + k][i + k] == '#') {
                        for (y = 0; y < 5; y++) {
                            if (palavra[k] == vogais[y])
                                continuar = 1;
                        }
                    }
                    /* Confere se a letra da palavra nao eh uma vogal */
                    else if (cruzada[j + k][i + k] == '%') {
                        continuar = 1;
                        for (y = 0; y < 5; y++) {
                            if (palavra[k] == vogais[y])
                                continuar = 0;
                        }
                    }
                    /* Palavra encontrada, copia para a resposta */
                    if ((k == TAMpalavra - 1) && (continuar)) {
                        /* Computa quantidade de palavras encontradas */ 
                        achou++;
                        for (l = 0; l <= k; l++) {
                            resposta[j + l][i + l] = cruzada[j + l][i + l];
                        }
                    }
                }
            }
        }
    }

    printf("%s %d\n", palavra, achou);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%c", resposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* Confere se a letra se trata de uma vogal */
int confereVogal (char letra)
    char vogais[6] = "aeiou";
    int vogal = 0;
    for (k = 0; k < 5; k++) {
        if (letra == vogais[k])
            vogal = 1;
    }
    return vogal;
}

/* Confere se a letra eh valida para a palavra */
int confereLetra (char verifica, int i, int j, int k);
    int continuar = 1;
    /* Confere se a primeira letra se trata de uma vogal */
    if (cruzada[i][j] == '#') {
        if confereVogal(palavra[k]) == 0)
            continuar = 0;
    }
    /* Confere se a primeira letra nao se trata de uma vogal */
    else if (cruzada[i][j] == '%') {
        if (confereVogal(palavra[k]))
            continuar = 0;
    }
    return continuar;
}
