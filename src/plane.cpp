/*
 * Plane.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Implementation for Plane class
 */

#include "plane.h"

Plane::Plane(){
	this->x1 = this->y1 = this->x2 = this->y2 = 0;
}

Plane::Plane(GLfloat tx1, GLfloat ty1, GLfloat tx2, GLfloat ty2){
	this->x1 = tx1;
	this->x2 = tx2;
	this->y1 = ty1;
	this->y2 = ty2;
}

void Plane::setPointOne(GLfloat tx1, GLfloat ty1){
	this->x1 = tx1;
	this->y1 = ty1;
}

void Plane::setPointTwo(GLfloat tx2, GLfloat ty2){
	this->x2 = tx2;
	this->y2 = ty2;
}

void Plane::draw(){

	glBegin(GL_POLYGON);

	/* We need to draw it in the XZ plane */

	glColor3f(0.0,0.0,1.0);
	glVertex3f(x1,-0.5,y1);
	glVertex3f(x1,-0.5,y2);
	glVertex3f(x2,-0.5,y2);
	glVertex3f(x2,-0.5,y1);

	glEnd();
}
