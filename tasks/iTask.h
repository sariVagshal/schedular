#ifndef __ITASK_H__
#define __ITASK_H__

#include <iostream>


struct ITask
{
	virtual ~ITask();
	
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
    virtual void decTimeToRun() = 0;
    virtual unsigned long getTimeToRun() = 0;
};



#endif //__ITASK_H__
