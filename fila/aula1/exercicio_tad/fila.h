#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int ini;
    int fim;
    int tam;
    int *vetor;
} Fila;

Fila *criar(int tam);
void enqueue(int elemento, Fila *f); 
int dequeue(Fila *f); 
void desaloc(Fila *f);
