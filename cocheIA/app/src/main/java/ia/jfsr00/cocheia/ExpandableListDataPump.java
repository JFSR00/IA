package ia.jfsr00.cocheia;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class ExpandableListDataPump {
	public static HashMap<String, List<String>> getData() {
		HashMap<String, List<String>> expandableListDetail = new HashMap<String, List<String>>();

		List<String> anchura = new ArrayList<String>();
		anchura.add("Anchura");
		anchura.add("Anchura con límite 4");
		anchura.add("Anchura con estados repetidos");

		List<String> profundidad = new ArrayList<String>();
		profundidad.add("Profundidad");
		profundidad.add("Profundidad con límite 4");
		profundidad.add("Profundidad con estados repetidos");

		List<String> heuristica = new ArrayList<String>();
		heuristica.add("Heurística");


		expandableListDetail.put("ANCHURA", anchura);
		expandableListDetail.put("PROFUNDIDAD", profundidad);
		expandableListDetail.put("HEURÍSTICA", heuristica);
		return expandableListDetail;
	}
}
