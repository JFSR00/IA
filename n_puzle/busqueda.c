/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

void solucionFin(int res){
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}
void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}
void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo raíz. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

LISTA expandir(tNodo *nodo, int fun){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
      if (esValido(op,nodo->estado)){
                        //s=(tEstado *)calloc(1,sizeof(tEstado));
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad+1;
          switch(fun){
          case 1:
        	  nuevo->valHeuristica=heuristica(s);
        	  break;
          case 2:
        	  nuevo->valHeuristica=heuristica(s)+camino(nuevo);
        	  break;
          default:
        	  nuevo->valHeuristica=0;
        	  break;
          }
          InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

int heuristica(tEstado* e){	// Número de piezas mal colocadas
	int h=0;
	tEstado* final=estadoObjetivo();

	for(int i=0; i<N*N; i++){
		if(final->col[i]!=e->col[i] || final->fila[i]!=e->fila[i]){
			h++;
		}
	}

	return h;
}

int camino(tNodo* n){	// Profundidad del nodo
	int g=0;
	tNodo* aux=n;

	while(aux!=NULL){
		aux=aux->padre;
		g++;
	}

	return g;
}

//###################################################################################################
int busquedaAnch(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        visitados++;
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual,0);
            Abiertos=Concatenar(Abiertos,Sucesores);
      }
   }//while
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
      	EliminarPrimero(Sucesores);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaProf(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        visitados++;
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual,0);
            Abiertos=Concatenar(Sucesores,Abiertos);
      }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
    	EliminarPrimero(Sucesores);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaAnchEstRep(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        if(!buscarElto(&Cerrados, Actual->estado)){
        	visitados++;
        	objetivo=testObjetivo(Actual->estado);
        	if (!objetivo){
        	    Sucesores = expandir(Actual,0);
        	    Abiertos=Concatenar(Abiertos,Sucesores);
        	}
        	InsertarUltimo(&Cerrados,(tNodo*) Actual, sizeof(tNodo));
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
      	EliminarPrimero(Sucesores);
    }
    while(esVacia(Cerrados)){
      	EliminarPrimero(Cerrados);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaProfEstRep(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        if(!buscarElto(&Cerrados, Actual->estado)){
        	visitados++;
        	objetivo=testObjetivo(Actual->estado);
        	if (!objetivo){
        	    Sucesores = expandir(Actual,0);
        	    Abiertos=Concatenar(Sucesores,Abiertos);
        	}
        	InsertarPrimero(&Cerrados,(tNodo*) Actual, sizeof(tNodo));
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
      	EliminarPrimero(Sucesores);
    }
    while(esVacia(Cerrados)){
      	EliminarPrimero(Cerrados);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaAnchLimite(int l){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        if(Actual->profundidad <= l){
        	visitados++;
        	objetivo=testObjetivo(Actual->estado);
        	if (!objetivo){
        	    Sucesores = expandir(Actual,0);
        	    Abiertos=Concatenar(Abiertos,Sucesores);
        	}
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
      	EliminarPrimero(Sucesores);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaProfLimite(int l){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        if(Actual->profundidad <= l){
        	visitados++;
        	objetivo=testObjetivo(Actual->estado);
        	if (!objetivo){
        	    Sucesores = expandir(Actual,0);
        	    Abiertos=Concatenar(Sucesores,Abiertos);
        	}
        }
   }//while

    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    /*while(esVacia(Sucesores)){
      	EliminarPrimero(Sucesores);
    }*/
    //free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

//###################################################################################################
int busquedaHeuristica(int op){	// OP = 1 para f(n) = h(n) | OP = 2 para f(n) = h(n) + g(n)
	int objetivo=0, visitados=0;
	tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
	tNodo *Inicial=nodoInicial();

	LISTA Abiertos= VACIA;
	LISTA Sucesores= VACIA;
	LISTA Cerrados= VACIA;
	InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
	while (!esVacia(Abiertos) && !objetivo){
		Actual=(tNodo*) calloc(1,sizeof(tNodo));
		ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
		EliminarPrimero(&Abiertos);
		if(!buscarElto(&Cerrados, Actual->estado)){
			objetivo=testObjetivo(Actual->estado);
			if (!objetivo){
				visitados++;
				Sucesores = expandir(Actual,op);
				Abiertos=Ordenar(Abiertos,Sucesores);
				//printLista(Abiertos);
			}
			InsertarPrimero(&Cerrados,(tNodo*) Actual, sizeof(tNodo));
		}
	}//while

	printf("\nVisitados= %d\n", visitados);
	if (objetivo)
		dispSolucion(Actual);
	free(Inicial);
	free(Actual);
	return objetivo;
}
