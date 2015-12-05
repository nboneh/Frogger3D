#include "car2.h"
 
Car2::Car2(): Car(right, 1.5f, 1){
}
 
void Car2::drawAfterSetup(){
       
        //car body
        glPushMatrix();
        glColor3f(1,0,1);
    glTranslatef(-.1,0.09,.05);
    glScalef(.9,.5,.9);
    drawCube();
    glPopMatrix();
       
       
       
    glEnd();
 
        //car front
        glPushMatrix();
   glTranslatef(.8,0.34,.05);
   
   glScalef(1, .5,.9);
   glRotatef(-90,0,0,1);
   
   
   drawHalfCylinder();
   glPopMatrix();
 
 
        //driver pod
   glColor3f(1,1,1);
   glPushMatrix();
   glTranslatef(.37,.45,.5);
   glScalef(.4,.4,.3);
   drawBall();
   glPopMatrix();
 
  //exaust
                glPushMatrix();
                glColor3f(0.411765, 0.411765, 0.411765);
        glTranslatef(-.2,.3,.5);
        glScalef(.4,.4,.4);
        glRotatef(90,0,1,0);
        drawCylinderNoText();
        glPopMatrix();
 
 //headlights
   glColor3f(1,1,0);
   glPushMatrix();
   glTranslatef(1.1,.45,.3);
   glScalef(.15,.18,.15);
   drawBall();
   glPopMatrix();
   
   glColor3f(1,1,0);
   glPushMatrix();
   glTranslatef(1.1,.45,.7);
   glScalef(.15,.18,.15);
   drawBall();
   glPopMatrix();
 
 
 
 
 
    Car::drawWheels();
}
