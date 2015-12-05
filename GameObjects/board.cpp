#include "board.h"
#include "winningrow.h"
#include <string>


float distance  =   15;  // Light distance
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
int ambient   =  30;  // Ambient intensity (%)
int diffuse   = 100;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shinyvec[1];    // Shininess (value)
double zh =  330;  // Light azimuth
float ylight  =   5;  // Elevation of light

static void drawLight(){
	  //  Translate intensity to color vectors
   float Ambient[]   = {0.01f*ambient ,0.01f*ambient ,0.01f*ambient ,1.0};
   float Diffuse[]   = {0.01f*diffuse ,0.01f*diffuse ,0.01f*diffuse ,1.0};
   float Specular[]  = {0.01f*specular,0.01f*specular,0.01f*specular,1.0};
   //  Light position

   float Position[]  = {distance*(float)(Cos(zh)),ylight,(float)distance*(float)(Sin(zh)),1.0};
    //  Draw light position as ball (still no lighting here)
   glColor3f(1,1,1);
   glPushMatrix();
   glTranslatef(Position[0],Position[1],Position[2]);
   glScalef(.1, .1,.1);
   drawBall();
   glPopMatrix();
   //  OpenGL should normalize normal vectors
   glEnable(GL_NORMALIZE);
   //  Enable lighting
   glEnable(GL_LIGHTING);
   //  glColor sets ambient and diffuse color materials
   glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
   //  Enable light 0
   glEnable(GL_LIGHT0);
   //  Set ambient, diffuse, specular components and position of light 0
   glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
   glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
   glLightfv(GL_LIGHT0,GL_POSITION,Position);
}
Board::Board(){
	std::vector<unsigned int> water;
	water.push_back(WATER4);
	water.push_back(WATER3);
	water.push_back(WATER2);
	water.push_back(WATER);

	rows.push_back(new WinningRow( water, .2, GRASS));
	Row * fifthWaterRow = new Row(water, .2);
	fifthWaterRow->setAsWaterRow();
	fifthWaterRow->addMovingObjects("AverageLog", 2, 3 );
	rows.push_back(fifthWaterRow);

	Row * fourthWaterRow = new Row(water, .2);
	fourthWaterRow->setAsWaterRow();
	fourthWaterRow->addMovingObjects("TwoTurtles", 1, 4);
	fourthWaterRow->addMovingObject("SubmergingTwoTurtles");
	rows.push_back(fourthWaterRow);

	Row * thirdWaterRow = new Row(water, .2);
	thirdWaterRow->setAsWaterRow();
	thirdWaterRow->addMovingObjects("LongLog", 3, 2 );
	rows.push_back(thirdWaterRow);
	
	Row * secondWaterRow = new Row(water, .2);
	secondWaterRow->setAsWaterRow();
	secondWaterRow->addMovingObjects("ShortLog", 3, 3 );
	rows.push_back(secondWaterRow);

	Row * firstWaterRow = new Row(water, .2);
	firstWaterRow->setAsWaterRow();
	firstWaterRow->addMovingObjects("ThreeTurtles", 1, 3);
	firstWaterRow->addMovingObject("SubmergingThreeTurtles");
	rows.push_back(firstWaterRow);
	
	rows.push_back(new Row(CONCRETE));
 	
	Row * fifthRoadRow = new Row(ROAD);
 	fifthRoadRow->addMovingObjects("Truck", 4,2);
 	rows.push_back(fifthRoadRow);

	Row * fourthRoadRow = new Row(ROAD);
 	fourthRoadRow->addMovingObjects("Car4", 0,1);
 	rows.push_back(fourthRoadRow);
 		
 	Row * thirdRoadRow = new Row(ROAD);
 	thirdRoadRow->addMovingObjects("Car3", 3,3);
 	rows.push_back(thirdRoadRow);
 	
 	Row * secondRoadRow = new Row(ROAD);
 	secondRoadRow->addMovingObjects("Car2", 3,3);
 	rows.push_back(secondRoadRow);

 	Row * firstRoadRow = new Row(ROAD);
 	firstRoadRow->addMovingObjects("Car1", 3, 3);
 	rows.push_back(firstRoadRow);

 	rows.push_back(new Row(GRASS));
 	frog = new Frog(ROW_WIDTH/2 , rows.size(),up);

}
void Board::update( double t){
	int numOfRows = rows.size();
	int checkColisionAtY = round(frog->getY())-1;
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->update(t);
 		if(i == checkColisionAtY)
 			rows.at(i)->checkColisonWithFrog(frog);
 	}
	frog->update(t);
	
	if(TIME <= 0)
		frog->die(roadkill);

	if(frog->getX() < 0){
		frog->setX(0);
		frog->stopMovement();
	}
	else if(frog->getX() > (ROW_WIDTH-1)){
		frog->setX(ROW_WIDTH-1);
		frog->stopMovement();
	}
	else if(frog->getY() > rows.size()){
		frog->setY(rows.size());
		frog->stopMovement();
	}

}

void Board::inputDirection(direction d){
	frog->inputDirection(d);
}

int Board::getFrogLives(){
	return frog->getLives();
}
void Board::draw(){
	int numOfRows = rows.size();
	glPushMatrix();
	//Adjusting camera
	if(BIRD_EYE_VIEW){
		glTranslatef(-(ROW_WIDTH/2),-6, -(numOfRows/2));
		//glScalef(1.2, 1, .75);
	} else {
		glTranslatef(-frog->getX(),0, - frog->getY() +numOfRows* .3f);
	}
	
	//Drawing rows
	glPushMatrix();
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->draw();
 		glTranslatef(0,0,1);
 	}
 	glPopMatrix();


 	//Drawing Frog
 	frog->draw();


 	//Hide wrap around edges from showing moving objects
 	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    glVertex3f(-7,1, -1);
    glVertex3f(-7,1, numOfRows+1);
    glVertex3f(0,2, numOfRows+1);
    glVertex3f(0,2, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0,-1, -1);
    glVertex3f(0,-1, numOfRows+1);
    glVertex3f(0,2, numOfRows+1);
    glVertex3f(0,2, -1);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex3f(ROW_WIDTH+7,1, -1);
    glVertex3f(ROW_WIDTH+7,1, numOfRows+1);
    glVertex3f(ROW_WIDTH,2, numOfRows+1);
    glVertex3f(ROW_WIDTH,2, -1);
    glEnd();


     glBegin(GL_POLYGON);
    glVertex3f(ROW_WIDTH,-1, -1);
    glVertex3f(ROW_WIDTH,-1, numOfRows+1);
    glVertex3f(ROW_WIDTH,2, numOfRows+1);
    glVertex3f(ROW_WIDTH,2, -1);
    glEnd();

    drawLight();

 	glPopMatrix();

}

void Board::resetFrogLives(){
	frog->resetLives();
}
