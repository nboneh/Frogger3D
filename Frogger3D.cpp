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

int widthOfScreen;
int heightOfScreen;
int ROW_WIDTH = 14;
int SCORE = 0;

float distance  =   7;  // Light distance
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
int ambient   =  30;  // Ambient intensity (%)
int diffuse   = 100;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shinyvec[1];    // Shininess (value)
double zh =  310;  // Light azimuth
float ylight  =   5;  // Elevation of light


void drawLight(){
   //  Translate intensity to color vectors
   float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
   float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
   float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
   //  Light position

   float Position[]  = {distance*Cos(zh),ylight,distance*Sin(zh),1.0};
    //  Draw light position as ball (still no lighting here)
   glColor3f(1,1,1);
   glPushMatrix();
   glTranslatef(Position[0],Position[1],Position[2]);
   glScalef(.1, .1,.1);
   drawBall();
   glPopMatrix();
   //  OpenGL should normalize normal vectors
   glEnable(GL_NORMALIZE);
   //  Enable lighting
   glEnable(GL_LIGHTING);
   //  glColor sets ambient and diffuse color materials
   glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
   //  Enable light 0
   glEnable(GL_LIGHT0);
   //  Set ambient, diffuse, specular components and position of light 0
   glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
   glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
   glLightfv(GL_LIGHT0,GL_POSITION,Position);
}
void idle()
{
    //  Elapsed time in seconds
   double currentT = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   double t = currentT - prevT;
   board->update(t);
   prevT = currentT;
   glutPostRedisplay();
}

void printScore(){
   glDisable(GL_DEPTH_TEST);
   glLineWidth(3);
   glRotatef(-th,0,1,0);
   glRotatef(-ph,1,0,0);
   
   glPushMatrix();
   glTranslatef(-5, -5,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   glColor3f(1,1,1);
   Print("Score");
   glPopMatrix();

   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(-2.5, -5,0);
   glScalef(1/152.0, 1/152.0, 1/152.0);
   Print("%d", SCORE);
   glPopMatrix();

   glEnable(GL_DEPTH_TEST);

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

   drawLight();
   board->draw();

   printScore();



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

   board = new Board();

   //  Pass control to GLUT for events
   glutMainLoop();
   //  Return to OS
   return 0;
}

