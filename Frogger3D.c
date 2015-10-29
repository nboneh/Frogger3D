/*
 *  Hello World Triangle Version 1
 */
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))

double th=0;  //  Rotation around y 
double ta=0;  // Rotation around x

double w2h = 1; // Aspect ratio
int fov=55;       //  Field of view (for perspective)
const double dim=5;

#define LEN 8192  //  Maximum length of text string
void Print(const char* format , ...)
{
   char    buf[LEN];
   char*   ch=buf;
   va_list args;
   //  Turn the parameters into a character string
   va_start(args,format);
   vsnprintf(buf,LEN,format,args);
   va_end(args);
   //  Display the characters one at a time at the current raster position
   while (*ch)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*ch++);
}


void project(){
   //  Switch to manipulating the projection matrix
    glMatrixMode(GL_PROJECTION);
   //  Undo previous transformations
   glLoadIdentity();
    gluPerspective(fov,w2h,dim/4,4* dim);

   //  Switch to manipulating the model matrix
   glMatrixMode(GL_MODELVIEW);
}

void idle()
{
    //  Elapsed time in seconds
   double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   glutPostRedisplay();
}

void display()
{
   //  Clear screen
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();

   double Ex = (-2*dim*Sin(th)*Cos(ta));
   double Ey = (+2*dim        *Sin(ta));
   double Ez = (+2*dim*Cos(th)*Cos(ta));
   gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ta),0);

   //  Make scene visible
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}


void special(int key,int x,int y)
{
     //  Right arrow - increase rotation by 5 degree
   if (key == GLUT_KEY_RIGHT){
         ;
   }
   //  Left arrow - decrease rotation by 5 degree
   else if (key == GLUT_KEY_LEFT){
        ;
   }
   
   //  Up Arrow - increase rotation by 5 degree
   else if (key == GLUT_KEY_UP){
        ;
   }
   //  Down Arrow - decrease rotation by 5 degree
   else if (key == GLUT_KEY_DOWN){
          ;
   }

   glutPostRedisplay();

}

void key(unsigned char ch,int x,int y)
{
   //  Exit on ESC
   if (ch == 27)
      exit(0);


   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}



void reshape(int width,int height)
{
   //  Ratio of the width to the height of the window
    w2h = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   project();
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


   //  Pass control to GLUT for events
   glutMainLoop();
   //  Return to OS
   return 0;
}
