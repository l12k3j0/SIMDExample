#include "RecordTimer.h"
#include <profileapi.h>

RecordTimer::RecordTimer()
{
    QueryPerformanceFrequency(&m_frequency);
}


RecordTimer::~RecordTimer()
{
}

void RecordTimer::start()
{
    QueryPerformanceCounter(&m_startTime);
}

void RecordTimer::end()
{
    QueryPerformanceCounter(&m_endTime);
}

double RecordTimer::getTick()
{
    return (double)(m_endTime.QuadPart - m_startTime.QuadPart) * 1.0 / m_frequency.QuadPart * 1000;
}