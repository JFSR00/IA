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

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


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
      case LLENAR:    printf("Movimiento LLENAR:\n"); break;
      case VACIAR:     printf("Movimiento VACIAR:\n"); break;
      case PASAR: printf("Movimiento PASAR:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
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


int esValido(unsigned op, unsigned jar, tEstado *estado)
{
	int res=0;
    switch(op){
    case LLENAR:
    	res=1;
    	break;
    case VACIAR:
    	res=1;
    	break;
    case PASAR:
    	if(jar){
    		res=(estado->jarras[0]<4);
    	}else{
    		res=(estado->jarras[0]<3);
    	}
    	break;
    default:
    	break;
    }
    return res;
}


tEstado *aplicaOperador(unsigned op, unsigned jar, tEstado *estado)
{
	tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
	memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado

	switch(op){
	case LLENAR:
		if(jar){
			nuevo->jarras[jar]=3;
		}else{
			nuevo->jarras[jar]=4;
		}
		break;
	case VACIAR:
		nuevo->jarras[jar]=0;
		break;
	case PASAR:
		if(jar){
			nuevo->jarras[0]+=nuevo->jarras[jar];
			if(nuevo->jarras[0]>4){
				nuevo->jarras[jar]=nuevo->jarras[0]-4;
				nuevo->jarras[0]=4;
			}else{
				nuevo->jarras[jar]=0;
			}
		}else{
			nuevo->jarras[1]+=nuevo->jarras[jar];
			if(nuevo->jarras[1]>3){
				nuevo->jarras[jar]=nuevo->jarras[0]-3;
				nuevo->jarras[0]=3;
			}else{
				nuevo->jarras[jar]=0;
			}
		}
		break;
	default:
		break;
	}
	return nuevo;
}




