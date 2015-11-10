#include "movingobject.h"

int WRAP_AROUND_WIDTH = 2;

MovingObject::MovingObject(direction _movingDirection, float _speed, int _width){
	movingDirection = _movingDirection;
	speed = _speed;
	width = _width;
	x =  ROW_WIDTH + width ;
	if(movingDirection == right){
			startX = 0;
			endX = ROW_WIDTH + WRAP_AROUND_WIDTH  ;
	} else if (movingDirection == left){
			startX = ROW_WIDTH - width ;
			endX = -WRAP_AROUND_WIDTH - width;
	}
	
}

void MovingObject::update(double t){
	 move = t * speed;
	if(movingDirection == right){
			x += move;
			if(x >= endX)
				reset();
	} else if (movingDirection == left){
			x -= move;
			if( x < endX)
				reset();
	}

}
void MovingObject::draw(){
	glPushMatrix();
	glTranslatef(x , 0, 0);
	drawAfterSetup();
	glPopMatrix();

	//Drawing wrap around
	if(movingDirection == right && x >=  (endX - width)){
		glPushMatrix();
		glTranslatef(x- ROW_WIDTH- WRAP_AROUND_WIDTH,0,0);
		drawAfterSetup();
		glPopMatrix();
	}	

	else if(movingDirection == left && x <= -WRAP_AROUND_WIDTH){
		glPushMatrix();
		glTranslatef(x + ROW_WIDTH+ WRAP_AROUND_WIDTH,0,0);
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
	if(movingDirection == right && x >=  (endX - width))
		return detectColision(frog, x- ROW_WIDTH- WRAP_AROUND_WIDTH);

	else if(movingDirection == left && x <= -WRAP_AROUND_WIDTH)
		return detectColision(frog, x + ROW_WIDTH+ WRAP_AROUND_WIDTH);

	return false; 
}

void MovingObject::reset(){
	x = startX;
} 

bool MovingObject::detectColision(Frog* frog, float objectX){
	return frog->getX() +1 >=  objectX && objectX + width >= frog->getX();
}


