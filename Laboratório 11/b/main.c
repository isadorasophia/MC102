/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 11b - BibTeX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LABEL 451
#define TAM_AUTHOR 501
#define TAM_TITLE 501
#define TAM_JOURNAL 101
#define TAM_YEAR 51
#define TAM_VOLUME 51
#define TAM_NUMBER 51
#define TAM_PAGES 51

struct Article {
    char label[TAM_LABEL], author[TAM_AUTHOR], title[TAM_TITLE],
journal[TAM_JOURNAL], year[TAM_YEAR], volume[TAM_VOLUME], number[TAM_NUMBER],
pages[TAM_PAGES];
};
typedef struct Article Article;

/* Inicia campos sujeitos a estarem vazios dos articles */
void iniciaArticles(Article article[], int n);

/* Le e registra os dados de cada article */
void leArticles (Article article[], int n);

/* Ordena o vetor de articles conforme ordem adequada de saida */
void ordenaArticles(Article article[], int n);

/* Ordena vetor ate a posicao i */
void insertion(Article article[], int i);

/* Imprime articles conforme formato adequado */
void imprimeArticles(Article article[], int n);

/* Verifica a posicao do inicio da informacao do campo */
int inicioCampo(char string[]);

/* Verifica a posicao do fim da informacao do campo */
int fimCampo(char string[]);

int main () {
    char entrada;
    int n;
    Article *article;

    scanf("%c %d", &entrada, &n);
    
    /* Aloca os registros necessarios */
    article = malloc(n * sizeof(Article));

    /* Antes de ler, inicia campos dos articles caso nao sejam preenchidos */
    iniciaArticles(article, n);
    
    /* Le todos os articles */
    leArticles(article, n);
    
    /* Ordena articles de acordo com o titulo ou com a ordem de aparecimento */
    ordenaArticles(article, n);

    /* Imprime articles de acordo com as instruncoes */
    imprimeArticles(article, n);
    
    free(article);
    return 0;
}

/* Funcao responsavel por alocar determinados campos do article */
void iniciaArticles(Article article[], int n) {
    int i;

    /* Inicia como nulo */
    for (i = 0; i < n; i++) {
        article[i].volume[0] = '\0';
        article[i].number[0] = '\0';
        article[i].pages[0] = '\0';
    }
}

/* Le e registra os dados de cada article */
void leArticles (Article article[], int n) {
    int ok, i;
    char entrada[TAM_LABEL + 11], inicio;
    
    /* Le os n articles */
    for (i = 0; i < n; i++) {
        /* Le @article e label, informacoes sujeitas a descarte */
        scanf("%s", entrada);
        setbuf(stdin, 0);
        ok = 1;        
        /* Le as informacoes de cada campo */
        while (ok) {
            scanf("%c", &inicio);
            /* Checa se eh uma entrada de campoK ou se esta finalizando o
             * article a partir do primeiro caractere da linha */
            if (inicio == '}')
                ok = 0;
            else {
                /* Identifica campoK a ser armazenado */
                scanf("%s", entrada);
                setbuf(stdin, 0);
                /* Registra a informacao com o modelo da entrada */
                if (strcmp(entrada, "author") == 0)
                    fgets(article[i].author, 6 + TAM_AUTHOR, stdin);
                else if (strcmp(entrada, "title") == 0)
                    fgets(article[i].title, 6 + TAM_TITLE, stdin);
                else if (strcmp(entrada, "journal") == 0)
                    fgets(article[i].journal, 6 + TAM_JOURNAL, stdin);
                else if (strcmp(entrada, "year") == 0)
                    fgets(article[i].year, 6 + TAM_YEAR, stdin);
                else if (strcmp(entrada, "volume") == 0)
                    fgets(article[i].volume, 6 + TAM_VOLUME, stdin);
                else if (strcmp(entrada, "number") == 0)
                    fgets(article[i].number, 6 + TAM_NUMBER, stdin);
                else if (strcmp(entrada, "pages") == 0)
                    fgets(article[i].pages, 6 + TAM_PAGES, stdin);
            }
        }
    }
}

/* Ordena o vetor de articles conforme ordem adequada de saida, utilizando o
 * metodo de Insertion Sort */
void ordenaArticles(Article article[], int n) {
    int i;
    
    for (i = 1; i < n; i++) {
        insertion(article, i);
    }
}

/* Ordena vetor ate a posicao i */
void insertion(Article article[], int i) {
    int j;
    Article aux = article[i];
    
    for (j = i - 1; (j >= 0) && strcmp(article[j].title, aux.title) >= 1; j--)
        article[j + 1] = article[j];
    
    article[j + 1] = aux;
}

/* Imprime articles conforme formato adequado */
void imprimeArticles(Article article[], int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        /* Le cada campo de acordo com as informacoes entre { e } lidos na
         * entrada */
        for (j = inicioCampo(article[i].title); j < fimCampo(article[i].title);
            j++)
            printf("%c", article[i].title[j]);
        printf(", ");
        for (j = inicioCampo(article[i].author); j <
            fimCampo(article[i].author); j++) {
            printf("%c", article[i].author[j]);
        }
        printf(", ");
        for (j = inicioCampo(article[i].journal); j <
            fimCampo(article[i].journal); j++) {
            printf("%c", article[i].journal[j]);
        }
        printf(", ");
        /* Antes de imprimir, verifica se tal informacao foi computada nos 
         * campos a seguir */
        if (article[i].volume[0]) {
            for (j = inicioCampo(article[i].volume); j <
                fimCampo(article[i].volume); j++) {
                printf("%c", article[i].volume[j]);
            }
            printf(", ");
        }
        if (article[i].number[0]) {
            for (j = inicioCampo(article[i].number); j <
                fimCampo(article[i].number); j++) {
                printf("%c", article[i].number[j]);
            }
            printf(", ");
        }
        if (article[i].pages[0]) {
            for (j = inicioCampo(article[i].pages); j <
                fimCampo(article[i].pages); j++) {
                printf("%c", article[i].pages[j]);
            }
            printf(", ");
        }
        for (j = inicioCampo(article[i].year); j <
            fimCampo(article[i].year); j++) {
            printf("%c", article[i].year[j]);
        }
        printf(".\n\n");
    }
}

/* Verifica a posicao do inicio da informacao do campo - depois de { */
int inicioCampo(char string[]) {
    int i = 0;

    while (string[i] != '{')
        i++;

    /* Retorna uma anterior a encontrada */
    return i + 1;
}

/* Verifica a posicao do inicio da informacao do campo - antes de } */
int fimCampo(char string[]) {
    int i = 0;

    while (string[i] != '}')
        i++;

    return i;
}