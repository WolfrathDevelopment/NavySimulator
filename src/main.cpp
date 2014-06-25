/*
 * main.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Navy Simulator entry point
 */

#include <glmanager.h>
#include <stdlib.h>
#include <iostream>

/* Globals */

GLManager manager;
GLdouble rotate_x = 25;
GLdouble rotate_y = 0;

/* Callback functions */

void display_callback(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	manager.drawScreen();

	glFlush();
	glutSwapBuffers();
}

void special_callback(int key, int x, int y){

	switch(key){

	case GLUT_KEY_RIGHT:
		rotate_y += 5;
		break;

	case GLUT_KEY_LEFT:
		rotate_y -= 5;
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

/* Main routine */

int main(int argc, char** argv){

	/* Command Line Args ? */

	
	manager.initialize(&argc, argv);
	manager.registerDisplayCallback(&display_callback);
	manager.registerSpecialCallback(&special_callback);
	manager.beginSimulation();

	return 0;
}
