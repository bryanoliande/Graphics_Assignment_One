/*
 * OpenGL demonstration program for UCI ICS Computer Graphics courses
 *
 */

#include "sceneModule.h"
#include "inputModule.h"

//Sets the window width and height
#define IMAGE_WIDTH  512
#define IMAGE_HEIGHT 512

int window;


//GLfloat represents a 32 bit color
GLfloat fieldOfView;
GLfloat aspect;
GLfloat nearPlane;
GLfloat farPlane;

//##########################################
// Init display settings

void initDisplay( ){
    /* Perspective projection parameters */
	
    fieldOfView = 45.0;
    aspect = (float)IMAGE_WIDTH/IMAGE_HEIGHT;
    nearPlane   = 0.1;
    farPlane    = 50.0;
    
    /* setup context */
    glMatrixMode( GL_PROJECTION ); //specifies the current matrix
    glLoadIdentity( );
    gluPerspective( fieldOfView, aspect, nearPlane, farPlane );
    
    glEnable( GL_DEPTH_TEST );
    glDisable( GL_CULL_FACE );
    
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClearDepth( 1 );
    
    glMatrixMode( GL_MODELVIEW );
}

//##########################################
// Main function

int main( int argc, char **argv ){
    
    //CREATES THE WINDOW
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB |
                        GLUT_DEPTH | GLUT_MULTISAMPLE );
    
    glutInitWindowSize( IMAGE_WIDTH,IMAGE_HEIGHT );
    
    glutInitWindowPosition(100,120);
    window = glutCreateWindow("Assignment 1");
    
    /* Register the appropriate callback functions with GLUT */
    glutDisplayFunc( display );
    glutKeyboardFunc( readKeyboard );
    glutMouseFunc( mouseButtHandler );
    glutMotionFunc( mouseMoveHandler );
    glutPassiveMotionFunc( mouseMoveHandler );
    
    initDisplay( );
    glutMainLoop( ); /*glutMainLoop enters the GLUT event processing loop. This routine should be called at most once in a GLUT program. Once called, this routine will never return. It will call as necessary any callbacks that have been registered.*/
    
    return( 0 );
}
