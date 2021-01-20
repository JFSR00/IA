package ia.jfsr00.cocheia;

import java.util.Arrays;

public class Coche {
//###############################| Constantes |###########################################
	public static final int ABAT_COP = 0;
	public static final int ABAT_CTRL_DCH = 1;
	public static final int ABAT_CTRL_IZQ = 2;
	public static final int ABAT_TRAS_DCH = 3;
	public static final int ABAT_TRAS_IZQ = 4;
	public static final int DESABAT_COP = 5;
	public static final int DESABAT_CTRL_DCH = 6;
	public static final int DESABAT_CTRL_IZQ = 7;
	public static final int DESABAT_TRAS_DCH = 8;
	public static final int DESABAT_TRAS_IZQ = 9;
	public static final int DESP_ATRAS_COP = 10;
	public static final int DESP_ATRAS_PIL = 11;
	public static final int DESP_DELAN_COP = 12;
	public static final int DESP_DELAN_PIL = 13;

	public static final int N_OP = 14;

	public static final int NORMAL = 0;
	public static final int ABATIDO = 1;
	public static final int DESPLAZADO = 2;

	public static final int PILOTO = 0;
	public static final int COPILOTO = 1;
	public static final int CTRL_IZQ = 2;
	public static final int CTRL_DCH = 3;
	public static final int TRAS_IZQ = 4;
	public static final int TRAS_DCH = 5;

//###############################| Estados |###########################################
	private int asientos[] = new int[6];

	public static final int[] INICIAL = {
			DESPLAZADO, DESPLAZADO,
			NORMAL, NORMAL,
			ABATIDO, ABATIDO};
	public static final int[] FINAL = {
			NORMAL, NORMAL,
			ABATIDO, ABATIDO,
			NORMAL, NORMAL};

//###############################| Métodos |###########################################

	// Constructor de objeto Coche a partir de una distribución de asientos dada.
	public Coche(int est[]){
		asientos = est;
	}

	// Constructor de objeto Coche por defecto.
	public Coche(){
		this(INICIAL);
	}

	// Devuelve el coste de aplicar el operador.
	public int coste(int op){
		int val = 0;

		if(op >= 0 && op <= 9){
			val = 2;
		}else if(op >= 10 && op <= 13){
			val = 1;
		}

		return val;
	}

	// Devuelve el contenido de un objeto Coche en forma de String.
	public String toString(){
		String str;

		str = asientoToString(asientos[0]) + "\t|\t" + asientoToString(asientos[1]);
		str += "\n--------------------";
		str += "\n" + asientoToString(asientos[2]) + "\t|\t" + asientoToString(asientos[3]);
		str += "\n--------------------";
		str += "\n" + asientoToString(asientos[4]) + "\t|\t" + asientoToString(asientos[5]);

		return str;
	}

	// Devuelve el nombre de cada operador.
	public String operadorToString(int op){
		String str;
		switch(op){
			case ABAT_COP:
				str = "ABAT_COP";
				break;
			case ABAT_CTRL_DCH:
				str = "ABAT_CTRL_DCH";
				break;
			case ABAT_CTRL_IZQ:
				str = "ABAT_CTRL_IZQ";
				break;
			case ABAT_TRAS_DCH:
				str = "ABAT_TRAS_DCH";
				break;
			case ABAT_TRAS_IZQ:
				str = "ABAT_TRAS_IZQ";
				break;
			case DESABAT_COP:
				str = "DESABAT_COP";
				break;
			case DESABAT_CTRL_DCH:
				str = "DESABAT_CTRL_DCH";
				break;
			case DESABAT_CTRL_IZQ:
				str = "DESABAT_CTRL_IZQ";
				break;
			case DESABAT_TRAS_DCH:
				str = "DESABAT_TRAS_DCH";
				break;
			case DESABAT_TRAS_IZQ:
				str = "DESABAT_TRAS_IZQ";
				break;
			case DESP_ATRAS_COP:
				str = "DESP_ATRAS_COP";
				break;
			case DESP_ATRAS_PIL:
				str = "DESP_ATRAS_PIL";
				break;
			case DESP_DELAN_COP:
				str = "DESP_DELAN_COP";
				break;
			case DESP_DELAN_PIL:
				str = "DESP_DELAN_PIL";
				break;
			default:
				str = "";
				break;
		}
		return str;
	}

	// Devuelve el nombre de cada estado posible de un asiento.
	public String asientoToString(int asi){
		String str;
		switch(asi){
			case NORMAL:
				str = "NORMAL";
				break;
			case ABATIDO:
				str = "ABATIDO";
				break;
			case DESPLAZADO:
				str = "DESPLAZADO";
				break;
			default:
				str = "";
				break;
		}
		return str;
	}

	// Comprueba si es posible aplicar un operador a una configuración determinada para el coche.
	// Devuelve true si el movimiento es válido y false en otro caso.
	public boolean esValido(int op){
		boolean res = false;

		switch(op){
			case ABAT_COP:
				if(asientos[COPILOTO] == NORMAL && asientos[CTRL_DCH] == ABATIDO){
					res = true;
				}
				break;
			case ABAT_CTRL_DCH:
				if(asientos[CTRL_DCH] == NORMAL){
					res = true;
				}
				break;
			case ABAT_CTRL_IZQ:
				if(asientos[CTRL_IZQ] == NORMAL){
					res = true;
				}
				break;
			case ABAT_TRAS_DCH:
				if(asientos[TRAS_DCH] == NORMAL){
					res = true;
				}
				break;
			case ABAT_TRAS_IZQ:
				if(asientos[TRAS_IZQ] == NORMAL){
					res = true;
				}
				break;
			case DESABAT_COP:
				if(asientos[COPILOTO] == ABATIDO){
					res = true;
				}
				break;
			case DESABAT_CTRL_DCH:
				if(asientos[CTRL_DCH] == ABATIDO){
					res = true;
				}
				break;
			case DESABAT_CTRL_IZQ:
				if(asientos[CTRL_IZQ] == ABATIDO){
					res = true;
				}
				break;
			case DESABAT_TRAS_DCH:
				if(asientos[TRAS_DCH] == ABATIDO){
					res = true;
				}
				break;
			case DESABAT_TRAS_IZQ:
				if(asientos[TRAS_IZQ] == ABATIDO){
					res = true;
				}
				break;
			case DESP_ATRAS_COP:
				if(asientos[COPILOTO] == NORMAL && asientos[CTRL_DCH] == NORMAL){
					res = true;
				}
				break;
			case DESP_ATRAS_PIL:
				if(asientos[PILOTO] == NORMAL && asientos[CTRL_IZQ] == NORMAL){
					res = true;
				}
				break;
			case DESP_DELAN_COP:
				if(asientos[COPILOTO] == DESPLAZADO && asientos[CTRL_DCH] == NORMAL){
					res = true;
				}
				break;
			case DESP_DELAN_PIL:
				if(asientos[PILOTO] == DESPLAZADO && asientos[CTRL_IZQ] == NORMAL){
					res = true;
				}
				break;
			default:
				break;
		}

		return res;
	}

	// Aplica un operador a una configuración concreta del puzle.
	//Devuelve la nueva configuración del tablero tras el movimiento.
	public Coche aplicaOperador(int op){
		int copia[] = asientos;

		if(esValido(op)){
			switch(op){
				case ABAT_COP:
					copia[COPILOTO] = ABATIDO;
					break;
				case ABAT_CTRL_DCH:
					copia[CTRL_DCH] = ABATIDO;
					break;
				case ABAT_CTRL_IZQ:
					copia[CTRL_IZQ] = ABATIDO;
					break;
				case ABAT_TRAS_DCH:
					copia[TRAS_DCH] = ABATIDO;
					break;
				case ABAT_TRAS_IZQ:
					copia[TRAS_DCH] = ABATIDO;
					break;
				case DESABAT_COP:
					copia[COPILOTO] = NORMAL;
					break;
				case DESABAT_CTRL_DCH:
					copia[CTRL_DCH] = NORMAL;
					break;
				case DESABAT_CTRL_IZQ:
					copia[CTRL_IZQ] = NORMAL;
					break;
				case DESABAT_TRAS_DCH:
					copia[TRAS_DCH] = NORMAL;
					break;
				case DESABAT_TRAS_IZQ:
					copia[TRAS_IZQ] = NORMAL;
					break;
				case DESP_ATRAS_COP:
					copia[COPILOTO] = DESPLAZADO;
					break;
				case DESP_ATRAS_PIL:
					copia[PILOTO] = DESPLAZADO;
					break;
				case DESP_DELAN_COP:
					copia[COPILOTO] = NORMAL;
					break;
				case DESP_DELAN_PIL:
					copia[PILOTO] = NORMAL;
					break;
				default:
					break;
			}
		}

		return new Coche(copia);
	}

	// Devuelve distribución de asientos de un objeto Coche.
	public int[] getAsientos(){
		return asientos;
	}

	// Devuelve true si dos estados son iguales y false en caso contrario.
	public boolean iguales(Coche c){
		return (Arrays.equals(asientos, c.getAsientos()));
	}

	// Devuelve true si un estado es igual al estado objetivo, false en caso contrario.
	public boolean testObjetivo(){
		return iguales(new Coche(FINAL));
	}

}
