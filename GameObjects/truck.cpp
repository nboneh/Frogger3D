#include "truck.h"

Truck::Truck(): Car(left, 1.5f, 2){
} 

void Truck::drawAfterSetup(){
	//Front
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(-.2,.3,-.01);
	glScalef(1,.5,1.02);
	drawCube();
	glPopMatrix();

	//Widows
	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-.21,.5,-.02);
	glScalef(.5,.25,1.05);
	drawCube();
	glPopMatrix();

	//Back 
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(.5,.3,-.02);
	glScalef(1.7,1,1.05);

	glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,REDDIT);

	 glBegin(GL_QUADS);
  glNormal3f( 0, 0, 1);
  glTexCoord2f(.1,0); glVertex3f(0,0, 1);
  glTexCoord2f(1.1,0); glVertex3f(1,0, 1);
  glTexCoord2f(1.1,1); glVertex3f(1,1, 1);
  glTexCoord2f(.1,1); glVertex3f(0,1, 1);
  glEnd();
  //  Back
  glBegin(GL_QUADS);
  glNormal3f( 0, 0,-1);
  glTexCoord2f(1.1,0); glVertex3f(0,0,0);
  glTexCoord2f(.1,0); glVertex3f(1,0,0);
  glTexCoord2f(.1,1); glVertex3f(1,1,0);
  glTexCoord2f(1.1,1); glVertex3f(0,1,0);
  glEnd();
  //  Right
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,BACK_OF_TRUCK);
  glBegin(GL_QUADS);
  glNormal3f(1, 0, 0);
  glTexCoord2f(1.1,1); glVertex3f(1,0,0);
  glTexCoord2f(1.1,0); glVertex3f(1,1,0);
  glTexCoord2f(.1,0); glVertex3f(1,1,1);
  glTexCoord2f(.1,1); glVertex3f(1,0,1);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  //  Left
  glBegin(GL_QUADS);
  glNormal3f(-1, 0, 0);
  glTexCoord2f(0,0); glVertex3f(0,0,0);
  glTexCoord2f(1,0); glVertex3f(0,1,0);
  glTexCoord2f(1,1); glVertex3f(0,1,1);
  glTexCoord2f(0,1); glVertex3f(0,0,1);
  glEnd();
  //  Top
  glBegin(GL_QUADS);
  glNormal3f( 0,+1, 0);
  glTexCoord2f(0,0); glVertex3f(0,1,0);
  glTexCoord2f(1,0); glVertex3f(0,1,1);
  glTexCoord2f(1,1); glVertex3f(1,1,1);
  glTexCoord2f(0,1); glVertex3f(1,1,0);
  glEnd();
  //  Bottom
  glBegin(GL_QUADS);
  glNormal3f( 0,-1, 0);
  glTexCoord2f(0,0); glVertex3f(0,0,0);
  glTexCoord2f(1,0); glVertex3f(0,0,1);
  glTexCoord2f(1,1); glVertex3f(1,0,1);
  glTexCoord2f(0,1); glVertex3f(1,0,0);
  glEnd();
 glPopMatrix();

  glPushMatrix();
  glTranslatef(-.1,0,0);
  Car::drawWheels(2.2);
    Car::drawWheels(1);
  glPopMatrix();

}