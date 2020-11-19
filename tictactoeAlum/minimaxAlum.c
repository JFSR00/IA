/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tictactoe.h"
#include "minimaxAlum.h"



tNodo *PSEUDOminimax(tNodo *t) {
     int mejorJugada = -1;
     int puntos = -2;
     int i, temp;
     tNodo *intento=malloc(sizeof(tNodo));
     printf("\n Mi turno: \n");
     for(i = 0; i < 9; ++i){
      if (esValida(t,i)) {
            intento=aplicaJugada(t,1,i); //Intenta jugada
            temp =terminal(intento); // Calcula el valor minimax
            if(temp > puntos) {
              puntos = temp;
              mejorJugada = i;
            }
      }}//for
      t=aplicaJugada(t,1,mejorJugada);
      return t;
}

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

tNodo *minimax(tNodo *n, int jugador){
	int max, max_actual, jugada, mejorJugada;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	max = -10000;
	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			max_actual = valorMin(intento);
			if(max_actual > max){
				max = max_actual;
				mejorJugada = jugada;
			}
		}
	}

	aux = aplicaJugada(aux, jugador, mejorJugada);
	free(intento);
	return aux;
}

tNodo *minimax2(tNodo *n, int jugador){
	int min, min_actual, jugada, mejorJugada;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	min = 10000;
	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			min_actual = valorMax(intento);
			if(min_actual < min){
				min = min_actual;
				mejorJugada = jugada;
			}
		}
	}

	aux = aplicaJugada(aux, jugador, mejorJugada);
	free(intento);
	return aux;
}

int valorMin(tNodo *n){
	int valor_min, jugada=0, jugador = -1;

	if(terminal(n)){
		valor_min = terminal(n);
	}else if(n->vacias){
		valor_min = 100000;

		for(jugada = 0; jugada < N; jugada++){
			if(esValida(n, jugada)){
				valor_min = MIN(valor_min, valorMax(aplicaJugada(n, jugador, jugada)));
			}
		}
	}else{
		valor_min = 0;
	}

	return valor_min;
}

int valorMax(tNodo *n){
	int valor_max, jugada=0, jugador = 1;

	if(terminal(n)){
		valor_max = terminal(n);
	}else if(n->vacias){
		valor_max = -100000;

		for(jugada = 0; jugada < N; jugada++){
			if(esValida(n, jugada)){
				valor_max = MAX(valor_max, valorMin(aplicaJugada(n, jugador, jugada)));
			}
		}
	}else{
		valor_max = 0;
	}

	return valor_max;
}

