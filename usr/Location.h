/* 
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Location class definition
 */

#ifndef LOCATION_H
#define LOCATION_H

#include "ATime.h"

class Location {
public:
	Location();
	Location(double,double);
	Location(double,double,double);
	void getXY(double&, double&) const;
    void getXYZ(double&, double&, double&) const;
	void update(ATime, double,double);
	void update(ATime,double,double,double);
	void getX(double&);
	void getY(double&);
	void getZ(double&);
	void print();
	bool operator==(Location);
	ATime getTime();
private:
	ATime time;
	double x,y,z;
};

#endif
