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

void printFila(tEstado* s);
void printCol(tEstado* s);

int main(){
	tEstado *puzle=crearEstado(puzle_inicial), *puzle2=crearEstado(puzle_inicial), *final=crearEstado(puzle_final);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\nSon iguales los puzles? %i\n",iguales(puzle, puzle2));
	printf("\nEs el objetivo? %i\n",testObjetivo(puzle));
	printf("\nEs el objetivo? %i\n",testObjetivo(final));

	printf("\n%i\n",esValido(ARRIBA,puzle));
	puzle=aplicaOperador(ARRIBA,puzle);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\n%i\n",esValido(ARRIBA,puzle));
	puzle=aplicaOperador(ARRIBA,puzle);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\n%i\n",esValido(ARRIBA,puzle));
	if(esValido(ARRIBA,puzle)){
		puzle=aplicaOperador(ARRIBA,puzle);
		dispEstado(puzle);
		printFila(puzle);
		printCol(puzle);
	}

	printf("\nSon iguales los puzles? %i\n",iguales(puzle, puzle2));

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
