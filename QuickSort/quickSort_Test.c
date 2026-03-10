#include <stdio.h>
#include <stdlib.h>

void QuickSort(int A[], int p, int r);
int Pivot(int A[], int p, int r);
void Intercambio(int A[], int i, int j);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    quickSort q;
    Inicializar(&q, n);

    for (int j = 0; j < n; j++)
    {
        int val;
        scanf("%d", &val);
        EscribirPosicion(&q, j, val);
    }

    QuickSort(A,0,n-1);

    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < Tamano(&q); j++)
    {
        printf("[%d]", LeerPosicion(&q, j).numero);
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
