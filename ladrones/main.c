/*
 * main.c
 *
 *  Created on: 7 oct. 2020
 *      Author: Juan Francisco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ladron.h"

void printInfo(tEstado *e);

int main(){
	tEstado *ladron=crearEstado(sacos_inicial), *ladron2=crearEstado(sacos_inicial), *final=crearEstado(sacos_final);

	dispEstado(ladron);
	printInfo(ladron);
	printf("\n");
	dispEstado(ladron2);
	printInfo(ladron2);
	printf("\n");
	dispEstado(final);
	printInfo(final);
	printf("\n");

	printf("\nSon iguales los puzles? %i\n",iguales(ladron, ladron2));
	printf("\nEs el objetivo? %i\n",testObjetivo(ladron));
	printf("\nEs el objetivo? %i\n",testObjetivo(final));

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	ladron=aplicaOperador(IZQUIERDA,ladron);
	dispEstado(ladron);
	printInfo(ladron);

	printf("\n%i\n",esValido(DERECHA,ladron));
	ladron=aplicaOperador(DERECHA,ladron);
	dispEstado(ladron);
	printInfo(ladron);

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(ladron);
		printInfo(ladron);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(ladron);
		printInfo(ladron);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(ladron);
		printInfo(ladron);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(ladron);
		printInfo(ladron);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(ladron);
		printInfo(ladron);
	}

	printf("\nSon iguales los puzles? %i\n",iguales(ladron, ladron2));

	return 0;
}

void printInfo(tEstado *e){
	printf("Ladron: %i\nRobot: %i\nIZQ: %i\nDCH: %i\n",e->ladron,e->robot,e->izq,e->dch);
}
