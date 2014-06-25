/*
 * GLManager.h
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Class for managing openGL functionality
 */

#ifndef GLMANAGER_HEADER
#define GLMANAGER_HEADER

#include "stdhdr.h"
#include "plane.h"

class GLManager {
public:
	GLManager();
	void drawScreen(void);
	void initialize(int*, char**);
	void registerDisplayCallback(void (*)());
	void registerSpecialCallback(void (*)(int,int,int));
	void beginSimulation(void);
private:
	Plane simPlane;
	const static GLuint WIDTH;
	const static GLuint HEIGHT;
	const static GLuint WIN_X;
	const static GLuint WIN_Y;
	const static char* WIN_TITLE;
};

#endif /* GLMANAGER_HEADER */
