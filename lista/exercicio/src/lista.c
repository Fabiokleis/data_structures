#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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

Lista* remover_rec(Lista *lista, int elem) {
    if (lista == NULL) {
        return lista;
    } else {
        if (lista->info == elem) {
            Lista *aux = lista->next;
            free(lista);
            return aux;

        } else {
            lista->next = remover_rec(lista->next, elem);
            return lista;
        }
    }
}

void imprimir_lista(Lista *lista) {
    Lista *v;
    for (v = lista; v != NULL; v = v->next) {
        printf("%d ", v->info);
    }
    printf("\n");
}

void imprimir_lista_rec(Lista *lista) {
    if (lista != NULL) {
        printf("%d ", lista->info);
        imprimir_lista_rec(lista->next);

    } else {
        printf("\n");
    }
}

void destruir_lista(Lista *lista) {
    Lista *aux;
    while (lista != NULL) {
        aux = lista->next;
        free(lista);
        lista = aux;
    }
}

int conta_nos_itr (Lista* lista) {
    Lista* aux;
    int i = 0;
    while(lista != NULL) {
        aux = lista->next;
        lista = aux;
        i++;
    }

    return i;
}

int conta_nos_rec (Lista* lista) {
    int c = 0;
    if (lista != NULL) {
        // passa para o proximo nó
        c += conta_nos_rec(lista->next);
        // retorna, mas antes incrementa
        return ++c;
 
    } else { 
        return c;
    }
}


int procura_itr (Lista* lista, int elem) {
    int i = 0;
    Lista* aux;
    if (lista != NULL) {
        while(lista->info != elem) {
            aux = lista->next;
            lista = aux;
            i++;
        }
        return i;

    } else {
        // caso a lista nao tenha valor
        return elem;
    }

}

int procura_rec (Lista* lista, int elem) {
    int c = 0;

    if (lista != NULL) {
        if (lista->info != elem) {
            // passa pro proximo nó
            c += procura_rec(lista->next, elem);    
            // retorna, mas antes incrementa
            return ++c;
        } else {
            // quando achou
            return c;
        }

    } else {
        // caso a lista nao tenha valor
        return elem;
    }
}

int lista_max_itr (Lista* lista) {
   /*TERMINAR*/
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec (Lista* lista) {
   /*TERMINAR*/
}

int lista_soma_itr (Lista* lista) {
   /*TERMINAR*/
}

int lista_soma_rec (Lista* lista) {
   /*TERMINAR*/
}

/*Você pode usar outras funções aqui se achar necessário!*/
void imprimir_invertida_itr (Lista* lista) {
   /*TERMINAR*/
}

void imprimir_invertida_rec (Lista* lista) {
   /*TERMINAR*/
}
