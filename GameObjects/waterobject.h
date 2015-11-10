#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif


class WaterObject : public MovingObject{
	public:
		WaterObject(direction _movingDirection, float _speed, int _width);
		virtual bool checkColisonWithFrog(Frog* frog);
};