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


---------------------------------------------------------
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
    h->size = 0;            // Inicialmente no hay elementos
    h->capacity = capacity; // Capacidad máxima del heap
}
/*
---------------------------------------------------------
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
            LastNode_i = Father_i;  // Subir en el árbol
        }
        else
        {
            break;
        }
    }
}
/*
---------------------------------------------------------
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

    int Node = 0;            // Nodo actual (inicia en la raíz)
    int SmallNode_i = 0;     // Índice del hijo más pequeño
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
        if (RightSon_i < h->size && h->data[RightSon_i].number < h->data[LeftSon_i].number)
        {
            SmallNode_i = RightSon_i;
        }
        // Si el nodo es mayor que su hijo menor, se intercambian        
        if (h->data[Node].number > h->data[SmallNode_i].number)
        {
            aux = h->data[Node];
            h->data[Node] = h->data[SmallNode_i];
            h->data[SmallNode_i] = aux;
            Node = SmallNode_i;  // Baja en el árbol
        }
        else
        {
            break;
        }
        LeftSon_i = (2 * Node) + 1;
    }
    return ret;  // Devuelve el elemento eliminado
}
/*
---------------------------------------------------------
Entrada:
    Heap *h -> heap a liberar
Descripción:
    Libera la memoria utilizada por el heap y reinicia
    sus valores.
---------------------------------------------------------
*/
void Destroy_Heap(Heap *h)
{
    free(h->data);    // Libera memoria del arreglo
    h->data = NULL;   // Evita punteros colgantes
    h->size = 0;      // Reinicia tamaño
    h->capacity = 0;  // Reinicia capacidad
}
