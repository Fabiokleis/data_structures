#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

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

int Particione_Aleatorio(int A[], int l, int r) {
    int t;
    int pp = l + rand() % (r - l + 1);
    t = A[r];
    A[r] = A[pp];
    A[pp] = t;

    return Particione(A, l, r);
}

void QuickSort (int *vetor, int esq, int dir) {
    int p;
    if(esq < dir) {
        p = Particione_Aleatorio(vetor, esq, dir);
        QuickSort(vetor, esq, p - 1);
        QuickSort(vetor, p + 1, dir);
    }
}


/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 1000000;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = tamanho; i > 0; i--) {
      //vetor[i] = rand() % (tamanho+1);
      vetor[i] = i;
   }
   //Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);

   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   //Imprimir (vetor, tamanho);
   free (vetor);
   return 0;
}
