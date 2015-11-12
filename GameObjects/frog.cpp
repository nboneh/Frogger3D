#include "frog.h"

Frog::Frog(float _spawnX, float _spawnY, direction _spawnDirection){
	spawnX = _spawnX;
	spawnY = _spawnY;
	spawnDirection = _spawnDirection;
	deathFrameTic = .1;
	x = spawnX;
	y = spawnY;
	facingDirection = spawnDirection;
	state = normal;
	lives =3;
	farthestY = (int)y;
}


void Frog::update(double t){
	float move;
	bool yFinished = false; 
	bool xFinished = false;
	switch(state){
	case normal:
		break;
	case moving:
		move = t*5;
		switch(facingDirection){
			case up:
			  y -= move;
			  if(y <= desty){
					y = desty;
					state = normal;
					if(y < farthestY){
						SCORE +=  (farthestY -(int)y ) *10;
						farthestY = (int)y;
					}
				}
			  break;
			case down:
				y += move;
				if(y >= desty){
					y = desty;
					state = normal;
				}
				break;
			case left:
				x -= move;
				if(x <= destx){
					x = destx;
					state = normal;
				}
				break;
			case right:
				x += move;
				if(x >= destx){
					x = destx;
					state = normal;
				}
				break;
		}
		break;
	case respawning:
			//Moving camera to respawn location
			x += respawnRateX*t;
			y += respawnRateY*t;

		
			if(respawnRateY >= 0 && y >= spawnY ){
				y = spawnY;
				yFinished = true; 
			}
			else if(respawnRateY < 0 && y <= spawnY){
				y = spawnY;
				yFinished = true; 
			}

			if(respawnRateX >= 0 && x >= spawnX ){
				x = spawnX;
				xFinished = true; 
			}
			else if(respawnRateX < 0 && x <= spawnX){
				x= spawnX;
				xFinished = true; 
			}

			if(yFinished && xFinished)
				state = normal;
			break;
	case dying: 
			//Playing death animation
			deathFrameTicCount += t;
			if(deathFrameTicCount >= deathFrameTic){
				deathFrameTicCount -= deathFrameTic;
				deathFrame++;
				if(deathFrame >= 4){
					respawn();
				}
			}
			break;
		}
	}

void Frog::inputDirection(direction moveDirection){
	if(!isInNormalState())
		return;
	facingDirection = moveDirection;
	state = moving; 
	switch(facingDirection){
		case up:
			desty = y - 1;
			break;
		case down:
			desty = y+1;
			break;
		case left:
			destx = x -1;
			break;
		case right:
			destx = x + 1;
			break;
	}

}

void Frog::respawn(){
	//Calculating camera movement rate
	farthestY = spawnY;
	state = respawning;
	float distToSpawnX = spawnX -x;
	float distToSpawnY = spawnY -y;
	float angle = atan (fabs(distToSpawnX/distToSpawnY)) * 180 / PI;
					
	respawnRateX = 5*Sin(angle);
	if(distToSpawnX < 0)
		respawnRateX = -respawnRateX;

	respawnRateY = 5*Cos(angle);
	if(distToSpawnY < 0)
		respawnRateY = -respawnRateY;

	facingDirection = spawnDirection;
			
}

void Frog::draw(){
	glPushMatrix();
	glTranslatef(x , 0, y);
	switch(facingDirection){
		case up:
			break;
		case down:
			glRotatef(180, 0,1,0);
			glTranslatef(-1,0,1);
			break;
		case left:
			glRotatef(90, 0,1,0);
			glTranslatef(0,0,1);
			break;
		case right:
			glRotatef(270, 0,1,0);
			glTranslatef(-1,0,0);
			break;
	}
	glColor3f(0,1,0);
	switch(state){
		case dying:
			drawDeath();
			break;
		case moving:
			drawJumpingFrog();
			break;
		case normal: 
			drawFrog();
			break;
		case respawning:
			break;
	}
	glPopMatrix();
}

void Frog::drawDeath(){
	switch(deathFrame){
		case 0:
			if(typeOfDeath == roadkill){
				glColor3f(1,0,0);
				glBegin(GL_POLYGON);
    			glVertex3f(0,.01, 0);
    			glVertex3f(0,.01, -.2);
    			glVertex3f(.2,.01, -.2);
    			glVertex3f(.2,.01, 0);
    			glEnd();

			}
			else if(typeOfDeath == drown){


			}
			break;
		case 1:
			if(typeOfDeath == roadkill){
				glColor3f(1,0,0);
				glBegin(GL_POLYGON);
    			glVertex3f(0,.01, 0);
    			glVertex3f(0,.01, -.6);
    			glVertex3f(.6,.01, -.6);
    			glVertex3f(.6,.01, 0);
    			glEnd();
				
			}

			else if(typeOfDeath == drown){

			}
			break;
		case 2:
			if(typeOfDeath == roadkill){
				glColor3f(1,0,0);
				glBegin(GL_POLYGON);
    			glVertex3f(0,.01, 0);
    			glVertex3f(0,.01, -.8);
    			glVertex3f(.8,.01, -.8);
    			glVertex3f(.8,.01, 0);
    			glEnd();
			}

			else if(typeOfDeath == drown){

			}
			break;
		case 3:
			//Draw skull
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
    		glVertex3f(0,.01, 0);
    		glVertex3f(0,.01, -1);
    		glVertex3f(1,.01, -1);
    		glVertex3f(1,.01, 0);
    		glEnd();
		  	break;
		case 4:
			break;
	}
}
void Frog::drawFrog(){
   glBegin(GL_POLYGON);
   glVertex3f(0,.01, 0);
   glVertex3f(.5,.01, -1);
   glVertex3f(1,.01, 0);
   glEnd();
}

bool Frog::isInNormalState(){
	return state == normal;
}
void Frog::die(deathType _typeOfDeath){
	if(state == dying || state == respawning)
		return;
	stopMovement();
	typeOfDeath = _typeOfDeath;
	state = dying; 
	deathFrameTicCount = 0;
	deathFrame = 0;
	lives--;
}

float Frog::getY(){
	return y;
}

float Frog::getX(){
	return x;
}

void Frog::setX(float _x){
	x = _x;
}

void Frog::setY(float _y){
	y = _y;
}

void Frog::stopMovement(){
	if(state == moving)
		state = normal;
}

bool Frog::movingVertically(){
  	return state == moving && (facingDirection == up || facingDirection == down);
}


void Frog::drawJumpingFrog(){
   glBegin(GL_POLYGON);
   glVertex3f(0,.01, 0);
   glVertex3f(.5,.01, -1.5);
   glVertex3f(1,.01, 0);
   glEnd();
}
