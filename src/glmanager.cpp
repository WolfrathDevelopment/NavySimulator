/*
 * GLManager.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Implementation for openGL functions
 */

#include "glmanager.h"
#include "../usr/SimulationMgr.h"
#include <iostream>
#include <string>

/* Static Initialization */

const GLuint GLManager::WIDTH = 800;
const GLuint GLManager::HEIGHT = 600;
const GLuint GLManager::WIN_X = 250;
const GLuint GLManager::WIN_Y = 250;
const char * GLManager::WIN_TITLE = "Navy Simulator";

/* Colors */

enum COLORS { RED = 0, GREEN, BLUE, PURPLE, YELLOW };
const GLdouble colors[][4] = {
    { 1.0, 0.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0, 0.0 },
    { 1.0, 0.1, 1.0, 0.0 },
    { 0.8, 0.8, 0.5, 0.0 },
    { 0.0, 1.0, 1.0, 0.0 },
    { 1.0, 0.5, 0.5, 0.0 },
    { 0.5, 1.0, 0.5, 0.0 },
    { 0.2, 0.3, 0.7, 0.0 },
    { 0.5, 0.5, 1.0, 0.0 },
    { 0.05, 0.05, 0.5, 0.0 },
};

ATime* GLManager::getClock(){
	return &(this->simClock);
}

SimulationMgr GLManager::getManager(){
	return this->manager;
}

void GLManager::drawScreen(void){

	NavyMap* nm = this->manager.getNavy();
    NavyMap::iterator itr;
	std::string status = "X ";

    for(itr = nm->begin(); itr != nm->end(); itr++){

        if ((itr->second)->isDeployed()) {
            status = "Is Deployed: ";
        }
        else if ((itr->second)->wasDeployed()) {
            status = "Was Deployed: ";
        }
        else {
            status = "Not Deployed: ";
        }

		std::cout << status << itr->first << std::endl;
    }

	std::cout << std::endl;

	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(this->rotate_x, 1.0, 0.0, 0.0);
	glRotatef(this->rotate_y, 0.0, 1.0, 0.0);

	simPlane.draw();

	glFlush();
	glutSwapBuffers();
}

void GLManager::handleSpecial(int key, int x, int y){

	switch(key){

	case GLUT_KEY_RIGHT:
		rotate_y += 5;
		break;

	case GLUT_KEY_LEFT:
		rotate_y += -5;
		break;

	case GLUT_KEY_UP:
		rotate_x += 5;
		break;

	case GLUT_KEY_DOWN:
		rotate_x -= 5;
		break;
	}

	glutPostRedisplay();
}

GLManager::GLManager(){
	
	this->rotate_x = 25;
	this->rotate_y = 0;
	simPlane.setPointOne(-0.5, -0.5);
	simPlane.setPointTwo(0.5, 0.5);
}

void GLManager::registerDisplayCallback(void (*callback)()){
	glutDisplayFunc(callback);
}

void GLManager::registerSpecialCallback(void (*callback)(int,int,int)){
	glutSpecialFunc(callback);
}

void GLManager::registerIdleCallback(void (*callback)()){
	glutIdleFunc(callback);
}

void GLManager::initialize(int* argc, char** argv){

	glutInit(argc,argv);
	glutInitWindowSize(GLManager::WIDTH, GLManager::HEIGHT);
	glutInitWindowPosition(GLManager::WIN_X, GLManager::WIN_Y);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(GLManager::WIN_TITLE);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}

void GLManager::beginSimulation(){

	this->manager.simInit("usr/Orders.txt");
	this->simClock = this->manager.getStart();
	glutMainLoop();
}

















