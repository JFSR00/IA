#include "robotCaja.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


tEstado *crearEstado(int celdas[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, pos;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         pos=celdas[i][j];
         estado->celdas[i][j]=pos;
      }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(mapa_inicial);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
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
    	for(int j=0; j<N && res; j++){
    		res=(s->celdas[i][j]==t->celdas[i][j]);
    	}
    }
	return res;
}


int testObjetivo(tEstado *estado)
{
	return (estado->xRobot==estado->yRobot && ) ? 1 : 0;
}


int esValido(unsigned op, tEstado *estado)
{
	int res=0;
    switch(op){
    case ARRIBA:
    	if(estado->fila[0]!=0){
    		res=1;
    	}
    	break;
    case ABAJO:
    	if(estado->fila[0]!=(N-1)){
    	    	res=1;
    	}
    	break;
    case IZQUIERDA:
    	if(estado->col[0]!=0){
    		res=1;
    	}
    	break;
    case DERECHA:
    	if(estado->col[0]!=(N-1)){
    		res=1;
    	}
    	break;
    default:
    	break;
    }
    return res;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
	tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
	memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado

	int ficha;

	switch(op){
	case ARRIBA:
		nuevo->fila[0]-=1;
		break;
	case ABAJO:
		nuevo->fila[0]+=1;
		break;
	case IZQUIERDA:
		nuevo->col[0]-=1;
		break;
	case DERECHA:
		nuevo->col[0]+=1;
		break;
	default:
		break;
	}
	ficha=nuevo->celdas[nuevo->fila[0]][nuevo->col[0]];

	nuevo->celdas[estado->fila[0]][estado->col[0]]=ficha;

	nuevo->fila[ficha]=estado->fila[0];
	nuevo->col[ficha]=estado->col[0];

	nuevo->celdas[nuevo->fila[0]][nuevo->col[0]]=0;
	return nuevo;
}
