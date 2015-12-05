#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#include "movingobject.h"
#endif

#ifndef CAR_H
#define CAR_H
#endif


class Car : public MovingObject{
	float wheelangle;
	public:
		Car(direction _movingDirection, float _speed, int _width);
		virtual void update(double t);
	protected:
		void drawWheels();
		void drawWheels(float distanceBetweenWheels);
		void drawStationaryWheel();
	private:
		 void drawWheel();
};