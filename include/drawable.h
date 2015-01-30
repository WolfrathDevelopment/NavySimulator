/*
 * drawable.h
 * Joel Wolfrath, 2015
 *
 * Defines a drawable object
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector>
#include <string>
#include <inttypes.h>
#include "stdhdr.h"

typedef struct _vec3{
	GLfloat x,y,z;
} vec3;

class DrawableOBJ{

public:

	DrawableOBJ();
	bool parseFromFile(std::string);
	void draw();
	~DrawableOBJ();

private:

	std::vector< vec3 > vertices;
	std::vector< vec3 > normals;
};

#endif
