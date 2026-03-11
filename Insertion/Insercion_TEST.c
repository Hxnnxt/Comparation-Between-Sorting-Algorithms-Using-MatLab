#include <stdio.h>
#include <stdlib.h>

/*
Entrada:
    int *A  -> arreglo de números enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena los elementos del arreglo utilizando
    el algoritmo de ordenamiento por inserción.
*/
void insercion(int *A, int n) {
    int i;
	// Recorre el arreglo comenzando desde el segundo elemento
    for (i = 1; i < n; i++) {
        int clave = A[i];	// Elemento que se desea insertar en la posición correcta
        int j = i - 1;		// Índice del elemento anterior

		// Desplaza los elementos mayores que la clave hacia la derecha
        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }
		 // Inserta el elemento en la posición correcta
        A[j + 1] = clave;
    }
}


/*
Función principal del programa
*/
int main(int argc, char *argv[]) {
// Verifica que el usuario haya ingresado el argumento n
    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }
// Convierte el argumento recibido a entero
    int n = atoi(argv[1]);
// Reserva memoria dinámica para almacenar n enteros
    int *A = malloc(n * sizeof(int));

    int i;
	// Lee los n números desde la entrada estándar
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Llama a la función de ordenamiento por inserción
    insercion(A, n);
	// Imprime el arreglo ya ordenado
    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	// Libera la memoria reservada dinámicamente
	free(A);
	printf("\n");
    return 0;
}

