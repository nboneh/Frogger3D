#include "../Frogger3D.h"
#include "frog.h"
#include "row.h"
#include <vector>

class Board{
		 std::vector<Row *> rows;
		 Frog* frog;
	public: 
		Board();
		void update(double t);
		void draw();
		void inputDirection(direction d);
		int getFrogLives();
};