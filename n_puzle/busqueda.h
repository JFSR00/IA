/*******************************************/
/* 		    BUSQUEDA.H                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#ifndef BUSQUEDA_H_
#define BUSQUEDA_H_
#include "puzle.h"

#define MAL_COLOC 1
#define A_STAR 2
#define MANHATTAN 3
#define MAN_A_STAR 4

#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif

int busquedaAnch(void);
int busquedaAnchLimite(int l);
int busquedaAnchEstRep(void);

int busquedaProf(void);
int busquedaProfLimite(int l);
int busquedaProfEstRep(void);
void solucionFin(int res);

int heuristica(tEstado* e, tEstado* final);
int camino(tNodo* n);
int busquedaHeuristica(int op);

#endif
