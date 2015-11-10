#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Truck : public MovingObject{
	public:
		Truck();
	protected:
		void drawAfterSetup();

};