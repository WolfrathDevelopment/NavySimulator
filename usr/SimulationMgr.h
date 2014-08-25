/* 
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * SimulationMgr class definition
 */

#ifndef SIMULATIONMGR_H
#define SIMULATIONMGR_H

#include "Order.h"
#include "Carrier.h"
#include "Fighter.h"
#include "Cruiser.h"
#include <map> 
#include <deque>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

typedef std::map<std::string,Movable*> NavyMap;
typedef std::deque<Order*> OrderQueue;
typedef std::pair<std::string,Movable*> MapPair;

class SimulationMgr {
public:
    bool simInit(std::string orderFile);
    ATime getStart() const;
    ATime getStop() const;
	void printOrders();
	void printNavy();
    NavyMap* getNavy();
	bool getOrders(std::string);
	void simDoUpdate(ATime);
	void sendUpdateCommand(ATime);
private:
	OrderQueue queue;
	ATime start,stop;
	NavyMap objectMap;
};

#endif