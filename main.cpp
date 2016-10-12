/*
	Computer Graphics

	Sphere with Vertex Arrays.
*/

#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#include "cSphere.h"
#include "cCylinder.h"
#include "cCone.h"

int width, height;
float deltaX, deltaY;
GLdouble fovy;

Sphere* sph0;
Cylinder* c0;
Cone* cone;


void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glRotatef( deltaY, 1.0, 0.0, 0.0 );
	glRotatef( deltaX, 0.0, 1.0, 0.0 );

	sph0->draw();
    c0->draw();
    cone->draw();

	glutSwapBuffers();
}

void idle( void )
{
	glutPostRedisplay();
}

void init( void ) 
{
	fovy = 45.0;

	glEnable( GL_DEPTH_TEST );
	glShadeModel( GL_FLAT );
	glClearColor( 0.0, 0.0, 0.0, 1.0 );

	float pos0[]  = { 0.0f,  0.0f, 0.0f };
	float size0[] = { 2.0f,  2.0f, 2.0f };

	float pos1[]  = { -3.0f, 0.0f, 0.0f };
	float size1[] = { 2.0f,  2.0f, 2.0f };

	float pos2[]  = { 3.0f,  0.0f, 0.0f };
	float size2[] = { 2.0f,  2.0f, 2.0f };

	sph0 = new Sphere( pos0, size0 );
    c0 = new Cylinder( pos1, size1 );
    cone = new Cone(pos2,size2);
	
}

void reshape( int w, int h )
{
	width  = w;
	height = h;
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	gluPerspective( fovy, w / h * 1.0, 0.01, 20 );
	glTranslatef( 0, 0, -10 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void keys( unsigned char key, int x, int y )
{
	switch( key )
	{
	case 'r': case 'R':
		glClearColor( 1.0, 0.0, 0.0, 1.0 );
		break;
	case 'b': case 'B':
		glClearColor( 0.0, 0.0, 1.0, 1.0 );
		break;
	case '0':
		glClearColor( 0.0, 0.0, 0.0, 1.0 );
		break;
	case 27:
		delete sph0;
        delete c0;
		
	default:
		break;
	}
}

void mouse( int button, int state, int x, int y )
{
	
}

void mouseWheel( int button, int dir, int x, int y )
{
    if( dir > 0 )	// ZOOM_IN
    {
        fovy -= 1.0;
		if( fovy < 10.0 )
		{
			fovy = 10.0;
		}
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		gluPerspective( fovy, width / height * 1.0, 0.01, 20 );
		glTranslatef( 0, 0, -10 );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
    }
    else			// ZOOM_OUT
    {
        fovy += 1.0;
		if( fovy > 70.0 )
		{
			fovy = 70.0;
		}
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		gluPerspective( fovy, width / height * 1.0, 0.01, 20 );
		glTranslatef( 0, 0, -10 );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
    }
}

void move( int x, int y )
{
	static int lastX = 0, lastY = 0;
	deltaX += lastX - x;
	deltaY += lastY - y;
	lastX = x;
	lastY = y;
}

int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 512, 512 ); 
	glutInitWindowPosition( 600, 100 );
	glutCreateWindow( "Sphere with Vertex Arrays" );

	glutReshapeFunc( reshape );
	glutKeyboardFunc( keys );
	glutMotionFunc( move );
	glutMouseFunc( mouse );
    
	

	init();
	glutDisplayFunc( display ); 
	glutIdleFunc( idle );
	glutMainLoop();
	return 0;
}
