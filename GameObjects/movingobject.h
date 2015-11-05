#include "../Frogger3D.h"
#include "frog.h"

class MovingObject{

	public: 
		MovingObject();
		void init(float _spawnX, float _spawnY, direction _movingDirection);
		void update(double t);
		void draw();
		void checkColisonWithFrog(Frog frog);
		void stop();
		bool isStopped();
		void reset();
	protected:
		virtual void drawAfterSetup();
		int width;
		float x, y, speed, spawnX, spawnY;
		direction movingDirection;
		bool stopped;

};