#include <stdio.h>
#include <stdlib.h>

/* TERMINAR */
/*
void CountingSort (A, n, ...) {
 
}
*/

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
  /*CountingSort (A, n, ...)*/;
  Imprimir (B, n);
  return 0;
}

