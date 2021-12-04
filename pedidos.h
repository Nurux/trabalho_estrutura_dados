struct cardapio;
struct itemPedido;
struct pedido;

// funcoes da lista de cardapio

int inserirNoCardapio(char *nome, double valor);

void printarCardapio();

// funcoes da fila

double calcularValorTotal(int *itensDoPedido);

int enfileirar(int numMesa, int *itensDoPedido);

int printarPedidos();

int printarPedidoPorId(int numMesa);
