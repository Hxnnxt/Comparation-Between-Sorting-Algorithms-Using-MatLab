#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"
/*
---------------------------------------------------------
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando la estructura Heap (Min-Heap).

El proceso consiste en:
1. Insertar todos los elementos en un heap.
2. Extraerlos en orden (del menor al mayor).
3. Guardarlos nuevamente en el arreglo.

Entrada:
- Un argumento desde línea de comandos (n)
- n números enteros desde la entrada estándar

Salida:
- Arreglo ordenado de menor a mayor
---------------------------------------------------------
*/
int main(int argc, char *argv[])
{
    int i;
	// Convierte el argumento recibido (n) a entero
    int n = atoi(argv[1]);
	// Reserva memoria dinámica para el arreglo
    int *A = malloc(sizeof(int) * n);
	// Verifica que la memoria se haya reservado correctamente
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }
	// Lee los n elementos desde la entrada estándar
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
	// Declara un Heap
    Heap H;
	// Inicializa el heap con capacidad n
    Initialize_Heap(&H, n);
    element e;
	// Inserta todos los elementos del arreglo en el heap
    for (i = 0; i < n; i++)
    {
        e.number = A[i];
        Insert_Heap(&H, e);
    }
	// Extrae los elementos del heap en orden y los guarda en el arreglo
    for (i = 0; i < n; i++)
    {
        A[i] = Remove_Heap(&H).number;
    }
	// Libera la memoria del heap
    Destroy_Heap(&H);
	// Imprime el arreglo ordenado
    for (i = 0; i < n; i++)
    {
        printf("[%d]", A[i]);
    }
	printf("\n");	
	free(A);	 // Libera la memoria del arreglo
}
