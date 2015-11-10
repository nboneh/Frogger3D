#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Car3 : public MovingObject{
	public:
		Car3();
	protected:
		void drawAfterSetup();

};