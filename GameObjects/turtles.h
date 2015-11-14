#include "../Frogger3D.h"

#ifndef WATEROBJECT_H
#include "waterobject.h"
#endif

class Turtles : public WaterObject{
	public:
		Turtles(float speed, int numOfTurtles);
	protected:
		void drawAfterSetup();
	private:
		void drawTurtle();
		void drawSubmergedTurtle1();
		void drawSubmergedTurtle2();
};