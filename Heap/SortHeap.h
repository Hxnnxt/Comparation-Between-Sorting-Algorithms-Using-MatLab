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


---------------------------------------------------------
Descripción:
Representa un elemento del heap.
Puede ampliarse para incluir más atributos si se desea.
---------------------------------------------------------
*/
typedef struct element
{
    int number;
} element;
/*
---------------------------------------------------------
Descripción:
Representa el Heap como una estructura con:
- Un arreglo dinámico de elementos
- El tamaño actual
- La capacidad máxima
---------------------------------------------------------
*/
typedef struct Heap
{
    element *data; // apuntador para arreglo dinámico de elementos
    int size;      // Número actual de elementos en el heap
    int capacity;  // Capacidad máxima del heap
} Heap;
/*
---------------------------------------------------------
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
Entrada:
    Heap *h -> heap a destruir
Descripción:
    Libera la memoria dinámica utilizada por el heap.
---------------------------------------------------------
*/
void Destroy_Heap(Heap *h);
