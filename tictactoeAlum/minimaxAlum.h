/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

#define LIMITE 9

/*
	tNodo *PSEUDOminimax(tNodo *Nodo)
	Funci�n que devuelve un tablero despu�s de que el ordenador realice un movimiento
	de forma poco inteligente

	Nodo:		Es el tablero actual,
	devuelve:	El tablero despu�s del movimiento del ordenador
*/
tNodo *PSEUDOminimax(tNodo *Nodo);


/*
	tNodo *jugadaAdversario(tNodo *t)
	Funci�n que recoge movimiento del jugador humano

	t:		Es el tablero actual,
	devuelve:	El tablero despu�s del movimiento del humano
*/
tNodo *jugadaAdversario(tNodo *t);

/*
	tNodo *minimax(tNodo *n)
	Funci�n que devuelve un tablero despu�s de que el ordenador realice un movimiento inteligente

	n:			Es el tablero actual,
	devuelve:	El tablero despu�s del movimiento del ordenador
*/
tNodo *minimax(tNodo *n, int jugador);
tNodo *minimax2(tNodo *n, int jugador);		// Versi�n para CPU vs CPU, uno debe ser minimax y el otro minimax2
tNodo *minimaxLim(tNodo *n, int jugador);	// Versi�n con l�mite
tNodo *minimaxLim2(tNodo *n, int jugador);	// Versi�n con l�mite para CPU vs CPU

/*
	int valorMax(tNodo *n)
	Funci�n que devuelve el m�ximo valor del tablero dado

	n:			Es el tablero actual,
	devuelve:	El m�ximo valor del nodo dado
*/
int valorMax(tNodo *n);

/*
	int valorMax(tNodo *n)
	Funci�n que devuelve el m�nimo valor del tablero dado

	n:			Es el tablero actual,
	devuelve:	El m�nimo valor del nodo dado
*/
int valorMin(tNodo *n);

/*
	int valorMinLim(tNodo *n, unsigned prof)
	Funci�n que devuelve el m�nimo valor del tablero dado con un l�mite

	n:			Es el tablero actual,
	devuelve:	El m�nimo valor del nodo dado
*/
int valorMinLim(tNodo *n, unsigned prof);

/*
	int valorMaxLim(tNodo *n, unsigned prof)
	Funci�n que devuelve el m�nimo valor del tablero dado con un l�mite

	n:			Es el tablero actual,
	devuelve:	El m�nimo valor del nodo dado
*/
int valorMaxLim(tNodo *n, unsigned prof);
