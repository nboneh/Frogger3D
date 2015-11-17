#include "../Frogger3D.h"

#ifndef WATEROBJECT_H
#include "waterobject.h"
#endif

class Turtles : public WaterObject{
	int frame ;
	float ticFrameCounter;
	bool submergingTurtles,currentlySubmerging, hittingFrog, descendSubmergeFrames;
	int frameCountTillSubmerging;


	public:
		Turtles(float speed, int numOfTurtles);
	 	void update(double t);
	protected:
		void drawAfterSetup();
		virtual bool checkColisonWithFrog(Frog* frog);
	private:
		void drawTurtle();

		void drawTurtleSwimming1();
		void drawTurtleSwimming2();

		void drawSubmergedTurtle1();
		void drawSubmergedTurtle2();
};