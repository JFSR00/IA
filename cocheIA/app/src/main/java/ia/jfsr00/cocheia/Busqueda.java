package ia.jfsr00.cocheia;

/*
#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;
 */

import java.util.LinkedList;

public class Busqueda {
	public static NodoBusqueda anchura(){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Sucesores;

		Abiertos.add(new NodoBusqueda());
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = new NodoBusqueda(new Coche(Abiertos.getFirst().estado.getAsientos()));
			Abiertos.pollFirst();
			visitados++;

			objetivo = Actual.estado.testObjetivo();
			if(!objetivo){
				Sucesores = expandir(Actual);
				Abiertos.addAll(Sucesores);
			}

		}

		if(objetivo){
			return Actual;
		}else{
			return null;
		}

	}

	public static void anchuraLim(int l){}
	public static void anchuraEstRep(){}
	public static void profundidad(){}
	public static void profundidadLim(int l){}
	public static void profundidadEstRep(){}

	public static LinkedList<NodoBusqueda> expandir(NodoBusqueda nodo){
		LinkedList<NodoBusqueda> sucesores = new LinkedList<>();
		NodoBusqueda nuevo;

		for(int op = 0; op < Coche.N_OP; op++){
			if(nodo.estado.esValido(op)){
				nuevo = new NodoBusqueda(new Coche(nodo.estado.aplicaOperador(op).getAsientos()));
				nuevo.padre = nodo;
				nuevo.operador = op;
				nuevo.costeCamino = nodo.costeCamino + nodo.estado.coste(op);
				nuevo.profundidad = nodo.profundidad + 1;
				nuevo.valHeuristica = 0;

				sucesores.addLast(nuevo);
			}
		}
		return sucesores;
	}

	public static String caminoToString(NodoBusqueda nodo){
		String str = "";

		if(nodo.padre == null){
			str += "\nDesde el inicio\n" + nodo.estado.toString();
		}else{
			str += caminoToString(nodo.padre) + "\n Operador: " + nodo.estado.toString();
		}

		return str;
	}

}
/*
LISTA expandir(tNodo *nodo, int fun){
	for (op=1; op<=NUM_OPERADORES;op++){
		if (esValido(op,nodo->estado)){
			//s=(tEstado *)calloc(1,sizeof(tEstado));
			s=aplicaOperador(op,nodo->estado);
			nuevo->estado=s;
			nuevo->padre=nodo;
			nuevo->operador=op;
			nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
			nuevo->profundidad=nodo->profundidad+1;
			switch(fun){
			case 1:
				nuevo->valHeuristica=heuristica(s,estadoObjetivo());
				break;
			case 2:
				nuevo->valHeuristica=heuristica(s,estadoObjetivo())+camino(nuevo);
				break;
			case 3:
				nuevo->valHeuristica=manhattan(s,estadoObjetivo());
				break;
			case 4:
				nuevo->valHeuristica=manhattan(s,estadoObjetivo())+camino(nuevo);
				break;
			default:
				nuevo->valHeuristica=0;
				break;
			}
			//printf("\nHeurística no lista= %d",nuevo->valHeuristica);
			InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
		}
	}
	return sucesores;
}
 */


/*
void solucionFin(int res);

int heuristica(tEstado* e, tEstado* final);
int camino(tNodo* n);
int busquedaHeuristica(int op);
 */