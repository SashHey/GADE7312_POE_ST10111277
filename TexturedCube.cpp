#include "TexturedCube.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>

void TexturedCube::drawGeometry() {


    glBegin(GL_QUADS); {
        glColor3f(1, 1, 1);
        //front face
        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, 1);

        glTexCoord2f(1, 0);
        glVertex3f(1, -1, 1);

        glTexCoord2f(1, 1);
        glVertex3f(1, 1, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-1, 1, 1);

        //back face
        glTexCoord2f(0, 0);
        glVertex3f(1, -1, -1);

        glTexCoord2f(1, 0);
        glVertex3f(-1, -1, -1);

        glTexCoord2f(1, 1);
        glVertex3f(-1, 1, -1);

        glTexCoord2f(0, 1);
        glVertex3f(1, 1, -1);

        //left face
        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, -1);

        glTexCoord2f(1, 0);
        glVertex3f(-1, -1, 1);

        glTexCoord2f(1, 1);
        glVertex3f(-1, 1, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-1, 1, -1);

        //right face
        glTexCoord2f(0, 0);
        glVertex3f(1, -1, 1);

        glTexCoord2f(1, 0);
        glVertex3f(1, -1, -1);

        glTexCoord2f(1, 1);
        glVertex3f(1, 1, -1);

        glTexCoord2f(0, 1);
        glVertex3f(1, 1, 1);

        //top face
        glTexCoord2f(0, 0);
        glVertex3f(-1, 1, 1);

        glTexCoord2f(1, 0);
        glVertex3f(1, 1, 1);

        glTexCoord2f(1, 1);
        glVertex3f(1, 1, -1);

        glTexCoord2f(0, 1);
        glVertex3f(-1, 1, -1);

        //bottom face
        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, -1);

        glTexCoord2f(1, 0);
        glVertex3f(1, -1, -1);

        glTexCoord2f(1, 1);
        glVertex3f(1, -1, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-1, -1, 1);

    }
    glEnd();
}