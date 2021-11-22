#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
    if (d != NULL) {
        return d->p;
    }
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
    if (d != NULL) {
        Deck *aux = d;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        return aux->p;
    }
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   Deck* apple = (Deck *)malloc(sizeof(Deck));
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   apple->p = p;
   apple->next = d;
   apple->prev = NULL;
   if (d != NULL) {
      d->prev = apple;
   }
   return apple;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   Deck* apple = (Deck *)malloc(sizeof(Deck));
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   apple->p = p;
   apple->prev = NULL;
   apple->next = NULL;

   if (d != NULL) {
       Deck *aux = d;
       while (aux->next != NULL) {
           aux = aux->next;
       }
       apple->prev = aux;
       aux->next = apple;
       return d;
   } else {
       return apple;
   }
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   if (d != NULL) {
       Deck *aux = d;
       if (aux->next != NULL) { 
           aux->next->prev = NULL;
       }
       d = d->next;
      field[aux->p.x][aux->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
      free(aux);
      return d;
   } else {
       return NULL;
   }

}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   if (d != NULL) {
       Deck *aux = d;
       while (aux->next != NULL) {
           aux = aux->next;

       }
       field[aux->p.x][aux->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/

       aux->prev->next = NULL;
       free(aux);
       return d;
   } else {
       return NULL;
   }
}


