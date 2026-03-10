#include <stdio.h>
#include <stdlib.h>

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

    insercion(A, n);

    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	free(A);
	printf("\n");
    return 0;
}
