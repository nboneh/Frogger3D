#include "waterobject.h"


WaterObject::WaterObject(direction _movingDirection, float _speed, int _width) : MovingObject( _movingDirection,  _speed,  _width){

} 

bool WaterObject::checkColisonWithFrog(Frog * frog){
	if(!frog->isMovable())
		return false;
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