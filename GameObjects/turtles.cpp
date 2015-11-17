#include "turtles.h"

int TOTAL_FRAMES = 3;
float TIME_TILL_SUBMERGE = .3;
float FRAME_TIC = .2;
float sumbergeSpeed = 1.3;
float MIN_ELEVATION = -.8;


Turtles::Turtles(float _speed, int numOfTurtles, bool _submergingTurtles):WaterObject( left, _speed,  numOfTurtles){
	frame = 0;
	submergingTurtles = _submergingTurtles;
	currentlySubmerging = false;
	hittingFrog = false;
	ticFrameCounter = 0;
	submergingCounter = 0;
	elevation = 0;
}

void Turtles::drawAfterSetup(){
	glPushMatrix();
	glTranslatef(0,elevation,0);
	for(int i = 0; i < width; i++){
		switch(frame){
			case 0:
				drawTurtle();
				break;
			case 1:
				drawTurtleSwimming1();
				break;
			case 2:
				drawTurtleSwimming2();
				break;

		}
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

void Turtles::drawTurtleSwimming1(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(.25,.5, .25);
    glVertex3f(.25,.5, .75);
    glVertex3f(.75,.5, .75);
    glVertex3f(.75,.5, .25);
    glEnd();
}

void Turtles::drawTurtleSwimming2(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
   	glVertex3f(.3,.5, .3);
    glVertex3f(.3,.5, .7);
    glVertex3f(.7,.5, .7);
    glVertex3f(.7,.5, .3);
    glEnd();
}



void Turtles::update(double t){
	WaterObject::update(t);
	ticFrameCounter += t;
	if(ticFrameCounter >= FRAME_TIC){
		ticFrameCounter -= FRAME_TIC;
		frame++;
		if(frame >= TOTAL_FRAMES)
			frame = 0;
	}

	if(currentlySubmerging){
		if(currentlyAscending){
			elevation += sumbergeSpeed * t;
			if(elevation >= 0){
				elevation = 0;
				currentlyAscending = false;
				currentlySubmerging = false;

			}
		}
		else {
			elevation -= sumbergeSpeed * t;
			if(elevation <= MIN_ELEVATION){
				elevation = MIN_ELEVATION;
				currentlyAscending = true;
			}
		}

	} else {
		//Check if start submerging
		if(submergingTurtles && !hittingFrog){
			submergingCounter += t;
			if(submergingCounter >= TIME_TILL_SUBMERGE){
				currentlySubmerging = true; 
				submergingCounter = 0;
			}
		}
	}
	//Setting hitting frog to false
	hittingFrog = false;
}

bool Turtles::checkColisonWithFrog(Frog* frog){
	if(currentlySubmerging)
		hittingFrog = false;
	else 
		hittingFrog = WaterObject::checkColisonWithFrog(frog);

	if(hittingFrog)
		submergingCounter = 0;
	return hittingFrog;
}