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

	printf("\n%i\n",esValido(LLENAR4, j1));
	j1=aplicaOperador(LLENAR4, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(LLENAR3CON4, j1));
	j1=aplicaOperador(LLENAR3CON4, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(VACIAR3, j1));
	j1=aplicaOperador(VACIAR3, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(VACIAR4EN3, j1));
	j1=aplicaOperador(VACIAR4EN3, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(LLENAR4, j1));
	j1=aplicaOperador(LLENAR4, j1);
	dispEstado(j1);

	printf("\n%i\n",esValido(LLENAR3CON4, j1));
	j1=aplicaOperador(LLENAR3CON4, j1);
	dispEstado(j1);

	printf("\nSon iguales los puzles? %i\n",iguales(j1, j2));
	printf("\nEs el objetivo? %i\n",testObjetivo(j1));

	return 0;
}
