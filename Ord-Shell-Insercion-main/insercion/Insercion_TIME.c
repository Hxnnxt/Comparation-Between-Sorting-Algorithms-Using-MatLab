#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ordenamiento por Inserción */
void insercion(int *A, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int clave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = clave;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    clock_t inicio = clock();

    insercion(A, n);

    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Insercion n=%d tiempo=%.6f segundos\n", n, tiempo);

    free(A);
    return 0;
}
