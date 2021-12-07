struct cardapio;
struct itemPedido;
struct pedido;

// funcoes da lista de cardapio

int inserirNoCardapio(char *nome, double valor);

struct cardapio *buscarNoCardapio(int id);

int getQuantidadeDeItensDoCardapio();

void printarCardapio();

// funcoes dos itens do pedido

struct itemPedido *inicializarPedido();

struct itemPedido *inserirItemNoPedido(int id, int quantidade, struct itemPedido *itemPedido);

struct itemPedido *retirarItemDoPedido(int id, struct itemPedido *itensDoPedido);

void printarItensDoPedido(struct itemPedido *itemPedido);

// funcoes da fila

double calcularValorTotal(struct itemPedido *itemPedido);

int enfileirar(struct itemPedido *itemPedido);

struct pedido *buscarPedido(int id);

void printarPedidos();

int printarPedidoPorId(int id);
