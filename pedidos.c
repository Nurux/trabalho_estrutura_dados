#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedidos.h"

// lista dos itens do cardapio
typedef struct cardapio {
    int id;
    char nome[50];
    double valor;
    struct cardapio *prox;
} Cardapio;

// lista dos intes do pedido
typedef struct itemPedido {
    struct cardapio *item;
    int quantidade;
    struct itemPedido *prox;
} ItemPedido;

// fila de pedidos
typedef struct pedido {
    int id;
    struct itemPedido *itensDoPedido;
    double valorTotal;
    struct pedido *prox;
} Pedido;

/*
    ****************************************
     FUNCOES DA LISTA DOS ITENS DO CARDAPIO
    ****************************************
*/

// guarda o id para incrementar a cada item na lista do cardapio
int idCardapio = 1;

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
    novoNo->id = idCardapio;

    // incrementa o id dos itens do cardapio
    idCardapio++;

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

// retorna 2 se o id for menor que zero e 1 se nao for encontrado
Cardapio *buscarNoCardapio(int id) {
    if (id <= 0) {
        return NULL;
    }

    Cardapio *aux = cardapio;
    if (aux->id == id) {
        return aux;
    }

    while (aux->prox != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    if (aux->id == id) {
        return aux;
    }

    return NULL;
}

void printarCardapio() {
    if (cardapio == NULL) {
        return;
    }

    Cardapio *aux = cardapio;
    while (aux->prox != NULL) {
        printf("Id: %d Nome do item: %s \t", aux->id, aux->nome);
        printf("Valor do item: R$ %.2f\n", aux->valor);
        aux = aux->prox;
    }
    printf("Id: %d Nome do item: %s \t", aux->id, aux->nome);
    printf("Valor do item: R$ %.2f\n", aux->valor);
}

/*
    ****************************************
      FUNCOES DA LISTA DOS ITENS DO PEDIDO
    ****************************************
*/

ItemPedido *inicializarPedido() {
    return NULL;
}

ItemPedido *inserirItemNoPedido(int id, int quantidade, ItemPedido *itemPedido) {

    ItemPedido *novoNo = (ItemPedido*)malloc(sizeof(ItemPedido));
    novoNo->item = buscarNoCardapio(id);
    if (novoNo->item == NULL) {
        return NULL;
    }
    novoNo->quantidade = quantidade;

    if (itemPedido == NULL) {
        return novoNo;
    }

    ItemPedido *aux = itemPedido;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novoNo;

    return itemPedido;
}

void printarItensDoPedido(ItemPedido *itemPedido) {
    if (itemPedido == NULL) {
        return;
    }

    ItemPedido *aux = itemPedido;
    while (aux->prox != NULL) {
        printf("%s R$ %.2f Quantidade: %d\n", aux->item->nome, aux->item->valor, aux->quantidade);
        aux = aux->prox;
    }

    printf("%s R$ %.2f Quantidade: %d\n", aux->item->nome, aux->item->valor, aux->quantidade);
}

// ****************************************

/*
    ****************************************
            FUNCOES DA FILA DE PEDIDOS
    ****************************************
*/

// guarda o id para incrementar a cada item na fila de pedidos
int idPedido = 1;
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
double calcularValorTotal(ItemPedido *itemPedido) {
    double valorTotal = 0;

    ItemPedido *aux = itemPedido;
    while (aux->prox != NULL) {
        valorTotal = valorTotal + (aux->quantidade * aux->item->valor);
        aux = aux->prox;
    }
    valorTotal = valorTotal + (aux->quantidade * aux->item->valor);

    return valorTotal;
}

// retorna 0 se der tudo certo
int enfileirar(ItemPedido *itemPedido) {
    double valorTotal = calcularValorTotal(itemPedido);

    Pedido *ped = (Pedido*)malloc(sizeof(Pedido));
    ped->id = idPedido;
    ped->itensDoPedido = itemPedido;
    ped->valorTotal = valorTotal;

    // incrementa o id global dos pedidos
    idPedido++;

    if (ultimo == NULL) {
        primeiro = ped;
        ultimo = ped;
        return 0;
    }

    ultimo->prox = ped;
    ultimo = ultimo->prox;
    return 0;
}

int pegarQuantidadeDeItensDoPedido(ItemPedido *itemPedido) {
    int quantidade = 0;

    ItemPedido *aux = itemPedido;
    while (aux->prox != NULL) {
        quantidade++;
        aux = aux->prox;
    }
    quantidade++;

    return quantidade;
}

// retorna 1 se a fila de pedidos estiver nula
void printarPedidos() {
    if (primeiro == NULL) {
        printf("\n\n\nNão há pedidos na fila!\n\n\n");
        return;
    }

    // percorre todos os pedidos
    Pedido *aux = primeiro;

    // percorre todos os itens de cada pedido
    ItemPedido *auxItemPedido;
    while (aux->prox != NULL) {
        auxItemPedido = aux->itensDoPedido;

        printf("\n\nPedidos da mesa: %d\n", aux->id);

        while (auxItemPedido->prox != NULL) {
            printf("%s R$ %.2f Quantidade: %d\n", auxItemPedido->item->nome, auxItemPedido->item->valor, auxItemPedido->quantidade);

            auxItemPedido = auxItemPedido->prox;
        }

        printf("%s R$ %.2f Quantidade: %d\n", auxItemPedido->item->nome, auxItemPedido->item->valor, auxItemPedido->quantidade);

        printf("\nValor total: R$ %.2f", aux->valorTotal);
        printf("\n__________________________________________________");

        aux = aux->prox;
    }
    auxItemPedido = aux->itensDoPedido;

    printf("\n\nPedidos da mesa: %d\n", aux->id);

    while (auxItemPedido->prox != NULL) {
        printf("%s R$ %.2f Quantidade: %d\n", auxItemPedido->item->nome, auxItemPedido->item->valor, auxItemPedido->quantidade);

        auxItemPedido = auxItemPedido->prox;
    }

    printf("%s R$ %.2f Quantidade: %d\n", auxItemPedido->item->nome, auxItemPedido->item->valor, auxItemPedido->quantidade);

    printf("\nValor total: R$ %.2f\n", aux->valorTotal);
    printf("\n__________________________________________________");

    aux = aux->prox;
}

// precisa implementar a funcao de busca para fazer essa
void printarPedidoPorId(int numMesa) {
    return;
}
