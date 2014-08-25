/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * Order class implementation
 */

#include "Order.h"

using namespace std;

Order::Order(ATime t,string id){
	this->time = t;
	this->id = id;
}

bool Order::operator==(const Order& o){
	return (this->id == o.id) && (this->time == o.time);
}

bool Order::operator<(const Order& o){
	return this->time < o.time;
}

bool Order::operator>(const Order& o){
	return this->time > o.time;
}

bool Order::operator!=(const Order& o){
	return (this->id != o.id) || (this->time != o.time);
}

ATime Order::exectime() const {
	return this->time;
}

string Order::get_id() const {
	return this->id;
}

ChangeShipOrder::ChangeShipOrder(ATime time,string ID,double heading,double speed):
Order(time,ID) {

	if(heading > 0)
		this->heading = heading;
	if(speed > 0)
		this->speed = speed;
}

ChangeAircraftOrder::ChangeAircraftOrder(ATime time,string id,double heading,double speed ,double altitude):
Order(time,id) {

	if(heading > 0)
		this->heading = heading;
	if(speed > 0)
		this->speed = speed;

	this->altitude = altitude;
}

DeployShipOrder::DeployShipOrder(ATime time,string id,double x,double y,double heading ,double speed):
Order(time,id) {

	this->x = x;
	this->y = y;

	if(heading > 0)
		this->heading = heading;
	if(speed > 0)
		this->speed = speed;
}

DeployAircraftOrder::DeployAircraftOrder(ATime time,string id,double heading,double speed,double altitude):
Order(time,id) {

	if(heading > 0)
		this->heading = heading;
	if(speed > 0)
		this->speed = speed;

	this->altitude = altitude;
}

LandAircraftOrder::LandAircraftOrder(ATime time,string shipId,string id):
Order(time,id) {
	this->shipId = shipId;
}

bool ChangeShipOrder::Execute(Movable* object,ATime time){
	object->changeOrders(time,heading,speed,0.0);
	return true;
}

bool ChangeAircraftOrder::Execute(Movable* object,ATime time){
	object->changeOrders(time,heading,speed,altitude);
	return true;
}

bool DeployShipOrder::Execute(Movable* object,ATime time){
	object->deploy(time,x,y,0,heading,speed);
	return true;
}

bool DeployAircraftOrder::Execute(Movable* object,ATime time){

	double x,y;
	Fighter* f = static_cast<Fighter*>(object);

	f->getParent()->getLocation().getXY(x,y);
	object->deploy(time,x,y,altitude,heading,speed);
	return true;
}

bool LandAircraftOrder::Execute(Movable* object,ATime time){

	Fighter* f = (dynamic_cast<Fighter*>(object));

	if(f){
		f->land(time,this->landShip);
		return true;
	}
	return false;
}