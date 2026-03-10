#include <stdio.h>
#include <stdlib.h>
#include "SortShell.h"

//**************************************************
//Libreria necesaria para medir rendimiento en Linux
//#include "tiempo.h"
//**************************************************

int main(int argc, char *argv[])
{

//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
//	double utime0, stime0, wtime0,utime1, stime1, wtime1;
//********************************************************

    int i;
    int n = atoi(argv[1]);

    element *A = malloc(sizeof(element) * n);

    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i].number);
    }

//******************************************************************	
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
//uswtime(&utime0, &stime0, &wtime0);
//******************************************************************

    ShellSort(A, n);

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

}
