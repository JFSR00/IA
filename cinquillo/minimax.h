tNodo *PSEUDOminimax(tNodo *t);


tNodo *minimax(tNodo *t);
tNodo *jugadaAdversario(tNodo *t);

int valorMax(tNodo *Nodo, int profundidad);
int valorMin(tNodo *Nodo, int profundidad);

int valorMinPoda(tNodo *Nodo, int profundidad, int alfa, int beta);
int valorMaxPoda(tNodo *Nodo, int profundidad, int alfa, int beta);
