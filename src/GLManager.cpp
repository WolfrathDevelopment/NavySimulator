/*
 * GLManager.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Implementation for openGL functions
 */

#include "GLManager.h"
#include <iostream>

/* Static Initialization */

const GLuint GLManager::WIDTH = 800;
const GLuint GLManager::HEIGHT = 600;
const GLuint GLManager::WIN_X = 250;
const GLuint GLManager::WIN_Y = 250;
const char * GLManager::WIN_TITLE = "Navy Simulator";

void GLManager::drawScreen(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();
}

GLManager::GLManager(){

}

void GLManager::initialize(int* argc, char** argv){

	glutInit(argc,argv);
	glutInitWindowSize(GLManager::WIDTH, GLManager::HEIGHT);
	glutInitWindowPosition(GLManager::WIN_X, GLManager::WIN_Y);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(GLManager::WIN_TITLE);
	glutDisplayFunc(drawScreen);
}

void GLManager::beginSimulation(){

	glutMainLoop();
}
