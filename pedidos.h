struct cardapio;
struct itemPedido;
struct pedido;

// funcoes da lista de cardapio

int inserirNoCardapio(char *nome, double valor);

void printarCardapio();

// funcoes dos itens do pedido

struct itemPedido *incializarPedido();

struct itemPedido *inserirItemNoPedido(int id, int quantidade, struct itemPedido *itemPedido);

// funcoes da fila

double calcularValorTotal(int *itensDoPedido);

int enfileirar(int numMesa, int *itensDoPedido);

int printarPedidos();

int printarPedidoPorId(int numMesa);
