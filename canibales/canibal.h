/*
 * canibal.h
 *
 *  Created on: 11 nov. 2020
 *      Author: JFSR00
 */

#ifndef CANIBAL_H_
#define CANIBAL_H_

#define M1_DCH 1
#define M2_DCH 2
#define M1C1_DCH 3
#define C1_DCH 4
#define C2_DCH 5
#define M1_IZQ 6
#define M2_IZQ 7
#define M1C1_IZQ 8
#define C1_IZQ 9
#define C2_IZQ 10
#define NUM_OPERADORES 10
#define N 3

#define IZQ 0
#define DCH 1

#ifndef _tEstado_
#define _tEstado_
	typedef struct {
		int o[5];
	} tEstado;
#endif


static int puzle_inicial[5]=
{N,N,IZQ,0,0};

static int puzle_final[5]=
{0,0,DCH,N,N};


/* A partir de una configuración de fichas construye un estado válido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[5]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();


/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();


/* Comprueba si es posible aplicar un operador a una configuración determinada para el puzle.
  Devuelve 1 si el movimiento es válido y 0 en otro caso. */
int esValido(unsigned op, tEstado* e);

/* Aplica un operador a una configuración concreta del puzle.
  Devuelve la nueva configuración del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);

#endif /* CANIBAL_H_ */
