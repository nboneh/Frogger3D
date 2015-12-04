#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

class Car4 : public MovingObject{
	bool playSpeeding;
	public:
		Car4();
	protected:
		void drawAfterSetup();
		virtual void update(double t);

};