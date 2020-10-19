/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include "jarras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




tEstado *crearEstado(int jarras_cr[N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i;

   for (i=0;i<N;i++){
	   estado->jarras[i]=jarras_cr[i];
   }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(jarras_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(jarras_final);
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
       printf("Jarra %d: %d\n",i,estado->jarras[i]);
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case LLENAR4:    printf("Movimiento LLENAR4:\n"); break;
      case LLENAR3:    printf("Movimiento LLENAR3:\n"); break;
      case VACIAR4:     printf("Movimiento VACIAR4:\n"); break;
      case VACIAR3:     printf("Movimiento VACIAR3:\n"); break;
      case LLENAR4CON3: printf("Movimiento LLENAR4CON3:\n"); break;
      case LLENAR3CON4: printf("Movimiento LLENAR3CON4:\n"); break;
      case VACIAR4EN3: printf("Movimiento VACIAR4EN3:\n"); break;
      case VACIAR3EN4: printf("Movimiento VACIAR3EN4:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Funci�n auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
	int res=1;
    for(int i=0; i<N && res; i++){
    	res=(s->jarras[i]==t->jarras[i]);
    }
	return res;
}


int testObjetivo(tEstado *estado)
{
	return (estado->jarras[0]==2);
}


int esValido(unsigned op, tEstado *estado)
{
	int res=0;
	switch(op)
	{
	   case LLENAR4:		if(!estado->jarras[0]){res=1;} break;
	   case LLENAR3:		if(!estado->jarras[1]){res=1;} break;
	   case VACIAR4:		if(estado->jarras[0]){res=1;} break;
	   case VACIAR3:		if(estado->jarras[1]){res=1;} break;
	   case LLENAR4CON3:	if(estado->jarras[0]+estado->jarras[1]>=4){res=1;} break;
	   case LLENAR3CON4:	if(estado->jarras[0]+estado->jarras[1]>=3){res=1;} break;
	   case VACIAR4EN3:		if(estado->jarras[0]+estado->jarras[1]<3){res=1;} break;
	   case VACIAR3EN4:		if(estado->jarras[0]+estado->jarras[1]<4){res=1;} break;
	}
    return res;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
	tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
	memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado

	switch(op)
	{
		case LLENAR4:	nuevo->jarras[0]=4; break;
		case LLENAR3:	nuevo->jarras[1]=3; break;
		case VACIAR4:	nuevo->jarras[0]=0; break;
		case VACIAR3:	nuevo->jarras[1]=0; break;
		case LLENAR4CON3:
			nuevo->jarras[0]+=nuevo->jarras[1];
			nuevo->jarras[1]=nuevo->jarras[0]-4;
			nuevo->jarras[0]=4;
			break;
		case LLENAR3CON4:
			nuevo->jarras[1]+=nuevo->jarras[0];
			nuevo->jarras[0]=nuevo->jarras[1]-3;
			nuevo->jarras[1]=3;
			break;
		case VACIAR4EN3:
			nuevo->jarras[1]+=nuevo->jarras[0];
			nuevo->jarras[0]=0;
			break;
		case VACIAR3EN4:
			nuevo->jarras[0]+=nuevo->jarras[1];
			nuevo->jarras[1]=0;
			break;
	}
	return nuevo;
}




