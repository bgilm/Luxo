#include "cCone.h"

Cone::Cone( float* position, float* _size )
{
	pos[0]  = position[0];
	pos[1]  = position[1];
	pos[2]  = position[2];

	size[0] = _size[0];
	size[1] = _size[1];
	size[2] = _size[2];

#include "coneData.h"
}

Cone::~Cone( void )
{

}

void Cone::draw( void )
{
	glPushMatrix();
	{
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(size[0], size[1], size[2]);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, cone_vertices);
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, cone_colors);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, cone_normals);

		glDrawElements(GL_TRIANGLES, 114, GL_UNSIGNED_BYTE, cone_v_index);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();
}
