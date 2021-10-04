#include <stdio.h>
#include "fila.h"

int main(int argc, char* argv[]) {
    

    int ct = 1;

    Fila* f1 = create_queue(10);
    Fila* f2 = create_queue(10);
    Fila* f3 = create_queue(10);


    for (int i = 1; i < 10; i++) {
        enqueue(f1, i);
        enqueue(f2, i);
        enqueue(f3, i);
    }


    return 0;
}
