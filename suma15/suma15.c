#include "suma15.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


tNodo *estadoInicial()
{
   return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N])
{
   tNodo *Nodo = (tNodo *) malloc(sizeof(tNodo));
   int i, c;
   Nodo->vacias=0;
   for (i=0;i<N;i++){
         c=celdas[i];
         Nodo->cifras[i]=c;
         if (c==0)
	      Nodo->vacias=Nodo->vacias+1;
      }
   return Nodo;
}


tNodo *aplicaJugada(tNodo *actual, int jugador, tJugada jugada){
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    memcpy(nuevo,actual,sizeof(tNodo));
    if(esValida(actual, jugada)){
    	nuevo->cifras[jugada]=jugador;
    	nuevo->vacias--;
    	if(jugador==MAX){
    		nuevo->sMax+=jugada->num;
    	}else{
    		nuevo->sMin+=jugada->num;
    	}
    }
    return nuevo;
}

int esValida(tNodo *actual, tJugada jugada){
	return (!actual->cifras[jugada->num]);
}

int opuesto(int jugador){
    return (jugador * -1);//Jugador 1 y Jugador -1
}

int lleno(tNodo *tablero){
    return (tablero->vacias == 0);
}

int terminal(tNodo *Nodo){
	int res;
	if(Nodo->sMax == 15){
		res = MAX;
	}else if(Nodo->sMin == 15){
		res = MIN;
	}else if(Nodo->sMax > 15){
		for(int i=0; i<N; i++){

		}
	}else if(Nodo->sMax > 15){
		for(int i=0; i<N; i++){

		}
	}

    return res*100;
}

int heuristica(tNodo *Nodo){
	unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	int res=0, val=0, jug=0, jugAux=0;
	for(int i=0; i<8; i++){
		jug=0;
		jugAux=0;
		val=0;
		for(int j=0; j<3; j++){
			if(Nodo->celdas[opciones[i][j]]!=0){
				jugAux = jug;
				jug = Nodo->celdas[opciones[i][j]];
			}
			if((jugAux == 0 && jug != jugAux) || (jugAux != 0 && jug == jugAux)){
				val=1;
			}else{
				val=0;
			}
		}
		if(val == 1){
			res+=jug;
		}
	}

	return res;
}

////////////////////////////////////////
//  VISUALIZACI�N DE NodoS
////////////////////////////////////////

char marca(int i){
	switch(i) {
	case 1:
		return 'X';
	case 0:
		return ' ';
	case -1:
		return 'O';
	default:
		return ' ';
	}
}

void dispNodo(tNodo *b) {
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[0]),marca(b->celdas[1]),marca(b->celdas[2]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[3]),marca(b->celdas[4]),marca(b->celdas[5]));
     printf("---+---+---\n");
     printf(" %c | %c | %c\n",marca(b->celdas[6]),marca(b->celdas[7]),marca(b->celdas[8]));
     printf("---+---+---\n\n");
}






