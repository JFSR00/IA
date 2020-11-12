/*
 * main.c
 *
 *  Created on: 7 oct. 2020
 *      Author: Juan Francisco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

void printFila(tEstado* s);
void printCol(tEstado* s);

int main(){
    //solucionFin(busquedaAnch());
    //solucionFin(busquedaProf());
    //solucionFin(busquedaAnchEstRep());
    //solucionFin(busquedaProfEstRep());
    //solucionFin(busquedaAnchLimite(3));
    //solucionFin(busquedaProfLimite(4));
	solucionFin(busquedaHeuristica(MAL_COLOC));
	solucionFin(busquedaHeuristica(A_STAR));
	solucionFin(busquedaHeuristica(MANHATTAN));
	solucionFin(busquedaHeuristica(MAN_A_STAR));
    return 0;
}

void printFila(tEstado* s){
	printf("\nFilas: ");
	for(int i=0; i<N*N; i++){
		printf("%i ",s->fila[i]);
	}
}
void printCol(tEstado* s){
	printf("\nColumnas: ");
	for(int i=0; i<N*N; i++){
		printf("%i ",s->col[i]);
	}
}
