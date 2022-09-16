#include "TerrainQuads.h"
#include "Texture.h"
#include <iostream>
#include <GL/glut.h>

void TerrainQuads::SetCoords(float x, float y, float z) {

	glPushMatrix();
	glBegin(GL_POINTS); 
	{
		glVertex3f(x, y, z);
		std::cout << "qwlkemrlqwmekrlmqwe" << std::endl;
	}
	glEnd;
	glPopMatrix();
}
