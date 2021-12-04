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
    int item = 0;
    int quantidade = 0;
    // 
    struct itemPedido *itemPedido;

    while (escolha != 0) {
        itemPedido = inicializarPedido();

        printf("O que você deseja?\n");
        printf("Digite (1) para fazer um novo pedido\n");
        printf("Digite (2) para listar os pedidos existentes\n");
        printf("Digite (3) para buscar um pedido\n");
        printf("Digite (0) para sair\n");
        fflush(stdin);
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                while (item != 0) {
                    printf("Itens do cardapio:\n");
                    printarCardapio();
                    printf("\nPara sair digite 0!\n");
                    printf("Digite o numero correspondente ao item do cardapio que você deseja: ");
                    fflush(stdin);
                    scanf("%d", &item);

                    switch (item) {
                        case 1:
                            printf("\nDigite a quantidade: ");
                            scanf("%d", &quantidade);
                            itemPedido = inserirItemNoPedido(item, quantidade, itemPedido);
                            break;

                        case 2:
                            break;
                    }
                }
                break;

            case 2:
                break;

            case 3:
                break;

            default:
                printf("Digite uma opção correta!\n");
                break;
        }
    }

    return 0;
}
