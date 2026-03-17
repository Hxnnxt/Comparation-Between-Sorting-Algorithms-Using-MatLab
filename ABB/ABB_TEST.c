#include <stdio.h>
#include <stdlib.h>
#include "TADArbolBin.h"
/*
---------------------------------------------------------
Programa: Ordenamiento utilizando Árbol Binario de Búsqueda
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los inserta en un Árbol Binario de Búsqueda (ABB)
y posteriormente los recupera en orden mediante un recorrido
inorden, logrando así ordenar los elementos.

Funcionamiento:
1. Se insertan los elementos en el árbol.
2. Se recorre el árbol en orden (InOrden).
3. Se almacenan los elementos ordenados en el arreglo.

Entrada:
- Un argumento (n) desde la línea de comandos
- n números enteros desde la entrada estándar

Salida:
- Arreglo ordenado de menor a mayor
---------------------------------------------------------
*/
int main(int argc, char *argv[])
{
	int i;
	// Declaración del árbol binario
	arbolBinario arbol;
	// Inicializa el árbol
	Inicializar(&arbol);
	// Convierte el argumento de entrada (n) a entero
	int n = atoi(argv[1]);
	// Reserva memoria dinámica para el arreglo
	int *A = malloc(sizeof(int) * n);
	// Verifica que la memoria se haya reservado correctamente
	if (A == NULL)
	{
		printf("\nError al reservar memoria para %d elementos\n", n);
		exit(EXIT_FAILURE);
	}
	// Lectura de los n elementos desde la entrada estándar
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &A[j]);
	}
	// Inserta cada elemento en el árbol binario
	for (i = 0; i < n; i++)
	{
		Insert(&arbol, A[i]);
	}
	// Inicializa el índice para llenar el arreglo ordenado
	i = 0;
	/*
	Recorrido InOrden:
	- Visita los nodos en orden ascendente
	- Guarda los valores en el arreglo A
	*/
	InOrden(&arbol, Raiz(&arbol), A, &i);
	// Libera la memoria del árbol
	Destruir(&arbol);
	// Imprime el arreglo ordenado
	printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	// Libera la memoria del arreglo
	free(A);
	printf("\n");
}
