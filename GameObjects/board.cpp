#include "board.h"
#include "WinningRow.h"



Board::Board(): frog(8, 0, up){
	rowsWidth = 14;

}

void Board::init(){
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

}
void Board::update( double t){
	int numOfRows = rows.size();

	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->update(t);
 	}
 	frog.update(t);
	if(frog.getX() < 0){
		frog.setX(0);
		frog.stopMovement();
	}
	else if(frog.getX() > rowsWidth){
		frog.setX(rowsWidth);
		frog.stopMovement();
	}
	else if(frog.getY() < 0){
		frog.setY(0);
		frog.stopMovement();
	}

}

void Board::inputDirection(direction d){
	frog.inputDirection(d);
}


void Board::draw(){
	int numOfRows = rows.size();
	//Adjusting camera
	glTranslatef(-frog.getX() -.5f,0,-(numOfRows - frog.getY()) + numOfRows* .4f);
	
	//Drawing rows
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i)->draw();
 		glTranslatef(0,0,1);
 	}

 	//Drawing Frog
 	frog.draw();
}