#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedidos.h"

// vetor de char para auxiliar na impressao
const char *card[] = {
    "PF",
    "Bebidas",
    "Sobremesa",
    "Churrasco"
};

// lista dos itens do cardapio
typedef struct cardapio {
    char nome[50];
    double valor;
    struct cardapio *prox;
} Cardapio;

// lista dos intes do pedido
typedef struct itemPedido {
    struct cardapio *item;
    int quantidade;
    struct itemPedido *prox;
} itemPedido;

// fila de pedidos
typedef struct pedido {
    int numMesa;
    int *itensDoPedido;
    double valorTotal;
    struct pedido *prox;
} Pedido;

/*
    ****************************************
     FUNCOES DA LISTA DOS ITENS DO CARDAPIO
    ****************************************
*/

Cardapio *cardapio;

int inserirNoCardapio(char *nome, double valor) {
    // se o valor for negativo ele retorna 1
    if (valor <= 0) {
        return 1;
    }

    if (nome == NULL) {
        return 1;
    }

    // alocando novo no da lista de itens do cardapio
    Cardapio *novoNo = (Cardapio*)malloc(sizeof(Cardapio));
    strcpy(novoNo->nome, nome);
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (cardapio == NULL) {
        cardapio = novoNo;
        return 0;
    }

    Cardapio *aux = cardapio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novoNo;

    return 0;
}

void printarCardapio() {
    if (cardapio == NULL) {
        return;
    }

    Cardapio *aux = cardapio;
    while (aux->prox != NULL) {
        printf("Nome do item: %s\n", aux->nome);
        printf("Valor do item: %f\n", aux->valor);
        aux = aux->prox;
    }
    printf("Nome do item: %s\n", aux->nome);
    printf("Valor do item: %f\n", aux->valor);
}

// ****************************************

/*
    ****************************************
                FUNCOES DA FILA
    ****************************************
*/

// guarda o ponteiro do primeiro elemento da fila
Pedido *primeiro;
// guarda o ponteiro do ultimo elemento da fila
Pedido *ultimo;


// funcao para calcular o valor total do pedido
/*
    devolve o valor total do pedido com as quantidades dentro do array
    o index do array mostra o item correspondente na constante "card"
    se o valor do array em qualquer index estiver diferente de -1
    significa que há um item do pedido referente ao index
    a quantidade de itens do pedido será o valor dentro do array no index informado
*/
double calcularValorTotal(int *itensDoPedido) {
    double valorTotal = 0;

    for (int i = 0; i < 4; i++) {
        if (itensDoPedido[i] != -1) {
            // i = 0 equivale ao PF
            if (i == 0) {
                valorTotal = valorTotal + (20 * itensDoPedido[i]);
            }
            // i = 1 equivale ao Bebidas
            if (i == 1) {
                valorTotal = valorTotal + (10 * itensDoPedido[i]);
            }
            // i = 2 equivale ao Sorvete
             if (i == 2) {
                valorTotal = valorTotal + (10 * itensDoPedido[i]);
            }
             // i = 3 equivale ao Churrasco
             if (i == 3) {
                valorTotal = valorTotal + (20 * itensDoPedido[i]);
            }
        }
    }

    return valorTotal;
}

// retorna 0 se der tudo certo
int enfileirar(int numMesa, int *itensDoPedido) {
    double valorTotal = calcularValorTotal(itensDoPedido);

    Pedido *ped = (Pedido*)malloc(sizeof(Pedido));
    ped->numMesa = numMesa;
    ped->valorTotal = valorTotal;
    ped->itensDoPedido = itensDoPedido;

    if (ultimo == NULL) {
        primeiro = ped;
        ultimo = ped;
        return 0;
    }

    ultimo->prox = ped;
    ultimo = ultimo->prox;
    return 0;
}

// retorna 1 se a fila de pedidos estiver nula
int printarPedidos() {
    if (primeiro == NULL) {
        return 1;
    }

    Pedido *aux = primeiro;
    while (aux->prox != NULL) {
        printf("Itens do pedido da mesa %d:\n", aux->numMesa);
        for (int i = 0; i < 4; i++) {
            if (aux->itensDoPedido[i] != -1) {
                printf("%s\n", card[i]);
            }
        }
        printf("Valor total: %f", aux->valorTotal);
        printf("\n");
        printf("\n");

        aux = aux->prox;
    }
    printf("Itens do pedido da mesa %d:\n", aux->numMesa);
    for (int i = 0; i < 4; i++) {
        if (aux->itensDoPedido[i] != -1) {
            printf("%s\n", card[i]);
        }
    }
    printf("Valor total: %f", aux->valorTotal);
    printf("\n");

    return 0;
}

// precisa implementar a funcao de busca para fazer essa
int printarPedidoPorId(int numMesa) {
    return 0;
}
