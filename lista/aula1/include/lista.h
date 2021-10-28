typedef struct node {
    int info;
    struct node* next;
} Lista;

Lista* criar_lista(void);

Lista* inserir(Lista *lista, int elem);

Lista* remover(Lista* lista, int elem);

void imprimir_lista(Lista* lista);

void destruir_lista(Lista *lista);

