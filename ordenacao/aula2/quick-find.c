#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

int Particione(int *vetor, int e, int d) {
    int t;
    int p = vetor[d]; // p é o pivô
    int i = e - 1;
    int j;

    for (j = e; j <= (d - 1); j++) {
        if (vetor[j] <= p) {
            i = i + 1;
            t = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = t;
        }
    }

    t = vetor[i + 1];
    vetor[i + 1] = vetor[d];
    vetor[d] = t;

    return i + 1;
}

int QuickFind (int *vetor, int esq, int dir, int k) {
    if (esq <= dir) {
        int q = Particione(vetor, esq, dir);
        if (q == k) {
            printf("O elemento procurado na posição %d é %d\n", k, vetor[k]);
            return vetor[k];
        } else if(q > k) {
            QuickFind(vetor, esq, dir-1, k);
        } else {
            QuickFind(vetor, q+1, dir, k);
        }
    }
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   
   int tamanho = 10;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
   }
   
   Imprimir (vetor, tamanho);
   start = clock();
   int pos = 4;
   printf("O elemento procurado na posição %d é %d\n", pos, QuickFind(vetor, 0, tamanho-1, pos));
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   return 0;
}
