#include "movingobject.h"

int WRAP_AROUND_WIDTH = 2;

MovingObject::MovingObject(direction _movingDirection, float _speed, int _width){
	movingDirection = _movingDirection;
	speed = _speed;
	width = _width;
	if(movingDirection == right){
			x = -width;
			startX = 0;
			endX = ROW_WIDTH + WRAP_AROUND_WIDTH  ;
	} else if (movingDirection == left){
			x =  ROW_WIDTH + width ;
			startX = ROW_WIDTH - width ;
			endX = -WRAP_AROUND_WIDTH - width;
	}
	
}

void MovingObject::update(double t){
	float move = t * speed;
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

direction MovingObject::getMovingDirection(){
	return movingDirection;
}

float MovingObject::getX(){
	return x;
}

void MovingObject::checkColisonWithFrog(Frog* frog){

}

void MovingObject::reset(){
	x = startX;
} 


