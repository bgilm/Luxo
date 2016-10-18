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

Sphere* foco;
Cylinder* base;
Cylinder* pole;
Cylinder* pole1;
Cylinder* pole2;
Cylinder* pole3;
Cylinder* pole4;
Cone* cone;



void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glRotatef( deltaY, 1.0, 0.0, 0.0 );
	glRotatef( deltaX, 0.0, 1.0, 0.0 );

	foco->draw();
    base->draw();
    cone->draw();
    pole->draw();
    pole1->draw();
    pole2->draw();
    pole3->draw();
    pole4->draw();

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

	float posCono[]  = { 0.0f,  2.5f, 0.0f };
	float sizeFoco[] = { 1.0f,  1.0f, 1.0f };

	float posBase[]  = { 0.0f, -2.0f, 0.0f };
	float sizeBase[] = { 2.0f,  0.5f, 2.0f };

	//float pos2[]  = { 3.0f,  0.0f, 0.0f };
	float sizeCono[] = { 2.0f,  2.0f, 2.0f };
    
    float sizePole0[] = { 0.5f,  3.0f, 0.5f };
    
    float posFoco[] = {posCono[0],static_cast<float>(posCono[1]-.25),posCono[2]};
    
    float posPole0[]  = { posBase[0], static_cast<float>(posBase[1]+0.75), posBase[2] };
    
    float sizePole1[] = {sizePole0[0]/2,sizePole0[1],sizePole0[2]/2};
    float posPole1[]  = { posPole0[0]+0.35f, posPole0[1]+1.25f, posBase[2] };
    
    float posPole2[]  = { posPole0[0]-0.35f, posPole0[1]+1.25f, posBase[2] };
    
    float posPole3[]  = { posPole0[0], posPole0[1]+2.25f, posBase[2] };
    float posPole4[]  = { posPole0[0], posPole0[1]+2.75f, posBase[2] };
    
    float sizePole3[] = {0.5f,1.25,0.5f};
    
    
    
   
    
    
    
  
    
	
    base = new Cylinder( posBase, sizeBase );
    
    cone = new Cone(posCono,sizeCono);
    foco = new Sphere( posFoco, sizeFoco );
    pole = new Cylinder(posPole0,sizePole0);
    pole1 = new Cylinder(posPole1,sizePole1);
    pole2 = new Cylinder(posPole2,sizePole1);
    pole3 = new Cylinder(posPole3,sizePole3);
    pole4 = new Cylinder(posPole4,sizePole3);
	
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
		delete foco;
        delete base;
		
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
	glutInitWindowSize( 1024, 2048 );
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
