#include <stdio.h>
#include <stdlib.h>

/* TERMINAR */
void CountingSort (int *A, int n, int *B, int k) {
    int i, j;
    int *C = (int*) malloc(k);

    for (i = 0; i < k; i++) {
        C[i] = 0;
    }

    for (j = 0; j <= (n-1); j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    for (i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (j = (n-1); j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

}

void Imprimir (int A[], int n) {
  int i;
  printf ("Vetor: ");
  for (i = 0; i < n; i++) {
     printf ("%d ", A[i]);
  }
  printf ("\n");
}

int main () {

  int i, n;
  printf ("Digite a quantidade de elementos: ");
  scanf ("%d", &n);
  int *A = (int *)malloc(n*sizeof(int));
  int *B = (int *)malloc(n*sizeof(int));
  int k = 10000; /*número máximo limite a ser sorteado!*/
  for (i = 0; i < n; i++) {
     A[i] = rand() % k; /*Sorteio de elementos até limite k-1*/
  }
  Imprimir (A, n);
  /*TERMINAR*/
  CountingSort (A, n, B, k);
  Imprimir (B, n);
  return 0;
}

