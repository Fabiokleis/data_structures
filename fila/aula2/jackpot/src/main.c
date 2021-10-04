#include <stdio.h>
#include "fila.h"

int main(int argc, char* argv[]) {
    

    int tam = 10;

    Fila* f1 = create_queue(tam);
    Fila* f2 = create_queue(tam);
    Fila* f3 = create_queue(tam);


    for (int i = 1; i < tam; i++) {
        enqueue(f1, i);
        enqueue(f2, i);
        enqueue(f3, i);
    }

    drawQueue(f1);

    printf("\n");

    return 0;
}
