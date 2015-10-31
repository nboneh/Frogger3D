#include "../Frogger3D.h"
#include "row.h"

class Board{
		Row *rows;
	public: 
		Board();
		void update(double t);
		void draw();
};