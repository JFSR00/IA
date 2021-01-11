#define MAX 1
#define MIN -1
#define N 10

typedef struct {
	int cifras[N];
	int vacias, sMax, sMin;
} tNodo;

typedef struct {
	int num;
} tJugada;

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// las posiciones ser�n numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Funci�n que crea tablero a partir de celdas dadas

	celdas[N]:	Celdas en funci�n de las cuales construir un tablero
	devuelve:	Un tablero creado en funci�n de las celdas dadas
*/
tNodo *crearNodo(int celdas[N]);

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Funci�n que devuelve un tablero inicial

	devuelve:	El tablero inicial
*/
tNodo *NodoInicial();

/*
	tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
	Funci�n que aplica jugada a un tablero concreto

	actual:		Es el tablero actual,
	jugador:	La marca del jugador que tiene el turno
	jugada:		Indica en qu� posici�n del tablero pondr� la marca
	devuelve:	El nuevo Nodo tras aplicar la jugada
*/
tNodo *aplicaJugada(tNodo *actual, int jugador, tJugada jugada);

/*
	int esValida(tNodo *actual, int jugada)
	Funci�n que determina si una jugada es v�lida

	actual:		Tablero actual
	jugada:		Jugada a comprobar
	devuelve:	0 (false) si no es v�lido, 1 (true) si es v�lido
*/
int esValida(tNodo *actual, tJugada jugada);

/*
	int terminal(tNodo *Nodo)
	Funci�n que determina si un nodo es terminal, ha ganado MAX o MIN

	actual:		Tablero actual
	jugador:	1 si es Max -1 si es Min
	devuelve:	si ha gando MAX 100, si ha ganado MIN -100, empate 0
				si no es terminal tambi�n devuelve 0
*/
int terminal(tNodo *Nodo);

/*
	int heuristica(tNodo *Nodo)
	Funci�n que devuelve el valor de un nodo en funci�n de quien tenga m�s posibilidades de ganar

	actual:		Tablero actual
	jugador:	1 si es Max -1 si es Min
	devuelve:	valor de un nodo en funci�n de quien tenga m�s posibilidades de ganar
*/
int heuristica(tNodo *Nodo);

/*
	void dispNodo(tNodo *s)
	Procedimiento que muestra por el terminal un tablero

	s:	tablero actual
*/
void dispNodo(tNodo *s);

/*
	int opuesto(int jugador)
	Funci�n que devuelve el jugador contrario al indicado

	jugador:	Jugador a oponer
	devuelve:	-1 para el jugador 1, 1 para el jugador -1
*/
int opuesto(int jugador);

/*
	int lleno(tNodo *s)
	Funci�n que determina si un tablero est� lleno o no

	s:			Tablero actual
	devuelve:	0 (false) si no est� lleno, 1 (true) si lo est�
*/
int lleno(tNodo *s);




