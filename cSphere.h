#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#ifndef SPHERE
#define SPHERE

class Sphere
{
public:
					Sphere		( float*	position,
								  float*	_size		);
					~Sphere		( void					);

	void			draw		( void					);

private:
	float			pos[3];
	float			size[3];
	float			sph_vertices[382][3];
	float			sph_normals[382][3];
	float			sph_colors[382][3];
	unsigned int	sph_v_index[2280];
};

#endif SPHERE
