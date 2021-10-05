#include <stdio.h>
#include "fila.h"
#include <unistd.h>

void Game(Fila *f1, Fila *f2, Fila *f3) {
    int r, i;
    Fila **f = (Fila *) malloc(sizeof(Fila*) * 3);
    f[0] = f1;
    f[1] = f2;
    f[2] = f3;

    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        r = rand() % 10 + 1;
        drawQueue(f[i], r);
    }
 
    while(!((f1->vetor[f1->ini] == f2->vetor[f2->ini]) && (f3->vetor[f3->ini] == f1->vetor[f1->ini]))) {

        for (i = 0; i < 3; i++) {
            r = rand() % 10 + 1;
            drawQueue(f[i], r);
        }
        
        printf("|%d|%d|%d|\n", f1->vetor[f1->ini], f2->vetor[f2->ini], f3->vetor[f3->ini]);
    }

} 

int main() {
    
    int tam = 10;

    Fila* f1 = create_queue(tam);
    Fila* f2 = create_queue(tam);
    Fila* f3 = create_queue(tam);


    for (int i = 1; i < tam; i++) {
        enqueue(f1, i);
        enqueue(f2, i);
        enqueue(f3, i);
    }
    
    Game(f1, f2, f3);

    return 0;
}
