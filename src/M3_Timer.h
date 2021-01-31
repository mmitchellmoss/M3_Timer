/*
M3_Timer.h

This class is designed to represent a timer, allowing count up or down timing.

Items to consider:
1. What to do when the TimerType is changed.

Author: Mitch Moss
*/

#ifndef M3_TIMER_8234089282_H
#define M3_TIMER_8234089282_H



#include "Arduino.h"

namespace M3 {

    class Timer {
    public:
        // Enums.
        enum TimerType { COUNT_UP, COUNT_DOWN };

        // Timer type getters and setters.
        TimerType getTimerType() const;
        bool setTimerType(TimerType timerType);

        // Start Time getters and setters.
        unsigned long getStartTime() const;
        bool setStartTime(unsigned long startTime);

        // Duration getters and setters.
        unsigned long getDuration() const;
        bool setDuration(unsigned long duration);

        

        // Methods.
        bool start();
        bool start(unsigned long duration);
        void reset();
        unsigned long timeRemaining() const;
        unsigned long elapsedTime() const;
        bool isTimerExpired() const;



    private:
        // Private members.
        TimerType m_timerType { COUNT_DOWN };
        unsigned long m_duration { 0ul };
        unsigned long m_startTime { 0ul };

    };

}

#endif