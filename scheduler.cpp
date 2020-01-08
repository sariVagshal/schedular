#include "scheduler.h"
#include <queue>

struct TaskComperator{
    bool operator()(const taskByTime& a,const taskByTime& b) const{
        return a > b;//b.second
    }
};

Scheduler::Scheduler()
{
	std::make_heap(m_tasksByTime.begin(), m_tasksByTime.end(), TaskComperator());//change struct to function
}

void Scheduler::add(SharedPtr<ITask> task)
{
	unsigned long t = task->getNextRunPeriod();
	if ((t > 0) &&(task->getTimeToRun() > 0))
	{
		TimeOnLinux time(t);
		taskByTime task0 = std::make_pair(task, time);
		m_tasksByTime.push_back(task0);
		std::push_heap(m_tasksByTime.begin(), m_tasksByTime.end(),TaskComperator());
	}
}

void Scheduler::run()
{
	while (shouldRun())
	{
		std::pop_heap(m_tasksByTime.begin(), m_tasksByTime.end(), TaskComperator());
		taskByTime thisTask = m_tasksByTime.back();
		m_tasksByTime.pop_back();
	
		thisTask.second.sleep();//second is type of TimeOnLinux

		thisTask.first->decTimeToRun();
		thisTask.first->run();
		add(thisTask.first);
	}
}



	








