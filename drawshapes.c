/*
 *  Draws basic shapes
 */
#include "Frogger3D.h"

 int inc       =  10;  // Ball and cylinder increment 

int emission  =   0;  // Emission intensity (%)
float shinyvec[1];    


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
   for (int ph=-90;ph<90;ph+=inc)
   {
      glBegin(GL_QUAD_STRIP);
      for (int th=0;th<=360;th+=2*inc)
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
    for (int i = 0; i <= 360; i++)   {
    	float x= Cos(i);
    	float y = Sin(i);
       	glTexCoord2f((x+1)*.5,(y+1)*.5); glVertex2f (x, y );
    }
    glEnd();
}

static void HalfCircle() 
{ 
   glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    for (int i = 0; i <= 180; i++)   {
      float x= Cos(i);
      float y = Sin(i);
        glTexCoord2f((x+1)*.5,(y+1)*.5); glVertex2f (x, y );
    }
    glEnd();
}


 void drawCylinder(unsigned int texture, unsigned int topTexture){
	
	glPushMatrix();
  glScalef(.5,.5,1);
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); 
  glBindTexture(GL_TEXTURE_2D,texture);
 
  glBegin(GL_QUAD_STRIP);
  for (int th=0;th<=360;th+=2*inc)
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
  for (int th=-90;th<=90;th+=2*inc)
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