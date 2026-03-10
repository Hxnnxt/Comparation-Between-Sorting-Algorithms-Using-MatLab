#include <stdio.h>
#include <stdlib.h>

/* ShellSort */
void shellsort(int *A, int n) {
    int gap = n / 2;

    while (gap >= 1) {
        int cambios;

        do {
            cambios = 0;
            int i;

            for (i = gap; i < n; i++) {
                if (A[i-gap] > A[i]) {
                    int temp = A[i];
                    A[i] = A[i-gap];
                    A[i-gap] = temp;
                    cambios++;
                }
            }

        } while (cambios != 0);

        gap = gap / 2;
    }
}

/* Verificar si está ordenado */
int esta_ordenado(int *A, int n){
	int i;
    for(i = 1; i < n; i++)
        if(A[i-1] > A[i])
            return 0;
    return 1;
}

int main(int argc, char *argv[]) {

    if(argc != 2){
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n*sizeof(int));

    int i;

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    shellsort(A,n);

    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	free(A);
	printf("\n");



    return 0;
}
