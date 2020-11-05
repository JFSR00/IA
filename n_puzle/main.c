/*
 * main.c
 *
 *  Created on: 7 oct. 2020
 *      Author: Juan Francisco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

void printFila(tEstado* s);
void printCol(tEstado* s);

//void busqueda(tEstado* s);

int main(){
    //solucionFin(busquedaAnch());
    //solucionFin(busquedaProf());
    //solucionFin(busquedaAnchEstRep());
    solucionFin(busquedaProfEstRep());
    //solucionFin(busquedaAnchLimite(3));
    //solucionFin(busquedaProfLimite(4));
	//solucionFin(busquedaHeuristica(2));
    return 0;
}
/*int main(){
	//pruebas del c�digo generado
	int op;
	tEstado *n,*a;
	a=estadoInicial();

	for(op=1; op<=NUM_OPERADORES; op++){
		dispOperador(op);
		if(esValido(op, a)){
			n=aplicaOperador(op,a);
			dispEstado(n);
		}else{
			printf("\n Operador no v�lido\n");
		}
	}
}*/

/*
// Main de pruebas
int main(){
	tEstado *puzle=crearEstado(puzle_inicial), *puzle2=crearEstado(puzle_inicial), *final=crearEstado(puzle_final);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\nSon iguales los puzles? %i\n",iguales(puzle, puzle2));
	printf("\nEs el objetivo? %i\n",testObjetivo(puzle));
	printf("\nEs el objetivo? %i\n",testObjetivo(final));

	printf("\n%i\n",esValido(ARRIBA,puzle));
	puzle=aplicaOperador(ARRIBA,puzle);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\n%i\n",esValido(ARRIBA,puzle));
	puzle=aplicaOperador(ARRIBA,puzle);
	dispEstado(puzle);
	printFila(puzle);
	printCol(puzle);

	printf("\n%i\n",esValido(ARRIBA,puzle));
	if(esValido(ARRIBA,puzle)){
		puzle=aplicaOperador(ARRIBA,puzle);
		dispEstado(puzle);
		printFila(puzle);
		printCol(puzle);
	}

	printf("\nSon iguales los puzles? %i\n",iguales(puzle, puzle2));

	return 0;
}
*/

void printFila(tEstado* s){
	printf("\nFilas: ");
	for(int i=0; i<N*N; i++){
		printf("%i ",s->fila[i]);
	}
}
void printCol(tEstado* s){
	printf("\nColumnas: ");
	for(int i=0; i<N*N; i++){
		printf("%i ",s->col[i]);
	}
}

/*void busqueda(tEstado* s){


}*/
