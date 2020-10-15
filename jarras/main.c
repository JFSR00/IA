/*
 * main.c
 *
 *  Created on: 7 oct. 2020
 *      Author: Juan Francisco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jarras.h"

int main(){
	tEstado *j1=crearEstado(jarras_inicial), *j2=crearEstado(jarras_inicial), *final=crearEstado(jarras_final);

	dispEstado(j1);
	printf("\n");
	dispEstado(j2);
	printf("\n");
	dispEstado(final);
	printf("\n");

	printf("\nSon iguales los puzles? %i\n",iguales(j1, j2));
	printf("\nEs el objetivo? %i\n",testObjetivo(j1));
	printf("\nEs el objetivo? %i\n",testObjetivo(final));

	printf("\n%i\n",esValido(LLENAR, 0, j1));
	j1=aplicaOperador(LLENAR, 0, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(PASAR, 0, j1));
	j1=aplicaOperador(PASAR, 0, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(LLENAR, 0, j1));
	if(esValido(LLENAR, 0, j1)){
		j1=aplicaOperador(LLENAR, 0, j1);
		dispEstado(j1);
	}

	printf("\n%i\n",esValido(PASAR, 0, j1));
	if(esValido(PASAR, 0, j1)){
		j1=aplicaOperador(PASAR, 0, j1);
		dispEstado(j1);
	}

	/*printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(j1);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(j1);
	}

	printf("\n%i\n",esValido(IZQUIERDA,ladron));
	if(esValido(IZQUIERDA,ladron)){
		ladron=aplicaOperador(IZQUIERDA,ladron);
		dispEstado(j1);
	}*/

	printf("\nSon iguales los puzles? %i\n",iguales(j1, j2));

	return 0;
}
