#include <stdio.h>
#include <stdlib.h>

#include "tiempo.h"

//**************************************************
//Libreria necesaria para medir rendimiento en Linux
#include "tiempo.h"
//**************************************************

void shellsort(int *A, int n);

int main(int argc, char *argv[])
{

//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
//********************************************************

     if(argc != 2){
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n*sizeof(int));

    int i;

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

//******************************************************************	
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
uswtime(&utime0, &stime0, &wtime0);
//******************************************************************

    shellsort(A,n);

//******************************************************************	
//Evaluar los tiempos de ejecución 
uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
	free(A);

//Mostrar los tiempos en formato exponecial+
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************	

}
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
