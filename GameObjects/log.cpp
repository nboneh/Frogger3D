#include "log.h"

Log::Log(float _speed, int _width):WaterObject( right, _speed,  _width){

}

void Log::drawAfterSetup(){
	glColor3f(.7,.7,.7);
	glPushMatrix();
	glTranslatef(0, -.1,.5);
	glRotatef(90, 0,1,0);
	glScalef(1,1,width);
	drawCylinder(BARK, LOG);
	glPopMatrix();
}