/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Fighter class definition
*/

#ifndef FIGHTER_H
#define FIGHTER_H

#include "Movable.h"

const int NO_LAND_COMMAND = 0;
const int LAND_IN_PROGRESS = 1;

class Fighter : public Movable {
public:
	Fighter(std::string,std::string,std::string,double,double,int);
	void updatePosition(ATime);
	void land(ATime, Movable*);
	Movable* getParent();
	Location calculatePosition(ATime,ATime);
	void setParentShip(Movable*);	
private:
	int landingProcedure;
	bool hasLanded(double);
	Movable* shipParent;
	double maxCeil;
	int maxBombs;
};

#endif