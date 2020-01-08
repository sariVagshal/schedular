#ifndef __HELLOTASK_H__
#define __HELLOTASK_H__

class HelloTask: public ITask
{
public:
	HelloTask();
	~HelloTask();
	
	void run();
	unsigned long getNextRunPeriod();
	void decTimeToRun();
	unsigned long getTimeToRun();
private:
	unsigned long m_timeToRun;
};

//	====implementations====

inline HelloTask::HelloTask() : m_timeToRun(2)
{}

inline HelloTask::~HelloTask()
{}

inline void HelloTask::run()
{
	std::cout << "run HelloTask: Hello!" << std::endl;
}

inline unsigned long HelloTask::getNextRunPeriod()
{
	return 1234;
}

inline void HelloTask::decTimeToRun()
{
	--m_timeToRun;
}

inline unsigned long HelloTask::getTimeToRun()
{
	return m_timeToRun;
}




#endif //__HELLOTASK_H__