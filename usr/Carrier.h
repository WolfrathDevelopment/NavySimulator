/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Carrier class definition
 */

#ifndef CARRIER_H
#define CARRIER_H

#include "Movable.h"

class Carrier : public Movable {
public:
	Carrier(std::string,std::string,int,double);
	void updatePosition(ATime);
private:
	int numPlanes;	
};

#endif