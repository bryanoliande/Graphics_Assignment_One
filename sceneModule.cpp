/*
 * OpenGL demonstration program for UCI ICS Computer Graphics courses
 *
 */

#include "sceneModule.h"

GLfloat angley = 20;    /* in degrees */
GLfloat anglex = 30;   /* in degrees */
GLfloat distanceX = 0.0;
GLfloat distanceY = 0.0;
GLfloat distanceZ = 5.0;

//6 sides, the 4 numbers of each row set the color of each side
static float cubeColors[6][4] =
{
  {0.8, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.0, 1.0},
  {0.0, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.8, 1.0},
  {0.0, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.8, 1.0},
};

//sets the cubes vertices 6 represents 6 faces of the cube, the first 4 represents the 4 corners of one face
//the 2nd 4 represents the coordinates of one corner of the face.
static float cubeVertexes[6][4][4] =
{
  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0}}
};

void drawScene(){

    
  //each iteration of the loop draws one face of the cube.
    
  for (int i = 0; i < 6; i++) {
    glBegin(GL_POLYGON);  //delimit the vertices of a primitive or a group of like primitives
		glColor3fv(&cubeColors[i][0]); //The GL stores both a current single-valued color index and a current four-valued RGBA color. This stores the color of one face of the cube in the GL library
      
       //these just specify the vertices of the polygon (created above)
		glVertex4fv(&cubeVertexes[i][0][0]);
		glVertex4fv(&cubeVertexes[i][1][0]);
		glVertex4fv(&cubeVertexes[i][2][0]);
		glVertex4fv(&cubeVertexes[i][3][0]);
    glEnd();
  }
}

void sceneTransformation(){
  glLoadIdentity( ); //glLoadIdentity replaces the current matrix with the identity matrix.

  glTranslatef(-distanceX, distanceY, -distanceZ); //glTranslate moves the coordinate system origin to the point specified by (x,y,z).
    
    //glRotate computes a matrix that performs a counterclockwise rotation of angle degrees about the vector from the origin through the point (x, y, z).
    

  glRotatef( anglex, 1.0, 0.0, 0.0 );
  glRotatef( angley, 0.0, 1.0, 0.0 );
}

void display(){
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  /* Set up transformation */
  sceneTransformation();
  /* Draw the scene into the back buffer */
  drawScene();
  /* Swap the front buffer with the back buffer - assumes double buffering */
  glutSwapBuffers();
}
