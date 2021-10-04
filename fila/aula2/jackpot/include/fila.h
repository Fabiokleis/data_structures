typedef enum {
    false = 0,
    true = 1
} bool;

typedef struct {
    int ini;
    int fim;
    int tam;
    int *vetor;
} Fila;

Fila *create_queue(int tam);
void enqueue(Fila *f, int e); 
int dequeue(Fila *f); 
void desaloc(Fila *f);
bool full(Fila *f);
bool empty(Fila *f);
void showQueue(Fila *f);
void drawQueue(Fila *f);
