/*
 * tictactoe.h
 *
 *  Created on: 18 nov. 2020
 *      Author: JFSR00
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#define N 9

typedef struct{
	int celdas[N];	// Cada posici�n de las celdas est� asociada con una posici�n de un tablero 3x3 (para N = 9)
	int vacias;		// Contador de posiciones vac�as
} tNodo;

typedef struct{
	int pos;		// Posici�n del tablero de 0 a 8 en caso de N = 9
}tJugada;

tNodo* crearNodo(int celdas[N]);
tNodo* aplicaJugada(tNodo *actual, int jugador, int jugada);
int esValida(tNodo *actual, int jugada);
int terminal(tNodo *nodo);
//void disp

#endif /* TICTACTOE_H_ */
