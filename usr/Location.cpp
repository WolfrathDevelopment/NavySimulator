/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Location class implementation
 */

#include "Location.h"
#include <iostream>

Location::Location(){
	x = y = z = 0.0;
}

Location::Location(double x,double y){
	this->x = x;
	this->y = y;
	this->z = 0.0;
}

Location::Location(double x,double y,double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Location::print(){
	std::cout << x
			<< ", " << y
			<< ", " << z << std::endl;
}

void Location::getXY(double& x_pos, double& y_pos) const{
	x_pos = x;
	y_pos = y;
}

void Location::getXYZ(double& x_pos, double& y_pos, double& z_pos) const{
	x_pos = x;
	y_pos = y;
	z_pos = z;
}

void Location::update(ATime t, double x,double y){
	time = t;
	this->x = x;
	this->y = y;
}

void Location::update(ATime t,double x,double y,double z){
	time = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Location::getX(double& x_pos){
	x_pos = x;
}

void Location::getY(double& y_pos){
	y_pos = y;
}

void Location::getZ(double& z_pos){
	z_pos = z;
}

bool Location::operator==(Location loc){
	return ((this->x == loc.x) && (this->y == loc.y) && (this->z == loc.z));
}

ATime Location::getTime(){
	return time;
}
