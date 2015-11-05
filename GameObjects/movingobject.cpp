#include "movingobject.h"


MovingObject::MovingObject(){
	stopped = false;
}

void MovingObject::init(float _spawnX, float _spawnY, direction _movingDirection){
	movingDirection = _movingDirection;
	spawnX = _spawnX;
	spawnY = _spawnY;
	x = spawnX;
	y = spawnY;
}

void MovingObject::update(double t){
	if(stopped)
		return;
	float move = t * speed;
	switch(movingDirection){
		case up:
			y += move;
			break;
		case down:
			y -= move;
			break;
		case right:
			x += move;
			break;
		case left:
			x -= move;
			break;
	}

}
void MovingObject::draw(){
	if(stopped)
		return;
	glPushMatrix();
	glTranslatef(x , 0, -y);
	switch(movingDirection){
		case up:
			break;
		case down:
			glRotatef(180, 0,1,0);
			glTranslatef(-1,0,1);
			break;
		case left:
			glRotatef(90, 0,1,0);
			glTranslatef(0,0,1);
			break;
		case right:
			glRotatef(270, 0,1,0);
			glTranslatef(-1,0,0);
			break;
	}
	drawAfterSetup();
	glPopMatrix();

}

void MovingObject::stop(){
	stopped = true;
}

bool MovingObject::isStopped(){
	return stopped;
}

void MovingObject::reset(){
	x = spawnX;
	y = spawnY;
	stopped = false;
} 
