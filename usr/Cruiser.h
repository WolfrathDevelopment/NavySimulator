/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Cruiser class definition
 */

#ifndef CRUISER_H
#define CRUISER_H

#include "Movable.h"

class Cruiser : public Movable {
public:
	Cruiser(std::string id,std::string name,int maxMissles, double maxSpeed);
	void updatePosition(ATime);
private:
	int maxMissles;
};

#endif