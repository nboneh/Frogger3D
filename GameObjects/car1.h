#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Car1 : public MovingObject{
	public:
		Car1();
	protected:
		void drawAfterSetup();

};