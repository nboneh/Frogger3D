#include "../Frogger3D.h"

class Frog{
	int xBoundary, yBoundary;
	float x, y, destx, desty;
	direction facingDirection;
	bool moving;
	public: 
		Frog();
		void init(int _xBoundary, int _yBoundary, float spawnX, float spawnY, direction spawnDirection);
		void update(double t);
		void inputDirection(direction moveDirection);
		void draw();
		float getY();
		float getX();
	private:
		void drawFrog();
		void drawJumpingFrog();
};