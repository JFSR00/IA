#ifndef ROBOTCAJA_H_
#define ROBOTCAJA_H_

#define ARR 1
#define ABJ 1
#define IZQ 1
#define DCH 1
#define NUM_OPERADORES 4

#define N 4

#define OBSTACULO 5
#define ROBOT 1
#define CAJA 2
//#define SALIDA 3

typedef struct{
        int celdas[N][N];
        int xRobot, yRobot, xCaja, yCaja, solo;
} tEstado;

static int mapa_inicial[N][N] =
{
	1,5,5,0,
	0,0,2,0,
	0,0,5,0,
	5,0,0,0
};

/* A partir de una configuraci�n de fichas construye un estado v�lido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();


/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);

/* Comprueba si es posible aplicar un operador a una configuraci�n determinada para el puzle.
  Devuelve 1 si el movimiento es v�lido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuraci�n concreta del puzle.
  Devuelve la nueva configuraci�n del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);

#endif
