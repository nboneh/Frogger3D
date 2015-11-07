#include "row.h"
#include "movingobjectsfactory.h"

Row::Row(unsigned int _texture){
	init(_texture);
}
Row::Row( std::vector<unsigned int>  _textures, float _textureSwitchTime){
  init( _textures.at(0));
  textureSwitchTime = _textureSwitchTime;
  textures = _textures;
  textureTicCount = 0;
  currentTexture = 0;
}

void Row::init( unsigned int _texture){
  texture = _texture;
}

void Row::addMovingObjects(std::string type, int distanceBetween, int num ){
    MovingObject* first = getMovingObject(type);
    direction dir = first->getMovingDirection();
    float x = first->getX();
    int width = first->getWidth();
    movingObjects.push_back(first);
    for(int i =1; i < num; i++){
        if(dir == right){
          x += (distanceBetween +width);
        }
        else if(dir == left){
          x -= (distanceBetween + width);
        }
        MovingObject* entry = getMovingObject(type);
        entry->setX(x);
        movingObjects.push_back(entry);
    }
}
 
void Row::update( double t){
  if(textures.size() > 0 ){
    textureTicCount += t;
    if(textureTicCount >= textureSwitchTime){
        textureTicCount -= textureSwitchTime;
        currentTexture++;
        if(currentTexture >= textures.size()){
           currentTexture = 0;
       }
       texture = textures.at(currentTexture);
    }
  }

  for(int i = 0; i < movingObjects.size(); i++){
    movingObjects.at(i)->update(t);
  }
}

void Row::draw(){
	float white[] = {1,1,1,1};
  float Emission[]  = {0.0,0.0,0,1.0};
  float shinyvec[] = {0};
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  glMaterialfv(GL_FRONT,GL_EMISSION,Emission);


 glEnable(GL_TEXTURE_2D);
 glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE); 
 glBindTexture(GL_TEXTURE_2D,texture);
 for(int i = 0; i < ROW_WIDTH; i++)
 {
     
 		glBegin(GL_POLYGON);
 		glNormal3f( 0,+1, 0);
  	glTexCoord2f(0,0);glVertex3f(i,0,0);
   	glTexCoord2f(1,0); glVertex3f(i+1,0,0);
  	glTexCoord2f(1,1); glVertex3f(i+1 ,0,1);
  	glTexCoord2f(0,1); glVertex3f(i ,0,1);
   	glEnd();
 	}
 	glDisable(GL_TEXTURE_2D);

  for(int i = 0; i < movingObjects.size(); i++){
      movingObjects.at(i)->draw();
  }
}