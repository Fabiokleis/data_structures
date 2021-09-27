#include <stdio.h>
#include <stdlib.h>

/*NAO USE VARIAVEIS GLOBAIS!!!!!!!!!!!!!*/

/*Função para enfileirar um dado elemento em um vetor: */
void enqueue (int elemento, int *vetor, int tam, int *fim) {
    if (tam > *fim) {
        vetor[*fim] = elemento;
        (*fim)++;
    }
}

int dequeue (int *vetor, int *inicio, int fim) {
    if (*inicio < fim) {
        int atender = vetor[*inicio];
        (*inicio)++;
        return atender;
    } else {
        printf("fila vazia!\n");
    }
}	

int main () {
    int inicio = 0;
    int fim = 0;
    int fila_tamanho = 10;

    int *vetor = (int *)malloc(fila_tamanho * sizeof(int)); 

    for (int i = 0; i < fila_tamanho; i++){
        enqueue(i, vetor, fila_tamanho, &fim);
    }

    printf("%d\n", dequeue (vetor, &inicio, fim));
    printf("%d\n", dequeue (vetor, &inicio, fim));

    free(vetor);

    return 0;	 
}

