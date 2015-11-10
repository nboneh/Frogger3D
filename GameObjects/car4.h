#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Car4 : public MovingObject{
	public:
		Car4();
	protected:
		void drawAfterSetup();

};