#include "movingobject.h"

int WRAP_AROUND_WIDTH = 2;

MovingObject::MovingObject(direction _movingDirection, float _speed, int _width){
	movingDirection = _movingDirection;
	speed = _speed;
	width = _width;
	x =  ROW_WIDTH - width/2.0 ;
	if(movingDirection == right){
			startX = -WRAP_AROUND_WIDTH;
			endX = ROW_WIDTH + WRAP_AROUND_WIDTH  ;
	} else if (movingDirection == left){
			startX =  ROW_WIDTH + WRAP_AROUND_WIDTH -width ;
			endX = -WRAP_AROUND_WIDTH - width;
	}
	
}

void MovingObject::update(double t){
	move = t * speed * (1+LEVEL*.4);
	if(movingDirection == right){
			x += move;
			if(x >= endX)
				x = startX + (x - endX);
	} else if (movingDirection == left){
			x -= move;
			if( x < endX)
				x = startX - (endX -x);
	}

}
void MovingObject::draw(){
	glPushMatrix();
	glTranslatef(x , 0, 0);
	drawAfterSetup();
	glPopMatrix();

	//Drawing wrap around
	if(movingDirection == right && (x+width) >= endX){
		glPushMatrix();
		glTranslatef(startX -(endX - x) ,0,0);
		drawAfterSetup();
		glPopMatrix();
	}	

	else if(movingDirection == left && (x-width) <= endX){
		glPushMatrix();
		glTranslatef(startX + (x - endX) ,0,0);
		drawAfterSetup();
		glPopMatrix();
	}




}

float MovingObject::getWidth(){
	return width;
}
void MovingObject::setX(float _x){
	x = _x;
}


float MovingObject::getX(){
	return x;
}

bool MovingObject::checkColisonWithFrog(Frog* frog){

	if(detectColision(frog, x))
		return true;
	
	//Check wrap around colision
	if(movingDirection == right && (x+width) >= endX)
		return detectColision(frog, startX -(endX - x));

	else if(movingDirection == left && (x-width) <= endX)
		return detectColision(frog, startX + (x - endX));

	return false; 
}


bool MovingObject::detectColision(Frog* frog, float objectX){
	return (frog->getX() +.8) >=  objectX && objectX + width >= (frog->getX()+.2);
}


