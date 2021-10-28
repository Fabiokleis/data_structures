#include <stdio.h>
#include <limits.h>
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
}

void imprimir_lista_rec(Lista *lista) {
    if (lista != NULL) {
        printf("%d ", lista->info);
        imprimir_lista_rec(lista->next);
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
        c = conta_nos_rec(lista->next);
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
            // passa por todos os nodes
            // depois de passar, vem retornando
            // cada um até achar o elemento
            c = procura_rec(lista->next, elem);

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
    Lista* aux;
    int u = INT_MIN; // /usr/include/limits.h

    while(lista != NULL) {
        if (lista->info > u) {
            u = lista->info;
        }
        aux = lista->next;
        lista = aux;
    }
    
    // caso lista vazia, ja retorna INT_MIN
    return u;
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec (Lista* lista) {

    int u = INT_MIN; // /usr/include/limits.h
    if (lista != NULL) {
        /* passa todos os lista->info, 
        então vai retornando cada lista->info para u,
        então comparamos com 1 elemento de atraso u
        em relacao ao próprio lista->info só que de 
        trás para frente.
        */
        u = lista_max_rec(lista->next);
        if (u > lista->info) {
            return u;
        } else {
            return lista->info;
        }
    }

    return u;
}

int lista_soma_itr (Lista* lista) {
    Lista* aux;
    int s = 0;

    while(lista != NULL) {
        s += lista->info;
        aux = lista->next;
        lista = aux;
    }

    return s;
}

int lista_soma_rec (Lista* lista) {
   int s = 0;

    if (lista != NULL) {
        // passa todos os elementos
        // então volta retornando na ordem reversa
        // e S vai somando com cada valor lista->info
        s = lista_soma_rec(lista->next);
        return s += lista->info;
    }

    return s;
}

// provavelmente existe uma maneira melhor, mas é isso
void imprimir_invertida_itr (Lista* lista) {
    Lista *next = NULL;
    Lista *prev = NULL;
    // inverte a lista
    while (lista != NULL) {
        /*
        passa o proximo nó para um aux,
        o proximo nó se torna o anterior (primeiro NULL),
        passa o anterior no lugar da lista atual,
        a lista atual se torna o próximo nó
        */

        next = lista->next;
        lista->next = prev;
        prev = lista;
        lista = next;
    }
    lista = prev;
    imprimir_lista(lista); // imprime o reverso

    // passa de volta a lista na ordem normal
    // visto que ja passei ela no reverso 
    // basta fazer novamente
    next = NULL;
    prev = NULL;
    while (lista != NULL) {
        next = lista->next;
        lista->next = prev;
        prev = lista;
        lista = next;
    }
}

void imprimir_invertida_rec (Lista* lista) {
    if (lista != NULL) {
        // passa todos os nós e vem `retornando` imprimindo
        imprimir_invertida_rec(lista->next);
        printf("%d ", lista->info);
    }
}
