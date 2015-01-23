/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Crusier class implementation
 */

#include "Cruiser.h"

using namespace std;

Cruiser::Cruiser(string id,string name,int missles,double maxSpeed):
Movable(name,id,maxSpeed){

	this->maxMissles = missles;
}

void Cruiser::updatePosition(ATime current){

	std::cout << "Prev Location: ";
	currentLocation.print();

	if(deployed){
		currentLocation = calculatePosition(current,this->currentLocation.getTime());
	}

	std::cout << "Next Location: ";
	currentLocation.print();

	history.push_back(currentLocation);
}
