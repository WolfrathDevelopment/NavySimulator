/*
 * main.cpp
 * Dodson, Wolfrath 2014
 *
 * Navy Simulator entry point
 *
 */

#include <GL/glut.h>
#include <GL/glx.h>

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;
const GLuint WIN_X = 250;
const GLuint WIN_Y = 250;

const char* WIN_TITLE = "Navy Simulator";

/* Main display function */

void draw_screen(){
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();
}

int main(int argc, char* argv[]){

	/* Initialize GL components */
	
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(WIN_X, WIN_Y);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(WIN_TITLE);
	glutDisplayFunc(draw_screen);

	glutMainLoop();
}
