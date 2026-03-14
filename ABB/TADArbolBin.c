/*TAD Arbol Binario de Búsqueda ABB, dirigido a ordenar un arreglode números.
Autor: Saul Ascencion Cruz
Fecha: 25 de Febrero del 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"

/*Reserva el espacio necesario para crear el ABB*/
void Inicializar(arbolBinario *a)
{
  *a = NULL;
}

/*Libera la memoria necesaria para crear el ABB*/
void Destruir(arbolBinario *a)
{
  if (*a != NULL)
  {
    if ((*a)->hijoIzq != NULL)
    {
      Destruir(&(*a)->hijoIzq);
    }
    if ((*a)->hijoDer != NULL)
    {
      Destruir(&(*a)->hijoDer);
    }
    free(*a);
    *a = NULL;
  }
}

/*Regresa el nodo raíz del subárbol*/
posicion Raiz(arbolBinario *a)
{
  return *a;
}

/*Regresa el hijo derecho del nodo actual*/
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

/*Inserta un elemento en un árbol siguiendo las reglas del ABB*/
void Insert(arbolBinario *a, int number)
{
  posicion *actual = a;
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
      return;
    }
  }
  *actual = malloc(sizeof(nodo));
  if (*actual == NULL)
  {
    printf("No se pudo reservar memoria");
    exit(1);
  }
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

  InOrden(a, HijoIzquierdo(a, p), array, i);
  array[*(i)] = LeerNodo(a, p).numero;
  (*i)++;
  InOrden(a, HijoDerecho(a, p), array, i);
}