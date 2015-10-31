#include "board.h"


int ROW_WIDTH = 10;
int ROW_DEPTH = 2;
int NUM_ROWS = 7;

Board::Board(){
	rows = new Row(ROW_WIDTH, ROW_DEPTH, 0);
};

void Board::update( double t){

}

void Board::draw(){
 	(*rows).draw();
}