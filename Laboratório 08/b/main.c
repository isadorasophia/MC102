/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 08b - Processamento de imagens */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario. */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
    * o filtro e o parametro, se houver */
    scanf("%c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    } 
 
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
 
    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++)
            /* Define como a cor oposta */
            img[i][j] = MaxV - img[i][j];
    }
    
    return;
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    int i, j, aux;
    
    /* Inverte coordenadas das colunas */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W/2; j++) {
            aux = img[i][j];
            img[i][j] = img[i][W - 1 - j];
            img[i][W - 1 - j] = aux;
        }
    }
    
    /* Inverte coordenadas das linhas */
    for (i = 0; i < H/2; i++) {
        for (j = 0; j < W; j++) {
            aux = img[i][j];
            img[i][j] = img[H - 1 - i][j];
            img[H - 1 - i][j] = aux;
        }
    }
    
    return;
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j, soma;
    int imgAUX[MAX_TAM][MAX_TAM];
    
    /* Matriz auxiliar para nao perder os valores originais */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            imgAUX[i][j] = img[i][j];
    
    /* Deve-se desconsiderar os elementos da borda ao computar os novos valores
     * */
    for (i = 1; i < H - 1; i++) {
        for (j = 1; j < W - 1; j++) {
            soma = (-1 * imgAUX[i - 1][j - 1]) + (-4 * imgAUX[i - 1][j]) + (-1 *
imgAUX[i - 1][j + 1]) + (-4 * imgAUX[i][j + 1]) + (-1 * imgAUX[i + 1][j + 1]) +
(-4 * imgAUX[i + 1][j]) + (-1 * imgAUX[i + 1][j - 1]) + (-4 * imgAUX[i][j - 1])
+ (20 * imgAUX[i][j]);
            if (soma < 0)
                img[i][j] = 0;
            else if (soma > MaxV)
                img[i][j] = MaxV;
            else
                img[i][j] = soma;
        }
    }
     
    return;
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {  
    int i, j, xl, yl;
    int imgAUX[MAX_TAM][MAX_TAM];
    
    /* Matriz auxiliar para nao perder os valores originais */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            imgAUX[i][j] = img[i][j];
        
    /* Zera matriz original para o resultado */
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            img[i][j] = 0;   
    
    /* Para cada posicao, encontra onde deve ser alocado no resultado */
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            xl = (i + (Py * j));
            yl = (j + (Px * i));
            if ((xl < H) && (yl < W))
                img[xl][yl] = imgAUX[i][j];
        }
    }
}

int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM]; 
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }
 
    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}