#include "winningrow.h"

WinningRow::WinningRow(std::vector<unsigned int> _textures, float _textureSwitchTime, unsigned int _boundaryTexture): Row( _textures, _textureSwitchTime){
        boundaryTexture =_boundaryTexture;
        numOfWinningAreas = ROW_WIDTH/3 + 1;
        wonAreas.resize(numOfWinningAreas);
        reset();
}

void WinningRow::reset(){
    for(int i = 0; i < numOfWinningAreas; i++){
        wonAreas.at(i) = false;
    }
}

void WinningRow::checkColisonWithFrog(Frog* frog){
    if(frog->isRespawning())
        return;
    for(int i = 0; i < numOfWinningAreas; i++){
        if(wonAreas.at(i) == false){
            float x = .5 + i *3;
            if((frog->getX() +.6) >=  x && (x + 1) >= (frog->getX()+.4)){
                if(!frog->movingVertically()){
                    PlaySound("win.wav");
                    frog->respawn();
                    wonAreas.at(i) = true;
                    SCORE += floor(TIME) * 10;
                    PRINT_WIN_TIME = true;
                    WIN_TIME = TIME;
                    for(int j = 0; j < numOfWinningAreas; j++){
                        //Checking if get all winning areas
                        if(wonAreas.at(j) == false)
                            return;
                    }
                    SCORE += 1000;
                    LEVEL++;
                    reset();
                }
                return;
            }
        }
    }
    frog->stopMovement();
    frog->setY(ceil(frog->getY()));
    PlaySound("fail.wav");
}

void WinningRow::draw(){
float white[] = {1,1,1,1};
float Emission[]  = {0.0,0.0,0,1.0};
float shinyvec[] = {0};
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
glMaterialfv(GL_FRONT,GL_EMISSION,Emission);


glEnable(GL_TEXTURE_2D);
glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE); 
glPushMatrix();
glTranslatef(0,-.4,0);

glBindTexture(GL_TEXTURE_2D,texture);
 for(int j =0; j > -2; j--){
    for(int i = 0; i < ROW_WIDTH; i++){

      if(i % 3 == 0){
        if(j == 0){
          drawLeftBoundaryRightReg(i,j);
          i++;
          drawLeftRegRightBoundary(i,0);
          if(wonAreas.at(i/3)){
            glPushMatrix();
            glTranslatef(i-.5,0,0);
            draw2DFrog();
            glPopMatrix();
          }
        } else{
          drawLeftBoundaryRightRegWithTop(i,j);
          i++;
          drawLeftRegRightBoundaryWithTop(i,j);
        }
      }
      else{
        glBindTexture(GL_TEXTURE_2D,boundaryTexture); 
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,0);glVertex3f(i,0,j);
        glTexCoord2f(1,0); glVertex3f(i+1,0,j);
        glTexCoord2f(1,1); glVertex3f(i+1 ,0,j+1);
        glTexCoord2f(0,1); glVertex3f(i ,0,j+1);
        glEnd();
      }
    }
  }
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
} 

void WinningRow::drawLeftBoundaryRightReg(int x, int y){
        glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,0);glVertex3f(x,0,y);
        glTexCoord2f(.5,0); glVertex3f(x+.5,0,y);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glTexCoord2f(0,1); glVertex3f(x ,0,y+1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D,texture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(.5,0);glVertex3f(x+.5,0,y);
        glTexCoord2f(1,0); glVertex3f(x+1,0,y);
        glTexCoord2f(1,1); glVertex3f(x+1 ,0,y+1);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glEnd();
}

void WinningRow::drawLeftRegRightBoundary(int x, int y){
        glBindTexture(GL_TEXTURE_2D,texture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,0);glVertex3f(x,0,y);
        glTexCoord2f(.5,0); glVertex3f(x+.5,0,y);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glTexCoord2f(0,1); glVertex3f(x ,0,y+1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(.5,0);glVertex3f(x+.5,0,y);
        glTexCoord2f(1,0); glVertex3f(x+1,0,y);
        glTexCoord2f(1,1); glVertex3f(x+1 ,0,y+1);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glEnd();
}

void WinningRow::drawLeftBoundaryRightRegWithTop(int x, int y){

        glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,0);glVertex3f(x,0,y);
        glTexCoord2f(.5,0); glVertex3f(x+.5,0,y);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glTexCoord2f(0,1); glVertex3f(x ,0,y+1);
        glEnd();

         glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(.5,0);glVertex3f(x+.5,0,y);
        glTexCoord2f(1,0); glVertex3f(x+1,0,y);
        glTexCoord2f(1,.5); glVertex3f(x+1 ,0,y+.5);
        glTexCoord2f(.5,.5); glVertex3f(x+.5 ,0,y+.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D,texture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(.5,.5);glVertex3f(x+.5,0,y+.5);
        glTexCoord2f(1,.5); glVertex3f(x+1,0,y+.5);
        glTexCoord2f(1,1); glVertex3f(x+1 ,0,y+1);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glEnd();
}


void WinningRow::drawLeftRegRightBoundaryWithTop(int x, int y){
       glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(.5,0);glVertex3f(x+.5,0,y);
        glTexCoord2f(1,0); glVertex3f(x+1,0,y);
        glTexCoord2f(1,1); glVertex3f(x+1 ,0,y+1);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glEnd();

         glBindTexture(GL_TEXTURE_2D,boundaryTexture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,0);glVertex3f(x,0,y);
        glTexCoord2f(.5,0); glVertex3f(x+.5,0,y);
        glTexCoord2f(.5,.5); glVertex3f(x+.5 ,0,y+.5);
        glTexCoord2f(0,.5); glVertex3f(x ,0,y+.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D,texture);
        glBegin(GL_POLYGON);
        glNormal3f( 0,+1, 0);
        glTexCoord2f(0,.5);glVertex3f(x,0,y+.5);
        glTexCoord2f(.5,.5); glVertex3f(x+.5,0,y+.5);
        glTexCoord2f(.5,1); glVertex3f(x+.5 ,0,y+1);
        glTexCoord2f(0,1); glVertex3f(x ,0,y+1);
        glEnd();
  }
