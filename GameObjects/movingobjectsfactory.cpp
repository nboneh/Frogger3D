#include "movingobjectsfactory.h"
#include "car1.h"
#include "car2.h"
#include "car3.h"
#include "car4.h"
#include "truck.h"
#include "log.h"
#include "turtles.h"

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
	else if(type == "LongLog")
		movingObject = new Log(3,6);
	else if(type == "AverageLog")
		movingObject = new Log(2,4);
	else if(type == "ShortLog")
		movingObject = new Log(1.2,3);
	else if(type == "ThreeTurtles")
		movingObject = new Turtles(2.5,3,false);
	else if(type == "TwoTurtles")
		movingObject = new Turtles(2,2, false);
	else if(type == "SubmergingThreeTurtles")
		movingObject = new Turtles(2.5,3,true);
	else if(type == "SubmergingTwoTurtles")
		movingObject = new Turtles(2,2, true);
		

	return movingObject;
}