/*TAD Arbol Binario de Búsqueda ABB, dirigido a ordenar un arreglode números.
Autor: Saul Ascencion Cruz
Fecha: 25 de Febrero del 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"
/*
---------------------------------------------------------
Descripción:
Este archivo implementa un Árbol Binario de Búsqueda (ABB).

Un ABB cumple:
- Los valores menores van al subárbol izquierdo
- Los valores mayores van al subárbol derecho

Se utiliza principalmente para ordenar elementos mediante
un recorrido InOrden.
---------------------------------------------------------
*/

/*Reserva el espacio necesario para crear el ABB*/
void Inicializar(arbolBinario *a)
{
  *a = NULL;
}

/*
---------------------------------------------------------
Entrada:
    arbolBinario *a -> árbol a liberar
Descripción:
    Libera la memoria de todos los nodos del árbol
    utilizando un recorrido recursivo (postorden).
---------------------------------------------------------
*/
void Destruir(arbolBinario *a)
{
  if (*a != NULL)
  {
   // Libera subárbol izquierdo
    if ((*a)->hijoIzq != NULL)
    {
      Destruir(&(*a)->hijoIzq);
    }
    // Libera subárbol derecho
    if ((*a)->hijoDer != NULL)
    {
      Destruir(&(*a)->hijoDer);
    }
   // Libera el nodo actual
    free(*a);
    *a = NULL;
  }
}

/*Regresa el nodo raíz del subárbol*/
posicion Raiz(arbolBinario *a)
{
  return *a;
}
/*
---------------------------------------------------------
Entrada:
    arbolBinario *a -> árbol
    posicion p      -> nodo actual
Salida:
    posicion -> hijo derecho del nodo
Descripción:
    Regresa el hijo derecho del nodo dado.
---------------------------------------------------------
*/
posicion HijoDerecho(arbolBinario *a, posicion p)
{
  nodo *ret;
  if (p != NULL)
  {
    ret = p->hijoDer;
  }
  else
  {
    ret = NULL;
  }

  return ret;
}

/*Regresa el hijo izquierdo del nodo actual*/
posicion HijoIzquierdo(arbolBinario *a, posicion p)
{
  nodo *ret;
  if (p != NULL)
  {
    ret = p->hijoIzq;
  }
  else
  {
    ret = NULL;
  }

  return ret;
}

/*Verifica si un nodo está vacío. Si el nodo está vacío regresa FALSE, por el contrario si el nodo NO
está vacío regresa TRUE*/
boolean Vacio(arbolBinario *a)
{
  return ((*a) == NULL);
}

/*Regresa el elemento del nodo dado*/
elemento LeerNodo(arbolBinario *a, posicion p)
{
  return p->valor;
}

/*
---------------------------------------------------------
Descripción:
    Inserta un elemento en el árbol respetando las
    propiedades del Árbol Binario de Búsqueda (ABB).

    - Menores a la izquierda
    - Mayores a la derecha
    - No inserta duplicados
---------------------------------------------------------
*/
void Insert(arbolBinario *a, int number)
{
  posicion *actual = a;
  // Busca la posición adecuada para insertar
  while (*actual != NULL)
  {
    if (number < (*actual)->valor.numero)
    {
      actual = &((*actual)->hijoIzq);
    }
    else if (number > (*actual)->valor.numero)
    {
      actual = &((*actual)->hijoDer);
    }
    else
    {
      return; // No inserta elementos duplicados
    }
  }
 // Reserva memoria para el nuevo nodo
  *actual = malloc(sizeof(nodo));
  if (*actual == NULL)
  {
    printf("No se pudo reservar memoria");
    exit(1);
  }
 // Inicializa el nodo
  (*actual)->hijoIzq = NULL;
  (*actual)->hijoDer = NULL;
  (*actual)->valor.numero = number;

  /*if (Vacio(&(*a)))
  {
    *a = malloc(sizeof(nodo));
    if (*a == NULL)
    {
      printf("No se pudo reservar memoria");
      exit(1);
    }
    (*a)->hijoIzq = NULL;
    (*a)->hijoDer = NULL;
    (*a)->valor.numero = number;
  }
  else if (number < (*a)->valor.numero)
  {
    Insert(&((*a)->hijoIzq), number);
    return;
  }
  else if (number > (*a)->valor.numero)
  {
    Insert(&((*a)->hijoDer), number);
    return;
  }*/
}

/*Recorre el ABB y sobreescribe el arreglo dado*/
void InOrden(arbolBinario *a, posicion p, int array[], int *i)
{
  if (p == NULL)
    return;
 // Recorre subárbol izquierdo
  InOrden(a, HijoIzquierdo(a, p), array, i);
 // Guarda el valor del nodo en el arreglo
  array[*(i)] = LeerNodo(a, p).numero;
  (*i)++;
 // Recorre subárbol derecho
  InOrden(a, HijoDerecho(a, p), array, i);
}
