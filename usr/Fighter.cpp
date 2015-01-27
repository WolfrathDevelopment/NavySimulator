/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Fighter class implementation
 */

#include "Fighter.h"
#include <cmath>

using namespace std;

Fighter::Fighter(string name,string id,string shipId,double maxSpeed,double maxCeil,int maxBombs):
Movable(name,id,maxSpeed){

	this->maxCeil = maxCeil;
	this->maxBombs = maxBombs;
	landingProcedure = NO_LAND_COMMAND;
}

void Fighter::updatePosition(ATime current){

	if(deployed){
		currentLocation = calculatePosition(current,this->currentLocation.getTime());
	}

	history.push_back(currentLocation);
}

void Fighter::setParentShip(Movable* ship){
	this->shipParent = ship;
}

void Fighter::land(ATime time, Movable* ship){

	this->shipParent = ship;
	this->landingProcedure = LAND_IN_PROGRESS;
	this->updatePosition(time);
}

Movable* Fighter::getParent(){
	return shipParent;
}

Location Fighter::calculatePosition(ATime one,ATime two){

	Location ret;
	double x1,y1,x2,y2;
	double rise=0.0,run=0.0,d = 0.0;

	if(landingProcedure == LAND_IN_PROGRESS){

		this->shipParent->getLocation().getXY(x1,y1);
		this->currentLocation.getXY(x2,y2);
		run = x1-x2;
		rise = y1-y2;
		d = sqrt(pow(run,2) + pow(rise,2));

		heading = 90.0 - toDegrees(atan2(rise,run));

		if(hasLanded(d)){
			ret = shipParent->getLocation();
			landingProcedure = NO_LAND_COMMAND;
			deployed = false;
			return ret;
		}
	}
	
	ret = Movable::calculatePosition(one,two);
	return ret;
}

bool Fighter::hasLanded(double distance){

	if(landingProcedure == LAND_IN_PROGRESS && ((distance*60)/currentSpeed) <= 1){
		return true;
	}

	return false;
}
