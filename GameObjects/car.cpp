#include "car.h"

Car::Car(direction _movingDirection, float _speed, int _width) : MovingObject( _movingDirection,  _speed,  _width){
	wheelangle = 0;
} 

void Car::update(double t){
	MovingObject::update(t);
	wheelangle += move * 120;
	if(wheelangle >= 360){
		wheelangle = fmod(wheelangle, 360.0);
	}
}

void Car::drawWheel(){
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(.15,.21,0);
	if(movingDirection == left)
	    glRotatef(wheelangle, 0,0,1);
	else 
		glRotatef(-wheelangle, 0,0,1);
	glScalef(.4,.4,.2);
	drawCylinder(WHEEL_TREAD, WHEEL);
	glPopMatrix();
}

void Car::drawWheels(){
	//Top right wheel
	drawWheel();

	//Bottom right wheel
	glPushMatrix();
	glTranslatef(0,0,0.8);
	drawWheel();
	glPopMatrix();

	//Top Left Wheel
	glPushMatrix();
	glTranslatef(width-.3,0,0);
	drawWheel();
	glPopMatrix();

	//Bottom Left Wheel
	glPushMatrix();
	glTranslatef(0,0,0.8);
	glTranslatef(width-.3,0,0);
	drawWheel();
	glPopMatrix();

}