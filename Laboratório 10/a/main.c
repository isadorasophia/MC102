/* Nome: Isadora Sophia Garcia Rodopoulos
 * RA: 158018
 * Laboratorio 10a - LSCrypto */
#include <stdio.h>

/* Constroi registro para realizar a criptografia */
struct Alfabeto {
    char letra;
    int freq;
};

typedef struct Alfabeto Alfabeto;

/* Computa frequencia de cada letra */
void computaLetra(char letra, Alfabeto alf[]);
/* Ordena os registros a partir da frequencia */
void ordenaRegistro(Alfabeto alf[]);
/* Encontra posicao de um valor maximo */
int encontraMax(Alfabeto alf[], int i);
/* Substitui cada letra da mensagem pela letra criptografada */
void substituiResposta(char *letra, Alfabeto alf[]);
/* Encontra a posicao de uma dada letra no registro */
int posicaoRegistro(char letra, Alfabeto alf[]);

int main() {
    Alfabeto alf[26];
    int N, i, j;
    char mensagem[15][501];

    /* Inicializa os registros */
    for (i = 0; i < 26; i++) {
        alf[i].letra = (97 + i);
        alf[i].freq = 0;
    }

    /* Le mensagem */
    scanf("%d\n", &N);

    for (i = 0; i < N; i++) {
        fgets(mensagem[i], 501, stdin);
    }

    /* Calcula frequencia de cada letra e aloca no registro */
    for (i = 0; i < N; i++) {
        for (j = 0; mensagem[i][j]; j++) {
            computaLetra(mensagem[i][j], alf);
        }
    }

    /* Ordena o registro na ordem descrescente de frequencias */
    ordenaRegistro(alf);
    
    /* Substitui cada letra da mensagem por sua referente criptografada */
    for (i = 0; i < N; i++) {
        for (j = 0; mensagem[i][j]; j++) {
            substituiResposta(&mensagem[i][j], alf);
        }
    }

    for (i = 0; i < N; i++)
        printf("%s", mensagem[i]);
    
    return 0;
}

/* Acrescenta a frequencia de cada letra computada em seu respectivo registro */
void computaLetra(char letra, Alfabeto alf[]) {
    /* Transforma letra maiuscula em minuscula */
    if ((letra >= 65) && (letra <= 90)) {
        letra += 32;
        alf[letra - 97].freq++;
    }
    /* Letra ja eh minuscula */
    else if ((letra >= 97) && (letra <= 122)) {
        alf[letra - 97].freq++;
    }
}

/* Ordena o vetor de registro, em ordem decrescente de frequencia */
void ordenaRegistro(Alfabeto alf[]) {
    int i, max;
    Alfabeto aux;
    
    for (i = 0; i < 25; i++) {
        max = encontraMax(alf, i);
        /* Substitui para ficar na ordem decrescente */
        aux = alf[i];
        alf[i] = alf[max];
        alf[max] = aux;
    }
}
            
/* Retorna a posicao de frequencia maxima ou lexicograficamente menor */
int encontraMax(Alfabeto alf[], int i) {
    int j, maior = i;
    
    for (j = maior + 1; j < 26; j++) {
        if (alf[maior].freq < alf[j].freq) {
            maior = j;
        }
        /* Caso seja a mesma frequencia, confere o menor termo lexicografico */
        else if (alf[maior].freq == alf[j].freq) {
            if (alf[maior].letra > alf[j].letra)
                maior = j;
        }
    }
        
    return maior;
}

/* Substitui a mensagem pela mensagem criptografada */
void substituiResposta(char *letra, Alfabeto alf[]) {
    int pos;
    
    /* Transforma letra maiuscula em minuscula, depois retorna a maiuscula */
    if (((*letra) >= 65) && ((*letra) <= 90)) {
        (*letra) += 32;
        /* Encontra a posicao da letra no vetor de registros */
        pos = posicaoRegistro((*letra), alf);
        /* Caso seja impar = troca com a letra anterior no registro */
        if (pos % 2)
            (*letra) = alf[pos - 1].letra;
        /* Caso seja par = troca com a letra proxima no registro */
        else
            (*letra) = alf[pos + 1].letra;
        (*letra) -= 32;
    }
    /* Eh uma letra minuscula, faz o processo normal */
    else if (((*letra) >= 97) && ((*letra) <= 122)) {
        pos = posicaoRegistro((*letra), alf);
        if (pos % 2)
            (*letra) = alf[pos - 1].letra;
        else
            (*letra) = alf[pos + 1].letra;
    }
}

/* Retorna a posicao da letra no vetor de registros */
int posicaoRegistro(char letra, Alfabeto alf[]) {
    int i;
    
    /* Percorre ate encontrar o registro da letra */
    for (i = 0; letra != alf[i].letra; i++);

    return i;
}