/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Order class definition
 */

#ifndef ORDER_H
#define ORDER_H

#include "ATime.h"
#include "Movable.h"
#include "Fighter.h"

class Order {
public:
	Order();
	Order(ATime,std::string);
    bool operator==(const Order&);
    bool operator<(const Order&);
    bool operator>(const Order&);
    bool operator!=(const Order&);
    ATime exectime() const;
    std::string get_id() const;
	virtual bool Execute(Movable*, ATime) = 0;  // make pure virtual
protected:
	ATime time;
	std::string id; 
};

class ChangeShipOrder : public Order
{
public:
	ChangeShipOrder(ATime,std::string,double,double);
	bool Execute(Movable*,ATime);
private:
	double heading;
	double speed;
};

class ChangeAircraftOrder : public Order
{
public:
	ChangeAircraftOrder(ATime,std::string,double,double,double);
	bool Execute(Movable*,ATime);
private:
	double heading;
	double speed;
	double altitude;
};

class DeployShipOrder : public Order
{
public:
	DeployShipOrder(ATime,std::string,double,double,double,double);
	bool Execute(Movable*,ATime);
private:
	double x;
	double y;
	double heading;
	double speed;
};

class DeployAircraftOrder: public Order
{
public:
	DeployAircraftOrder(ATime,std::string,double,double,double);
	bool Execute(Movable*,ATime);
private:
	double heading;
	double speed;
	double altitude;
};

class LandAircraftOrder : public Order
{
public:
	LandAircraftOrder(ATime,std::string,std::string);
	bool Execute(Movable*,ATime);
	Movable* landShip;
private:
	std::string shipId;
};


#endif