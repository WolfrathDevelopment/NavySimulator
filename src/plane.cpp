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

	glColor3f(0.0,0.0,1.0);

	/* Top side */

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(x1,0.0,y1);
	glVertex3f(x1,0.0,y2);
	glVertex3f(x2,0.0,y2);
	glVertex3f(x2,0.0,y1);
	glEnd();

	/* Bottom side */

	glColor3f(0.0,0.0,1.0);

	glBegin(GL_POLYGON);
	glVertex3f(x1,-0.1,y1);
	glVertex3f(x1,-0.1,y2);
	glVertex3f(x2,-0.1,y2);
	glVertex3f(x2,-0.1,y1);
	glEnd();

	/* Front side */

	glBegin(GL_POLYGON);
	glVertex3f(x1,-0.1,y1);
	glVertex3f(x1, 0.0,y1);
	glVertex3f(x2, 0.0,y1);
	glVertex3f(x2,-0.1,y1);
	glEnd();

	/* Back side */

	glBegin(GL_POLYGON);
	glVertex3f(x1,-0.1,y2);
	glVertex3f(x1, 0.0,y2);
	glVertex3f(x2, 0.0,y2);
	glVertex3f(x2,-0.1,y2);
	glEnd();

	/* Left side */

	glBegin(GL_POLYGON);
	glVertex3f(x1,-0.1,y1);
	glVertex3f(x1, 0.0,y2);
	glVertex3f(x1, 0.0,y2);
	glVertex3f(x1,-0.1,y1);
	glEnd();

	/* Right side */

	glBegin(GL_POLYGON);
	glVertex3f(x2,-0.1,y1);
	glVertex3f(x2, 0.0,y1);
	glVertex3f(x2, 0.0,y2);
	glVertex3f(x2,-0.1,y2);
	glEnd();

	/* Draw Grid */ 

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	/*
	GLdouble delta = -0.4;

	for(int i=0; i < 9; i++){

		glVertex3f(delta, 0.0, 0.5);
		glVertex3f(delta, 0.0, -0.5);

		glVertex3f( 0.5, 0.0, delta);
		glVertex3f(-0.5, 0.0, delta);

		delta += 0.1;
	}
	*/
	/* Borders */

	glVertex3f(x1, 0.0, y1);
	glVertex3f(x1, 0.0, y2);
	glVertex3f(x1, 0.0, y2);
	glVertex3f(x2, 0.0, y2);
	glVertex3f(x2, 0.0, y2);
	glVertex3f(x2, 0.0, y1);
	glVertex3f(x2, 0.0, y1);
	glVertex3f(x1, 0.0, y1);

	glVertex3f(x1,-0.1, y1);
	glVertex3f(x1,-0.1, y2);
	glVertex3f(x1,-0.1, y2);
	glVertex3f(x2,-0.1, y2);
	glVertex3f(x2,-0.1, y2);
	glVertex3f(x2,-0.1, y1);
	glVertex3f(x2,-0.1, y1);
	glVertex3f(x1,-0.1, y1);

	glVertex3f(x1, 0.0, y1);
	glVertex3f(x1,-0.1, y1);
	glVertex3f(x2, 0.0, y2);
	glVertex3f(x2,-0.1, y2);
	glVertex3f(x1, 0.0, y2);
	glVertex3f(x1,-0.1, y2);
	glVertex3f(x2, 0.0, y1);
	glVertex3f(x2,-0.1, y1);

	glEnd();
}
