#include <stdio.h>
#include <stdlib.h>

void selection (int A[], int n);

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
    
	selection(A,n);
	
	
    printf("Arreglo ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }
    free(A);
    printf("\n");

    return 0;
}


void selection (int A[], int n){
    int k,p,i,temp;

    for( k = 0 ; k <= n - 2 ; k++){
        p = k;
        for( i = k + 1 ; i <= n - 1 ; i++){
            if(A[i] < A[p]){
                p = i;
            }
        }
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
}
