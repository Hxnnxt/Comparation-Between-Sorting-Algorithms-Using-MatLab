#include <stdio.h>
#include <stdlib.h>
/*
---------------------------------------------------------
Programa: Ordenamiento Burbuja (Bubble Sort)
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando el algoritmo de la burbuja.

El algoritmo compara elementos adyacentes e intercambia
sus posiciones si están en el orden incorrecto.
Este proceso se repite hasta que el arreglo queda ordenado.
---------------------------------------------------------
*/
void bubble (int A[],int n);

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
	
	//Llamar al algoritmo
    
	bubble(A,n);
	
	// Imprime el arreglo ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }

    return 0;
}

te voy a enviar codigos y quiero que los documentes

Perfecto 👍
Envíame los códigos y te los documento.

Puedo documentarlos de varias formas (dime si tu profesor pide alguna en específico):

Comentarios dentro del código explicando cada parte.

Encabezado del programa con:

Nombre del programa

Descripción

Autor

Fecha

Compilación / ejecución

Explicación de cada función (entrada, proceso, salida).

Comentarios línea por línea si necesitas que quede muy detallado para entrega.

📌 Normalmente para materias de Algoritmos / Estructuras de Datos en C se usa algo así:

/*
    Programa: Ordenamiento por Inserción
    Descripción: Ordena un arreglo de números enteros utilizando
    el algoritmo de inserción.
*/
Mándame el primer código y lo documento. 💻


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ordenamiento por Inserci�n */
void insercion(int *A, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int clave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = clave;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    clock_t inicio = clock();

    insercion(A, n);

    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Insercion n=%d tiempo=%.6f segundos\n", n, tiempo);

    free(A);
    return 0;
}

Aquí tienes tu código documentado con comentarios claros para que puedas entregarlo o estudiarlo.

#include <stdio.h>   // Librería para entrada y salida estándar (printf, scanf)
#include <stdlib.h>  // Librería para funciones como malloc y atoi
#include <time.h>    // Librería para medir el tiempo de ejecución

/*
    ---------------------------------------------------------
    Programa: Ordenamiento por Inserción
    Descripción:
    Este programa lee n números enteros desde la entrada
    estándar, los guarda en un arreglo dinámico y los ordena
    utilizando el algoritmo de ordenamiento por inserción.
    
    Además, mide el tiempo que tarda en ejecutarse el
    algoritmo de ordenamiento.

    Entrada:
    - Un argumento desde línea de comandos (n) que indica
      la cantidad de números a ordenar.
    - n números enteros desde la entrada estándar.

    Salida:
    - El tiempo de ejecución del algoritmo de inserción.

    Compilación:
    gcc insercion.c -o insercion.exe

    Ejecución:
    insercion.exe n < archivoNumeros.txt
    ---------------------------------------------------------
*/


/*
    Función: insercion
    Entrada:
        int *A  -> arreglo de enteros
        int n   -> tamaño del arreglo
    Descripción:
        Ordena el arreglo utilizando el algoritmo
        de ordenamiento por inserción.
*/
void insercion(int *A, int n) {

    int i;

    // Recorre el arreglo desde el segundo elemento
    for (i = 1; i < n; i++) {

        int clave = A[i];   // Elemento que se insertará en su posición correcta
        int j = i - 1;      // Índice del elemento anterior

        // Desplaza los elementos mayores que la clave hacia la derecha
        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        // Inserta la clave en su posición correcta
        A[j + 1] = clave;
    }
}


/*
    Función principal del programa
*/
int main(int argc, char *argv[]) {

    // Verifica que el número de argumentos sea correcto
    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    // Convierte el argumento recibido a entero
    int n = atoi(argv[1]);

    // Reserva memoria dinámica para el arreglo
    int *A = malloc(n * sizeof(int));

    int i;

    // Lee n números desde la entrada estándar
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Guarda el tiempo inicial antes de ordenar
    clock_t inicio = clock();

    // Llama a la función de ordenamiento por inserción
    insercion(A, n);

    // Guarda el tiempo final después de ordenar
    clock_t fin = clock();

    // Calcula el tiempo de ejecución en segundos
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Imprime el tamaño del arreglo y el tiempo de ejecución
    printf("Insercion n=%d tiempo=%.6f segundos\n", n, tiempo);

    // Libera la memoria reservada
    free(A);

    return 0;
}
✅ Este tipo de documentación es la que normalmente piden en Algoritmos / Análisis de Algoritmos porque:

Explica qué hace cada función

Explica las variables importantes

Incluye compilación y ejecución

Si quieres, también puedo darte una versión más profesional (tipo práctica de IPN) con secciones como:

Algoritmo

Complejidad O(n²)

Descripción paso a paso

para que tu tarea quede mucho más completa.


#include <stdio.h>
#include <stdlib.h>

/* Ordenamiento por Inserci�n */
void insercion(int *A, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int clave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = clave;
    }
}



int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    insercion(A, n);

    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	free(A);
	printf("\n");
    return 0;
}

Aquí tienes tu código documentado con comentarios claros para explicar cada parte del programa.

#include <stdio.h>   // Librería para funciones de entrada y salida (printf, scanf)
#include <stdlib.h>  // Librería para funciones de conversión y manejo de memoria (atoi, malloc, free)

/*
---------------------------------------------------------
Programa: Ordenamiento por Inserción
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando el algoritmo de ordenamiento por
inserción.

Entrada:
- Un argumento desde la línea de comandos (n), que
  indica la cantidad de números a leer.
- n números enteros ingresados por la entrada estándar.

Salida:
- El arreglo ordenado de menor a mayor.

Compilación:
gcc insercion.c -o insercion.exe

Ejecución:
insercion.exe n < archivoNumeros.txt
---------------------------------------------------------
*/


/*
Función: insercion
Entrada:
    int *A  -> arreglo de números enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena los elementos del arreglo utilizando
    el algoritmo de ordenamiento por inserción.
*/
void insercion(int *A, int n) {

    int i;

    // Recorre el arreglo comenzando desde el segundo elemento
    for (i = 1; i < n; i++) {

        int clave = A[i];   // Elemento que se desea insertar en la posición correcta
        int j = i - 1;      // Índice del elemento anterior

        // Desplaza los elementos mayores que la clave hacia la derecha
        while (j >= 0 && A[j] > clave) {
            A[j + 1] = A[j];
            j--;
        }

        // Inserta el elemento en la posición correcta
        A[j + 1] = clave;
    }
}


/*
Función principal del programa
*/
int main(int argc, char *argv[]) {

    // Verifica que el usuario haya ingresado el argumento n
    if (argc != 2) {
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    // Convierte el argumento recibido a entero
    int n = atoi(argv[1]);

    // Reserva memoria dinámica para almacenar n enteros
    int *A = malloc(n * sizeof(int));

    int i;

    // Lee los n números desde la entrada estándar
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Llama a la función de ordenamiento por inserción
    insercion(A, n);

    // Imprime el arreglo ya ordenado
    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < n; j++)
    {
        printf("[%d]", A[j]);
    }

    // Libera la memoria reservada dinámicamente
    free(A);

    printf("\n");

    return 0;
}
✅ Este programa hace 3 cosas principales:

Lee n números desde un archivo o teclado.

Los ordena usando Inserción.

Imprime el arreglo ordenado.

Si quieres, también puedo darte una versión de documentación más corta (la que suelen pedir los profes) para que todos tus códigos de ordenamientos queden iguales y tu práctica se vea más profesional.


#include <stdio.h>
#include <stdlib.h>

/* ShellSort */
void shellsort(int *A, int n) {
    int gap = n / 2;

    while (gap >= 1) {
        int cambios;

        do {
            cambios = 0;
            int i;

            for (i = gap; i < n; i++) {
                if (A[i-gap] > A[i]) {
                    int temp = A[i];
                    A[i] = A[i-gap];
                    A[i-gap] = temp;
                    cambios++;
                }
            }

        } while (cambios != 0);

        gap = gap / 2;
    }
}

/* Verificar si est� ordenado */
int esta_ordenado(int *A, int n){
	int i;
    for(i = 1; i < n; i++)
        if(A[i-1] > A[i])
            return 0;
    return 1;
}

int main(int argc, char *argv[]) {

    if(argc != 2){
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *A = malloc(n*sizeof(int));

    int i;

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    shellsort(A,n);

    printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	free(A);
	printf("\n");



    return 0;
}

Aquí tienes tu código documentado con comentarios claros para explicar cada parte del programa.

#include <stdio.h>   // Librería para funciones de entrada y salida (printf, scanf)
#include <stdlib.h>  // Librería para funciones de conversión y manejo de memoria (atoi, malloc, free)

/*
---------------------------------------------------------
Programa: Ordenamiento ShellSort
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los guarda en un arreglo dinámico y los ordena
utilizando el algoritmo ShellSort.

El algoritmo ShellSort es una mejora del ordenamiento por
inserción, ya que compara elementos separados por una
distancia llamada "gap", reduciendo gradualmente esa
distancia hasta llegar a 1.

Entrada:
- Un argumento desde la línea de comandos (n), que indica
  la cantidad de números a leer.
- n números enteros desde la entrada estándar.

Salida:
- El arreglo ordenado de menor a mayor.

Compilación:
gcc shellsort.c -o shellsort.exe

Ejecución:
shellsort.exe n < archivoNumeros.txt
---------------------------------------------------------
*/


/*
Función: shellsort
Entrada:
    int *A  -> arreglo de números enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena los elementos del arreglo utilizando el
    algoritmo ShellSort. Se comienza comparando
    elementos separados por un gap grande y se
    reduce progresivamente hasta llegar a 1.
*/
void shellsort(int *A, int n) {

    int gap = n / 2;  // Distancia inicial entre elementos a comparar

    // Mientras el gap sea mayor o igual a 1
    while (gap >= 1) {

        int cambios;  // Variable para verificar si hubo intercambios

        do {
            cambios = 0;
            int i;

            // Recorre el arreglo comparando elementos separados por gap
            for (i = gap; i < n; i++) {

                // Si el elemento anterior es mayor, se intercambian
                if (A[i-gap] > A[i]) {

                    int temp = A[i];
                    A[i] = A[i-gap];
                    A[i-gap] = temp;

                    cambios++; // Se registra que hubo un cambio
                }
            }

        } while (cambios != 0);  // Se repite mientras existan cambios

        // Se reduce el gap a la mitad
        gap = gap / 2;
    }
}


/*
Función: esta_ordenado
Entrada:
    int *A  -> arreglo de números enteros
    int n   -> tamaño del arreglo
Salida:
    1 si el arreglo está ordenado
    0 si no está ordenado

Descripción:
    Verifica si el arreglo está ordenado de forma ascendente.
*/
int esta_ordenado(int *A, int n){
    
    int i;

    // Recorre el arreglo comparando cada elemento con el anterior
    for(i = 1; i < n; i++)
        if(A[i-1] > A[i])
            return 0;  // Si encuentra un elemento mayor antes que otro, no está ordenado

    return 1;  // Si no encuentra errores, el arreglo está ordenado
}


/*
Función principal del programa
*/
int main(int argc, char *argv[]) {

    // Verifica que el usuario haya ingresado el número correcto de argumentos
    if(argc != 2){
        printf("Uso: %s n\n", argv[0]);
        return 1;
    }

    // Convierte el argumento recibido a entero
    int n = atoi(argv[1]);

    // Reserva memoria dinámica para el arreglo
    int *A = malloc(n*sizeof(int));

    int i;

    // Lee los n números desde la entrada estándar
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    // Llama al algoritmo de ordenamiento ShellSort
    shellsort(A,n);

    // Imprime el arreglo ordenado
    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < n; j++)
    {
        printf("[%d]", A[j]);
    }

    // Libera la memoria reservada
    free(A);

    printf("\n");

    return 0;
}
✅ Este programa hace lo siguiente:

Lee n números desde la entrada estándar.

Los ordena usando ShellSort.

Imprime el arreglo ordenado.

Incluye una función para verificar si el arreglo está ordenado.

💡 Si quieres, también puedo ayudarte a documentar todos tus algoritmos de ordenamiento con el mismo formato (Inserción, Shell, Heap, Quick, Merge) para que tu práctica se vea uniforme y más profesional.


al poner close pull request, se cancela los cambios que hice?

No necesariamente. Cerrar (Close) un Pull Request no borra ni cancela los cambios que hiciste. 👍

Cuando haces Close Pull Request en GitHub ocurre esto:

🔹 Qué pasa al cerrar un Pull Request
❌ No se fusionan (merge) los cambios con la rama principal.

✅ Los commits que hiciste siguen existiendo en tu rama.

✅ Puedes volver a abrir el Pull Request después si quieres.

🔹 Ejemplo
Supongamos que:

Rama principal: main

Tu rama: feature-ordenamiento

Si haces un Pull Request de feature-ordenamiento → main y luego presionas Close Pull Request:

Tu código sigue en feature-ordenamiento.

Simplemente no se agregó a main.

🔹 Qué pasaría si quisieras eliminar los cambios
Para eliminarlos tendrías que:

borrar la rama (delete branch), o

revertir los commits.

🔹 Algo importante
Si cerraste el PR por error, puedes:

entrar al PR

presionar Reopen pull request

✅ y todo vuelve a la normalidad.

💡 Si quieres, también puedo explicarte cuándo usar Close, Merge y Delete branch, porque muchos estudiantes se confunden con eso cuando empiezan a usar GitHub para tareas o proyectos.


#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"

/*
HEAP COMO ARRAY:
***************************************************               *****************************
* ELEMENT_0 * ELEMENT_1 * ELEMENT_2 * ELEMENT_1,3 *   .   .   .   *         ELEMENT_N-1       *
*           *           *           *   Son of 1  *               *       Son of (i-2)/2      *
***************************************************               *****************************
            \                       /\
             \_____________________/  \_____________________/
                    Depth 1                   Depth 2
                    
HEAP COMO ÁRBOL
            *************
            * ELEMENT_0 *
            *************
          _____|___________        ========
         |                  |               \
    *************      *************        I
    * ELEMENT_1 *      * ELEMENT_2 *        I Depth 1
    *************     *************         I
      ___|_____             |               /
     |      . . .        . . .     =========
*************                       
* ELEMENT_3 *
*  Son of 1 *
*************
            .       .       .
        /
*******************                       
* ELEMENT_N-1     *
*  Son of (i-2)/2 *
*******************


*/

void Initialize_Heap(Heap *h, int capacity)
{
    h->data = malloc(sizeof(element) * capacity);
    if (h->data == NULL)
    {
        printf("ERROR: Initialize_Heap(&h, capacity)\nNo se pudo reservar memoria\n");
        exit(EXIT_FAILURE);
    }
    h->size = 0;
    h->capacity = capacity;
}

void Insert_Heap(Heap *h, element e)
{
    int Father_i;
    int LastNode_i = h->size;
    element aux;
    if (h->size == h->capacity)
    {
        printf("ERROR: Insert_Heap(&h, element)\nHeap lleno\n");
        exit(EXIT_FAILURE);
    }

    h->data[LastNode_i] = e;
    h->size++;
    while (LastNode_i > 0)
    {
        Father_i = (LastNode_i - 1) / 2;
        if (h->data[LastNode_i].number < h->data[Father_i].number)
        {
            aux = h->data[Father_i];
            h->data[Father_i] = h->data[LastNode_i];
            h->data[LastNode_i] = aux;
            LastNode_i = Father_i;
        }
        else
        {
            break;
        }
    }
}

element Remove_Heap(Heap *h)
{
    if (h == NULL || h->size == 0)
    {
        printf("ERROR: Remove_Heap(&h)\nHeap vacío o inexistente\n");
        exit(EXIT_FAILURE);
    }

    int Node = 0;
    int SmallNode_i = 0;
    int LeftSon_i = (2 * Node) + 1;
    int RightSon_i = (2 * Node) + 2;
    int LastNode_i = (h->size) - 1;
    element aux;
    element ret = h->data[0];
    h->data[0] = h->data[LastNode_i];
    h->size--;
    while (LeftSon_i < h->size)
    {
        LeftSon_i = (2 * Node) + 1;
        SmallNode_i = LeftSon_i;
        RightSon_i = (2 * Node) + 2;
        if (RightSon_i < h->size && h->data[RightSon_i].number < h->data[LeftSon_i].number)
        {
            SmallNode_i = RightSon_i;
        }
        if (h->data[Node].number > h->data[SmallNode_i].number)
        {
            aux = h->data[Node];
            h->data[Node] = h->data[SmallNode_i];
            h->data[SmallNode_i] = aux;
            Node = SmallNode_i;
        }
        else
        {
            break;
        }
        LeftSon_i = (2 * Node) + 1;
    }
    return ret;
}

void Destroy_Heap(Heap *h)
{
    free(h->data);
    h->data = NULL;
    h->size = 0;
    h->capacity = 0;
}

Aquí tienes tu código del Heap completamente documentado y listo para entrega 👇

#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"

/*
---------------------------------------------------------
Programa: Implementación de Heap (Min-Heap)
Descripción:
Este código implementa una estructura de datos tipo Heap
(Min-Heap) utilizando un arreglo dinámico.

Un Min-Heap es un árbol binario completo donde el valor
de cada nodo es menor o igual que el de sus hijos.

Se incluyen las operaciones:
- Inicializar el Heap
- Insertar elementos
- Eliminar el elemento mínimo
- Liberar memoria

Representación:
El Heap se almacena en un arreglo:
- Padre: (i - 1) / 2
- Hijo izquierdo: (2 * i) + 1
- Hijo derecho: (2 * i) + 2
---------------------------------------------------------
*/


/*
---------------------------------------------------------
Función: Initialize_Heap
Entrada:
    Heap *h      -> estructura heap
    int capacity -> capacidad máxima del heap
Descripción:
    Reserva memoria para el heap e inicializa sus valores.
---------------------------------------------------------
*/
void Initialize_Heap(Heap *h, int capacity)
{
    h->data = malloc(sizeof(element) * capacity);

    // Verifica que la memoria se haya reservado correctamente
    if (h->data == NULL)
    {
        printf("ERROR: Initialize_Heap(&h, capacity)\nNo se pudo reservar memoria\n");
        exit(EXIT_FAILURE);
    }

    h->size = 0;         // Inicialmente no hay elementos
    h->capacity = capacity; // Capacidad máxima del heap
}


/*
---------------------------------------------------------
Función: Insert_Heap
Entrada:
    Heap *h  -> heap donde se insertará el elemento
    element e -> elemento a insertar
Descripción:
    Inserta un elemento en el heap manteniendo la
    propiedad de Min-Heap (heapify hacia arriba).
---------------------------------------------------------
*/
void Insert_Heap(Heap *h, element e)
{
    int Father_i;
    int LastNode_i = h->size; // Índice donde se insertará el nuevo elemento
    element aux;

    // Verifica si el heap está lleno
    if (h->size == h->capacity)
    {
        printf("ERROR: Insert_Heap(&h, element)\nHeap lleno\n");
        exit(EXIT_FAILURE);
    }

    // Inserta el elemento al final del arreglo
    h->data[LastNode_i] = e;
    h->size++;

    // Reacomoda el heap (subiendo el elemento)
    while (LastNode_i > 0)
    {
        Father_i = (LastNode_i - 1) / 2;

        // Si el hijo es menor que el padre, se intercambian
        if (h->data[LastNode_i].number < h->data[Father_i].number)
        {
            aux = h->data[Father_i];
            h->data[Father_i] = h->data[LastNode_i];
            h->data[LastNode_i] = aux;

            LastNode_i = Father_i; // Subir en el árbol
        }
        else
        {
            break; // Ya cumple la propiedad de heap
        }
    }
}


/*
---------------------------------------------------------
Función: Remove_Heap
Entrada:
    Heap *h -> heap del cual se eliminará el elemento
Salida:
    element -> elemento mínimo (raíz del heap)
Descripción:
    Elimina el elemento raíz (mínimo) y reorganiza
    el heap (heapify hacia abajo).
---------------------------------------------------------
*/
element Remove_Heap(Heap *h)
{
    // Verifica que el heap exista y no esté vacío
    if (h == NULL || h->size == 0)
    {
        printf("ERROR: Remove_Heap(&h)\nHeap vacío o inexistente\n");
        exit(EXIT_FAILURE);
    }

    int Node = 0;               // Nodo actual (inicia en la raíz)
    int SmallNode_i = 0;        // Índice del hijo más pequeño
    int LeftSon_i = (2 * Node) + 1;
    int RightSon_i = (2 * Node) + 2;
    int LastNode_i = (h->size) - 1;

    element aux;

    // Guarda el elemento mínimo (raíz)
    element ret = h->data[0];

    // Sustituye la raíz con el último elemento
    h->data[0] = h->data[LastNode_i];
    h->size--;

    // Reorganiza el heap (bajando el elemento)
    while (LeftSon_i < h->size)
    {
        LeftSon_i = (2 * Node) + 1;
        SmallNode_i = LeftSon_i;
        RightSon_i = (2 * Node) + 2;

        // Determina cuál hijo es menor
        if (RightSon_i < h->size &&
            h->data[RightSon_i].number < h->data[LeftSon_i].number)
        {
            SmallNode_i = RightSon_i;
        }

        // Si el nodo es mayor que su hijo menor, se intercambian
        if (h->data[Node].number > h->data[SmallNode_i].number)
        {
            aux = h->data[Node];
            h->data[Node] = h->data[SmallNode_i];
            h->data[SmallNode_i] = aux;

            Node = SmallNode_i; // Baja en el árbol
        }
        else
        {
            break; // Ya cumple la propiedad de heap
        }

        LeftSon_i = (2 * Node) + 1;
    }

    return ret; // Devuelve el elemento eliminado
}


/*
---------------------------------------------------------
Función: Destroy_Heap
Entrada:
    Heap *h -> heap a liberar
Descripción:
    Libera la memoria utilizada por el heap y reinicia
    sus valores.
---------------------------------------------------------
*/
void Destroy_Heap(Heap *h)
{
    free(h->data);   // Libera memoria del arreglo
    h->data = NULL;  // Evita punteros colgantes
    h->size = 0;     // Reinicia tamaño
    h->capacity = 0; // Reinicia capacidad
}
✅ Resumen rápido (para que lo pongas en tu práctica)
Este código implementa un Min-Heap usando arreglos.

Permite:

Insertar elementos (O(log n))

Eliminar el mínimo (O(log n))

Se basa en relaciones de índices:

Padre → (i - 1) / 2

Hijos → 2i + 1, 2i + 2

Si quieres, el siguiente paso que te conviene mucho es que te haga:

👉 HeapSort usando este Heap (seguro te lo van a pedir o ya lo tienes 👀)


#include <stdio.h>
#include <stdlib.h>

/*
HEAP COMO ARRAY:
***************************************************               *****************************
* ELEMENT_0 * ELEMENT_1 * ELEMENT_2 * ELEMENT_1,3 *   .   .   .   *         ELEMENT_N-1       *
*           *           *           *   Son of 1  *               *       Son of (i-2)/2      *
***************************************************               *****************************
            \                       /\
             \_____________________/  \_____________________/
                    Depth 1                   Depth 2
                    
HEAP COMO ÁRBOL
            *************
            * ELEMENT_0 *
            *************
          ______|___________        ========
         |                  |               \
    *************      *************        I
    * ELEMENT_1 *      * ELEMENT_2 *        I Depth 1
    *************     *************         I
      ___|_____             |               /
     |      . . .        . . .     =========
*************                       
* ELEMENT_3 *
*  Son of 1 *
*************
            .       .       .
        /
*******************                       
* ELEMENT_N-1     *
*  Son of (i-2)/2 *
*******************


*/

typedef struct element
{
    int number;
} element;

typedef struct Heap
{
    element *data; // apuntador para arreglo dinámico de elementos
    int size;
    int capacity;
} Heap;

void Initialize_Heap(Heap *h, int capacity);

void Insert_Heap(Heap *h, element e);

element Remove_Heap(Heap *h);

void Destroy_Heap(Heap *h);

Aquí tienes tu archivo tipo header (SortHeap.h) completamente documentado 👇

#include <stdio.h>
#include <stdlib.h>

/*
---------------------------------------------------------
Archivo: SortHeap.h
Descripción:
Este archivo define las estructuras y prototipos de
funciones para implementar un Heap (Min-Heap) en C.

Un Heap es una estructura de datos basada en un árbol
binario completo que se puede representar mediante un
arreglo.

En este caso se implementa un Min-Heap:
- El valor del padre siempre es menor o igual al de sus hijos.

Relaciones importantes en el arreglo:
- Padre: (i - 1) / 2
- Hijo izquierdo: (2 * i) + 1
- Hijo derecho: (2 * i) + 2
---------------------------------------------------------
*/


/*
---------------------------------------------------------
Estructura: element
Descripción:
Representa un elemento del heap.
Puede ampliarse para incluir más atributos si se desea.
---------------------------------------------------------
*/
typedef struct element
{
    int number; // Valor del elemento
} element;


/*
---------------------------------------------------------
Estructura: Heap
Descripción:
Representa el Heap como una estructura con:
- Un arreglo dinámico de elementos
- El tamaño actual
- La capacidad máxima
---------------------------------------------------------
*/
typedef struct Heap
{
    element *data; // Apuntador al arreglo dinámico
    int size;      // Número actual de elementos en el heap
    int capacity;  // Capacidad máxima del heap
} Heap;


/*
---------------------------------------------------------
Función: Initialize_Heap
Entrada:
    Heap *h      -> heap a inicializar
    int capacity -> capacidad máxima del heap
Descripción:
    Inicializa el heap reservando memoria dinámica
    para almacenar los elementos.
---------------------------------------------------------
*/
void Initialize_Heap(Heap *h, int capacity);


/*
---------------------------------------------------------
Función: Insert_Heap
Entrada:
    Heap *h  -> heap donde se insertará el elemento
    element e -> elemento a insertar
Descripción:
    Inserta un elemento en el heap manteniendo
    la propiedad de Min-Heap.
---------------------------------------------------------
*/
void Insert_Heap(Heap *h, element e);


/*
---------------------------------------------------------
Función: Remove_Heap
Entrada:
    Heap *h -> heap del cual se eliminará el elemento
Salida:
    element -> elemento mínimo del heap
Descripción:
    Elimina y retorna el elemento raíz (mínimo)
    del heap, reordenando la estructura.
---------------------------------------------------------
*/
element Remove_Heap(Heap *h);


/*
---------------------------------------------------------
Función: Destroy_Heap
Entrada:
    Heap *h -> heap a destruir
Descripción:
    Libera la memoria dinámica utilizada por el heap.
---------------------------------------------------------
*/
void Destroy_Heap(Heap *h);
✅ Qué es este archivo (importante para tu práctica)
Este archivo es un .h (header) y sirve para:

Definir las estructuras (struct)

Declarar las funciones (prototipos)

Permitir que otros archivos .c usen el heap

💡 Cómo se conecta con tu otro código
SortHeap.h → definiciones

SortHeap.c → implementación (el que ya documentamos antes)

Heap_TEST.c → programa principal

Si quieres, puedo ayudarte a dejar todo el proyecto listo así:

SortHeap.h
SortHeap.c
Heap_TEST.c
Heap_TIME.c
con compilación tipo práctica (como te la piden en el IPN) 🚀


#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"
int main(int argc, char *argv[])
{
    int i;
    int n = atoi(argv[1]);
    int *A = malloc(sizeof(int) * n);
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    Heap H;
    Initialize_Heap(&H, n);
    element e;
    for (i = 0; i < n; i++)
    {
        e.number = A[i];
        Insert_Heap(&H, e);
    }
    for (i = 0; i < n; i++)
    {
        A[i] = Remove_Heap(&H).number;
    }
    Destroy_Heap(&H);

    for (i = 0; i < n; i++)
    {
        printf("[%d]", A[i]);
    }
	printf("\n");	
	free(A);
}

Aquí tienes tu programa principal de HeapSort documentado 👇

#include <stdio.h>   // Entrada y salida estándar
#include <stdlib.h>  // Funciones de memoria y conversión
#include "SortHeap.h" // Definiciones del Heap

/*
---------------------------------------------------------
Programa: HeapSort utilizando Min-Heap
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando la estructura Heap (Min-Heap).

El proceso consiste en:
1. Insertar todos los elementos en un heap.
2. Extraerlos en orden (del menor al mayor).
3. Guardarlos nuevamente en el arreglo.

Entrada:
- Un argumento desde línea de comandos (n)
- n números enteros desde la entrada estándar

Salida:
- Arreglo ordenado de menor a mayor

Compilación:
gcc SortHeap.c Heap_TEST.c -o HEAP_TEST.exe

Ejecución:
HEAP_TEST.exe n < archivoNumeros.txt
---------------------------------------------------------
*/


int main(int argc, char *argv[])
{
    int i;

    // Convierte el argumento recibido (n) a entero
    int n = atoi(argv[1]);

    // Reserva memoria dinámica para el arreglo
    int *A = malloc(sizeof(int) * n);

    // Verifica que la memoria se haya reservado correctamente
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    // Lee los n elementos desde la entrada estándar
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // Declara un Heap
    Heap H;

    // Inicializa el heap con capacidad n
    Initialize_Heap(&H, n);

    element e;

    // Inserta todos los elementos del arreglo en el heap
    for (i = 0; i < n; i++)
    {
        e.number = A[i];
        Insert_Heap(&H, e);
    }

    // Extrae los elementos del heap en orden y los guarda en el arreglo
    for (i = 0; i < n; i++)
    {
        A[i] = Remove_Heap(&H).number;
    }

    // Libera la memoria del heap
    Destroy_Heap(&H);

    // Imprime el arreglo ordenado
    for (i = 0; i < n; i++)
    {
        printf("[%d]", A[i]);
    }

    printf("\n");

    // Libera la memoria del arreglo
    free(A);
}
✅ ¿Qué hace este programa? (resumen corto)
Lee n números

Los mete a un Min-Heap

Va sacando el mínimo uno por uno

Los guarda en orden en el arreglo

👉 Eso es básicamente HeapSort

⚠️ Detalle importante (te puede dar puntos extra)
Tu implementación es:

✔️ Correcta

✔️ Usa Heap

❗ Pero es HeapSort con estructura auxiliar (usa memoria extra)

📌 Complejidad:

Tiempo: O(n log n)

Espacio: O(n) (porque usas heap adicional)

Si quieres subir de nivel tu práctica 🔥
puedo ayudarte a hacer:

👉 HeapSort en el mismo arreglo (in-place)
(el que les encanta a los profes porque es más óptimo 😎)


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

Aquí tienes tu código de Selection Sort completamente documentado 👇

#include <stdio.h>   // Librería de entrada y salida (printf, scanf)
#include <stdlib.h>  // Librería para malloc y atoi

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

Entrada:
- Un argumento (n) desde la línea de comandos
- n números enteros desde la entrada estándar

Salida:
- Arreglo ordenado de menor a mayor

Compilación:
gcc selection.c -o selection.exe

Ejecución:
selection.exe n < archivoNumeros.txt
---------------------------------------------------------
*/


/*
---------------------------------------------------------
Función: selection
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena el arreglo utilizando el algoritmo de
    selección (Selection Sort).
---------------------------------------------------------
*/
void selection (int A[], int n){
    
    int k, p, i, temp;

    // Recorre el arreglo
    for (k = 0; k <= n - 2; k++) {

        p = k; // Se asume que el mínimo está en la posición k

        // Busca el elemento más pequeño en el resto del arreglo
        for (i = k + 1; i <= n - 1; i++) {
            if (A[i] < A[p]) {
                p = i; // Actualiza la posición del mínimo
            }
        }

        // Intercambia el elemento mínimo con la posición actual
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
}


/*
---------------------------------------------------------
Función principal
---------------------------------------------------------
*/
int main(int argc, char const *argv[]){
    
    // Convierte el argumento recibido a entero
    int n = atoi(argv[1]);

    int *A;

    // Reserva memoria dinámica para n enteros
    A = malloc(n * sizeof(int));

    // Verifica que la memoria se haya asignado correctamente
    if (A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);        
        exit(1);
    }    

    // Lee los n números desde la entrada estándar
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    // Llama al algoritmo de ordenamiento
    selection(A, n);
    
    // Imprime el arreglo ordenado
    printf("Arreglo ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    // Libera la memoria
    free(A);

    printf("\n");

    return 0;
}
✅ Resumen rápido
Algoritmo: Selection Sort

Idea: Buscar el mínimo y colocarlo en su posición

Complejidad:

Tiempo: O(n²)

Espacio: O(1) (no usa memoria extra)

💡 Tip para tu práctica (esto les gusta a los profes):

👉 A diferencia de Inserción:

Selection hace menos intercambios

Inserción es más eficiente si el arreglo ya está medio ordenado

Si quieres, te puedo hacer una tabla comparativa de todos tus algoritmos (Inserción, Shell, Heap, Selection) para que saques puntos extra en conclusiones 😎


no cambies el codigo, documentalo como te lo di

Perfecto 👍 aquí tienes tu mismo código SIN modificar, solo con documentación agregada:

#include <stdio.h>   // Librería para entrada y salida (printf, scanf)
#include <stdlib.h>  // Librería para malloc, free y atoi

/*
---------------------------------------------------------
Programa: Ordenamiento por Selección (Selection Sort)
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en memoria dinámica y los ordena
utilizando el algoritmo de selección.

El algoritmo busca el elemento más pequeño del arreglo
y lo coloca en la posición correcta en cada iteración.
---------------------------------------------------------
*/

void selection (int A[], int n); // Prototipo de la función


int main(int argc, char const *argv[]){
    
    // Convierte el argumento de entrada (n) a entero
    int n = atoi(argv[1]);

    int *A;

    // Apartar memoria para n números enteros
	A = malloc(n * sizeof(int));

	// Verifica si la memoria se reservó correctamente
	if(A == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n", n);		
		exit(1);
	}	

    // Lectura de los n elementos desde la entrada estándar
    for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	// Llamar al algoritmo de ordenamiento por selección
	selection(A, n);
	
	// Imprime el arreglo ya ordenado
    printf("Arreglo ordenado\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    // Libera la memoria dinámica
    free(A);

    printf("\n");

    return 0;
}


/*
---------------------------------------------------------
Función: selection
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
    
    int k, p, i, temp;

    // Recorre el arreglo hasta el penúltimo elemento
    for( k = 0 ; k <= n - 2 ; k++){

        p = k; // Se asume que el mínimo está en la posición k

        // Busca el elemento más pequeño en el resto del arreglo
        for( i = k + 1 ; i <= n - 1 ; i++){
            if(A[i] < A[p]){
                p = i; // Actualiza la posición del mínimo
            }
        }

        // Intercambia el elemento mínimo con la posición k
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
}
✅ Así está como te lo piden normalmente:

No cambié tu código

Solo agregué comentarios claros

Mantiene tu estilo original

Si quieres, puedo documentarte los demás exactamente con este mismo formato para que toda tu práctica quede uniforme.


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

Perfecto 👍 aquí tienes tu mismo código documentado sin modificar nada de la lógica:

#include <stdio.h>   // Librería para entrada y salida (printf, scanf)
#include <stdlib.h>  // Librería para malloc, free y atoi

/*
---------------------------------------------------------
Programa: Ordenamiento Burbuja (Bubble Sort)
Descripción:
Este programa lee n números enteros desde la entrada
estándar, los almacena en un arreglo dinámico y los
ordena utilizando el algoritmo de la burbuja.

El algoritmo compara elementos adyacentes e intercambia
sus posiciones si están en el orden incorrecto.
Este proceso se repite hasta que el arreglo queda ordenado.
---------------------------------------------------------
*/

void bubble (int A[],int n); // Prototipo de la función


int main(int argc, char const *argv[]){
    
    // Convierte el argumento de entrada (n) a entero
    int n = atoi(argv[1]);

    int *A;

    // Apartar memoria para n números enteros
	A = malloc(n * sizeof(int));

	// Verifica si la memoria se reservó correctamente
	if(A == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n", n);		
		exit(1);
	}	

    // Lectura de los n elementos desde la entrada estándar
    for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	// Llamar al algoritmo de ordenamiento burbuja
	bubble(A, n);
	
	// Imprime el arreglo ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}


/*
---------------------------------------------------------
Entrada:
    int A[] -> arreglo de enteros
    int n   -> tamaño del arreglo
Descripción:
    Ordena el arreglo utilizando el algoritmo de
    la burbuja (Bubble Sort).

    En cada iteración:
    - Compara elementos adyacentes
    - Los intercambia si están en orden incorrecto
    - Repite el proceso hasta ordenar completamente
---------------------------------------------------------
*/
void bubble (int A[],int n){
    int i,j,aux;
	// Recorre el arreglo múltiples veces
    for(i=0;i<=n-2;i++){
	    // Compara elementos adyacentes
        for(j=0;j<=n-2;j++){
			// Si están en orden incorrecto, se intercambian
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
