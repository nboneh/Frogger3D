#include "../Frogger3D.h"

#ifndef FROG_H
#define FROG_H
#endif

class Frog{
	float spawnX, spawnY, deathCounter;
	int  lives, farthestY;
	float x, y, totalMove, respawnRateX, respawnRateY;
	direction facingDirection,spawnDirection;
	deathType typeOfDeath;
	frogState state;
	bool decreaseLife;
	public:
		Frog( float _spawnX, float _spawnY, direction _spawnDirection);
		void update(double t);
		void inputDirection(direction moveDirection);
		void draw();
		void setX(float _x);
		void setY(float _y);
		float getY();
		float getX();
		void die(deathType _typeOfDeath);
		void stopMovement();
		bool movingVertically();
		bool isRespawning();
		void respawn();
		int getLives();
		void resetLives();
	private:
		void drawDeath();
		void drawSkull();
		void drawFrog();
		void drawJumpingFrog();
};
