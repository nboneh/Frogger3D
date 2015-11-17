#include "waterobject.h"


WaterObject::WaterObject(direction _movingDirection, float _speed, int _width) : MovingObject( _movingDirection,  _speed,  _width){

} 

bool WaterObject::checkColisonWithFrog(Frog * frog){
	bool hitFrog = MovingObject::checkColisonWithFrog(frog);
	if(hitFrog){
		if(movingDirection == left){
			frog->setX(frog->getX() - move);
			if(frog->getX() < 0)
				frog->die(drown);
		}
		else if(movingDirection == right){
			frog->setX(frog->getX() + move);
			if(frog->getX() > (ROW_WIDTH-1))
				frog->die(drown);
		}
	}
	return hitFrog;

}
bool WaterObject::detectColision(Frog* frog, float objectX){
	//Making hit box smaller for water objects so frog does not stand on air
	return frog->getX() +1 >=  (objectX+.25) && (objectX-.25) + width >= frog->getX();
}