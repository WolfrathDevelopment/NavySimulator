/*
 * Joel Wolfrath
 * CSC-231 Navy Simulation, 2012
 * ATime class definition
 */

#ifndef ATIME_H
#define ATIME_H

#include <iostream>
#include <string>
#include <ctime>

class ATime {
	friend std::ostream& operator<<(std::ostream& os, ATime at);
	friend ATime operator+(int, const ATime&);
public:
	ATime();
	ATime(std::string,std::string);
	ATime(time_t t);
	std::string getSVal() const;
	bool isValid() const;
	bool operator<(const ATime &) const;
	bool operator>(const ATime &) const;
	bool operator==(const ATime &) const;
	bool operator!=(const ATime &) const;
	ATime operator+(const int)const;
	ATime operator++();
	ATime operator++(int);
	ATime& operator+=(int);
	int operator-(const ATime&) const;
	int operator-(const int) const;	
private:
	time_t time;
};

#endif