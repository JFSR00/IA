/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#ifndef PUZLE_H_
#define PUZLE_H_

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define N 4


#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int celdas[N][N];
        int fila[N*N], col[N*N];
   } tEstado;
#endif


/*static int puzle_inicial[N][N]=
{
  {0,2},
  {1,3},
};


static int puzle_inicial[N][N]=
{
	{0,1},
	{3,2},
};

static int puzle_final[N][N]=
{
  {1,2},
  {0,3},
};*/


/*static int puzle_inicial[N][N]=	// No tiene solución
{
  {1,7,3},
  {6,2,4},
  {8,5,0}
};*/

/*static int puzle_inicial[N][N]=	// Creado por mi, tiene que tener solución
{
	{2,3,4},
	{1,0,8},
	{7,6,5}
};*/

/*static int puzle_inicial[N][N]=	// Tiene solución
{
	{1,2,3},
	{7,8,0},
	{6,5,4}
};*/

/*static int puzle_inicial[N][N]=
{
	{1,3,0},
	{6,2,4},
	{8,7,5}
};*/

/*static int puzle_inicial[N][N]=
{
	{6,3,1},
	{8,0,4},
	{7,5,2}
};*/

/*static int puzle_final[N][N]=
{
	{1,2,3},
	{8,0,4},
	{7,6,5}
};*/

static int puzle_inicial[N][N]=
{
	{1	,2	,3	,4	},
	{5	,6	,15	,8	},
	{9	,10	,0	,12	},
	{13	,14	,7	,11	}
};

static int puzle_final[N][N]=
{
	{1	,2	,3	,4	},
	{5	,6	,7	,8	},
	{9	,10	,11	,12	},
	{13	,14	,15	,0	}
};

/* A partir de una configuración de fichas construye un estado válido para el problema
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


/* Comprueba si es posible aplicar un operador a una configuración determinada para el puzle.
  Devuelve 1 si el movimiento es válido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuración concreta del puzle.
  Devuelve la nueva configuración del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);

#endif
