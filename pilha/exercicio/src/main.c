#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <time.h>
#include <unistd.h>
#define N 10


void push_cards(Stack* cards) {
    int k;
    srand(time(NULL));

    for (k = 0; k < N; k++) {
        push(cards, rand() % 9 + 1);
    }
}

void show_cards(Stack* cards) {
    int j, top;

    for (j = cards->top-1; j >= 0; j--) {
        printf("|%d", cards->vector[j]);
    }
    printf("|");
    printf("\n");

}

void game(Stack *cards1, Stack *cards2) {
    bool flag = false;
    int j, pop1, pop2, rounds=0;
   
    do {

        pop1 = pop(cards1);
        pop2 = pop(cards2);

        if (pop1 > pop2) {

            for (j = 0; (j < (pop1 - pop2)) && !(empty(cards1)); j++) {
               push(cards2, pop(cards1));
            }

        } else if (pop2 > pop1) {

            for (j = 0; (j < (pop2 - pop1)) && !(empty(cards2)); j++) {
                push(cards1, pop(cards2));
            }
        }
        show_cards(cards1);

        show_cards(cards2);

        rounds++;

        printf("rounds: %d\n", rounds);
       
        // se nenhuma das stacks estiverem vazias
        // continua o loop, se estiverem pelo menos uma, para.
        if (empty(cards2) || empty(cards1)) {
            flag = true;
        }
 
    } while (!flag);
  
   

    if (empty(cards1)) {
        printf("Primeiro Jogador venceu!\n");

    } else {
        printf("Segundo Jogador venceu!\n");
    }


}


int main(int argc, char argv[]) {

    // create players cards;
    Stack *cards1 = create(2*N);
    Stack *cards2 = create(2*N);
    
    // initialize cards
    push_cards(cards1);
    usleep(1000000); // sleep 1 sec
    push_cards(cards2);
    printf("init state of cards\n"); 
    show_cards(cards1);
    show_cards(cards2);
    printf("---------------------\n");
    // call game function
    game(cards1, cards2);

    // free stacks
    desalloc(cards1);
    desalloc(cards2);


    return 0;
}
