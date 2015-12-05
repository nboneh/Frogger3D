#include "car4.h"

Car4::Car4(): Car(right, 5, 1){
	playSpeeding = false;
} 

void Car4::drawAfterSetup(){
	glPushMatrix();

	glRotatef(180,0,1,0);
	glTranslatef(-1,0,-1);
	  glColor3f(1,1,1);
    //front side
   glNormal3f( 0, 0, 1);
   
   glBegin(GL_POLYGON);
   glVertex3f(-0.1,.1, .85);
   glVertex3f(-0.1,.4,.85);
   glVertex3f(.2,.4, .85);
   glVertex3f(.3,.6, .85);
   
   glVertex3f(.7,.6, .85);
   glVertex3f(.8,.4, .85);
   glVertex3f(1.1,.4, .85);
   glVertex3f(1.1,.1, .85);
   glVertex3f(-0.2,.1, .85);
   glEnd();
   //rear side
 
       
   glNormal3f( 0, 0, -1);
   
   glBegin(GL_POLYGON);
   glVertex3f(-0.1,.1, .05);
   glVertex3f(-0.1,.4, .05);
   glVertex3f(.2,.4, .05);
   glVertex3f(.3,.6, .05);
   
   glVertex3f(.7,.6, .05);
   glVertex3f(.8,.4, .05);
   glVertex3f(1.1,.4, .05);
   glVertex3f(1.1,.1, .05);
   glVertex3f(-0.2,.1, .05);
   glEnd();
   
   //left side
   
   glNormal3f( -1, 0, 0);
   
   glBegin(GL_POLYGON);
   glVertex3f(-0.1,.1, .05);
   glVertex3f(-0.1,.1, .85);
   glVertex3f(-0.1,.4, .85);
   glVertex3f(-0.1,.4, .05);
   glEnd();
   //left top
   
   glNormal3f( 0, 1, 0);
   
   glBegin(GL_POLYGON);
   glVertex3f(-0.1,.4, .85);
   glVertex3f(-0.1,.4, .05);
   glVertex3f(0.2,.4, .05);
   glVertex3f(0.2,.4, .85);
   
   glEnd();
   //right side
   
   glNormal3f( 1, 0, 0);
   
   glBegin(GL_POLYGON);
   glVertex3f(1.1,.1, .05);
   glVertex3f(1.1,.1, .85);
   glVertex3f(1.1,.4, .85);
   glVertex3f(1.1,.4, .05);
   glEnd();
   
   //right top
   glNormal3f( 0, 1, 0);
   
   glBegin(GL_POLYGON);
   glVertex3f(1.1,.4, .85);
   glVertex3f(1.1,.4, .05);
   glVertex3f(0.8,.4, .05);
   glVertex3f(0.8,.4, .85);
   
   glEnd();
   //windsheild
   
   glNormal3f(.476, .879, 0);
   glColor3f(0, 1, 0);
   glBegin(GL_POLYGON);
 
   glVertex3f(0.14,.4, .05);
   glVertex3f(0.14,.4, .85);
   glVertex3f(0.3,.6, .85);
   glVertex3f(0.3,.6, .05);
   glEnd();
   
   
   //back windsheild
   
   glNormal3f( .9998, .0002, 0);
   
   glBegin(GL_POLYGON);
   glVertex3f(.8,.4, .05);
   glVertex3f(.8,.4, .85);
   glVertex3f(.7,.6, .85);
   glVertex3f(.7,.6, .05);
   glEnd();
   
   //car top
   glNormal3f( 0, 1, 0);
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
 
   glVertex3f(0.7,.6, .05);
   glVertex3f(0.7,.6, .85);
   glVertex3f(0.3,.6, .85);
   glVertex3f(0.3,.6, .05);
   glEnd();
   
   //far window
   glColor3f(0,1,0);
   glPushMatrix();
   glNormal3f( 0, 0, -1);

   glTranslatef(.17,.4,0.04);
   glScalef(.1,.09,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.0499);
   glVertex3f(3,0,.0499);
   glVertex3f(3,2, .0499);
   glVertex3f(1.5,2, .0499);
   
   glEnd();
   glPopMatrix();
   
    //close window
  glPushMatrix();
   glNormal3f( 0, 0, 1);
 
   glTranslatef(.17,.4,.75);
   glScalef(.1,.09,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.9);
   glVertex3f(3,0,.9);
   glVertex3f(3,2, .9);
   glVertex3f(1.5,2, .9);
   
   glEnd();
   glPopMatrix();
   
   //headlights
                glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-.088,.25, 0.23);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
       
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-.088,.25, 0.69);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
       
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(1.1,.25, 0.23);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
       
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(1.1,.25, 0.69);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
   
 
      glPopMatrix();

         glPushMatrix();
         glTranslatef(0,0,.1);
     glScalef(.9,.9,.9);
       Car::drawWheels();
      glPopMatrix();
}

void Car4::update(double t){
	Car::update(t);
	if(!BIRD_EYE_VIEW && FROG_PASS_CARS)
		return;
	
	if(playSpeeding && x >= 0){
		PlaySound("speedby.wav");
		playSpeeding = false;
	} 
	else if (x < 0){
		playSpeeding = true;
	}	
}