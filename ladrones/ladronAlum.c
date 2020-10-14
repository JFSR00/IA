/*******************************************/
/* 		      LADRON.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ladron.h"



tEstado *crearEstado(int sacos[N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, ficha;

   for (i=0;i<N;i++)
      estado->sacos[i]=sacos[i];

   estado->ladron=0;
   estado->robot=0;
   estado->izq=0;
   estado->dch=N-1;

   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(sacos_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(sacos_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i;

   for (i=0; i<N; i++)
	   printf("%d ",estado->sacos[i]);
   printf("\n");

}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Funci�n auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
	int res=1;
    for(int i=0; i<N && res; i++){
    	res=(s->sacos[i]==t->sacos[i]);
    }
	return res;
}


int testObjetivo(tEstado *estado)
{
	return ((estado->izq>estado->dch)&&(estado->ladron>estado->robot));
}


int esValido(unsigned op, tEstado *estado)
{
    return testObjetivo(estado);
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
	tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
	memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado

	switch(op){
	case IZQUIERDA:
		estado->ladron+=estado->sacos[estado->izq];
		estado->sacos[estado->izq]=0;

		estado->robot+=estado->sacos[estado->dch];
		estado->sacos[estado->dch]=0;
		break;
	case DERECHA:
		estado->ladron+=estado->sacos[estado->dch];
		estado->sacos[estado->dch]=0;

		estado->robot+=estado->sacos[estado->izq];
		estado->sacos[estado->izq]=0;
		break;
	default:
		break;
	}

	estado->izq++;
	estado->dch--;

	return nuevo;
}




