#include "winningrow.h"

WinningRow::WinningRow(int _width, std::vector<unsigned int> _textures, float _textureSwitchTime, unsigned int _boundaryTexture): Row(_width,  _textures, _textureSwitchTime){
        boundaryTexture =_boundaryTexture;
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

glBindTexture(GL_TEXTURE_2D,texture);
 for(int j =0; j > -2; j--){
    for(int i = 0; i < width; i++){

      if(i % 3 == 0){
        if(j == 0){
          drawLeftBoundaryRightReg(i,j);
          i++;
          drawLeftRegRightBoundary(i,0);
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
