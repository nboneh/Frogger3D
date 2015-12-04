#include "../Frogger3D.h"
#include <vector>
#include <string>
#include "movingobject.h"

#ifndef ROW_H
#define ROW_H
#endif

class Row{
	public: 
		Row( unsigned int _texture);
		Row( std::vector<unsigned int> _textures, float _textureSwitchTime);
		void update(double t);
		void addMovingObjects(std::string type, int distanceBetween, int num );
		void addMovingObject(std::string type);
		virtual void checkColisonWithFrog(Frog* frog);
		void setAsWaterRow();
		virtual void draw();
	protected:
		bool waterRow;
		unsigned int texture;
		std::vector<unsigned int> textures;
		std::vector<MovingObject *> movingObjects;
		float textureSwitchTime;
		float textureTicCount;
		//current texture is position in the array of textures
		unsigned int currentTexture;
		int distanceBetweenMovingObjects;
	private:
		void init( unsigned int _texture);
};