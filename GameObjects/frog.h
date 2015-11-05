#include "../Frogger3D.h"

class Frog{
	float x, y, destx, desty;
	direction facingDirection;
	bool moving;
	public: 
		Frog( float spawnX, float spawnY, direction spawnDirection);
		void update(double t);
		void inputDirection(direction moveDirection);
		void draw();
		void setX(float _x);
		void setY(float _y);
		float getY();
		float getX();
		int getWidth();
		void stopMovement();
	private:
		void drawFrog();
		void drawJumpingFrog();
};