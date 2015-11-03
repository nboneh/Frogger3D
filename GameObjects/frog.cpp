#include "frog.h"

Frog::Frog(){

}
void Frog::init(int _xBoundary, int _yBoundary, float spawnX, float spawnY, direction spawnDirection){
	xBoundary = _xBoundary;
	yBoundary = _yBoundary;
	x = spawnX;
	y = spawnY;
	facingDirection = spawnDirection;
	moving = false;
}

void Frog::update(double t){
	if(moving){
		float move = t*3;
		switch(facingDirection){
			case up:
			  y += move;
			  if(y >= desty){
			  	y = desty;
			  	moving = false;
			  }
			  break;
			case down:
				y -= move;
				if(y <= desty){
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
	if(facingDirection != moveDirection){
		facingDirection = moveDirection;
		return;
	}
	moving = true; 
	switch(facingDirection){
		case up:
			desty = y + 1;
			if(desty >= yBoundary)
				moving = false;
			break;
		case down:
			desty = y -1;
			if(desty < 0)
				moving = false;
			break;
		case left:
			destx = x -1;
			if(destx < 0)
				moving =false;
			break;
		case right:
			destx = x + 1;
			if(destx >= xBoundary)
				moving = false;
			break;
	}

}

void Frog::draw(){
	glPushMatrix();
	glTranslatef(x -xBoundary/2, 0, -y);
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

float Frog::getY(){
	return y;
}

float Frog::getX(){
	return x;
}

void Frog::drawJumpingFrog(){
   glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
  	glVertex3f(.5,.01, -1.5);
   glVertex3f(1,.01, 0);
   glEnd();

}