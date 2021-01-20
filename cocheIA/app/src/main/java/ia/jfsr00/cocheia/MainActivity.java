package ia.jfsr00.cocheia;

import android.text.method.ScrollingMovementMethod;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

	TextView scr;

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		scr = findViewById(R.id.pantalla);

		scr.setMovementMethod(new ScrollingMovementMethod());
	}

	@Override
	protected void onResume(){
		super.onResume();

		scr.setText(Busqueda.caminoToString(Busqueda.anchura()));

	}

	@Override
	protected void onDestroy(){
		super.onDestroy();
	}
}