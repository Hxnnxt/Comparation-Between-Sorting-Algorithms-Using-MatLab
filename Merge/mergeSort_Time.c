#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//**************************************************
//Libreria necesaria para medir rendimiento en Linux
#include "tiempo.h"
//**************************************************

void Merge(int C[],int A[], int p, int r);
void Sort(int C[], int A[], int p, int q, int r);
int main(int argc, char *argv[])
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
//********************************************************

    int n = atoi(argv[1]);
    int *A;
    int *C;

    A=malloc(n*sizeof(int));
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	

    C=malloc(n*sizeof(int));
	if(C==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}

    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
   
//******************************************************************
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	uswtime(&utime0, &stime0, &wtime0);
//******************************************************************

    Merge(C,A,0,n-1);

//******************************************************************
//Evaluar los tiempos de ejecución
	uswtime(&utime1, &stime1, &wtime1);
//******************************************************************
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
	printf("real (Tiempo total)            %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys  (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
//***************************************************************************************************

    return 0;
}

void Merge(int C[],int A[], int p, int r){
    if (p<r)
    {
        int q=(p+r)/2;
        Merge(C,A,p,q);
        Merge(C,A,q+1,r);
        Sort(C,A,p,q,r);
    }
}

void Sort(int C[], int A[], int p, int q, int r){
    int k,l,i,j;
    l=r-p+1;
    i=p;
    j=q+1;
    k=0;
    for ( k = 0; k <l ; k++)
    {
        if (i<=q&&j<=r)
        {
            if (A[i]<A[j])
            {
                C[k]=A[i];
                i++;
            }
            else
            {
            C[k]=A[j];
            j++;
            }
        } 
        
        else if (i<=q)
        {
            C[k]=A[i];
            i++;
        }
        else{
            C[k]=A[j];
            j++;
        }
    }

    k=p;

    for ( i = 0; i < l; i++)
    {
        A[k]=C[i];
        k++;
    }
}
