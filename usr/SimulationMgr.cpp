/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * SimulationMgr class implementation
 */

#include "SimulationMgr.h"
#include <iostream>

using namespace std;

bool SimulationMgr::simInit(string file){
	return getOrders(file);
}

bool sorter(Order* one,Order* two){
	return (*one < *two);
}

bool SimulationMgr::getOrders(string path){

	std::fstream stream;

	//return false if opening file fails

	try{
		stream.open(path.c_str(),ios::in);
	}catch(...){ return false;}

	while(!stream.eof()){

		string line;
		string command;

		getline(stream,line);
		istringstream sstream(line);
		sstream >> command;
		cout << command << endl;

		if(command == "\0")
			continue;
		else if(command[0] == '#')
			continue;
		else if(command == "CreateAircraftCarrier"){
			string name,id;
			double speed;
			int planes;
			if(sstream >> name >> id >> planes >> speed){
				Carrier* c = new Carrier(name,id,planes,speed);
				objectMap.insert(MapPair(id,c));
			}
		}
		else if(command == "CreateCruiser"){
			string name,id;
			double speed;
			int missles;
			if(sstream >> name >> id >> missles >> speed){
				Cruiser* c = new Cruiser(name,id,missles,speed);
				objectMap.insert(MapPair(id,c));
			}
		}
		else if(command == "CreateFighter"){
			string name,id,shipid;
			double speed,ceil;
			int bombs;
			if(sstream >> name >> id >> shipid >> speed >> ceil >>bombs){
				Fighter* f = new Fighter(name,id,shipid,speed,ceil,bombs);
				if(objectMap.find(shipid) == objectMap.end())
					continue;
				f->setParentShip(objectMap.find(shipid)->second);
				objectMap.insert(MapPair(id,f));
			}
		}
		else if(command == "StartSim"){
			string day,time;
			if(sstream >> day >> time){
				ATime t(day,time);
				start = t;
			}
		}
		else if(command == "StopSim"){
			string day,time;
			if(sstream >> day >> time){
				ATime t(day,time);
				stop = t;
			}
		}
		else if(command == "DeployShip"){
			string day,hour;
			string id;
			double x;
			double y;
			double heading;
			double speed;
			if(sstream >> day >> hour >> id >> x >> y >> heading >> speed){
				DeployShipOrder* order = new DeployShipOrder(ATime(day,hour),id,x,y,heading,speed);
				queue.push_back(order);
			}
		}
		else if(command == "DeployAircraft"){
			string day,hour;
			string id;
			double altitude;
			double heading;
			double speed;
			if(sstream >> day >> hour >> id >> heading >> speed >> altitude){
				DeployAircraftOrder* order = new DeployAircraftOrder(ATime(day,hour),id,heading,speed,altitude);
				queue.push_back(order);
			}
		}
		else if(command == "ChangeAircraftOrders"){
			string day,hour;
			string id;
			double altitude;
			double heading;
			double speed;
			if(sstream >> day >> hour >> id >> heading >> speed >> altitude){
				ChangeAircraftOrder* order = new ChangeAircraftOrder(ATime(day,hour),id,heading,speed,altitude);
				queue.push_back(order);
			}
		}
		else if(command == "LandAircraft"){
			string day,hour;
			string id;
			string shipid;
			if(sstream >> day >> hour >> shipid >> id){
				LandAircraftOrder* order = new LandAircraftOrder(ATime(day,hour),shipid,id);
				order->landShip = objectMap.find(shipid)->second;
				queue.push_back(order);
			}
		}
		else if(command == "ChangeShipOrders"){
			string day,hour;
			string id;
			double heading;
			double speed;
			if(sstream >> day >> hour >> id >> heading >> speed){
				ChangeShipOrder* order = new ChangeShipOrder(ATime(day,hour),id,heading,speed);
				queue.push_back(order);
			}
		}
	}

	stream.close();
	// sort orders
	sort(queue.begin(),queue.end(),sorter);
	//if no orders, return false
	if(queue.empty())
		return false;
	//if a bad file path, return false
	return true;
}

ATime SimulationMgr::getStart() const{
	return start;
}

ATime SimulationMgr::getStop() const{
	return stop;
}

NavyMap* SimulationMgr::getNavy(){
	return &objectMap;
}

void SimulationMgr::simDoUpdate(ATime now){

	std::cout << "UPDATE: " << now << std::endl;

	NavyMap::iterator it;
	Order* temp;

	while(queue.size()){

		temp = queue.front();
		if(temp->exectime() > now)
			break;

		queue.pop_front();

		it = objectMap.find(temp->get_id());
		if(it != objectMap.end())
			temp->Execute(it->second,now);
	}

	sendUpdateCommand(now);
}

void SimulationMgr::sendUpdateCommand(ATime now){

	NavyMap::iterator it = objectMap.begin();
	Movable* temp;

	while(it != objectMap.end()){
		temp = it->second;
		if(temp->isDeployed())
			temp->updatePosition(now);
		it++;
	}
}

void SimulationMgr::printOrders(){
	
}

void SimulationMgr::printNavy(){

}
