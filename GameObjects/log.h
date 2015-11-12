#include "../Frogger3D.h"

#ifndef WATEROBJECT_H
#include "waterobject.h"
#endif

class Log : public WaterObject{
	public:
		Log(float speed, int width);
	protected:
		void drawAfterSetup();
};