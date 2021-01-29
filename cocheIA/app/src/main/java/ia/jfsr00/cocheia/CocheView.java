package ia.jfsr00.cocheia;

import android.content.Context;
import android.graphics.*;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class CocheView extends SurfaceView {
	private Bitmap bmp;
	public CocheView(Context context) {
		super(context);
		bmp = BitmapFactory.decodeResource(getResources(), R.drawable.coche);
	}

	@Override
	protected void onDraw(Canvas canvas) {
		canvas.drawColor(Color.BLACK);
		canvas.drawBitmap(bmp, 10, 10, null);
	}
}
