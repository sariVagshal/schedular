#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <vector>
#include "tasks/iTask.h"
#include "times/timeOnLinux.h"
#include "sharePtr.h"

typedef std::pair<SharedPtr< ITask > , TimeOnLinux> taskByTime;

class Scheduler 
{
public:
	Scheduler();
	
	void add(SharedPtr<ITask> task);
	void run();
private:
	bool shouldRun();
	
	std::vector<taskByTime> m_tasksByTime;
};

inline bool Scheduler::shouldRun()
{
	return !(m_tasksByTime.empty());
}

#endif //__SCHEDULER_H__




