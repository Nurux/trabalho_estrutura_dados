struct cardapio;
struct itemPedido;
struct pedido;

// funcoes da lista de cardapio

int inserirNoCardapio(char *nome, double valor);

struct cardapio *buscarNoCardapio(int id);

void printarCardapio();

// funcoes dos itens do pedido

struct itemPedido *inicializarPedido();

struct itemPedido *inserirItemNoPedido(int id, int quantidade, struct itemPedido *itemPedido);

void printarItensDoPedido();
// funcoes da fila

double calcularValorTotal(struct itemPedido *itemPedido);

int enfileirar(struct itemPedido *itemPedido);

int pegarQuantidadeDeItensDoPedido();

void printarPedidos();

void printarPedidoPorId(int numMesa);
