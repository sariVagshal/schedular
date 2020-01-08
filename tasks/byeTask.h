#ifndef __BYETASK_H__
#define __BYETASK_H__

class ByeTask: public ITask
{
public:
	ByeTask();
	~ByeTask();

	void run();
	unsigned long getNextRunPeriod();
	void decTimeToRun();
	unsigned long getTimeToRun();
private:
	unsigned long m_timeToRun;
};

//	====implementations====
	
inline ByeTask::ByeTask() : m_timeToRun(4)
{}

inline ByeTask::~ByeTask()
{}

inline void ByeTask::run()
{
	std::cout << "run ByeTask: Bye!" << std::endl;
}

inline unsigned long ByeTask::getNextRunPeriod()
{
	return 1234;
}

inline void ByeTask::decTimeToRun()
{
	--m_timeToRun;
}

inline unsigned long ByeTask::getTimeToRun()
{
	return m_timeToRun;
}



#endif //__BYETASK_H__