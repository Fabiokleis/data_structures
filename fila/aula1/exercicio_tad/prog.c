#include "fila.c"

int main() {
    int i = 0;
    int tam = 3;
    Fila *f = criar(tam);
    for (i = 0; i < tam; i++) {
        enqueue(i, f);
    }

    printf("Cliente atendido %d\n", dequeue(f));
    printf("Cliente atendido %d\n", dequeue(f));
    printf("Cliente atendido %d\n", dequeue(f));

   
    desaloc(f);

    return 0;
}
