#include "board.h"
#include "WinningRow.h"
#include <string>

Board::Board(){
	std::vector<unsigned int> water;
	water.push_back(WATER4);
	water.push_back(WATER3);
	water.push_back(WATER2);
	water.push_back(WATER);

	rows.push_back(new WinningRow( water, .2, GRASS));
	rows.push_back(new Row(water, .2));
	rows.push_back(new Row(water, .2));
	rows.push_back(new Row(water, .2));
	rows.push_back(new Row(water, .2));
	rows.push_back(new Row(CONCRETE));
 	
	Row * fifthRoadRow = new Row(ROAD);
 	fifthRoadRow->addMovingObjects("Truck", 4,2);
 	rows.push_back(fifthRoadRow);

	Row * fourthRoadRow = new Row(ROAD);
 	fourthRoadRow->addMovingObjects("Car4", 1,0);
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


void Board::draw(){
	int numOfRows = rows.size();
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	//Adjusting camera
	glTranslatef(-frog->getX(),0, - frog->getY() +numOfRows* .38f);
	
	//Drawing rows
	glPushMatrix();
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->draw();
 		glTranslatef(0,0,1);
 	}
 	glPopMatrix();

 	//Drawing Frog
 	frog->draw();
 	glPopMatrix();
 	glDisable(GL_DEPTH_TEST);
}