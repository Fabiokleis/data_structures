#include "lista.h"

List* criar () {
   return NULL;
}

List *inserir_frente (List *lista, int elem) {
   List *no = (List *)malloc(sizeof(List));
   no->info = elem;
   no->prev = NULL;
   no->next = lista;
   if (lista != NULL)
      lista->prev = no;
   return no;   
}

List *buscar (List *lista, int elem) {
   List *aux;
   for (aux = lista; aux != NULL; aux = aux->next) {
      if (aux->info == elem)	
	 return aux;     
   }
   return NULL;
}

List* remover (List* lista, int elem) {
    List *no = buscar (lista, elem);
    if (no == NULL)
        return lista;
    if (lista == no)
        lista = no->next;
    if (no->next != NULL)
        no->next->prev = no->prev;
    if (no->prev != NULL)
        no->prev->next = no->next;
    free(no);
    return lista;
}

void imprimir (List *lista) {
   List *aux, *ultimo;
   printf("Lista (inicio-fim): ");
   for (aux = lista; aux != NULL; aux = aux->next) {
      ultimo = aux; 	   
      printf("%d ", aux->info);
   }
   printf("\n");
   printf("Lista (fim-inicio): ");
   for (aux = ultimo; aux != NULL; aux = aux->prev) {
      printf("%d ", aux->info);
   }
   printf("\n");
}

