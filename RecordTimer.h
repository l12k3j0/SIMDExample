#pragma once
#include <Windows.h>
#include <winnt.h>
class RecordTimer
{
public:
    RecordTimer();
    ~RecordTimer();

    void start();
    void end();
    double getTick();

private:
    LARGE_INTEGER m_frequency;
    LARGE_INTEGER m_startTime;
    LARGE_INTEGER m_endTime;
};


