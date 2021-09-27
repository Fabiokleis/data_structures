#include "fila.h"

Fila *criar(int tam) {
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = 0;
    f->fim = 0;
    f->tam = tam;
    f->vetor = (int*) malloc(sizeof(int) * tam);

    return f;
}

void enqueue(int elemento, Fila *f) {
    if (f->fim < f->tam) {
        f->vetor[f->fim] = elemento;
        f->fim++;
    } else {
        printf("fila cheia!\n");
    }
}

int dequeue(Fila *f) {
    if (f->ini < f->fim) {
        int atender = f->vetor[f->ini];
        (f->ini)++;
        return atender;
    } else { 
        printf("fila vazia!\n");
    }
}

void desaloc(Fila *f) {
    free(f->vetor);
    free(f);
}

