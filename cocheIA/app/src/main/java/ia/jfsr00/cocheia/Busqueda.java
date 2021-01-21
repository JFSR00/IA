package ia.jfsr00.cocheia;

import java.util.LinkedList;

public class Busqueda {
	public static NodoBusqueda anchura(){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			visitados++;

			objetivo = Actual.estado.testObjetivo();
			if(!objetivo){
				Sucesores = expandir(Actual);
				Abiertos.addAll(Sucesores);
			}

		}

		System.out.println("visitados: " + visitados);

		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda anchuraLim(int l){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			if(Actual.profundidad <= l){
				visitados++;
				objetivo = Actual.estado.testObjetivo();
				if(!objetivo){
					Sucesores = expandir(Actual);
					Abiertos.addAll(Sucesores);
				}
			}
		}
		System.out.println("visitados: " + visitados);
		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda anchuraEstRep(){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Cerrados = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			if(!existsElto(Cerrados, Actual)){
				visitados++;
				objetivo = Actual.estado.testObjetivo();
				if(!objetivo){
					Sucesores = expandir(Actual);
					Abiertos.addAll(Sucesores);
				}
				Cerrados.addLast(Actual);
			}
		}
		System.out.println("visitados: " + visitados);
		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda profundidad(){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			visitados++;

			objetivo = Actual.estado.testObjetivo();
			if(!objetivo){
				Sucesores = expandir(Actual);
				Abiertos.addAll(0, Sucesores);
			}

		}

		System.out.println("visitados: " + visitados);

		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda profundidadLim(int l){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			if(Actual.profundidad <= l){
				visitados++;
				objetivo = Actual.estado.testObjetivo();
				if(!objetivo){
					Sucesores = expandir(Actual);
					Abiertos.addAll(0, Sucesores);
				}
			}
		}
		System.out.println("visitados: " + visitados);
		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda profundidadEstRep(){
		int visitados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Cerrados = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			if(!existsElto(Cerrados, Actual)){
				visitados++;
				objetivo = Actual.estado.testObjetivo();
				if(!objetivo){
					Sucesores = expandir(Actual);
					Abiertos.addAll(0, Sucesores);
				}
				Cerrados.addLast(Actual);
			}
		}
		System.out.println("visitados: " + visitados);
		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static NodoBusqueda heuristica(int fun){
		int visitados = 0, max_abiertos = 0, max_aux = 0, generados = 0;
		boolean objetivo = false;
		NodoBusqueda Actual = new NodoBusqueda();
		LinkedList<NodoBusqueda> Abiertos = new LinkedList<>(), Cerrados = new LinkedList<>(), Sucesores;

		Abiertos.add(Actual);
		while(!Abiertos.isEmpty() && !objetivo){
			Actual = Abiertos.getFirst();
			Abiertos.pollFirst();
			objetivo = Actual.estado.testObjetivo();
			if(!objetivo){
				if(!existsElto(Cerrados, Actual)){
					visitados++;
					Sucesores = expandir(Actual, fun);
					generados += Sucesores.size();

					Abiertos = ordenar(Abiertos, Sucesores);

					max_aux = Abiertos.size();
					if(max_aux > max_abiertos){
						max_abiertos = max_aux;
					}
					Cerrados.addLast(Actual);
				}
			}
		}
		System.out.println("Visitados: " + visitados);
		System.out.println("Generados: " + generados);
		System.out.println("Máximo de abiertos: " + max_abiertos);
		if(objetivo){
			return Actual;
		}else{
			return null;
		}
	}

	public static LinkedList<NodoBusqueda> expandir(NodoBusqueda nodo, int fun){
		LinkedList<NodoBusqueda> sucesores = new LinkedList<>();
		NodoBusqueda nuevo;

		for(int op = 0; op < Coche.N_OP; op++){
			if(nodo.estado.esValido(op)){
				nuevo = new NodoBusqueda(new Coche(nodo.estado.aplicaOperador(op).getAsientos()));
				nuevo.padre = nodo;
				nuevo.operador = op;
				nuevo.costeCamino = nodo.costeCamino + nodo.estado.coste(op);
				nuevo.profundidad = nodo.profundidad + 1;
				switch(fun){
					case 1:
						nuevo.valHeuristica = nuevo.estado.heuristica();
						break;
					case 2:
						nuevo.valHeuristica = nuevo.estado.heuristica() + nuevo.camino();
						break;
					default:
						nuevo.valHeuristica=0;
						break;
				}

				sucesores.addLast(nuevo);
			}
		}
		return sucesores;
	}

	public static LinkedList<NodoBusqueda> expandir(NodoBusqueda nodo){
		return expandir(nodo, 0);
	}

	public static String caminoToString(NodoBusqueda nodo){
		String str = "";

		if(nodo == null){
			str += "\nSIN SOLUCIÓN\n";
		}else if(nodo.padre == null){
			str += "\nDesde el inicio\n" + nodo.estado.toString();
		}else{
			str += caminoToString(nodo.padre) + "\n Operador: " + nodo.estado.operadorToString(nodo.operador) + "\n" + nodo.estado.toString();
		}

		return str;
	}

	public static boolean existsElto(LinkedList<NodoBusqueda> l, NodoBusqueda n){
		boolean res = false;

		if(!l.isEmpty()){
			for(NodoBusqueda elto: l){
				if(elto.estado.iguales(n.estado)){
					res = true;
					break;
				}
			}
		}

		return res;
	}

	public static LinkedList<NodoBusqueda> insertarOrdenado(LinkedList<NodoBusqueda> C, NodoBusqueda nuevo){
		LinkedList<NodoBusqueda> R = new LinkedList<>();
		NodoBusqueda nc;

		if(C.isEmpty()){
			R.addLast(nuevo);
		}else{
			nc = C.getFirst();
			while(!C.isEmpty() && nuevo.valHeuristica >= nc.valHeuristica){
				R.addLast(nc);
				C.pollFirst();
				if(!C.isEmpty()){
					nc = C.getFirst();
				}
			}
			R.addLast(nuevo);
			R.addAll(C);
		}
		return R;
	}

	public static LinkedList<NodoBusqueda> ordenar(LinkedList<NodoBusqueda> A, LinkedList<NodoBusqueda> B){
		while(!B.isEmpty()){
			A = insertarOrdenado(A, B.getFirst());
			B.pollFirst();
		}

		return A;
	}
}
