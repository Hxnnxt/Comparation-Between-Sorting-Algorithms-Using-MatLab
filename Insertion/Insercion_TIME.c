#include <stdio.h>
#include <stdlib.h>
//**************************************************
//Libreria necesaria para medir rendimiento en Linux
#include "tiempo.h"
//**************************************************
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

int main(int argc, char *argv[]) 
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
//********************************************************
    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
//******************************************************************	
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	uswtime(&utime0, &stime0, &wtime0);
//******************************************************************
    insercion(A, n);
//******************************************************************	
//Evaluar los tiempos de ejecución 
	uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
    free(A);
//******************************************************************	
//Evaluar los tiempos de ejecución 
	uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
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
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
//***************************************************************************************************
return 0;	
}
