#include "stack.h"

Stack *create(int size) {
    Stack *p = (Stack*) malloc(sizeof(Stack));

    p->top = 0;
    p->size = size;
    p->vector = (int*) malloc(sizeof(int) * size);

    return p;
}

void push(Stack *p, int elem) {
    if (full(p)) {
        printf("pilha cheia!\n");
        exit(1);
    }

    p->vector[p->top] = elem;
    (p->top)++;
}

int pop(Stack *p) {
    if (empty(p)) {
        printf("pilha vazia!\n");
        exit(1);
    }
    (p->top)--;
    return p->vector[p->top];
}

bool full(Stack *p) {
    return (p->top == p->size);
}

bool empty(Stack *p) {
    return (p->top == 0);
}

void desalloc(Stack *p) {
    free(p->vector);
    free(p);
}

