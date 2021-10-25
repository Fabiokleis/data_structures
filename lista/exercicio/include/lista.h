typedef struct node {
    int info;
    struct node* next;
} Lista;

Lista* criar_lista(void);

Lista* inserir(Lista *lista, int elem);

Lista* remover(Lista* lista, int elem);

Lista* remover_rec(Lista* lista, int elem);

void imprimir_lista(Lista* lista);

void imprimir_invertida_rec(Lista* lista);

void destruir_lista(Lista *lista);

///////////////////////////////////
/* Funcoes propostas sobre lista */
///////////////////////////////////

int conta_nos_itr(Lista* lista);

int conta_nos_rec(Lista* lista);

int procura_itr(Lista *lista, int elem);

int procura_rec(Lista *lista, int elem);

int lista_max_itr(Lista* lista);

int lista_max_rec(Lista* lista);

int lista_soma_itr(Lista* lista);

int lista_soma_rec(Lista* lista);

void imprimir_invertida_itr(Lista* lista);

void imprimir_invertida_rec(Lista* lista);
