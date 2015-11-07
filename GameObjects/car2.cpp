#include "car2.h"

Car2::Car2(): MovingObject(right, (3/2.0), 1){
} 

void Car2::drawAfterSetup(){
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
    glVertex3f(0,.01, 1);
    glVertex3f(1,.01, 1);
    glVertex3f(1,.01, 0);
    glEnd();
}