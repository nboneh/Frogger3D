#include "truck.h"

Truck::Truck(): MovingObject(left, 1.5f, 2){
} 

void Truck::drawAfterSetup(){
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
    glVertex3f(0,.01, 1);
    glVertex3f(2,.01, 1);
    glVertex3f(2,.01, 0);
    glEnd();
}