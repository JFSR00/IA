/*******************************************/
/* 		    tictactoe.h                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define N 9

typedef struct tNodo {
        int celdas[N];
        int vacias;
} tNodo;

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// las posiciones serán numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Función que crea tablero a partir de celdas dadas

	celdas[N]:	Celdas en función de las cuales construir un tablero
	devuelve:	Un tablero creado en función de las celdas dadas
*/
tNodo *crearNodo(int celdas[N]);

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Función que devuelve un tablero inicial

	devuelve:	El tablero inicial
*/
tNodo *NodoInicial();

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Función que aplica jugada a un tablero concreto

	actual:		Es el tablero actual,
	jugador:	La marca del jugador que tiene el turno
	jugada:		Indica en qué posición del tablero pondrá la marca
	devuelve:	El nuevo Nodo tras aplicar la jugada
*/
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);

/*
	int esValida(tNodo *actual, int jugada)
	Función que determina si una jugada es válida

	actual:		Tablero actual
	jugada:		Jugada a comprobar
	devuelve:	0 (false) si no es válido, 1 (true) si es válido
*/
int esValida(tNodo *actual, int jugada);

/*
	int terminal(tNodo *actual, int jugador)
	Función que determina si un nodo es terminal, ha ganado MAX o MIN

	actual:		Tablero actual
	jugador:	1 si es Max -1 si es Min
	devuelve:	si ha gando MAX 100, si ha ganado MIN -100, empate 0
				si no es terminal tambiŽn devuelve 0
*/
int terminal(tNodo *actual);

/*
	void dispNodo(tNodo *s)
	Procedimiento que muestra por el terminal un tablero

	s:	tablero actual
*/
void dispNodo(tNodo *s);

/*
	int opuesto(int jugador)
	Función que devuelve el jugador contrario al indicado

	jugador:	Jugador a oponer
	devuelve:	-1 para el jugador 1, 1 para el jugador -1
*/
int opuesto(int jugador);

/*
	int lleno(tNodo *s)
	Función que determina si un tablero está lleno o no

	s:			Tablero actual
	devuelve:	0 (false) si no está lleno, 1 (true) si lo está
*/
int lleno(tNodo *s);




