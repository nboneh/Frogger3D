#include "Frogger3D.h"

int inc       =  10;  // Ball and cylinder increment

int emission  =   0;  // Emission intensity (%)

void drawCube()
{

  //  Offset, scale and rotate
  //  Enable textures
  //  Front
  glBegin(GL_QUADS);
  glNormal3f( 0, 0, 1);
  glTexCoord2f(0,0); glVertex3f(0,0, 1);
  glTexCoord2f(1,0); glVertex3f(1,0, 1);
  glTexCoord2f(1,1); glVertex3f(1,1, 1);
  glTexCoord2f(0,1); glVertex3f(0,1, 1);
  glEnd();
  //  Back
  glBegin(GL_QUADS);
  glNormal3f( 0, 0,-1);
  glTexCoord2f(0,0); glVertex3f(0,0,0);
  glTexCoord2f(1,0); glVertex3f(1,0,0);
  glTexCoord2f(1,1); glVertex3f(1,1,0);
  glTexCoord2f(0,1); glVertex3f(0,1,0);
  glEnd();
  //  Right
  glBegin(GL_QUADS);
  glNormal3f(1, 0, 0);
  glTexCoord2f(0,0); glVertex3f(1,0,0);
  glTexCoord2f(1,0); glVertex3f(1,1,0);
  glTexCoord2f(1,1); glVertex3f(1,1,1);
  glTexCoord2f(0,1); glVertex3f(1,0,1);
  glEnd();
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
  //  Undo transformations and textures


}

void drawSquare(){
    glBegin(GL_POLYGON);
  glNormal3f( 0, 0, 1);
  glTexCoord2f(0,0); glVertex2f(0,0);
  glTexCoord2f(1,0); glVertex2f(1,0);
  glTexCoord2f(1,1); glVertex2f(1,1);
  glTexCoord2f(0,1); glVertex2f(0,1);
  glEnd();
}
/*
*  Draw vertex in polar coordinates with normal
*/
static void Vertex(double th,double ph)
{
  double x = Sin(th)*Cos(ph);
  double y = Cos(th)*Cos(ph);
  double z =         Sin(ph);
  //  For a sphere at the origin, the position
  //  and normal vectors are the same
  glNormal3d(x,y,z);
  glVertex3d(x,y,z);
}

/*
*  Draw a ball
*     at (x,y,z)
*     radius (r)
*/
void drawBall()
{
  //  Bands of latitude
  int ph;
  for (ph=-90 ;ph<90;ph+=inc)
  {
     glBegin(GL_QUAD_STRIP);
     int th;
     for (th=0;th<=360;th+=2*inc)
     {
        Vertex(th,ph);
        Vertex(th,ph+inc);
     }
     glEnd();
  }
  //  Undo transofrmations
}

static void VertexCylinder(double th,double ph,double z)
{
 double x = Sin(th)*Cos(ph);
 double y = Cos(th)*Cos(ph);
 //  For a sphere at the origin, the position
 //  and normal vectors are the same
 glNormal3d(x,y,z);
 glTexCoord2f(th/360 ,z); glVertex3d(x,y,z);
}


static void Circle()
{
  glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
  int i;
   for (i = 0; i <= 360; i++)   {
     float x= Cos(i);
     float y = Sin(i);
       glTexCoord2f((x+1.25)*.5 ,(y+1)*.5); glVertex2f (x, y );
   }
   glEnd();
}

static void HalfCircle()
{
  glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
  int i;
   for (i = 0; i <= 180; i++)   {
     float x= Cos(i);
     float y = Sin(i);
       glTexCoord2f((x+1)*.5,(y+1)*.5); glVertex2f (x, y );
   }
   glEnd();
}

void drawCylinderNoText(){
   glPushMatrix();
 glScalef(.5,.5,1);
 glBegin(GL_QUAD_STRIP);
 int th;
 for (th=0;th<=360;th+=2*inc)
 {
     VertexCylinder(th,0,0);
     VertexCylinder(th,inc,1);
 }
 glEnd();

 glNormal3f(0,0,-1);
 Circle();
 glTranslatef(0,0,1);

 glNormal3f(0,0,1);
 Circle();
 glPopMatrix();

}

void drawCylinder(unsigned int texture, unsigned int topTexture){

 glPushMatrix();
 glScalef(.5,.5,1);
 glEnable(GL_TEXTURE_2D);
 glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
 glBindTexture(GL_TEXTURE_2D,texture);

 glBegin(GL_QUAD_STRIP);
 int th;
 for (th=0;th<=360;th+=2*inc)
 {
     VertexCylinder(th,0,0);
     VertexCylinder(th,inc,1);
 }
 glEnd();

 glBindTexture(GL_TEXTURE_2D,topTexture);

 glNormal3f(0,0,-1);
 Circle();
 glTranslatef(0,0,1);

 glNormal3f(0,0,1);
 Circle();

 glPopMatrix();

 glDisable(GL_TEXTURE_2D);

}

void drawHalfCylinder(){

 glPushMatrix();
 glScalef(.5,.5,1);

 glBegin(GL_QUAD_STRIP);
 int th;
 for (th=-90;th<=90;th+=2*inc)
 {
   VertexCylinder(th,0,0);
   VertexCylinder(th,inc,1);
 }
 glEnd();


 glNormal3f(0,0,-1);
 HalfCircle();
 glTranslatef(0,0,1);

 glNormal3f(0,0,1);
 HalfCircle();

 glPopMatrix();
}

void draw2DFrog(){
 
  glScalef(.09,.09,.09);
 
 
 
  glBegin(GL_POLYGON);
   glColor3f(0,1,0);
   glVertex3f(0,0,0);
   glVertex3f(0,0,7);
   glVertex3f(6,0,7);
   glVertex3f(6,0,0);
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f(0,1,0);
   glVertex3f(1,0.1,-1);
   glVertex3f(5,0.1,-1);
   glVertex3f(5,0.1,8);
   glVertex3f(1,0.1,8);
   glEnd();
   
   //lefttopleg
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
   glVertex3f(-2,0,4);
   glVertex3f(8,0,4);
   glVertex3f(8,0,5);
   glVertex3f(-2,0,5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(-2,0,4);
   glVertex3f(-2,0,9);
   glVertex3f(-1,0,9);
   glVertex3f(-1,0,4);
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(-3,0,7);
   glVertex3f(-3,0,8);
   glVertex3f(-2,0,8);
   glVertex3f(-2,0,7);
   glEnd();
   
   //rightleftleg
   glBegin(GL_POLYGON);
   glVertex3f(8,0,4);
   glVertex3f(8,0,9);
   glVertex3f(7,0,9);
   glVertex3f(7,0,4);
 glEnd();
 
 glBegin(GL_POLYGON);
   glVertex3f(9,0,7);
   glVertex3f(9,0,8);
   glVertex3f(7,0,8);
   glVertex3f(7,0,7);
 glEnd();
 
 
 
 //lowerlegs
  glBegin(GL_POLYGON);
   glVertex3f(-2,0,2.5);
   glVertex3f(8,0,2.5);
   glVertex3f(8,0,1);
   glVertex3f(-2,0,1);
   glEnd();
 
 
  glBegin(GL_POLYGON);
   glVertex3f(-2,0,2.5);
   glVertex3f(-2,0,-3);
   glVertex3f(-1,0,-3);
   glVertex3f(-1,0,2.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(-2,0,-2);
   glVertex3f(-3,0,-2);
   glVertex3f(-3,0,-1);
   glVertex3f(-2,0,-1);
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(8,0,2.5);
   glVertex3f(8,0,-3);
   glVertex3f(7,0,-3);
   glVertex3f(7,0,2.5);
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(8,0,-2);
   glVertex3f(9,0,-2);
   glVertex3f(9,0,-1);
   glVertex3f(8,0,-1);
   glEnd();
   
   
   //eyes
   
   glBegin(GL_POLYGON);
   glColor3f(1,0,1);
   glVertex3f(0,0.01,6);
   glVertex3f(0,0.01,7);
   glVertex3f(1,0.01,7);
   glVertex3f(1,0.01,6);
   glEnd();
   
    glBegin(GL_POLYGON);
   glColor3f(1,0,1);
   glVertex3f(6,0.01,6);
   glVertex3f(6,0.01,7);
   glVertex3f(5,0.01,7);
   glVertex3f(5,0.01,6);
   glEnd();
   
   
 
}
