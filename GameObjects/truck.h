#include "../Frogger3D.h"

#ifndef CAR_H
#include "car.h"
#endif

class Truck : public Car{
	public:
		Truck();
	protected:
		void drawAfterSetup();

};