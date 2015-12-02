#include "frog.h"

int TOTAL_DEATH_FRAME = 4;
float DEATH_FRAME_TIC = .1;



Frog::Frog(float _spawnX, float _spawnY, direction _spawnDirection){
	spawnX = _spawnX;
	spawnY = _spawnY;
	spawnDirection = _spawnDirection;
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
		totalMove += move;

		if(totalMove > 1){
			state = normal;
			move = move - (totalMove -1);
			if(y < farthestY){
				SCORE +=  (farthestY -(int)y ) *10;
				farthestY = (int)y;
			}
	    }
		switch(facingDirection){
			case up:
			  	y -= move;
			 	break;
			case down:
				y += move;
				break;
			case left:
				x -= move;
				break;
			case right:
				x += move;
				break;
		}
		break;
	case respawning:
			//Moving frog to respawn location
			if(!yFinished){
				if((respawnRateY >= 0 && y >= spawnY)  || (respawnRateY < 0 && y <= spawnY)|| (fabs(respawnRateY) < .1)){
					y = spawnY;
					yFinished = true;
				} else {
					y += respawnRateY*t;
				}
			}


			if(!xFinished){
				if((respawnRateX >= 0 && x >= spawnX) || (respawnRateX < 0 && x <= spawnX ) || (fabs(respawnRateX) < .1)){
					x = spawnX;
					xFinished = true;
				}else {
					x += respawnRateX*t;
				}
			}


			if(yFinished && xFinished)
				state = normal;
			break;
	case dying:
			//Playing death animation
			deathFrameTicCount += t;
			if(deathFrameTicCount >= DEATH_FRAME_TIC){
				deathFrameTicCount -= DEATH_FRAME_TIC;
				deathFrame++;
				if(deathFrame >= TOTAL_DEATH_FRAME){
					respawn();
				}
			}
			break;
		}
	}

void Frog::inputDirection(direction moveDirection){
	if(state != normal)
		return;
	facingDirection = moveDirection;
	state = moving;
	totalMove = 0;

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
			glTranslatef(.2,0,-.2);
			break;
		case down:
			glRotatef(180, 0,1,0);
			glTranslatef(-.8,0,.8);
			break;
		case left:
			glRotatef(90, 0,1,0);
			glTranslatef(.2,0,.8);
			break;
		case right:
			glRotatef(270, 0,1,0);
			glTranslatef(-.8,0,-.2);
			break;
	}
	glScalef(.15, .15, .09996);
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

static void drawFrogBody(){
	glColor3f(0,1,0);


   //Back
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, 1);
   glVertex3f(1,0, 0);
   glVertex3f(1,1, 0);
   glVertex3f(3,1, 0);
   glVertex3f(3,0, 0);
   glEnd();

   //Bottom
   glBegin(GL_QUADS);
    glNormal3f( 0, -.98, -.195);
   glNormal3f( 0, 0, 1);
   glVertex3f(1,0, 0);
   glVertex3f(0,1, -5);
   glVertex3f(4,1, -5);
   glVertex3f(3,0, 0);
   glEnd();

   //Top
   glBegin(GL_QUADS);
   glNormal3f( 0, .857, .51);
   glVertex3f(1,1, 0);
   glVertex3f(0,4, -5);
   glVertex3f(4,4, -5);
   glVertex3f(3,1, 0);
   glEnd();

    //Left Side
   glBegin(GL_QUADS);
   glNormal3f( -.98, 0, .195);
   glVertex3f(1,0, 0);
   glVertex3f(0,1, -5);
   glVertex3f(0,4, -5);
   glVertex3f(1,1, 0);
   glEnd();


   //Right Side
   glBegin(GL_QUADS);
   glNormal3f( .98, 0, .195);
   glVertex3f(3,1, 0);
   glVertex3f(4,4, -5);
   glVertex3f(4,1, -5);
   glVertex3f(3,0, 0);
   glEnd();

   //Drawing Face
   glPushMatrix();
   glTranslatef(4,2.5,-5);
   glScalef(4, 3,2);
   glRotatef(90,0,0,1);
   glRotatef(-90,1,0,0);
   drawHalfCylinder();
   glPopMatrix();

   //Mouth
   glColor3f(1,0,0);
   glPushMatrix();
   glTranslatef(3,2.2,-5.1);
   glScalef(2, 1,2);
   glRotatef(90,0,0,1);
   glRotatef(-90,1,0,0);
   drawHalfCylinder();
   glPopMatrix();

   glColor3f(1,1,1);

   //Upper teeth
   glPushMatrix();
   glTranslatef(3,2.4,-5.1);
   glScalef(2, .5,2);
   glRotatef(90,0,0,1);
   glRotatef(-90,1,0,0);
   drawHalfCylinder();
   glPopMatrix();

   //Lower teeth
   glPushMatrix();
   glTranslatef(3,2,-5.1);
   glScalef(2, .5,2);
   glRotatef(90,0,0,1);
   glRotatef(-90,1,0,0);
   drawHalfCylinder();
   glPopMatrix();

   //Left Nostril
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(2.2,3,-5.9);
   glScalef(.1,.1,.1);
   drawBall();
   glPopMatrix();

   //Right Nostril
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(1.8,3,-5.9);
   glScalef(.1,.1,.1);
   drawBall();
   glPopMatrix();

   //Drawing left eye lid
   glColor3f(0,1,0);
   glPushMatrix();
   glTranslatef(1.25,4,-4.75);
   drawBall();
   glPopMatrix();

   //Drawing left eye ball
   glColor3f(1,1,1);
   glPushMatrix();
   glTranslatef(1.25,4,-5.15);
   glScalef(.8,.8,.8);
   drawBall();
   glPopMatrix();

   //Drawing left eye pupil
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(1.25,4.1,-5.78);
   glScalef(.4,.2,.2);
   drawBall();
   glPopMatrix();

   //Drawing right eye lid
   glColor3f(0,1,0);
   glPushMatrix();
   glTranslatef(2.75,4,-4.75);
   drawBall();
   glPopMatrix();

   //Drawing right eye ball
   glColor3f(1,1,1);
   glPushMatrix();
   glTranslatef(2.75,4,-5.15);
   glScalef(.8,.8,.8);
   drawBall();
   glPopMatrix();

   //Drawing right eye pupil
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(2.75,4.1,-5.78);
   glScalef(.4,.2,.2);
   drawBall();
   glPopMatrix();

   //Tail
   glPushMatrix();
   glColor3f(1,1,0);
   glTranslatef(2,1,-4);
   glScalef(1,1,3);
   glRotatef(30, 1,0,0);
   glRotatef(45, 0,0,1);
   drawCube();
   glPopMatrix();
}

static void drawLeg(){
   glColor3f(0,1,0);
   glPushMatrix();
   glTranslatef(.5,0,-1);
   glScalef(.5,1,1);
   drawCube();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0,.2,-.5);
   glRotatef(90,0,1,0);
   glScalef(.3,.3,1);
   drawCylinderNoText();
   glPopMatrix();

    glPushMatrix();
   glTranslatef(0,.2,-1.3);
   glRotatef(50,0,1,0);
   glScalef(.3,.3,1);
   drawCylinderNoText();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0,.2,.3);
   glRotatef(130,0,1,0);
   glScalef(.3,.3,1);
   drawCylinderNoText();
   glPopMatrix();

}

void Frog::drawJumpingFrog(){
 	drawFrogBody();

 	//Draw back left Leg
   glPushMatrix();
   glTranslatef(.1,0,.5);
   glRotatef(15,0,1,0);
   drawLeg();
   glPopMatrix();

   //Draw back right Leg
   glPushMatrix();
   glTranslatef(3.9,0,-.5);
   glRotatef(165,0,1,0);
   drawLeg();
   glPopMatrix();

   //Draw front left Leg
   glPushMatrix();
   glTranslatef(0,.7,-6.6);
    glRotatef(30,1,0,0);
   glRotatef(-90,0,1,0);
  drawLeg();
   glPopMatrix();

    //Draw front right Leg
   glPushMatrix();
   glTranslatef(3,.7,-6.6);
   glRotatef(30,1,0,0);
   glRotatef(-90,0,1,0);
   drawLeg();
   glPopMatrix();

}

void Frog::drawFrog(){
   drawFrogBody();

    //Draw back left leg
   drawLeg();

   //Draw back right leg
   glPushMatrix();
   glTranslatef(4,0,-1);
   glRotatef(180,0,1,0);
   drawLeg();
   glPopMatrix();

   //Draw front left leg
   glPushMatrix();
   glTranslatef(0,0,-5);
   glRotatef(-90,0,1,0);
   drawLeg();
   glPopMatrix();

    //Draw front right leg
   glPushMatrix();
   glTranslatef(3,0,-5);
   glRotatef(-90,0,1,0);
 	drawLeg();
   glPopMatrix();


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
  if(state==dying || state == respawning)
    return;
	x = _x;
}

void Frog::setY(float _y){
  if(state==dying || state == respawning)
    return;
	y = _y;
}

void Frog::stopMovement(){
	if(state == moving)
		state = normal;
}

bool Frog::movingVertically(){
  	return state == moving && (facingDirection == up || facingDirection == down);
}
