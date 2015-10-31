#include "../Frogger3D.h"

class Row{
		int width, depth;
		unsigned int texture;
	public: 
		Row(int _width, int _depth, unsigned int _texture);
		void update(double t);
		void draw();
};