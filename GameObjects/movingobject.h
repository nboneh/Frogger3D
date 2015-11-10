#include "../Frogger3D.h"

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#endif

#ifndef FROG_H
#include "frog.h"
#endif

class MovingObject{

	public: 
	   	MovingObject(direction _movingDirection, float _speed, int _width);
		void update(double t);
		void draw();
		bool checkColisonWithFrog(Frog* frog);
		void setX(float _x);
		float getX();
		float getWidth();
		void reset();
	protected:
		virtual void drawAfterSetup() =0;
		float x, speed;
		int endX, startX, width;
		direction movingDirection;
	private:
		bool detectColision(Frog* frog, float objectX);

};