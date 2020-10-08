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

int main(){
	tEstado puzle*=crearEstado(puzle_inicial);

	dispEstado(puzle);

	return 0;
}
