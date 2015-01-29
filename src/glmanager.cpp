/*
 * GLManager.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Implementation for openGL functions
 */

#include "glmanager.h"
#include "../usr/SimulationMgr.h"
#include "hud.h"
#include "drawable.h"
#include <iostream>
#include <string>
#include <sstream>

static DrawableOBJ plane;

using namespace std;

/* Static Initialization */

const GLuint GLManager::WIDTH = 800;
const GLuint GLManager::HEIGHT = 600;
const GLuint GLManager::WIN_X = 250;
const GLuint GLManager::WIN_Y = 250;
const GLfloat GLManager::PLANE_DIM = 0.75;
const char * GLManager::WIN_TITLE = "Navy Simulator";

const GLdouble colors[][4] = {
    { 1.0, 0.0, 0.0, 0.0 },
    { 1.0, 0.1, 1.0, 0.0 },
    { 0.0, 1.0, 1.0, 0.0 },
    { 0.8, 0.8, 0.5, 0.0 },
    { 1.0, 0.5, 0.5, 0.0 },
    { 0.5, 1.0, 0.5, 0.0 },
    { 0.2, 0.3, 0.7, 0.0 },
    { 0.5, 0.5, 1.0, 0.0 },
    { 0.05, 0.05, 0.5, 0.0 },
    { 0.0, 0.0, 1.0, 0.0 },
};

ATime* GLManager::getClock(){
	return &(this->simClock);
}

SimulationMgr GLManager::getManager(){
	return this->manager;
}

void GLManager::drawScreen(void){

	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glRotatef(this->rotate_x, 1.0, 0.0, 0.0);
	glRotatef(this->rotate_y, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	simPlane.draw();

	NavyMap* nm = this->manager.getNavy();
    NavyMap::iterator itr;
	HistoryList* hlist;
	HistoryList::iterator itr2;

	int colorIndex = 0;
	double x,y,z;
	bool draw3D, drawShip, drawPlane;

    for(itr = nm->begin(); itr != nm->end(); itr++){

		draw3D = drawShip = drawPlane = false;

		Movable* obj = (itr->second);
		hlist = obj->getHistory();
		obj->getLocation().getXYZ(x,y,z);

		if((itr->second)->wasDeployed() && !(itr->second)->isDeployed()){
			glColor4d(0.8,0.8,0.8,0.0);
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(2,0xAAAA);
		}
		else{
			glColor4dv(colors[colorIndex++]);
			glDisable(GL_LINE_STIPPLE);
			draw3D = true;
		}

		double z2, mult;
		if(z < 1.0){
			z2 = 0.0f;
			mult = 10.0;
			drawShip = true;
		}
		else{
			z2 = z / 50000.0;
			mult = 2.0;
			drawPlane = true;
		}

		glBegin(GL_LINE_STRIP);

		for(itr2 = hlist->begin(); itr2 != hlist->end(); itr2++){

			itr2->getXYZ(x,y,z);
			glVertex3d((x/WIDTH) * mult, z2, ((y/HEIGHT) * mult));
		}

		glEnd();

		glDisable(GL_LINE_STIPPLE);

		/* DRAW 3D Object */

		if(draw3D){
	
			if(drawPlane){

				glPushMatrix();
				glLoadIdentity();

				//glScalef(0.01,0.01,0.01);
				//glTranslated(50.0,50.0,50.0);
				glTranslatef((x/WIDTH) * mult, z2, ((y/HEIGHT) * mult));
				glRotatef(-90, 1.0, 0.0, 0.0);
				glRotatef(-180 + obj->getHeading(), 0.0, 0.0, 1.0);
				//glTranslated(50.0,50.0,50.0);
				glScalef(0.005,0.005,0.005);
				plane.draw();

				glPopMatrix();
			}
		}
	}

	/* Overlay HUD */

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glClear(GL_DEPTH_BUFFER_BIT);

	renderHUD(getClock(), nm);

	glPopMatrix();
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
	
	this->rotate_x = -90;
	this->rotate_y = 0;
	simPlane.setPointOne(-GLManager::PLANE_DIM, -GLManager::PLANE_DIM);
	simPlane.setPointTwo(GLManager::PLANE_DIM, GLManager::PLANE_DIM);
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

static void onclick(unsigned char key, int x, int y){

	switch(key){
	case 27:
		exit(0);
	}
}


void GLManager::initialize(int* argc, char** argv){

	std::cout << "Loading Models..." << std::endl;

	glutInit(argc,argv);
	glutInitWindowSize(GLManager::WIDTH, GLManager::HEIGHT);
	glutInitWindowPosition(GLManager::WIN_X, GLManager::WIN_Y);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(GLManager::WIN_TITLE);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(2.0);
	glLineWidth(2.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glutKeyboardFunc(onclick);

	plane.parseFromFile("obj/plane.obj");
}

void GLManager::beginSimulation(string orderFile){

	if(!this->manager.simInit(orderFile)){
		std::cout << "Simulation failed" << std::endl;
		exit(1);
	}
	this->simClock = this->manager.getStart();
	glutMainLoop();
}


