#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   /*Terminar ...*/
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   /*Terminar ...*/
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   /*Terminar ...*/
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
   /*Terminar ...*/
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   /*Terminar ...*/
   field[p.x][p.y] = '*';  /*Ponto inserido faz parte do corpo da Snake!*/
   /*Terminar ...*/
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   /*Terminar ...*/
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   /*Terminar ...*/
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   /*Terminar ...*/
   //field[x][y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
   /*Terminar ...*/
}


