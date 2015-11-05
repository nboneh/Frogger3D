#include "car1.h"

Car1::Car1() : MovingObject(){
	width = 1;
} 
void Car1::drawAfterSetup(){
	glBegin(GL_POLYGON);
   glVertex3f(0,.01, 0);
   glVertex3f(.5,.01, -1);
   glVertex3f(1,.01, 0);
   glEnd();
}