#include "car4.h"

Car4::Car4(): MovingObject(right, 5, 1){
	playSpeeding = false;
} 

void Car4::drawAfterSetup(){
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
    glVertex3f(0,.01, 1);
    glVertex3f(1,.01, 1);
    glVertex3f(1,.01, 0);
    glEnd();
}

void Car4::update(double t){
	MovingObject::update(t);
	if(FROG_PASS_CARS)
		return;
	
	if(playSpeeding && x >= 0){
		PlaySound("speedby.wav");
		playSpeeding = false;
	} 
	else if (x < 0){
		playSpeeding = true;
	}	
}