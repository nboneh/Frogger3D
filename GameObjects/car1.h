#include "../Frogger3D.h"

#ifndef CAR_H
#include "car.h"
#endif

class Car1 : public Car{
	public:
		Car1();
	protected:
		void drawAfterSetup();

};