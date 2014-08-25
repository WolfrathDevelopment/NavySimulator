/* 
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Carrier class implementation
 */

#include "Movable.h"
#include "Carrier.h"

using namespace std;

Carrier::Carrier(string name,string id,int maxPlanes,double maxSpeed):
Movable(name,id,maxSpeed){

	this->numPlanes = maxPlanes;
}

void Carrier::updatePosition(ATime current){

	if(deployed){
		currentLocation = calculatePosition(current,this->currentLocation.getTime());
	}

	history.push_back(currentLocation);
}