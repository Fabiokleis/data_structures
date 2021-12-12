#include <stdio.h>
#include <stdlib.h>

/* Passe via argv 3 argumentos n inteiros e o intervalo {a...b} */

void showInterval(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void PProcessamento(int n, int k, int* v, int* C) {

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    
    for (int j = 0; j < (n-1); j++) {
        C[v[j]]++;
    }

    showInterval(k, C);

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
        printf("%d\n", C[i]);

    }
}

int Query(int a, int b, int* C) {
    if (b > 0) {
        if (a > 0) {
            return (C[b]) - C[a-1];
        } else if(a == 0) {
            return C[b];
        }
    } else if (b == 0){
        return (C[b]);
    }
}

int main(int argc, char *argv[]) {
    int n, a, b, k = 10;
    int *v = (int*) malloc(n*sizeof(int));
    int *C = (int*) malloc(k*sizeof(int));

    n = atoi(argv[1]);
    a = atoi(argv[2]);
    b = atoi(argv[3]);

    for (int i = 0; i < n; i++) {
        v[i] = rand() % (k+1);
    }

    showInterval(n, v);
    PProcessamento(n, k, v, C);
    showInterval(k, C);

    int qN = Query(a, b, C);
    printf("quantidade de inteiros entre %d e %d é %d\n", a, b, qN);

    free(v);
    return 0;
}
