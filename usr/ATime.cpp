/* 
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * ATime class implementation
 */

#include "ATime.h"
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

ATime::ATime(){
	this->time = 0;
}

ATime::ATime(std::string day,std::string hour){

	istringstream ds(day);
	istringstream hs(hour);
	struct tm now;
	int d,m,y,h,min,sec;
	char slash;
	if((ds >> m >> slash >> d >> slash >> y) && (hs >> h >> slash >> min >> slash >> sec)){
		now.tm_hour = h;
		now.tm_min = min;
		now.tm_sec = sec;
		now.tm_mon = m-1;
		now.tm_mday = d;
		now.tm_year = y - 1900;
		this->time = mktime(&now);
	}
	else
		this->time = 0;
}

ATime::ATime(time_t t){
	this->time = t;
}

string ATime::getSVal() const{

	struct tm* now;
	ostringstream os;

	now = localtime(&time);
	os << "Current Date: " << now->tm_mon+1 << "/" <<now->tm_wday << "/" << now->tm_year+1900 << "    ";

	os << "Time of Day: ";
	if(now->tm_hour < 10)
		os << "0" << now->tm_hour << ":";
	else
		os << now->tm_hour << ":";
	if(now->tm_min < 10)
		os << "0" << now->tm_min << ":";
	else
		os << now->tm_min << ":";
	if(now->tm_sec < 10)
		os << "0" << now->tm_sec;
	else
		os << now->tm_sec;

	return os.str();
}

bool ATime::isValid() const{

	if(time!=0)
		return true;

	return false;
}
bool ATime::operator<(const ATime& arg) const{
	return this->time < arg.time;
}
bool ATime::operator>(const ATime& arg) const{
	return this->time > arg.time;
}
bool ATime::operator==(const ATime& arg) const{
	return this->time == arg.time;
}
bool ATime::operator!=(const ATime& arg) const{
	return this->time != arg.time;
}
ATime ATime::operator+(const int add)const{

	ATime ret = *this;
	ret.time += add;
	return ret;
}
ATime ATime::operator++(){

	time++;
	return *this;
}	
ATime ATime::operator++(int){

	ATime temp = *this;
	time++;
	return temp;
}
ATime& ATime::operator+=(int add){

	time+=add;
	return *this;
}
int ATime::operator-(const ATime& sub) const{
	return this->time - sub.time;
}
int ATime::operator-(const int sub) const{
	return this->time - sub;
}

std::ostream& operator<<(std::ostream& os, ATime at){

	os << at.getSVal();
	return os;
}
ATime operator+(int add, const ATime& arg){

	ATime temp = arg;
	return (temp.time + add);
}