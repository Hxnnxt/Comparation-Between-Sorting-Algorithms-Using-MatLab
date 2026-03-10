#include <stdio.h>
#include <stdlib.h>

void bubbleop2 (int A[],int n);

int main(int argc, char const *argv[]){
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
	
	//Llamar al algoritmo
    
	bubbleop2(A,n);
	
	
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }

    return 0;
}

void bubbleop2 (int A[],int n){
    int i,j,aux;
    int cambios = 1;
    while(i<=n-2 && cambios != 0){
        cambios = 0;
        for(j=0;j<=(n-2)-i;j++){
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                cambios = 1;
            }
        }
        i=i+1;
    }
}