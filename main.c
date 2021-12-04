#include <stdio.h>
#include <stdlib.h>

#include "pedidos.h"

int main() {
    inserirNoCardapio("Prato Feito", 20.0);
    inserirNoCardapio("Sorvete", 10.0);
    inserirNoCardapio("Churrasco", 20.0);

    printarCardapio();

    return 0;
}
