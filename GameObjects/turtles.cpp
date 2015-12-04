#include "turtles.h"

int TOTAL_FRAMES = 4;
float TIME_TILL_SUBMERGE = .6;
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
static void drawTurtleBody(){
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(0,0,.5);
	glScalef(.36,.08,.24);
	drawBall();
	glPopMatrix();
}
static void drawTurtleHead(){
	glColor3f(0,1,0);
        glPushMatrix();
        glTranslatef(-.43,0,.5);
        glScalef(.062,.016,.051);
        drawBall();
        glPopMatrix();

}
static void drawTurtleLegs1(){
	glColor3f(0,1,0);
	//upperleft leg
        glPushMatrix();
        glTranslatef(-.22,0,.27);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
	//lowerleft leg
	glPushMatrix();
        glTranslatef(-.22,0,.73);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
	//upperright leg
	 glPushMatrix();
        glTranslatef(.23,0,.27);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
	//upperleft leg
	 glPushMatrix();
        glTranslatef(.23,0,.73);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
}

static void drawTurtleLegs(){
	glColor3f(0,1,0);
        //upperleft leg
        glPushMatrix();
        glTranslatef(-.19,0,.27);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
        //lowerleft leg
        glPushMatrix();
        glTranslatef(-.19,0,.73);
        glScalef(.048,.016,.072);
        glRotatef(30,0,0,1);
	drawBall();
        glPopMatrix();
        //upperright leg
         glPushMatrix();
        glTranslatef(.26,0,.27);
        glScalef(.048,.016,.072);
	glRotatef(30,1,0,0);
        drawBall();
        glPopMatrix();
        //upperleft leg
         glPushMatrix();
        glTranslatef(.26,0,.73);
        glScalef(.048,.016,.072);
	glRotatef(30,0,0,1);
        drawBall();
        glPopMatrix();


}
static void drawTurtleLegs2(){
	 glColor3f(0,1,0);
        //upperleft leg
        glPushMatrix();
        glTranslatef(-.16,0,.27);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
        //lowerleft leg
        glPushMatrix();
        glTranslatef(-.16,0,.73);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
        //upperright leg
         glPushMatrix();
        glTranslatef(.29,0,.27);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();
        //upperleft leg
         glPushMatrix();
        glTranslatef(.29,0,.73);
        glScalef(.048,.016,.072);
        drawBall();
        glPopMatrix();




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
	drawTurtleBody();
	drawTurtleHead();
	drawTurtleLegs();

    glEnd();
}

void Turtles::drawTurtleSwimming1(){
	drawTurtleBody();
	drawTurtleHead();
	drawTurtleLegs1();
	 glEnd();
}

void Turtles::drawTurtleSwimming2(){
	drawTurtleBody();
	drawTurtleHead();
	drawTurtleLegs2();

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
