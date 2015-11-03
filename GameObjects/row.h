#include "../Frogger3D.h"
#include <vector>

class Row{
		int width, halfWidth;
		unsigned int texture;
		std::vector<unsigned int> textures;
		float textureSwitchTime;
		float textureTicCount;
		int currentTexture;
		unsigned int texture2; 
	public: 
		Row(int _width, unsigned int _texture);
		Row(int _width, std::vector<unsigned int> _textures, float _textureSwitchTime);
		void addSecondTexture(unsigned int _texture2);
		void update(double t);
		void draw();
	private:
		void init(int _width, unsigned int _texture);
};