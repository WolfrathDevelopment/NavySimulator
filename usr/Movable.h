/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Movable class definition
 */

#ifndef MOVABLE_H
#define MOVABLE_H

#include "Location.h"
#include "ATime.h"
#include <vector>
#include <list>

const double PI = 3.141592653;
typedef std::list<Location> HistoryList;

class Movable {
public:
	Movable();
	Movable(std::string,std::string,double);
	bool isDeployed() const;
	bool wasDeployed() const;
	void changeOrders(ATime,double,double,double);
	HistoryList* getHistory();
	void deploy(ATime, double,double,double,double,double);
	virtual void updatePosition(ATime) = 0;
	virtual Location calculatePosition(ATime,ATime);
	double toRadians(double);
	double toDegrees(double);
	Location getLocation();
	double getHeading();
	double getSpeed();
protected:
	Location currentLocation;
	bool deployed,beenDeployed;
	double heading;
	double currentSpeed;
	std::string id;
	std::string name;
	double maxSpeed;
	HistoryList history;
};

#endif