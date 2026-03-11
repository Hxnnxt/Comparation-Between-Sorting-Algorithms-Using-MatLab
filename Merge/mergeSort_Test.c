#include <stdio.h>
#include <stdlib.h>

void Merge(int C[], int A[], int p, int r);
void Sort(int C[], int A[], int p, int q, int r);

/*
Función principal del programa
*/
int main(int argc, char *argv[])
{
    // Convierte el primer argumento recibido a entero para definir el tamaño de los arreglos
    int n = atoi(argv[1]);
    int *A; // Apuntador para el arreglo principal
    int *C; // Apuntador para el arreglo auxiliar/temporal

    // Reserva memoria dinámica para el arreglo principal A
    A = malloc(n * sizeof(int));
    if(A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);       
        exit(1);
    }   

    // Reserva memoria dinámica para el arreglo temporal C
    C = malloc(n * sizeof(int));
    if(C == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);       
        exit(1);
    }

    // Lee los n números desde la entrada estándar y los guarda en A
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Llama a la función principal de MergeSort indicando los índices inicial (0) y final (n-1)
    Merge(C, A, 0, n - 1);    

    // Imprime el arreglo ya ordenado
    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < n; j++)
    {
        printf("[%d]", A[j]);
    }
    printf("\n");

    // Es una buena práctica liberar la memoria reservada al finalizar
    free(A);
    free(C);

    return 0;
}

/*
Entrada:
    int C[] -> arreglo temporal/auxiliar
    int A[] -> arreglo de números enteros a ordenar
    int p   -> índice inicial de la sublista
    int r   -> índice final de la sublista
Descripción:
    Aplica la estrategia "divide y vencerás". Divide recursivamente 
    el arreglo en mitades hasta llegar a subarreglos de 1 elemento, 
    para luego llamar a la función Sort y fusionarlos en orden.
*/
void Merge(int C[], int A[], int p, int r){
    // Condición base: verifica que la sublista tenga al menos dos elementos
    if (p < r)
    {
        // Calcula el índice medio para dividir el arreglo en dos mitades
        int q = (p + r) / 2;
        
        // Llamada recursiva para ordenar la mitad izquierda (de p hasta q)
        Merge(C, A, p, q);
        // Llamada recursiva para ordenar la mitad derecha (de q+1 hasta r)
        Merge(C, A, q + 1, r);
        
        // Fusiona ambas mitades ya ordenadas
        Sort(C, A, p, q, r);
    }
}

/*
Entrada:
    int C[] -> arreglo temporal/auxiliar
    int A[] -> arreglo principal
    int p   -> índice inicial de la primera mitad
    int q   -> índice medio (fin de la primera mitad)
    int r   -> índice final de la segunda mitad
Descripción:
    Toma dos subarreglos adyacentes que ya están ordenados (A[p..q] 
    y A[q+1..r]) y los combina ordenadamente en el arreglo temporal C. 
    Finalmente, copia los elementos ordenados de vuelta al arreglo original A.
*/
void Sort(int C[], int A[], int p, int q, int r){
    int k, l, i, j;
    
    l = r - p + 1;  // Calcula la longitud total de los elementos a fusionar
    i = p;          // Índice para recorrer la primera mitad (izquierda)
    j = q + 1;      // Índice para recorrer la segunda mitad (derecha)
    k = 0;          // Índice para almacenar elementos en el arreglo temporal C

    // Recorre todos los espacios necesarios para la fusión (l elementos)
    for (k = 0; k < l ; k++)
    {
        // Si ambas mitades aún tienen elementos disponibles para comparar
        if (i <= q && j <= r)
        {
            // Compara los elementos actuales de ambas mitades
            if (A[i] < A[j])
            {
                C[k] = A[i]; // El elemento de la izquierda es menor, se guarda en C
                i++;         // Avanza el índice de la izquierda
            }
            else
            {
                C[k] = A[j]; // El elemento de la derecha es menor, se guarda en C
                j++;         // Avanza el índice de la derecha
            }
        } 
        // Si la segunda mitad ya se agotó, copia directamente lo que queda de la primera
        else if (i <= q)
        {
            C[k] = A[i];
            i++;
        }
        // Si la primera mitad ya se agotó, copia directamente lo que queda de la segunda
        else
        {
            C[k] = A[j];
            j++;
        }
    }

    // Reinicia k al índice inicial p del arreglo original
    k = p;

    // Copia los elementos ya ordenados del arreglo temporal C de vuelta al arreglo principal A
    for (i = 0; i < l; i++)
    {
        A[k] = C[i];
        k++;
    }
}
