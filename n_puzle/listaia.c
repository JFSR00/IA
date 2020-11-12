/*******************************************/
/*             LISTAIA .C                  */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaia.h"

tEstado* buscarElto(LISTA *c, tEstado *n){
	tEstado *res=NULL;
	LISTA aux=*c;

	while(aux!=NULL && res==NULL){
		if(memcmp(((tNodo*)aux->nodo)->estado,n,sizeof(tEstado))==0){
			res=((tNodo*)aux->nodo)->estado;
		}else{
			aux=aux->next;
		}
	}

	return res;
}

int esVacia( LISTA c){
    return (c==VACIA);
}//esVacia

void InsertarPrimero(LISTA *c, void *n, int size){
    LISTA p=(LISTA ) malloc(sizeof(LISTA)+size);
    memcpy((void *)p->nodo,(void*)n, size);
    p->next=(*c);
    *c=p;
}//InsertarPrimero


void ExtraerPrimero(LISTA c, void *n, int size){
    memcpy((void *) n, (void *) c->nodo,size);
};//Extraer primer elemento


void EliminarPrimero(LISTA *c){
    LISTA p;
    p=*c;
    *c=p->next;
    free(p);
}//Eliminar primer elemento de la lista

void InsertarUltimo(LISTA *c, void *n, int size){
    LISTA p=malloc(sizeof(LISTA)+size);
    LISTA aux=VACIA;
    //creando el nodo
    memcpy((void*)(p->nodo),(void *) n, size);
    p->next=NULL;
    if (esVacia(*c)){
        *c=p;
    }
    else{
        aux=*c;
        while (aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=p;
    }
}//InsertarUltimo

LISTA Concatenar(LISTA c,LISTA p){
    LISTA aux;
    if (esVacia(c))
        c= p;
    else {
        aux=c;
        while (aux->next!= NULL) {
            aux = aux->next;
        }
        aux->next=p;
    }
    return c;
}//Concatenar

/*LISTA Ordenar(LISTA l){
	LISTA aux=NULL, aux2=NULL, orig=NULL;
	tNodo* nodo;
	int insertado=0;

	if(l != NULL){
		nodo=(tNodo*)l->nodo;
		InsertarPrimero(&aux,(tNodo*) nodo,sizeof(tNodo));
		orig=aux;
		l=l->next;
	}

	while(l != NULL){
		nodo=(tNodo*)l->nodo;
		aux=orig;
		aux2=NULL;
		insertado=0;
		while(!insertado && aux != NULL){
			if(nodo->valHeuristica<=((tNodo*)aux->nodo)->valHeuristica){
				if(aux2==NULL){
					InsertarPrimero(&aux,(tNodo*) nodo,sizeof(tNodo));
					orig=aux;
				}else{
					InsertarSiguiente(&aux2,(tNodo*) nodo,sizeof(tNodo));
				}
				insertado=1;
			}*//*else if(aux->next == NULL){
				InsertarSiguiente(&aux, (tNodo*) nodo,sizeof(tNodo));
			}*/
			/*aux2=aux;
			aux=aux->next;
		}
		l=l->next;
	}

	return orig;
}*/

LISTA InsertarOrdenado(LISTA C, tNodo *nuevo){
	LISTA R=NULL;
	tNodo* nc = (tNodo*) calloc(1,sizeof(tNodo));

	if(esVacia(C)){
		InsertarUltimo(&R,(tNodo*) nuevo,sizeof(tNodo));
	}else{
		ExtraerPrimero(C,(tNodo*) nc,sizeof(tNodo));
		while(!esVacia(C) && (*nuevo).valHeuristica >= (*nc).valHeuristica){
			InsertarUltimo(&R,(tNodo*) nc,sizeof(tNodo));
			C=C->next;
			if(!esVacia(C)){
				ExtraerPrimero(C,(tNodo*)nc,sizeof(tNodo));
			}
		}
		InsertarUltimo(&R,(tNodo*) nuevo,sizeof(tNodo));
		Concatenar(R,C);
	}
	free(nc);
	return R;
}

LISTA Ordenar(LISTA A, LISTA B){
	tNodo* nodo = (tNodo*) calloc(1,sizeof(tNodo));
	while(!esVacia(B)){
		ExtraerPrimero(B,(tNodo*) nodo,sizeof(tNodo));
		A=InsertarOrdenado(A,nodo);
		B=B->next;
	}
	free(nodo);
	return A;
}

/*void InsertarSiguiente(LISTA *c, void *n, int size)
{
	LISTA sig=(*c)->next;
	(*c)->next = (LISTA) malloc(sizeof(LISTA)+size);
	memcpy((void*)((*c)->nodo),(void *) n, size);
	(*c)->next->next=sig;
}
*/

int Longitud(LISTA A){
	int l=0;
	while(A!=NULL){
		l++;
		A=A->next;
	}
	return l;
}

void printLista(LISTA l){
	printf("\n\n");
	while(l != NULL){
		printf("Heuristica: %i\n",((tNodo*)l->nodo)->valHeuristica);
		l=l->next;
	}
}
