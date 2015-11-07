#include "frog.h"

Frog::Frog(float _spawnX, float _spawnY, direction _spawnDirection){
	spawnX = _spawnX;
	spawnY = _spawnY;
	spawnDirection = _spawnDirection;
	reset();
}

void Frog::reset(){
	x = spawnX;
	y = spawnY;
	facingDirection = spawnDirection;
	moving = false;
	dying = false;
}

void Frog::update(double t){
	if(moving){
		float move = t*3;
		switch(facingDirection){
			case up:
			  y -= move;
			  if(y <= desty){
					y = desty;
					moving = false;
				}
			  break;
			case down:
				y += move;
				if(y >= desty){
					y = desty;
					moving = false;
				}
				break;
			case left:
				x -= move;
				if(x <= destx){
					x = destx;
					moving = false;
				}
				break;
			case right:
				x += move;
				if(x >= destx){
					x = destx;
					moving = false;
				}
				break;
		}

	}
}

void Frog::inputDirection(direction moveDirection){
	if(moving)
		return;
	facingDirection = moveDirection;
	moving = true; 
	switch(facingDirection){
		case up:
			desty = y - 1;
			break;
		case down:
			desty = y+1;
			break;
		case left:
			destx = x -1;
			break;
		case right:
			destx = x + 1;
			break;
	}

}

void Frog::draw(){
	glPushMatrix();
	glTranslatef(x , 0, y);
	switch(facingDirection){
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
	glColor3f(0,1,0);
	if(moving)
		drawJumpingFrog();
	else 
		drawFrog();
	glPopMatrix();
}

void Frog::drawFrog(){
   glBegin(GL_POLYGON);
   glVertex3f(0,.01, 0);
   glVertex3f(.5,.01, -1);
   glVertex3f(1,.01, 0);
   glEnd();
}

void Frog::kill(deathType _typeOfDeath){
	typeOfDeath = _typeOfDeath;

	dying = true; 
}

float Frog::getY(){
	return y;
}

float Frog::getX(){
	return x;
}

void Frog::setX(float _x){
	x = _x;
	moving = false;
}

void Frog::setY(float _y){
	y = _y;
	moving = false;
}

void Frog::stopMovement(){
	moving = false;
}

void Frog::drawJumpingFrog(){
   glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
  	glVertex3f(.5,.01, -1.5);
   glVertex3f(1,.01, 0);
   glEnd();
}
