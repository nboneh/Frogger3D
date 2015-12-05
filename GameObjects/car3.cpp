#include "car3.h"
 
Car3::Car3(): Car(left, 1.75f, 1){
}
 
void Car3::drawAfterSetup(){
        glColor3f(1, 0.54902, 0);
       
       
       
        //carbody
        glPushMatrix();
       
    glTranslatef(.1,0.25,.05);
    glScalef(.9,.7,.9);
    drawCube();
    glPopMatrix();
       
        //tire
       
        glPushMatrix();
        glTranslatef(.95,.4,.65);
        //glScalef(1.1,1.1,1.1);
        glRotatef(90,0,1,0);
        drawStationaryWheel();
        glPopMatrix();
       
        //front bumper
        glPushMatrix();
        glColor3f(1, 0.54902, 0);
    glTranslatef(-.15,0.25,.05);
    glScalef(.3,.4,.9);
    drawCube();
    glPopMatrix();
   
    //connection from bumper to body
    glPushMatrix();
    glTranslatef(0.1,.45,.05);
    glScalef(.2,.2,.9);
    glRotatef(45, 0,0,1);
    drawCube();
    glPopMatrix();
   
    //headlights
    glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-.14,.45, 0.25);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
       
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-.14,.45, 0.73);
        glScalef(.05,.08,.08);
        drawBall();
        glPopMatrix();
       
        //rear lights
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(.97,.42, 0.1);
        glScalef(.05,.15,.2);
        drawCube();
        glPopMatrix();
       
        glColor3f(1,0,0);
        glPushMatrix();
        glTranslatef(.97,.42, 0.7);
        glScalef(.05,.15,.2);
        drawCube();
        glPopMatrix();
       
       
       
       
        //real life grill
        glColor3f(0,0,0);
                glPushMatrix();
                glTranslatef(-.15,.57,.47);
                glScalef(.03, .23,.03);
                glRotatef(90,1,0,0);
                glRotatef(90,0,0,1);
                drawHalfCylinder();
                glPopMatrix();
               
                glPushMatrix();
                glTranslatef(-.15,.57,.52);
                glScalef(.03, .23,.03);
                glRotatef(90,1,0,0);
                glRotatef(90,0,0,1);
                drawHalfCylinder();
                glPopMatrix();
       
                glPushMatrix();
                glTranslatef(-.15,.57,.42);
                glScalef(.03, .23,.03);
                glRotatef(90,1,0,0);
                glRotatef(90,0,0,1);
                drawHalfCylinder();
                glPopMatrix();
               
                glPushMatrix();
                glTranslatef(-.15,.57,.57);
                glScalef(.03, .23,.03);
                glRotatef(90,1,0,0);
                glRotatef(90,0,0,1);
                drawHalfCylinder();
                glPopMatrix();
               
               
                //front windshield
                glNormal3f( -1, 0, 0);
   glColor3f(0.529412, 0.807843, 0.980392);
   glBegin(GL_POLYGON);
   glVertex3f(0.089,.91, .15);
   glVertex3f(0.089,.91, .85);
   glVertex3f(0.089,.73, .85);
   glVertex3f(0.089,.73, .15);
   glEnd();
               
                //rear windshield
                glPushMatrix();
                glColor3f(0.466667, 0.533333, 0.6);
        glNormal3f( 1, 0, 0);
   glTranslatef(-.09,.5,.05);
   glBegin(GL_POLYGON);
   glVertex3f(1.1,.1, .05);
   glVertex3f(1.1,.1, .85);
   glVertex3f(1.1,.4, .85);
   glVertex3f(1.1,.4, .05);
   glEnd();
                glPopMatrix();
               
    //near window
   
    glPushMatrix();
   glNormal3f( 0, 0, 1);
   glColor3f(0.529412, 0.807843, 0.980392);
   
   glTranslatef(.15,.7,.85);
   glScalef(.1,.1,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.9);
   glVertex3f(3,0,.9);
   glVertex3f(3,2, .9);
   glVertex3f(.3,2, .9);
   
   glEnd();
   glPopMatrix();
   
   
    glPushMatrix();
   glNormal3f( 0, 0, 1);
   glColor3f(0.529412, 0.807843, 0.980392);
   
   glTranslatef(.6,.7,.85);
   glScalef(.1,.1,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.9);
   glVertex3f(3,0,.9);
   glVertex3f(3,2, .9);
   glVertex3f(0,2, .9);
   
   glEnd();
   glPopMatrix();
    //far window
   
     glPushMatrix();
   glNormal3f( 0, 0, 1);
   glColor3f(0.529412, 0.807843, 0.980392);
   
   glTranslatef(.15,.7,-.06);
   glScalef(.1,.1,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.9);
   glVertex3f(3,0,.9);
   glVertex3f(3,2, .9);
   glVertex3f(.3,2, .9);
   
   glEnd();
   glPopMatrix();
   
   
    glPushMatrix();
   glNormal3f( 0, 0, 1);
   glColor3f(0.529412, 0.807843, 0.980392);
   
   glTranslatef(.6,.7,-.06);
   glScalef(.1,.1,.12);
   glBegin(GL_POLYGON);
   glVertex3f(0,0,.9);
   glVertex3f(3,0,.9);
   glVertex3f(3,2, .9);
   glVertex3f(0,2, .9);
   
   glEnd();
   glPopMatrix();
   
 
    Car::drawWheels();
}