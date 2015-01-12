/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Movable class implementation
 */

#include "Movable.h"
#include <math.h>

using namespace std;

Movable::Movable(){
	deployed = false;
	beenDeployed = false;
}

Movable::Movable(std::string name,std::string id,double max){

	deployed = false;
	beenDeployed = false;
	this->id = id;
	this->name = name;
	this->maxSpeed = max;
}

void Movable::deploy(ATime time, double x,double y,double z,double heading,double speed){

	this->currentLocation.update(time,x,y,z);
	this->heading = heading;

	if(speed <= maxSpeed)
		this->currentSpeed = speed;
	else
		this->currentSpeed = maxSpeed;

	deployed = true;
	beenDeployed = true;
}

bool Movable::isDeployed() const {
	return deployed;
}

bool Movable::wasDeployed() const {
	return beenDeployed;
}

HistoryList* Movable::getHistory(){
	return &this->history;
}

void Movable::changeOrders(ATime now, double heading,double speed,double altitude){

	double x,y,z;
	this->currentLocation.getXYZ(x,y,z);

	if(isDeployed()){

		if(heading > 0)
			this->heading = heading;
		if(speed <= maxSpeed && speed > 0)
			this->currentSpeed = speed;
		if(z > 0.0)
			this->currentLocation.update(now,x,y,altitude);

		this->updatePosition(now);
	}
}

Location Movable::calculatePosition(ATime one,ATime two){

	int time = one - two;
	Location ret(0,0,0);
	double x,y,z;
	double new_x,new_y,theta,hyp;

	theta = toRadians(heading);
	hyp = (currentSpeed * time)/(60.0*60.0);
	currentLocation.getXYZ(x,y,z);
	new_x = sin(theta)*hyp + x;
	new_y = cos(theta)*hyp + y;
	ret.update(one,new_x,new_y,z);
	//currentLocation.update(one,new_x,new_y,z);

	return ret;
}

double Movable::toRadians(double degrees){
	return (degrees * PI)/180;
}

double Movable::toDegrees(double radians){
	return (radians * 180)/PI;
}

Location Movable::getLocation(){
	return this->currentLocation;
}

double Movable::getHeading(){
	return heading;
}

double Movable::getSpeed(){
	return currentSpeed;
}
