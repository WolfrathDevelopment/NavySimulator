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

static GLManager manager;
static ATime* simTime;
static SimulationMgr smanager;
static bool waiting = false;


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

void fireClock(int ignore){

    glutPostRedisplay();
	*simTime += 60;
	waiting = false;
}

/* Callback functions */

void idle_callback(void){

	smanager = manager.getManager();
	simTime = manager.getClock();

	if (*simTime < smanager.getStop() && !waiting) {

		//smanager.printOrders();
	
    	smanager.simDoUpdate(*simTime);
		waiting = true;
		glutTimerFunc(1000, fireClock, 0);
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
