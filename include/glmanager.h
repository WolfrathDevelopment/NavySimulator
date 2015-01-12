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
#include "../usr/SimulationMgr.h"

class GLManager {
public:
	GLManager();
	void drawScreen(void);
	void handleSpecial(int,int,int);
	void initialize(int*, char**);
	void registerDisplayCallback(void (*)());
	void registerSpecialCallback(void (*)(int,int,int));
	void registerIdleCallback(void (*)());
	void beginSimulation(void);
	ATime* getClock();
	SimulationMgr getManager();
private:
	Plane simPlane;
	SimulationMgr manager;
	ATime simClock;
	const static GLuint WIDTH;
	const static GLuint HEIGHT;
	const static GLuint WIN_X;
	const static GLuint WIN_Y;
	const static GLfloat PLANE_DIM;
	const static char* WIN_TITLE;
	GLdouble rotate_x, rotate_y;
};

#endif /* GLMANAGER_HEADER */
