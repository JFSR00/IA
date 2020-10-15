/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#define LLENAR 1
#define VACIAR 2
#define PASAR 3
#define NUM_OPERADORES 3
#define N 2

#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int jarras[N];
   } tEstado;
#endif


static int jarras_inicial[N]=
{0,0};


static int jarras_final[N]=
{2,0};


/* A partir de una configuración de fichas construye un estado válido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N]);

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
int esValido(unsigned op, unsigned dest, tEstado* estado);

/* Aplica un operador a una configuración concreta del puzle.
  Devuelve la nueva configuración del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, unsigned jar, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);
