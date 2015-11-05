#include "../Frogger3D.h"
#include "row.h"
#include <vector>
#include "frog.h"


class Board{
		 std::vector<Row *> rows;
		 Frog frog;
		 int rowsWidth;
	public: 
		Board();
		void init();
		void update(double t);
		void draw();
		void inputDirection(direction d);
};