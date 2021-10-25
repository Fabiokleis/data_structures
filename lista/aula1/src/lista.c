#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criar_lista(void) {
    return NULL;
}

Lista* inserir(Lista* lista, int elem) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->info = elem;
    novo->next = lista;
}

Lista* remover(Lista *lista, int elem) {
    Lista *prev = NULL, *v = lista;

    while((v != NULL) && (v->info != elem)) {
        prev = v;
        v = v->next;
    }
    if (v == NULL) {
        return lista;

    } else if (prev == NULL) {
        lista = v->next;

    } else {
        prev->next = v->next;
    }

    return lista;
}

void imprimir_lista(Lista *lista) {
    Lista *v;
    for (v = lista; v != NULL; v = v->next) {
        printf("%d ", v->info);
    }
    printf("\n");
}

void destruir_lista(Lista *lista) {
    Lista *aux;
    while (lista != NULL) {
        aux = lista->next;
        free(lista);
        lista = aux;
    }
}
