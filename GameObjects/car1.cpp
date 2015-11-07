#include "car1.h"

Car1::Car1(): MovingObject(left, (3/2.0), 1){
} 

void Car1::drawAfterSetup(){
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
    glVertex3f(0,.01, 1);
    glVertex3f(1,.01, 1);
    glVertex3f(1,.01, 0);
    glEnd();
}