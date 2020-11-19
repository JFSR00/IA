/*
 * tictactoe.c
 *
 *  Created on: 18 nov. 2020
 *      Author: JFSR00
 */


#include "tictactoe.h"

tNodo* crearNodo(int celdas[N]){
	tNodo *nuevo = (tNodo*) malloc(sizeof(tNodo));
	memcpy(nuevo->celdas, celdas, sizeof(int)*N);
	nuevo->vacias = 0;

	for(int i=0; i<N; i++){
		if(nuevo->celdas[i] == 0){
			nuevo->vacias++;
		}
	}

	return nuevo;
}

tNodo* aplicaJugada(tNodo *actual, int jugador, int jugada){
	tNodo *nuevo = (tNodo*) malloc(sizeof(tNodo));
	memcpy(nuevo, actual, sizeof(tNodo));

	if(esValida(actual,jugada)){
		nuevo->celdas[jugada]=jugador;
	}

	return nuevo;
}

int esValida(tNodo *actual, int jugada){
	// La celda está en el rango y no está ocupada
	return (jugada >= 0 && jugada < N && actual->celdas[jugada] == 0);
}

int terminal(tNodo *nodo){
	unsigned opciones[8][3] = {
			{0,1,2},	// Filas
			{3,4,5},
			{6,7,8},

			{0,3,6},	// Columnas
			{1,4,7},
			{2,5,8},

			{0,4,8},	// Diagonales
			{2,4,6}
	};

	int i=0, ganador=0;

	while(ganador == 0 && i<8){
		if(nodo->celdas[opciones[i][0]]!=0 &&
			nodo->celdas[opciones[i][0]]==nodo->celdas[opciones[i][1]] &&
			nodo->celdas[opciones[i][0]]==nodo->celdas[opciones[i][2]]){
			ganador = nodo->celdas[opciones[i][2]];	// Indica qué jugador ocupa las casillas
		}
		i++;
	}

	return ganador*100;	// Incluye el valor de utilidad
}
