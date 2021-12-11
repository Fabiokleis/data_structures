#include <stdio.h>
#include <stdlib.h>

/*
 * Trocando a ordem do loop para j = n - 1 para j = 0
 * continua funcionando, mas se existem números repetidos
 * ele não mantém a propriedade da ordem, visto que ele
 * começa do index 0 ele preenche na ordem errada, pois
 * ele coloca as primeiras ocorrências nas últimas posições
 * respectivas o que não respeita a ordem, já no decrescente j = n -1
 * ele passa corretamenta a posição correspondente
*/


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

    for (j = 0; j <= (n-1); j++) {
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
  n = 8;
  //int *A = (int *)malloc(n*sizeof(int));
  int A[8] = {2, 5, 3, 0, 2, 3, 0, 3};
  int *B = (int *)malloc(n*sizeof(int));
  int k = 10000; /*número máximo limite a ser sorteado!*/

  
  //for (i = 0; i < n; i++) {
     //A[i] = rand() % k; /*Sorteio de elementos até limite k-1*/
  //}
  

  Imprimir (A, n);
  /*TERMINAR*/
  CountingSort (A, n, B, k);
  Imprimir (B, n);
  return 0;
}

