#include "movingobjectsfactory.h"
#include "car1.h"

MovingObject* getMovingObject(std::string type){
	MovingObject *movingObject = NULL;
	if(type == "Car1")
		movingObject = new Car1();
	return movingObject;
}