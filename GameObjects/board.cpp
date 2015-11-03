#include "board.h"


int ROW_WIDTH = 15;


void Board::update( double t){
	int numOfRows = rows.size();
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i).update(t);
 	}
 	frog.update(t);
}

void Board::inputDirection(direction d){
	frog.inputDirection(d);
}
void Board::init(){
	unsigned int grass = LoadTexBMP("GameObjects/textures/grass.bmp");
	unsigned int road = LoadTexBMP("GameObjects/textures/road.bmp");
	unsigned int concrete = LoadTexBMP("GameObjects/textures/concrete.bmp");
	std::vector<unsigned int> water;
	water.push_back(LoadTexBMP("GameObjects/textures/water4.bmp"));
	water.push_back(LoadTexBMP("GameObjects/textures/water3.bmp"));
	water.push_back(LoadTexBMP("GameObjects/textures/water2.bmp"));
	water.push_back(LoadTexBMP("GameObjects/textures/water.bmp"));

	rows.push_back(Row(ROW_WIDTH, grass));
	Row winRow = Row(ROW_WIDTH, water, .2);
	winRow.addSecondTexture(grass);
	rows.push_back(winRow);

	rows.push_back(Row(ROW_WIDTH, water, .2));
	rows.push_back(Row(ROW_WIDTH, water, .2));
	rows.push_back(Row(ROW_WIDTH, water, .2));
	rows.push_back(Row(ROW_WIDTH, water, .2));
	rows.push_back(Row(ROW_WIDTH, concrete));
 	rows.push_back(Row(ROW_WIDTH, road));
 	rows.push_back(Row(ROW_WIDTH, road));
 	rows.push_back(Row(ROW_WIDTH, road));
 	rows.push_back(Row(ROW_WIDTH, road));
 	rows.push_back(Row(ROW_WIDTH, grass));

 	frog.init(ROW_WIDTH, rows.size(), ROW_WIDTH/2, 0,up);
}	

void Board::draw(){
	int numOfRows = rows.size();
	glTranslatef(ROW_WIDTH/2-frog.getX() -.5f,0,-(numOfRows - frog.getY()) + numOfRows* .4f);
	for(int i = 0; i < numOfRows;i++){
 		rows.at(i).draw();
 		glTranslatef(0,0,1);
 	}
 	frog.draw();
}