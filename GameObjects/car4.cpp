#include "car4.h"

Car4::Car4(): MovingObject(right, 3, 1){
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