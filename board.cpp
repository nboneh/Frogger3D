#include "Frogger3D.h"

void Board::update( double t){

}

void Board::draw(){
   glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0); glVertex2f( 0.0, 0.5);
   glColor3f(0.0,1.0,0.0); glVertex2f( 0.5,-0.5);
   glColor3f(0.0,0.0,1.0); glVertex2f(-0.5,-0.5);
   glEnd();
}