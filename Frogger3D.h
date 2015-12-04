#ifndef Frogger3D
#define Frogger3D

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))
#define PI 3.14159265


#ifdef __cplusplus
extern "C" {
#endif

extern int SCORE;
extern int ROW_WIDTH;
extern unsigned int WATER;
extern unsigned int WATER2;
extern unsigned int WATER3;
extern unsigned int WATER4;
extern unsigned int ROAD;
extern unsigned int GRASS;
extern unsigned int CONCRETE;
extern unsigned int BARK;
extern unsigned int LOG;
extern bool FROG_PASS_CARS;

void Print(const char* format , ...);
void Fatal(const char* format , ...);
unsigned int  LoadTexBMP(const char* file);
void Project(double fov,double asp,double dim);
void ErrCheck(const char* where);
void PlaySound(const char* soundname);

void drawCylinderNoText();
void drawCylinder(unsigned int texture, unsigned int topTexture);
void drawHalfCylinder();
void drawBall();
void drawCube();
void draw2DFrog();

enum direction{
	up,
	down,
	left,
	right
};

enum deathType{
	drown,
	roadkill
};

enum frogState{
	normal,
	moving,
	dying,
	respawning
};

#ifdef __cplusplus
}


#endif

#endif
