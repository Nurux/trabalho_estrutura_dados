#include <stdio.h>
#include <stdlib.h>

#include "pedidos.h"

void instanciarCardapio() {
    inserirNoCardapio("Prato Feito", 20.0);
    inserirNoCardapio("Churrasco", 20.0);
    inserirNoCardapio("Sorvete", 10.0);
    inserirNoCardapio("Refrigerante", 10.0);
    inserirNoCardapio("Cerveja", 10.0);
}

int main() {
    // instancia os itens do cardapio
    instanciarCardapio();

    int escolha = -1;
    int item = -1;
    int quantidade = 0;
    int id = 0;
    int flag = -1;
    // 
    struct itemPedido *itemPedido;
    struct pedido *pedido;

    while (escolha != 0) {
        itemPedido = inicializarPedido();
        pedido = NULL;

        item = -1;
        id = 0;
        flag = -1;

        printf("\n\n\nO que você deseja?\n");
        printf("Digite (1) para fazer um novo pedido\n");
        printf("Digite (2) para listar os pedidos existentes\n");
        printf("Digite (3) para buscar um pedido\n");
        printf("Digite (0) para sair\n");
        fflush(stdin);
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                while (item != 0) {
                    system("clear");

                    printf("\nItens do pedido ate agora:\n\n");
                    printarItensDoPedido(itemPedido);

                    printf("\nItens do cardapio:\n");
                    printarCardapio();
                    printf("\nPara sair e cancelar o pedido digite 0!\n");
                    printf("Para finalizar o pedido, digite -1\n");
                    printf("Digite o numero correspondente ao item do cardapio que você deseja: ");
                    fflush(stdin);
                    scanf("%d", &item);

                    // 0 para cancelar o pedido
                    if (item == 0) {
                        break;
                    }

                    // -1 para finalizar pedido
                    if (item == -1) {
                        enfileirar(itemPedido);
                        break;
                    }

                    printf("\nDigite a quantidade: ");
                    fflush(stdin);
                    scanf("%d", &quantidade);



                    itemPedido = inserirItemNoPedido(item, quantidade, itemPedido);
                }
                break;

            case 2:
                printarPedidos();
                break;

            case 3:
                printf("Digite o Id referente ao pedido: ");
                fflush(stdin);
                scanf("%d", &id);

                flag = printarPedidoPorId(id);
                if (flag == 1) {
                    printf("Nao encontrado!\n");
                }
                break;

            case 0:
                printf("\n\nAté mais!\n\n");
                break;

            default:
                printf("Digite uma opção correta!\n");
                break;
        }
    }

    return 0;
}
