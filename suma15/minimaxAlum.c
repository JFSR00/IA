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

#include "minimaxAlum.h"
#include "suma15.h"



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

//##############################################################################################################################
tNodo *minimaxLim(tNodo *n, int jugador){
	int max, max_actual, jugada, mejorJugada;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	max = -10000;
	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			max_actual = valorMinLim(intento,0);
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

tNodo *minimaxLim2(tNodo *n, int jugador){
	int min, min_actual, jugada, mejorJugada;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	min = 10000;
	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			min_actual = valorMaxLim(intento,0);
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

int valorMinLim(tNodo *n, unsigned prof){
	int valor_min, jugada=0, jugador = -1;

	if(terminal(n)){
		valor_min = terminal(n);
	}else if(n->vacias && prof <= LIMITE){
		valor_min = 100000;

		for(jugada = 0; jugada < N; jugada++){
			if(esValida(n, jugada)){
				valor_min = MIN(valor_min, valorMaxLim(aplicaJugada(n, jugador, jugada),prof+1));
			}
		}
	}else{
		valor_min = heuristica(n);
	}

	return valor_min;
}

int valorMaxLim(tNodo *n, unsigned prof){
	int valor_max, jugada=0, jugador = 1;

	if(terminal(n)){
		valor_max = terminal(n);
	}else if(n->vacias && prof <= LIMITE){
		valor_max = -100000;

		for(jugada = 0; jugada < N; jugada++){
			if(esValida(n, jugada)){
				valor_max = MAX(valor_max, valorMinLim(aplicaJugada(n, jugador, jugada),prof+1));
			}
		}
	}else{
		valor_max = heuristica(n);
	}

	return valor_max;
}

//##############################################################################################################################
tNodo *poda_ab(tNodo *n){
	int v, jugada, mejorJugada;
	int alfa = -100000, beta = 100000, prof = 0, jugador = 1;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			v = valorMinAB(intento,alfa,beta);
			if(v > alfa){
				alfa = v;
				mejorJugada = jugada;
			}
		}
	}

	aux = aplicaJugada(aux, jugador, mejorJugada);
	free(intento);
	return aux;
}

tNodo *poda_ab2(tNodo *n){
	int v, jugada, mejorJugada;
	int alfa = -100000, beta = 100000, prof = 0, jugador = -1;
	tNodo *intento=(tNodo*) malloc(sizeof(tNodo));
	tNodo *aux=(tNodo*) malloc(sizeof(tNodo));
	memcpy(aux,n,sizeof(tNodo));

	for(jugada = 0; jugada < N; jugada++){
		if(esValida(aux, jugada)){
			intento = aplicaJugada(aux, jugador, jugada);
			v = valorMaxAB(intento,alfa,beta);
			if(v < beta){
				beta = v;
				mejorJugada = jugada;
			}
		}
	}

	aux = aplicaJugada(aux, jugador, mejorJugada);
	free(intento);
	return aux;
}

int valorMinAB(tNodo *n, int a, int b){
	int valor_min, jugada=0, jugador = -1;

	if(terminal(n)){
		valor_min = terminal(n);
	}else if(n->vacias){
		valor_min = 100000;

		for(jugada = 0; (jugada < N) && (valor_min < a); jugada++){
			if(esValida(n, jugada)){
				valor_min = MIN(valor_min, valorMaxAB(aplicaJugada(n, jugador, jugada),a,b));
			}
			b = MIN(b,valor_min);
		}
	}else{
		valor_min = 0;
	}

	return valor_min;
}

int valorMaxAB(tNodo *n, int a, int b){
	int valor_max, jugada=0, jugador = 1;

	if(terminal(n)){
		valor_max = terminal(n);
	}else if(n->vacias){
		valor_max = -100000;

		for(jugada = 0; (jugada < N) && (valor_max < b); jugada++){
			if(esValida(n, jugada)){
				valor_max = MAX(valor_max, valorMinAB(aplicaJugada(n, jugador, jugada),a,b));
			}
			a = MAX(a,valor_max);
		}
	}else{
		valor_max = 0;
	}

	return valor_max;
}
