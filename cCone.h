#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

#ifndef CONE
#define CONE

class Cone
{
public:
					Cone		( float*	position,
								  float*	_size		);
					~Cone		( void					);

	void			draw		( void					);

private:
	float			pos[3];
	float			size[3];
	float			cone_vertices[21][3];
	float			cone_normals[21][3];
	float			cone_colors[21][3];
	unsigned char	cone_v_index[114];
};

#endif CONE
