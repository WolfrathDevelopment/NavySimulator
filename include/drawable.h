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
#include <glm/glm.hpp>
#include <inttypes.h>

class DrawableOBJ{

public:

	DrawableOBJ();
	bool parseFromFile(std::string);
	void draw();
	~DrawableOBJ();

private:

	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec3 > normals;
};

#endif
