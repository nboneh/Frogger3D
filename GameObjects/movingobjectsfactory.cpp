#include "movingobjectsfactory.h"
#include "car1.h"
#include "car2.h"
#include "car3.h"
#include "car4.h"
#include "truck.h"

MovingObject* getMovingObject(std::string type){
	MovingObject *movingObject = NULL;
	if(type == "Car1")
		movingObject = new Car1();
	else if(type == "Car2")
		movingObject = new Car2();
	else if(type == "Car3")
		movingObject = new Car3();
	else if(type == "Car4")
		movingObject = new Car4();
	else if(type == "Truck")
		movingObject = new Truck();
	return movingObject;
}