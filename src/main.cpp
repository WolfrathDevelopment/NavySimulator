/*
 * main.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Navy Simulator entry point
 */

#include <GLManager.h>

int main(int argc, char** argv){

	GLManager manager;

	/* Command Line Args? */

	
	manager.initialize(&argc, argv);
	manager.beginSimulation();

	return 0;
}
