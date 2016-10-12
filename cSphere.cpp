#include "cSphere.h"

Sphere::Sphere( float* position, float* _size )
{
	pos[0]  = position[0];
	pos[1]  = position[1];
	pos[2]  = position[2];

	size[0] = _size[0];
	size[1] = _size[1];
	size[2] = _size[2];

#include "sphereData.h"

}

Sphere::~Sphere( void )
{

}

void Sphere::draw( void )
{
	glPushMatrix();
	{
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(size[0], size[1], size[2]);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, sph_vertices);
		glColor3f(0.0f, 0.0f, 1.0f);
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, sph_colors);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, sph_normals);

		glDrawElements(GL_TRIANGLES, 2280, GL_UNSIGNED_INT, sph_v_index);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();
}
