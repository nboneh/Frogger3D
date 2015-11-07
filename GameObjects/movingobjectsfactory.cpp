#include "movingobjectsfactory.h"
#include "car1.h"
#include "car2.h"

MovingObject* getMovingObject(std::string type){
	MovingObject *movingObject = NULL;
	if(type == "Car1")
		movingObject = new Car1();
	else if(type == "Car2")
		movingObject = new Car2();
	return movingObject;
}