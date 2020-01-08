#ifndef __TIMEONLINUX_H__
#define __TIMEONLINUX_H__
#include <time.h>

class TimeOnLinux
{
public:
	TimeOnLinux();//now
	TimeOnLinux(const unsigned long period); //milliseconds
	
	TimeOnLinux operator+(const unsigned long period) const;
	bool operator<(const TimeOnLinux& t) const;
	
	void sleep() const;
private:
	timespec m_time;
};


#endif //__TIMEONLINUX_H__
