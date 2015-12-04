#include "../Frogger3D.h"

#ifndef CAR_H
#include "car.h"
#endif

class Car4 : public Car{
	bool playSpeeding;
	public:
		Car4();
	protected:
		void drawAfterSetup();
		virtual void update(double t);

};