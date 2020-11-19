/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

/*
	tNodo *PSEUDOminimax(tNodo *Nodo)
	Función que devuelve un tablero después de que el ordenador realice un movimiento
	de forma poco inteligente

	Nodo:		Es el tablero actual,
	devuelve:	El tablero después del movimiento del ordenador
*/
tNodo *PSEUDOminimax(tNodo *Nodo);


/*
	tNodo *jugadaAdversario(tNodo *t)
	Función que recoge movimiento del jugador humano

	t:		Es el tablero actual,
	devuelve:	El tablero después del movimiento del humano
*/
tNodo *jugadaAdversario(tNodo *t);

/*
	tNodo *minimax(tNodo *n)
	Función que devuelve un tablero después de que el ordenador realice un movimiento inteligente

	n:			Es el tablero actual,
	devuelve:	El tablero después del movimiento del ordenador
*/
tNodo *minimax(tNodo *n, int jugador);
tNodo *minimax2(tNodo *n, int jugador);	// Versión para CPU vs CPU, uno debe ser minimax y el otro minimax2

/*
	int valorMax(tNodo *n)
	Función que devuelve el máximo valor del tablero dado

	n:			Es el tablero actual,
	devuelve:	El máximo valor del nodo dado
*/
int valorMax(tNodo *n);

/*
	int valorMax(tNodo *n)
	Función que devuelve el mínimo valor del tablero dado

	n:			Es el tablero actual,
	devuelve:	El mínimo valor del nodo dado
*/
int valorMin(tNodo *n);
