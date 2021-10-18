#include <stdlib.h>
#include <stdio.h>

typedef enum { false = 0, true = 1 } bool;

typedef struct {
    int top;
    int size;
    int *vector;
} Stack;

Stack *create(int size);
void push(Stack *p, int elem);
int pop(Stack *p);
bool full(Stack *p);
bool empty(Stack *p);
void desalloc(Stack *p);
