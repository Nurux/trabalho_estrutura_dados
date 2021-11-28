#include <stdio.h>
#include <stdlib.h>

#include "pedidos.h"

int main() {
    int itensDoPedido[4] = {2, -1, 2, -1};
    int itensDoPedido2[4] = {-1, -1, 2, 3};
    int result = -1;

    result = enfileirar(25, itensDoPedido);
    result = enfileirar(35, itensDoPedido2);
    result = enfileirar(45, itensDoPedido2);
    result = enfileirar(55, itensDoPedido2);
    result = enfileirar(65, itensDoPedido2);

    result = printarPedidos();

    return 0;
}
