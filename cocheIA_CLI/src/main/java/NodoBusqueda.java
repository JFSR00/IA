public class NodoBusqueda {
	public Coche estado;
	public int operador, costeCamino, profundidad, valHeuristica;
	public NodoBusqueda padre;

	public NodoBusqueda(NodoBusqueda n){
		estado = n.estado;
		operador = n.operador;
		costeCamino = n.costeCamino;
		profundidad = n.profundidad;
		valHeuristica = n.valHeuristica;
		padre = n.padre;
	}

	public NodoBusqueda(Coche coche){
		estado = coche;
		padre = null;
	}

	public NodoBusqueda(){
		this(new Coche());
	}

	// Profundidad del nodo
	public int camino(){
		return profundidad;
	}
}