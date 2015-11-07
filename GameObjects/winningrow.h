#include "../Frogger3D.h"

#ifndef ROW_H
#include "row.h"
#endif


class WinningRow : public Row{
		unsigned int boundaryTexture;
	public:
		WinningRow( std::vector<unsigned int> _textures, float _textureSwitchTime, unsigned int _boundaryTexture);
		void draw();
	private:
		void drawLeftBoundaryRightReg(int x, int y);
		void drawLeftRegRightBoundary(int x,int y);

		void drawLeftBoundaryRightRegWithTop(int x, int y);
		void drawLeftRegRightBoundaryWithTop(int x,int y);
};