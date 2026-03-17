#include <stdio.h>
#include <stdlib.h>
/*
---------------------------------------------------------
Programa: Ordenamiento por Selección (Selection Sort)
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando el algoritmo de selección.

El algoritmo de selección funciona buscando el elemento
más pequeño y colocándolo en la posición correcta en
cada iteración.
---------------------------------------------------------
*/

void selection (int A[], int n);

int main(int argc, char const *argv[]){
    // Convierte el argumento de entrada (n) a entero
    int n = atoi(argv[1]);
    int *A;

    //Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	// Verifica si la memoria se reservó correctamente
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	// Lectura de los n elementos desde la entrada estándar
    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	// Llamar al algoritmo de ordenamiento por selección
    
	selection(A,n);
	
	// Imprime el arreglo ya ordenado
    printf("Arreglo ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }
	// Libera la memoria dinámica
    free(A);	
    printf("\n");

    return 0;
}

/*
---------------------------------------------------------
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena el arreglo utilizando el algoritmo de
    selección (Selection Sort).

    En cada iteración:
    - Se busca el elemento mínimo del arreglo
    - Se intercambia con la posición actual
---------------------------------------------------------
*/
void selection (int A[], int n){
    int k,p,i,temp;
	// Recorre el arreglo hasta el penúltimo elemento
    for( k = 0 ; k <= n - 2 ; k++){
        p = k;// Se asume que el mínimo está en la posición k
		// Busca el elemento más pequeño en el resto del arreglo
        for( i = k + 1 ; i <= n - 1 ; i++){
            if(A[i] < A[p]){
                p = i;	// Actualiza la posición del mínimo
            }
        }
		// Intercambia el elemento mínimo con la posición k
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
}
