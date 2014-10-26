/* Laboratorio 14b - Whiteworse
 * Autor: Isadora Sophia Garcia Rodopoulos 158018
 * e-mail: isaecia@gmail.com
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tamanho maximo do nome do titular */
#define MAXNOME 21
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de contas */
#define MAXCONTAS 20
/* Numero maximo de transacoes */
#define MAXTRANS 40
/* Valor da taxa de deposito em conta com saldo negativo */
#define TAXA 5.00

/* Conta
 * ag = numero da agencia
 * cc = numero da conta corrente
 * titular = Nome do titular da conta
 * saldo = Saldo da conta
 */
struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

/* Transacao
 * tipo - 'D' para Depositos e 'S' para Saques
 * ag - Numero da agencia
 * cc - Numero da conta corrente
 * valor - Valor da operacao
 */
struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

/* Prototipo de funcoes */
void le_contas(FILE *entradaConta, Conta *conta, int numContas);
void le_trans(FILE *entradaTrans, Transacao *transacao, int numTrans);
void computa_trans(Conta *conta, Transacao *transacao, int numContas, 
                   int numTrans);
void escreve_saida(FILE *saida, Conta *conta, int numContas);

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    FILE *entradaConta, *entradaTrans, *saida;
    Conta *conta;
    Transacao *transacao;
    int numContas, numTrans;
    
    /* Obtendo o nome dos arquivos */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);
    
    /* Inicia arquivos */
    entradaConta = fopen(nomeArqConta, "rb");
    entradaTrans = fopen(nomeArqTrans, "rb");
    saida = fopen(nomeArqSaida, "wb");
    
    /* Verifica se todos os arquivos foram devidamente abertos */
    if ((entradaConta == NULL) || (entradaTrans == NULL) || (nomeArqSaida ==
        NULL))
        return 0;
    
    /* Computa o numero de contas totais e realiza a leitura do arquivo */
    fread(&numContas, sizeof(int), 1, entradaConta);
    conta = malloc(numContas * sizeof(Conta));

    le_contas(entradaConta, conta, numContas);

    /* Computa o numero de transacoes totais e realiza a leitura do arquivo */
    fread(&numTrans, sizeof(int), 1, entradaTrans);
    transacao = malloc(numTrans * sizeof(Transacao));
    
    le_trans(entradaTrans, transacao, numTrans);
   
    /* Atualiza as contas de acordo com as transacoes validas e imprime as
    transacoes validas na saida padrao */ 
    computa_trans(conta, transacao, numContas, numTrans);
    
    /* Escreve as contas atualizadas no arquivo de saida */
    escreve_saida(saida, conta, numContas);

    /* Desaloca memoria */
    free(conta);
    free(transacao);
    fclose(entradaConta);
    fclose(entradaTrans);
    fclose(saida);
    
    return 0;
}

/* Ambas as funcoes realizam a leitura do arquivo e copia para os registros */
void le_contas(FILE *entradaConta, Conta *conta, int numContas) {
    fread(conta, sizeof(Conta), numContas, entradaConta);
}
void le_trans(FILE *entradaTrans, Transacao *transacao, int numTrans) {
    fread(transacao, sizeof(Transacao), numTrans, entradaTrans);
}

/* A partir das transicoes ocorridas, verifica quais sao validas, as imprime na
 * saida padrao e atualiza os registros de contas */
void computa_trans(Conta *conta, Transacao *transacao, int numContas, 
                   int numTrans) {
    int i, j, ok;
    
    /* Checa a validade de cada transacao */
    for (i = 0; i < numTrans; i++) {
        ok = 1;
        /* Busca a conta referente a transacao */
        for (j = 0; j < numContas && ok; j++) {
            if ((conta[j].ag == transacao[i].ag) && (conta[j].cc ==
transacao[i].cc)) {
                /* Se foi um deposito e encontrou a conta, a transacao ja eh
                 * considerada aceita - portanto atualiza dados e copia na saida
                 * */
                if (transacao[i].tipo == 'D') {
                    conta[j].saldo += transacao[i].valor;
                    /* Imprime na saida padrao */
                    printf("T%d: %c %d %d %.2f\n", i, transacao[i].tipo,
transacao[i].ag, transacao[i].cc, transacao[i].valor);
                }
                else if (transacao[i].tipo == 'S') {
                    /* Se foi um saldo e encontrou a conta, deve antes ser
                     * verificado se o saldo eh positivo */
                    if (conta[j].saldo > 0) {
                        /* Verifica se o saldo excede o limite */
                        if (conta[j].saldo - transacao[i].valor >= -100.00) {
                            conta[j].saldo -= transacao[i].valor;
                            /* Verifica se eh necessario cobrar taxa */
                            if (conta[j].saldo < 0)
                                conta[j].saldo -= 5.00;
                            /* Imprime na saida padrao */
                            printf("T%d: %c %d %d %.2f\n", i, transacao[i].tipo,
    transacao[i].ag, transacao[i].cc, transacao[i].valor);
                        }
                    }
                }
                /* Finaliza busca dessa transicao */
                ok = 0;
            }
        }
    }
}

/* Escreve registros finais de contas no arquivo de saida */
void escreve_saida(FILE *saida, Conta *conta, int numContas) {
    fwrite(&numContas, sizeof(int), 1, saida);

    fwrite(conta, sizeof(Conta), numContas, saida);
}