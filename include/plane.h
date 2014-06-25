/*
 * Plane.h
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Defines the main simulator plane
 */

#ifndef PLANE_HEADER
#define PLANE_HEADER

#include "stdhdr.h"

class Plane {
public:
	Plane();
	Plane(GLfloat, GLfloat, GLfloat, GLfloat);
	void setPointOne(GLfloat, GLfloat);
	void setPointTwo(GLfloat, GLfloat);
	void draw();
private:
	GLfloat x1,y1,x2,y2;
};

#endif /* PLANE_HEADER */
