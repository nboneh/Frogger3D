#include "board.h"
#include "WinningRow.h"



Board::Board(){
	rowsWidth = 14;
	std::vector<unsigned int> water;
	water.push_back(WATER4);
	water.push_back(WATER3);
	water.push_back(WATER2);
	water.push_back(WATER);

	rows.push_back(new WinningRow(rowsWidth, water, .2, GRASS));
	rows.push_back(new Row(rowsWidth, water, .2));
	rows.push_back(new Row(rowsWidth, water, .2));
	rows.push_back(new Row(rowsWidth, water, .2));
	rows.push_back(new Row(rowsWidth, water, .2));
	rows.push_back(new Row(rowsWidth, CONCRETE));
 	rows.push_back(new Row(rowsWidth, ROAD));
 	rows.push_back(new Row(rowsWidth, ROAD));
 	rows.push_back(new Row(rowsWidth, ROAD));
 	rows.push_back(new Row(rowsWidth, ROAD));
 	rows.push_back(new Row(rowsWidth, GRASS));
 	frog = new Frog(rowsWidth/2 , rows.size(),up);

}
void Board::update( double t){
	int numOfRows = rows.size();

	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->update(t);
 	}
 	frog->update(t);
	
	if(frog->getX() < 0){
		frog->setX(0);
		frog->stopMovement();
	}
	else if(frog->getX() >= (rowsWidth-1)){
		frog->setX(rowsWidth-1);
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
	//Adjusting camera
	glTranslatef(-frog->getX(),0, - frog->getY() +numOfRows* .4f);
	
	//Drawing rows
	glPushMatrix();
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->draw();
 		glTranslatef(0,0,1);
 	}
 	glPopMatrix();

 	//Drawing Frog
 	frog->draw();
}