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
	   	virtual void update(double t);
		void draw();
		virtual bool checkColisonWithFrog(Frog* frog);
		void setX(float _x);
		float getX();
		float getWidth();
	protected:
		virtual void drawAfterSetup() =0;
		float x, speed;
		int endX, startX, width;
		direction movingDirection;
		float move;
	    virtual bool detectColision(Frog* frog, float objectX);

};