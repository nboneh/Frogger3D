#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

#ifndef WATEROBJECT_H
#define WATEROBJECT_H
#endif


class WaterObject : public MovingObject{
	public:
		WaterObject(direction _movingDirection, float _speed, int _width);
		virtual bool checkColisonWithFrog(Frog* frog);
	protected:
		virtual bool detectColision(Frog* frog, float objectX);
};