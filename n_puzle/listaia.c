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

LISTA Ordenar(LISTA l){
	LISTA aux, aux2, orig=aux;
	tNodo* nodo;
	int insertado=0;
	if(!esVacia(l)){
		while(l->next!=NULL){
			nodo=(tNodo*)l->nodo;
			aux=orig;
			aux2=NULL;
			insertado=0;
			while(!insertado && aux != NULL){
				if(!esVacia(aux) && nodo->valHeuristica>((tNodo*)aux->nodo)->valHeuristica){
					if(aux2==NULL){
						insertarPrimero(&aux,(tNodo*) nodo,sizeof(tNodo));
					}else{
						insertarSiguiente(&aux2,(tNodo*) nodo,sizeof(tNodo));
					}
					insertado=1;
				}else{
					insertarSiguiente(&aux,(tNodo*) nodo,sizeof(tNodo));
					insertado=1;
				}
				aux2=aux;
				aux=aux->next;
			}
			l=l->next;
		}
	}
	return aux;
}

//void Lista<T>::insertar(const T& x, Lista<T>::posicion p)
void insertarSiguiente(LISTA *c, void *n, int size)
{
	LISTA sig=(*c)->next;
	(*c)->next = (LISTA) malloc(sizeof(LISTA)+size);
	memcpy((void*)((*c)->nodo),(void *) n, size);
	(*c)->next->next=sig;
}
