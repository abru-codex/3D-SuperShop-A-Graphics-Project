#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "gl_compat.h"

void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1,
                 GLfloat x2, GLfloat y2, GLfloat z2,
                 GLfloat x3, GLfloat y3, GLfloat z3);

void drawCube(GLfloat difX, GLfloat difY, GLfloat difZ,
              GLfloat ambX, GLfloat ambY, GLfloat ambZ,
              GLfloat shine = 50);

void drawSphere(GLfloat difX, GLfloat difY, GLfloat difZ,
                GLfloat ambX, GLfloat ambY, GLfloat ambZ,
                GLfloat shine = 50, GLint slices = 30, GLint stacks = 30);

void drawCylinder(float radius, float height, int slices);

#endif
