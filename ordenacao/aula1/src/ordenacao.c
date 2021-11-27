#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * --Time elapsed--
 * 
 * 10, 100, 1000, 10.000, 100.000, 250.000
 *
 * BubbleSort: 0.00, 0.00, 0.01, 1.43, 164.19, 1030.87
 * SelectionSort: 0.00, 0.00, 0.01, 0.68, 62.89, 545.85
 * InsertionSort: 0.00, 0.00, 0.01, 0.65, 78.20, 308.80
 *
*/


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

void BubbleSortRec (int *vetor, int tamanho, int i) {
    int j, t;

    for (j = 0; j < tamanho; j++) {
        if (vetor[j] > vetor[j + 1]) {
            t = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = t;
        }
    }
    
    if (i < tamanho) {
        return BubbleSortRec(vetor, tamanho, i+1);
    }
}

void SelectionSort (int *vetor, int tamanho) {
    int i, j, lt, t;

    for (i = 0; i < tamanho; i++) {
        t = i; // salva a posição
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[t]) {
                t = j; // muda para posicao do menor
            }
        }
        
        // faz a troca
        lt = vetor[i];
        vetor[i] = vetor[t];
        vetor[t] = lt;
    }
}

void SelectionSortRec (int *vetor, int tamanho, int i) {
    int j, lt, t;
    t = i; // salva a posição
    for (j = i+1; j < tamanho; j++) {
        if (vetor[j] < vetor[t]) {
            t = j; // muda para posicao do menor
        }
    }
    // faz a troca
    lt = vetor[i];
    vetor[i] = vetor[t];
    vetor[t] = lt;
 
    if (i < tamanho) {
       return SelectionSortRec(vetor, tamanho, i+1);
    }
}

void InsertionSort (int *vetor, int tamanho) {
    int i, j, k;

    for (i = 1; i < tamanho; i++) {
        k = vetor[i];
        for (j = i-1; (j >= 0) && (vetor[j] > k); j--) {
            vetor[j + 1] = vetor[j]; // abre espaço
        }
        // quando for achado o lugar, ele estará uma posição atrás
        vetor[j + 1] = k;
    }
}

void InsertionSortRec (int *vetor, int tamanho, int i) {
    int j, k;
    k = vetor[i];
    for (j = i-1; (j >= 0) && (vetor[j] > k); j--) {
        vetor[j + 1] = vetor[j]; // abre espaço
    }
    // quando for achado o lugar, ele estará uma posição atrás
    vetor[j + 1] = k;

    if (i < tamanho) {
        return InsertionSortRec(vetor, tamanho, i+1);
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

  int tamanho = 250000;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }  

  start = clock();
  //Imprimir(v1, tamanho);
  BubbleSort(v1, tamanho);
  //BubbleSortRec (v1, tamanho, 1);
  //Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (BubbleSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }
  

  start = clock();
  //Imprimir(v2, tamanho);
  SelectionSort (v2, tamanho);
  //SelectionSortRec (v2, tamanho, 0);
  //Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenação do SelectionSort não está correta!\n");
  }

  
  start = clock();
  //Imprimir(v3, tamanho);
  InsertionSort(v3, tamanho);
  //InsertionSortRec (v3, tamanho, 1);
  //Imprimir(v3, tamanho);
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

