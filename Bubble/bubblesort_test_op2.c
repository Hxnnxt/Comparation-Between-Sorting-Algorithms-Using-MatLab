#include <stdio.h>
#include <stdlib.h>
/*
---------------------------------------------------------
Programa: Bubble Sort Optimizado 
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando una versión optimizada del algoritmo
de burbuja.

La optimización consiste en usar una variable (cambios)
para detectar si en una pasada no hubo intercambios,
lo que indica que el arreglo ya está ordenado y se
puede detener el algoritmo antes de tiempo.
---------------------------------------------------------
*/
void bubbleop2 (int A[],int n);

int main(int argc, char const *argv[]){
	// Convierte el argumento de entrada (n) a entero
    int n = atoi(argv[1]);
    int *A;

    //Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	// Verifica que la memoria se reservó correctamente
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	// Lectura de los n elementos desde la entrada estándar
    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	// Llamar al algoritmo de ordenamiento burbuja optimizado
    
	bubbleop2(A,n);
	
	// Imprime el arreglo ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }

    return 0;
}

/*
---------------------------------------------------------
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Implementa el algoritmo de burbuja optimizado con
    una bandera (cambios).

    Funcionamiento:
    - Se repite el proceso mientras haya intercambios
    - Si en una pasada no hay cambios, el algoritmo termina

    Ventaja:
    - Puede detenerse antes si el arreglo ya está ordenado
---------------------------------------------------------
*/
void bubbleop2 (int A[],int n){
    int i,j,aux;
    int cambios = 1;	// Bandera para detectar intercambios
	// Se ejecuta mientras haya cambios y no se haya recorrido todo el arreglo
    while(i<=n-2 && cambios != 0){
        cambios = 0;	// Se asume que no habrá cambios en esta pasada
		// Recorre el arreglo comparando elementos adyacentes
        for(j=0;j<=(n-2)-i;j++){
			// Si están en desorden, se intercambian
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                cambios = 1;	// Indica que sí hubo cambios
            }
        }
        i=i+1;	// Avanza a la siguiente pasada
    }
}
