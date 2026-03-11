#include <stdio.h>
#include <stdlib.h>

void QuickSort(int A[], int p, int r);
int Pivot(int A[], int p, int r);
void Intercambio(int A[], int i, int j);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int *A = malloc(sizeof(int) * n);
	if (A == NULL)
	{
		printf("\nError al reservar memoria para %d elementos\n", n);
		exit(EXIT_FAILURE);
	}

	for (int j = 0; j < n; j++)
	{
		scanf("%d", &A[j]);
	}

    QuickSort(A,0,n-1);

    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < n; j++)
    {
        printf("[%d]",A[j]);
    }

    printf("\n");

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
