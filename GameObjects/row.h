#include "../Frogger3D.h"
#include <vector>

#ifndef ROW_H
#define ROW_H
#endif

class Row{
	public: 
		Row(int _width, unsigned int _texture);
		Row(int _width, std::vector<unsigned int> _textures, float _textureSwitchTime);
		void update(double t);
		virtual void draw();
	protected:
		int width;
		unsigned int texture;
		std::vector<unsigned int> textures;
		float textureSwitchTime;
		float textureTicCount;
		int currentTexture;
	private:
		void init(int _width, unsigned int _texture);
};