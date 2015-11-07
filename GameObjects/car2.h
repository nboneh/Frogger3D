#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Car2 : public MovingObject{
	public:
		Car2(float spawnX);
	protected:
		void drawAfterSetup();

};