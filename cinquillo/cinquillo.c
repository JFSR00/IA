#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cinquillo.h"



////////////////////////////////////////
//  VISUALIZACIÓN DE NodoS
////////////////////////////////////////

void dispJugada (tJugada j, int jugador){
    if (jugador==MAX){
        printf("\n mi jugada es el %d de ",j.num+1);
        dispPalo(j.palo);
    }
    else if (jugador==MIN){
        printf("\n TU jugada es el %d de ",j.num+1);
        dispPalo(j.palo);
    }
}
void dispPalo(int palo){
    switch(palo){
        case 0: printf(" Oros:    \n");break;
        case 1: printf(" Bastos:  \n");break;
        case 2: printf(" Copas:   \n");break;
        case 3: printf(" Espadas: \n");break;
        default: printf("\n Palo erroneo\n");
    }
}
void dispNumero(tNodo *b,int palo, int jugador){
    int i;
    for (i=0; i<N; i++){
        if (b->cartas[palo*N+i]==jugador)
            printf(" %d", i+1);
    }
}

void dispNodo(tNodo *b, int jugador) {
    int j;
    if (jugador ==MIN){
        printf("\n -- Cartas de MIN --");
        printf(" Tienes %d cartas: \n", b->nMin);
    }
    else if (jugador ==MAX){
        printf("\n -- Cartas de MAX --");
        printf(" Tengo %d cartas: \n", b->nMax);
    }
    else if (jugador ==MESA)
        printf("\n ---------------Cartas en la MESA -------- \n");
    
    for (j=0; j<P; j++){
        dispPalo(j);
        dispNumero(b,j,jugador);
        printf("\n");
    }
    //printf("\n ----------------------------- \n");
    
}//dispNodo

// 2. Reparto aleatorio de las cartas
tNodo *repartir(){
    tNodo *nodo = (tNodo *) malloc(sizeof(tNodo));
    int i=0, jugador=MAX, indice;
    //inicializaci—n del mazo
    for (i=0; i<(N*P); i++)
        nodo->cartas[i]=3;
    //reparto entre jugadores
    for( i = 0; i < N*P; i++){
        // reparte n cartas para cada jugador, si el nœmero generado ya es de algœn jugador, se genera otro nœmero aleatorio
        indice = rand()%(N*P);
        while (nodo->cartas[indice]!=3)
            indice = rand()%(N*P);
        nodo->cartas[indice]=jugador;
        jugador=opuesto(jugador);
    }//for
    nodo->nMin=N*P/2;  // se han repartido n cartas a cada jugador
    nodo->nMax=N*P/2;
    return(nodo);
}//repartir

int opuesto( int jugador){
    return (jugador * -1);//Jugador 1 y Jugador -1
}


//********  FORMALIZACIîN EN C DEL CINQUILLO *****************************************************/

/*Los nodos pueden ser creados especificando cada carta o de forma aleatoria
tNodo *nodoInicial(){
    int Inicial[N*P]= { 'MAX', 'MIN', 'MESA'}; // especificar aqu’ cada carta de cada jugador o de la mesa
   return crearNodo(Inicial);
}*/
tNodo *crearNodo(int cartas[N*P]){
  tNodo *nodo = (tNodo *) malloc(sizeof(tNodo));
 
  return nodo;
}


tNodo *aplicaJugada(tNodo *actual, int jugador, tJugada jugada){
	tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
	memcpy(nuevo,actual,sizeof(tNodo));
	nuevo->cartas[jugada.palo*10+jugada.num]=MESA;
	if(jugador == MAX){
		nuevo->nMax--;
	}else{
		nuevo->nMin--;
	}
	return nuevo;
}

int esValida(tNodo *actual,  int jugador, tJugada jugada){
	int valido=0;

	if((jugada.num == 4) ||
		(jugada.num > 4 && actual->cartas[jugada.palo*10+jugada.num-1] == MESA) ||
		(jugada.num < 4 && actual->cartas[jugada.palo*10+jugada.num+1] == MESA)){
		valido = 1;
	}

	return valido;
}

int terminal(tNodo *Nodo)
{
	return !(Nodo->nMax && Nodo->nMin);	// No es correcto, hay que terminar esta función
}
int heuristica(tNodo *Nodo){			// Esta también hay que terminarla
    // Posibilidades de cada jugador
    int sumMin=0, sumMax=0;
    
    return (sumMax-sumMin);
}






