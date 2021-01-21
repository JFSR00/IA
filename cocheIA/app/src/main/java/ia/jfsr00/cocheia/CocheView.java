package ia.jfsr00.cocheia;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Rect;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class CocheView extends SurfaceView implements SurfaceHolder {
	public CocheView(Context context){
		super(context);
	}

	@Override
	public void addCallback(Callback callback){

	}

	@Override
	public void removeCallback(Callback callback){

	}

	@Override
	public boolean isCreating(){
		return false;
	}

	@Override
	public void setType(int i){

	}

	@Override
	public void setFixedSize(int i, int i1){

	}

	@Override
	public void setSizeFromLayout(){

	}

	@Override
	public void setFormat(int i){

	}

	@Override
	public Canvas lockCanvas(){
		return null;
	}

	@Override
	public Canvas lockCanvas(Rect rect){
		return null;
	}

	@Override
	public void unlockCanvasAndPost(Canvas canvas){

	}

	@Override
	public Rect getSurfaceFrame(){
		return null;
	}

	@Override
	public Surface getSurface(){
		return null;
	}
}
