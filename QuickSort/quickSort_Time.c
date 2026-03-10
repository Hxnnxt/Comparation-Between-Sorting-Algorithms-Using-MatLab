#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
//**************************************************
//Libreria necesaria para medir rendimiento en Linux
//#include "tiempo.h"
//**************************************************

int main(int argc, char *argv[])
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
//	double utime0, stime0, wtime0, utime1, stime1, wtime1;
//********************************************************

    int n = atoi(argv[1]);
    int *A;

    //Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	


    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

//******************************************************************
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
//	uswtime(&utime0, &stime0, &wtime0);
//******************************************************************

    QuickSort(A,0,n-1);

//******************************************************************
//Evaluar los tiempos de ejecución
//	uswtime(&utime1, &stime1, &wtime1);
//******************************************************************

    printf("\n");

//***************************************************************************************************
//Cálculo del tiempo de ejecución del programa
//	printf("real (Tiempo total)            %.10f s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
//	printf("sys  (Tiempo en acciones de E/S)  %.10f s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************

//***************************************************************************************************
//Mostrar los tiempos en formato exponencial
//	printf("real (Tiempo total)            %.10e s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
//	printf("sys  (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************

    return 0;
}

void QuickSort(int A[], int p, int r){
    int j;
    if (p<r)
    {
        j = Pivot(A,p,r);
        QuickSort(A, p, j-1);
        QuickSort(A, j+1, r);
    }
}

int Pivot(int A[], int p, int r){
    int piv=A[p];
    int i=p+1;
    int j=r;

    while (i<j)
    {
        while (A[i]<=piv && i<=r){
            i++;
        }
        
        while (A[j]>piv && j>=p){
            j--;
        }

        if (i<j)
        {
            Intercambio(A,i,j);
        }  
    }
    Intercambio(A,p,j);
    return j;
}

void Intercambio(int A[], int i, int j){
    int temp=A[j];
    A[j]=A[i];
    A[i]=temp;
}
