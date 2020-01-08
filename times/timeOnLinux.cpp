#include "timeOnLinux.h"
#include <ctime>


TimeOnLinux::TimeOnLinux()
{
	m_time.tv_nsec = std::time(0)*1000000000;
    m_time.tv_sec = 0;
}

TimeOnLinux::TimeOnLinux(const unsigned long period)
{
	m_time.tv_nsec = (period*1000000) + (std::time(0)*1000000000);
    m_time.tv_sec = 0;
}
	
TimeOnLinux TimeOnLinux::operator+(const unsigned long period) const
{
	return TimeOnLinux(m_time.tv_sec + (period * 1000000));
}

bool TimeOnLinux::operator<(const TimeOnLinux& t) const
{
	if(m_time.tv_sec < t.m_time.tv_sec)
        return true;
    if(m_time.tv_nsec < t.m_time.tv_nsec)
        return true;
    return false;
}
	
void TimeOnLinux::sleep() const
{
	timespec delta;
    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &delta);
    if (m_time.tv_sec < delta.tv_sec || (m_time.tv_sec == delta.tv_sec && m_time.tv_nsec < delta.tv_nsec))
    {
        return;
    }
    delta.tv_sec = m_time.tv_sec - delta.tv_sec - 1;
    unsigned long temp = 1000000000 + m_time.tv_nsec - delta.tv_nsec;
    delta.tv_sec += temp / 1000000000;
    delta.tv_nsec = temp % 1000000000;
    nanosleep(&delta,NULL);
}
