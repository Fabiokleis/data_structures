#include <stdio.h>
#include "lista.h"

int main(int argc, char* argv[]) {

    Lista *lista = criar_lista();
    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 4);
    imprimir_lista(lista);
    lista = remover(lista, 2);
    imprimir_lista(lista);
    lista = remover(lista, 1);
    imprimir_lista(lista);
    lista = remover(lista, 4);
    imprimir_lista(lista);
    destruir_lista(lista);

    return 0;
}
