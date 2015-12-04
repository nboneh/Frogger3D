#include "car3.h"

Car3::Car3(): Car(left, 1.75f, 1){
} 

void Car3::drawAfterSetup(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(0,.01, 0);
    glVertex3f(0,.01, 1);
    glVertex3f(1,.01, 1);
    glVertex3f(1,.01, 0);
    glEnd();

    Car::drawWheels();
}