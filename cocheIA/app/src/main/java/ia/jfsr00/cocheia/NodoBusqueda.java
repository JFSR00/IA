package ia.jfsr00.cocheia;

public class NodoBusqueda {
	public Coche estado;
	public int operador, costeCamino, profundidad, valHeuristica;
	public NodoBusqueda padre;

	public NodoBusqueda(Coche coche){
		estado = coche;
		padre = null;
	}

	public NodoBusqueda(){
		this(new Coche());
	}

}