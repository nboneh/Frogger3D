#include "Frogger3D.h"
#include "GameObjects/board.h"

double dim=5.0;
int th=0;         //  Azimuth of view angle
int ph=45;         //  Elevation of view angle
double prevT = 0;
Board* board;

unsigned int WATER;
unsigned int WATER2;
unsigned int WATER3;
unsigned int WATER4;
unsigned int ROAD;
unsigned int GRASS;
unsigned int CONCRETE;
unsigned int BARK;
unsigned int LOG;
unsigned int WHEEL;
unsigned int WHEEL_TREAD;

int widthOfScreen;
int heightOfScreen;
int ROW_WIDTH = 14;
int SCORE = 0;
float TIME = 60;
bool FROG_PASS_CARS = false;
bool UPDATE_TIME = true;
bool PRINT_WIN_TIME = false;
int WIN_TIME = 0;
int LEVEL = 0;
bool paused = false;
bool BIRD_EYE_VIEW = false;

void idle()
{
    //  Elapsed time in seconds
   double currentT = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   double t = currentT - prevT;
    
    if(!paused){
    if(UPDATE_TIME && TIME >= 0){
       TIME = TIME - t;
       PRINT_WIN_TIME = false;
    }
    board->update(t);
   }
   prevT = currentT;
   glutPostRedisplay();
}

void printLives(){
   int lives = board->getFrogLives();
   for(int i = 0; i < lives; i++){
      glPushMatrix();
      glTranslatef(-6+i,-4 ,0);
      glScalef(.7,.7,1);
      glRotatef(-90,1,0,0);
      draw2DFrog();
      glPopMatrix();
   }
}

void printScore(){
   glLineWidth(3);
   glRotatef(-th,0,1,0);
   glRotatef(-ph,1,0,0);

   glPushMatrix();
   glTranslatef(-6, -5,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   glColor3f(1,1,1);
   Print("Score");
   glPopMatrix();

   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(-3.5, -5,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   Print("%d", SCORE);
   glPopMatrix();

}

void drawTime(){
   glPushMatrix();
   glTranslatef(5.1, -5,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   glColor3f(1,1,0);
   Print("Time");
   glPopMatrix();


  float startX = 5 -5*(TIME/60);
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
    glVertex3f(startX,-4.5, 0);
    glVertex3f(startX,-5, 0);
    glVertex3f(5,-5, 0);
    glVertex3f(5,-4.5, 0);
    glEnd();
}


void printWinTime(){
   glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-2,-.2, 0);
    glVertex3f(-2,.8, 0);
    glVertex3f(2.2,.8, 0);
    glVertex3f(2.2,-.2, 0);
    glEnd();

    glPushMatrix();
   glTranslatef(-1.8, 0,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   glColor3f(1,0,0);
   Print("Time: %d", WIN_TIME );
   glPopMatrix();
}

void printGameOver(){

  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex3f(-2.7,-.6, 0);
  glVertex3f(-2.7,1.3, 0);
  glVertex3f(3.4,1.3, 0);
  glVertex3f(3.4,-.6, 0);
  glEnd();


  glPushMatrix();
  glTranslatef(-1.9, .4,0);
  glScalef(1/152.0, 1/152.0, 1/152.0);
  glColor3f(1,0,0);
  Print("Game Over");
  glPopMatrix();


 
  glPushMatrix();
  glTranslatef(-2.5, -.4,0);
  glScalef(1/300.0, 1/300.0, 1/300.0);
  glColor3f(1,1,1);
  Print("Press any button to retry");
  glPopMatrix();
}

void printPause(){

  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex3f(-3.2,-.6, 0);
  glVertex3f(-3.2,1.3, 0);
  glVertex3f(3.3,1.3, 0);
  glVertex3f(3.3,-.6, 0);
  glEnd();


  glPushMatrix();
  glTranslatef(-1.5, .4,0);
  glScalef(1/152.0, 1/152.0, 1/152.0);
  glColor3f(1,0,0);
  Print("Paused");
  glPopMatrix();


 
  glPushMatrix();
  glTranslatef(-3, -.4,0);
  glScalef(1/300.0, 1/300.0, 1/300.0);
  glColor3f(1,1,1);
  Print("Press any button to resume");
  glPopMatrix();
}


void display()
{
   //  Clear screen
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();
   double Ex = (-2*dim*Sin(th)*Cos(ph));
   double Ey = (+2*dim        *Sin(ph));
   double Ez = (+2*dim*Cos(th)*Cos(ph));
   gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);

   board->draw();
   
   glDisable(GL_LIGHTING);
   glDisable(GL_DEPTH_TEST);
   printScore();
   printLives();
   drawTime();
    
   if(paused){
    printPause();
   }
   else if(PRINT_WIN_TIME){
      printWinTime();
   }
   else if(board->getFrogLives() == 0){
      UPDATE_TIME = false;
      printGameOver();
   }

   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);


   //  Make scene visible
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}



void special(int key,int x,int y)
{
     //  Right arrow - increase rotation by 5 degree
   if (key == GLUT_KEY_RIGHT)
      th += 5;
   //  Left arrow - decrease rotation by 5 degree
   else if (key == GLUT_KEY_LEFT)
      th -= 5;

   //  Up Arrow - increase rotation by 5 degree
   else if (key == GLUT_KEY_UP)
      ph -= 5;
   //  Down Arrow - decrease rotation by 5 degree
   else if (key == GLUT_KEY_DOWN)
      ph += 5;

   glutPostRedisplay();

}

void key(unsigned char ch,int x,int y)
{
    if(board->getFrogLives() == 0){
      UPDATE_TIME =true;
      board->resetFrogLives();
      SCORE =0;
      LEVEL =0;
      PlaySound("start.wav");
      return;
    }

    if(paused){
      paused = false;
      PlaySound("clickoff.wav");
      return;
    }
   //  Exit on ESC
   if (ch == 27)
      exit(0);

   else if(ch == 'w'){
      board->inputDirection(up);
   }
   else if (ch == 'd'){
      board->inputDirection(right);
   }

   else if(ch == 's'){
      board->inputDirection(down);
   }

   else if(ch == 'a'){
      board->inputDirection(left);
   }

    else if(ch == 'm'  || ch == 'M'){
      if(BIRD_EYE_VIEW){
        BIRD_EYE_VIEW = false;
        ph=45; 
      } else {
         BIRD_EYE_VIEW = true;
        ph=90; 
      }
   }

   else if(ch == 'p'  || ch == 'P'){
      paused = true; 
      PlaySound("clickon.wav");
   }

   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}



void reshape(int width,int height)
{
   widthOfScreen = width;
   heightOfScreen = height;
   //  Ratio of the width to the height of the window
    double w2h = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   Project(55, w2h, dim);
}



/*
 * GLUT based Hello World
 */
int main(int argc,char* argv[])
{
   //  Initialize GLUT
   glutInit(&argc,argv);
   //  Request double buffered true color window with Z-buffer
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

   glutInitWindowSize(600, 600);
   //  Create window
   glutCreateWindow("Frogger3D");
   glutFullScreen();  

   //  Register display, reshape, and key callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutKeyboardFunc(key);
   glutIdleFunc(idle);
   glEnable(GL_DEPTH_TEST);

   WATER4 = LoadTexBMP("textures/water4.bmp");
   WATER3 = LoadTexBMP("textures/water3.bmp");
   WATER2 = LoadTexBMP("textures/water2.bmp");
   WATER  = LoadTexBMP("textures/water.bmp");

   GRASS = LoadTexBMP("textures/grass.bmp");
   ROAD = LoadTexBMP("textures/road.bmp");
   CONCRETE = LoadTexBMP("textures/concrete.bmp");

   BARK = LoadTexBMP("textures/bark.bmp");
   LOG = LoadTexBMP("textures/log.bmp");

   WHEEL = LoadTexBMP("textures/wheel.bmp");
   WHEEL_TREAD = LoadTexBMP("textures/wheeltread.bmp");

   board = new Board();
  PlaySound("start.wav");

   //  Pass control to GLUT for events
   glutMainLoop();
   //  Return to OS
   return 0;
}
