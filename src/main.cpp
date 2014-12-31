/*
 * main.cpp
 * Navy Simulator
 * Dodson, Wolfrath 2014
 *
 * Navy Simulator entry point
 */

#include "glmanager.h"
#include "SimulationMgr.h"
#include <stdlib.h>
#include <iostream>

/* Globals */

GLManager manager;
ATime* simTime;
SimulationMgr smanager;

/* wrapper sleep function */

void delay(int ms) {

#if defined(WIN32)
    Sleep(ms);
#else
    struct timespec ts;
    ts.tv_sec = ms/1000;
    ts.tv_nsec = 1000000 * (ms%1000);
    nanosleep(&ts,NULL);
#endif
}

/* Callback functions */

void idle_callback(void){

	smanager = manager.getManager();
	simTime = manager.getClock();

	if (*simTime < smanager.getStop()) {
    	smanager.simDoUpdate(*simTime);
    	delay(1000);
    	glutPostRedisplay();
        *simTime += 60;  // add one minute
		std::cout << *simTime << std::endl;
    }
}

void display_callback(void){

	manager.drawScreen();
}

void special_callback(int key, int x, int y){

	manager.handleSpecial(key,x,y);
}

/* Main routine */

int main(int argc, char** argv){

	/* Command Line Args ? */

	
	manager.initialize(&argc, argv);
	manager.registerDisplayCallback(&display_callback);
	manager.registerSpecialCallback(&special_callback);
	manager.registerIdleCallback(&idle_callback);
	manager.beginSimulation();

	return 0;
}
