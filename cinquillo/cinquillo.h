#define MAX 1
#define MIN -1
#define MESA 3
#define N 10 //cartas
#define P 2 //palos
#define LIMITE 2
#define maximo(a, b) (((a) > (b)) ? (a) : (b))
#define minimo(a, b) (((a) < (b)) ? (a) : (b))

//// VERSION
typedef struct tNodo {
    int cartas[N*P]; //Presencia de cartas de cada jugador: +1 -1 3
    int nMax, nMin;  //contadores del numeor de cartas de cada jugador
} tNodo;
typedef struct tJugada{
    int num;
    int palo;
}tJugada;

void dispPalo(int palo);
void dispJugada (tJugada j, int jugador);
void dispNodo(tNodo *s, int jugador);
tNodo *repartir();

int opuesto( int jugador);

tNodo *crearNodo(int cartas[P*N]);
tNodo *nodoInicial(void);




tNodo *aplicaJugada(tNodo *actual, int jugador, tJugada jugada);
int esValida(tNodo *actual,  int jugador, tJugada jugada);
int terminal(tNodo *s);
int heuristica(tNodo *s);
