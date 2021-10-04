#include "fila.h"
#include <stdlib.h>

Fila* create_queue(int tam) {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = 0;
    f->fim = 0;
    f->tam = tam;

    f->vetor = (int*)malloc(tam * sizeof(int));

    return f;
}

void enqueue(Fila *f, int e) {
    if (full(f)) {
        printf("fila cheia: capacidade esgotada!");
        exit(1);
    }

    f->vetor[f->fim] = e;
    f->fim = (f->fim + 1) % f->tam;
}

int dequeue(Fila* f) {
    if (empty(f)) {
        printf("fila vazia!\n");
        exit(1);
    }
    int elemento = f->vetor[f->ini];
    f->ini = (f->ini + 1) % f->tam;
    return elemento;
}

void drawQueue(Fila* f) {
    srand(time(NULL));
    int r = rand() % 10 + 1;

    for (int i = 0; i < r; i++) {
        enqueue(f, dequeue(f));
    }
    showQueue(f);
}

void showQueue(Fila* f) {
    int i;
    for (i = f->ini; i != f->fim; (i = (i + 1) % f->tam)) {
        printf("%d ", f->vetor[i]);
    }
    printf("\n");
}

bool empty(Fila *f) {
    return (f->ini == f->fim);
}

bool full(Fila *f) {
    return (f->ini == ((f->fim + 1)  % f->tam));
}

void desaloc(Fila *f) {
    free(f->vetor);
    free(f);
}
