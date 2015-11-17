#include "turtles.h"

int TOTAL_NORMAL_FRAMES = 3;
int TOTAL_FRAMES = 6;
int TOTAL_FRAME_COUNT_TILL_SUBMERGING = 2;
float FRAME_TIC = .2;


Turtles::Turtles(float _speed, int numOfTurtles):WaterObject( left, _speed,  numOfTurtles){
	frame = 0;
	submergingTurtles = true;
	currentlySubmerging = false;
	hittingFrog = false;
	descendSubmergeFrames = false;
	frameCountTillSubmerging = 0;
	ticFrameCounter = 0;
}

void Turtles::drawAfterSetup(){
	glPushMatrix();
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
			case 3:
				drawSubmergedTurtle1();
				break;
			case 4:
				drawSubmergedTurtle2();
				break;
			case 5:
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

void Turtles::drawSubmergedTurtle1(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(.2,.3, .2);
    glVertex3f(.2,.3, .8);
    glVertex3f(.8,.3, .8);
    glVertex3f(.8,.3, .2);
    glEnd();
}


void Turtles::drawSubmergedTurtle2(){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(.2,.1, .2);
    glVertex3f(.2,.1, .8);
    glVertex3f(.8,.1, .8);
    glVertex3f(.8,.1, .2);
    glEnd();
}


void Turtles::update(double t){
	WaterObject::update(t);
	ticFrameCounter += t;
	if(ticFrameCounter >= FRAME_TIC){
		
		ticFrameCounter -= FRAME_TIC;
		
		if(currentlySubmerging){
			//Draw Submerging frames
			if(descendSubmergeFrames){
				frame--;
				if(frame < TOTAL_NORMAL_FRAMES){
					frame = 0;
					descendSubmergeFrames = false; 
					currentlySubmerging = false;
				}
			} else {
				frame++;
				if(frame >= TOTAL_FRAMES){
					descendSubmergeFrames = true;
					frame -= 2;
				}

			}
		} else {
			frame++;
			if(frame >= TOTAL_NORMAL_FRAMES){
				frame = 0;
			}

			//Check if start submerging
			if(submergingTurtles && !hittingFrog){
				frameCountTillSubmerging++;
				if(frameCountTillSubmerging >= TOTAL_FRAME_COUNT_TILL_SUBMERGING){
					frameCountTillSubmerging = 0;
					currentlySubmerging = true;
				
					//Setting to first submerge frame
					frame = TOTAL_NORMAL_FRAMES; 
				}
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
		frameCountTillSubmerging = 0;
	return hittingFrog;
}