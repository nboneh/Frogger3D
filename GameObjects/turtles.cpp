#include "turtles.h"

Turtles::Turtles(float _speed, int numOfTurtles):WaterObject( left, _speed,  numOfTurtles){

}

void Turtles::drawAfterSetup(){
	glPushMatrix();
	for(int i = 0; i < width; i++){
		drawTurtle();
		glTranslatef(1,0,0);
	}
	glPopMatrix();
}

void Turtles::drawTurtle(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(.2,.5, .2);
    glVertex3f(.2,.5, .8);
    glVertex3f(.8,.5, .8);
    glVertex3f(.8,.5, .2);
    glEnd();
}