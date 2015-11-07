#include "../Frogger3D.h"

#ifndef FROG_H
#define FROG_H
#endif

class Frog{
	float spawnX, spawnY;
	float x, y, destx, desty;
	direction facingDirection,spawnDirection;
	deathType typeOfDeath;
	bool dying,moving;
	public: 
		Frog( float _spawnX, float _spawnY, direction _spawnDirection);
		void update(double t);
		void reset();
		void inputDirection(direction moveDirection);
		void draw();
		void setX(float _x);
		void setY(float _y);
		float getY();
		float getX();
		void kill(deathType _typeOfDeath);
		void stopMovement();
	private:
		void drawDeathFrame();
		void drawDeathFrame2();
		void drawDeathFrame3();
		void drawSkull();
		
		void drawFrog();
		void drawJumpingFrog();
};