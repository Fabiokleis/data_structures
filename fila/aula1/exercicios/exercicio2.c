#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int tamanho) {
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = 0;
    f->fim = 0;
    f->tam = tamanho;
    f->vetor = (int*) malloc(sizeof(int) * tamanho);

    return f;
}

void destruir_fila (Fila *f) {
    free(f->vetor);
    free(f);
}

void enqueue (Fila *f, int elemento) {
    if (f->fim < f->tam) {
        f->vetor[f->fim] = elemento;
        f->fim++;
    } else {
        printf("fila cheia!\n");
    }
}

int dequeue (Fila *f) {
    if (f->ini < f->fim) {
        int atender = f->vetor[f->ini];
        (f->ini)++;
        return atender;
    } else { 
        printf("fila vazia!\n");
        exit(1);
    }
}       

int main () {

   /*Inicializando a estrutura de dados fila!*/  
   Fila *fila = criar_fila (10);

   /*Tentando inserir o elemento 1 na fila!*/ 
   int elem = 1; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 2 na fila!*/ 
   elem = 2; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 3 na fila!*/ 
   elem = 3; 
   enqueue (fila, elem);

   /*Tentando inserir o elemento 4 na fila!*/ 
   elem = 4; 
   enqueue (fila, elem);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/ 
   printf("%d\n", dequeue (fila));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/ 
   printf("%d\n", dequeue (fila));

   destruir_fila (fila);

   return 0;
}
