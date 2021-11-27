#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort (int *vetor, int tamanho) {
    int i, j, t;

    for (i = 1; i < tamanho; i++) {
        for (j = 0; j < tamanho-i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                t = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = t;
            }
        }
    }
}
 
void SelectionSort (int *vetor, int tamanho) {
    int i, j, lt, t;

    for (i = 0; i < tamanho; i++) {
        t = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[t]) {
                t = j;
            }
        }

        lt = vetor[i];
        vetor[i] = vetor[t];
        vetor[t] = lt;
    }
}

void InsertionSort (int *vetor, int tamanho) {
    int i, j, k, t;

    for (i = 1; i < tamanho; i++) {
        k = vetor[i]; // chave
        for (j = i; j > 0 && (vetor[j] < k); j--) {
            if (k < vetor[j]) {
                vetor[j] = vetor[j - 1];
            }
        }

        vetor[j] = k;
    }

}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}


int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;

  int tamanho = 10;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }  

  start = clock();
  Imprimir(v1, tamanho);
  BubbleSort (v1, tamanho);
  Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (BubbleSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }
  
  start = clock();
  Imprimir(v2, tamanho);
  SelectionSort (v2, tamanho);
  Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenação do SelectionSort não está correta!\n");
  }
  
  start = clock();
  Imprimir(v3, tamanho);
  InsertionSort (v3, tamanho);
  Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho)) {
     printf("Erro: a ordenação do InsertionSort não está correta!\n");
  }
  
  free (v1);
  free (v2);
  free (v3);

  return 0;
}

