package ia.jfsr00.cocheia;

import android.os.Parcelable;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ExpandableListAdapter;
import android.widget.ExpandableListView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

	Button[] asientos = new Button[Coche.INICIAL.length];
	Button reset;

	ExpandableListView menu;
	ExpandableListAdapter expandableListAdapter;
	List<String> expandableListTitle;
	HashMap<String, List<String>> expandableListDetail;

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		reset = findViewById(R.id.reset);

		menu = findViewById(R.id.lista_busqueda);
		expandableListDetail = ExpandableListDataPump.getData();
		expandableListTitle = new ArrayList<String>(expandableListDetail.keySet());
		expandableListAdapter = new CustomExpandableListAdapter(this, expandableListTitle, expandableListDetail);
		menu.setAdapter(expandableListAdapter);

		asientos[0] = findViewById(R.id.piloto);
		asientos[1] = findViewById(R.id.copiloto);
		asientos[2] = findViewById(R.id.ctrl_izq);
		asientos[3] = findViewById(R.id.ctrl_dch);
		asientos[4] = findViewById(R.id.tras_izq);
		asientos[5] = findViewById(R.id.tras_dch);

		for(int i = 0; i < Coche.INICIAL.length; i++){
			asientos[i].setText(Coche.asientoToString(Coche.INICIAL[i]));
		}
	}

	@Override
	protected void onResume(){
		super.onResume();

		menu.setOnChildClickListener(new ExpandableListView.OnChildClickListener() {
			@Override
			public boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
				switch(groupPosition){
					case 0:
						switch(childPosition){
							case 0:
								printCamino(Busqueda.anchura());
								break;
							case 1:
								printCamino(Busqueda.anchuraLim(4));
								break;
							case 2:
								printCamino(Busqueda.anchuraEstRep());
								break;
							default:
								break;
						}
						break;
					case 1:
						printCamino(Busqueda.heuristica(2));
						break;
					case 2:
						switch(childPosition){
							case 0:
								printCamino(Busqueda.profundidad());
								break;
							case 1:
								printCamino(Busqueda.profundidadLim(4));
								break;
							case 2:
								printCamino(Busqueda.profundidadEstRep());
								break;
							default:
								break;
						}
						break;
					default:
						break;
				}
				return false;
			}
		});

		reset.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				reset();
			}
		});
	}

	@Override
	protected void onDestroy(){
		super.onDestroy();
	}

	private void printCoche(int[] c){
		for(int i = 0; i < 6; i++){
			asientos[i].setText(Coche.asientoToString(c[i]));
		}
	}

	private void reset(){
		printCoche(Coche.INICIAL);
	}

	private void printCamino(final NodoBusqueda nodo){
		LinkedList<NodoBusqueda> camino = makeCamino(nodo);
		while(!camino.isEmpty()){
			printCoche(camino.getFirst().estado.getAsientos());
			camino.pollFirst();
			try{
				Thread.sleep(300);
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}

	private LinkedList<NodoBusqueda> makeCamino(NodoBusqueda nodo){
		LinkedList<NodoBusqueda> res = new LinkedList<>();

		res = makeCamino(res, nodo);

		return res;
	}

	private LinkedList<NodoBusqueda> makeCamino(LinkedList<NodoBusqueda> l, NodoBusqueda n){
		if(n.padre == null){
			l.add(n);
		}else{
			l = makeCamino(l, n.padre);
			l.addLast(n);
		}
		return l;
	}
}