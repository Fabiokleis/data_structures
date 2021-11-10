#include <stdio.h>
#include <stdlib.h>

typedef struct list {
   int info;
   struct list *next;
   struct list *prev;
} List;

List* criar ();

List *inserir_frente (List *lista, int elem);

List *buscar (List *lista, int elem);

List* remover (List* lista, int elem);

void imprimir (List *lista);

