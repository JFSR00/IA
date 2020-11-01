/*******************************************/
/*             LISTAIA.H                   */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PUZLE_H_
#include "puzle.h"
#endif
#ifndef BUSQUEDA_H_
#include "busqueda.h"
#endif

#define VACIA NULL

typedef struct ListaNodos {
    struct ListaNodos *next;
    int nodo[];
    
}ListaNodos;

typedef struct ListaNodos *LISTA;

tEstado* buscarElto(LISTA *c, tEstado *n);

int esVacia( LISTA c);
void InsertarPrimero(LISTA *c, void *n, int size);
//void PopL(LISTA *c, void *n, int size);

void ExtraerPrimero(LISTA c, void *n, int size);
void EliminarPrimero(LISTA *c);

void InsertarUltimo(LISTA *c, void *n, int size);
LISTA Concatenar(LISTA l1,LISTA l2);

LISTA Ordenar(LISTA l);
void InsertarSiguiente(LISTA *c, void *n, int size);

void printLista(LISTA l);


