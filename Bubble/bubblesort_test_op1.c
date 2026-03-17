#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//**************************************************
//Libreria necesaria para medir rendimiento en Linux
#include "tiempo.h"
//**************************************************
void bubbleop1 (int A[],int n);
int main(int argc, char *argv[])
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
//********************************************************
    int i;
    int n = atoi(argv[1]);
    int *A = malloc(sizeof(int) * n);
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

//******************************************************************	
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
//uswtime(&utime0, &stime0, &wtime0);
//******************************************************************
    bubbleop1(A,n);
//******************************************************************	
//Evaluar los tiempos de ejecución 
//uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
    free(A);
//***************************************************************************************************	
//Cálculo del tiempo de ejecución del programa
//	printf("\n");
//	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
//	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************		
//***************************************************************************************************	
//Mostrar los tiempos en formato exponecial
//	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
//***************************************************************************************************	
return 0;
}
/*
---------------------------------------------------------
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Implementa el algoritmo de burbuja optimizado.

    Mejora:
    En cada iteración se reduce el número de comparaciones,
    ya que los elementos más grandes se van colocando al
    final del arreglo.

    Complejidad:
    - Peor caso: O(n^2)
    - Mejor caso: O(n)
---------------------------------------------------------
*/
void bubbleop1 (int A[],int n){
    int i,j,aux;
	// Recorre el arreglo
    for(i=0;i<=n-2;i++){
		// Reduce el rango de comparación en cada iteración
        for(j=0;j<=(n-2)-i;j++){
			// Intercambia si los elementos están desordenados
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
