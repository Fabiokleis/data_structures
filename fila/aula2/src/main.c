#include <stdio.h>
#include "fila.h"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        for(int i=0; i < argc; i++) { printf("%s\n", argv[i]); }

        printf("passe dois argumentos inteiros: passo participantes\n");
        exit(1);
    }

    int step = atoi(argv[1]);
    int tam = atoi(argv[2]) + 1;
    int ct = 1;

    Fila* f = create_queue(tam);

    for (int i = 1; i < tam; i++) {
        enqueue(f, i);
    }

    while(!empty(f)) {
        if (ct == step) {
            printf("%d ", dequeue(f));
            ct = 1;
        } else {
            enqueue(f, dequeue(f));
            ct++;
        }
    }
    printf("\n");

    return 0;
}
