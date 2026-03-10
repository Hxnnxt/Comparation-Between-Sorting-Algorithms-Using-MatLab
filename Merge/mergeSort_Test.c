#include <stdio.h>
#include <stdlib.h>

void Merge(int C[],int A[], int p, int r);
void Sort(int C[], int A[], int p, int q, int r);

int main(int argc, char *argv[])
{
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

    Merge(C,A,0,n-1);    

    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < Tamano(&m); j++)
    {
        printf("[%d]", A[j]);
    }
    printf("\n");

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
