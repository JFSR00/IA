/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#ifndef PUZLE3_H_
#define PUZLE3_H_

#define ARRIBA_A 1
#define ABAJO_A 2
#define IZQUIERDA_A 3
#define DERECHA_A 4

#define ARRIBA_B 5
#define ABAJO_B 6
#define IZQUIERDA_B 7
#define DERECHA_B 8

#define ARRIBA_C 9
#define ABAJO_C 10
#define IZQUIERDA_C 11
#define DERECHA_C 12

#define NUM_OPERADORES 12

#define N 6		// Número de celdas de ancho y alto del tablero
#define NF 3	// Número de fichas

#define O 4
#define V 0

#define A 1
#define B 2
#define C 3

#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int celdas[N][N];
        int fila[NF+1], col[NF+1];
   } tEstado;
#endif


static int puzle_inicial[N][N]=
{
  {O,V,V,C,V,V},
  {O,V,V,C,V,V},
  {V,A,V,C,V,V},
  {A,A,A,O,B,V},
  {V,A,V,B,B,B},
  {V,V,V,V,V,V}
};

static int puzle_inicial_fila[NF+1]=
{NULL,};

static int puzle_final[N][N]=
{
  {O,V,V,V,V,V},
  {O,V,V,V,V,V},
  {V,V,V,V,V,V},
  {V,A,V,O,V,C},
  {A,A,A,B,V,C},
  {V,A,B,B,B,C}
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

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();


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
