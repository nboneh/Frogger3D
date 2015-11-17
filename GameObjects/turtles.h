#include "../Frogger3D.h"

#ifndef WATEROBJECT_H
#include "waterobject.h"
#endif

class Turtles : public WaterObject{
	int frame ;
	float ticFrameCounter;
	bool submergingTurtles,currentlySubmerging, hittingFrog, currentlyAscending;
	float submergingCounter;
	float elevation ;


	public:
		Turtles(float speed, int numOfTurtles, bool _submergingTurtles);
	 	void update(double t);
	protected:
		void drawAfterSetup();
		virtual bool checkColisonWithFrog(Frog* frog);
	private:
		void drawTurtle();

		void drawTurtleSwimming1();
		void drawTurtleSwimming2();
};