/*
 * GLManager.h
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Class for managing openGL functionality
 */

#ifndef GLMANAGER_HEADER
#define GLMANAGER_HEADER

#include <GL/glut.h>
#include <GL/glx.h>

class GLManager {
public:
	GLManager();
	static void drawScreen(void);
	void initialize(int*, char**);
	void beginSimulation(void);
private:
	const static GLuint WIDTH;
	const static GLuint HEIGHT;
	const static GLuint WIN_X;
	const static GLuint WIN_Y;
	const static char* WIN_TITLE;
};

#endif /* GLMANAGER_HEADER */
