#include <stdio.h>
#include <stdlib.h>

void bubble (int A[],int n);

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
    
	bubble(A,n);
	
	
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }

    return 0;
}

void bubble (int A[],int n){
    int i,j,aux;
    for(i=0;i<=n-2;i++){
        for(j=0;j<=n-2;j++){
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}