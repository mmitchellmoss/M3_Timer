#include "M3_Timer.h"

// Timer type getters and setters.
M3_Timer::TimerType M3_Timer::getTimerType() const {
	return m_timerType;
}
bool M3_Timer::setTimerType(M3_Timer::TimerType timerType) {
	m_timerType = timerType;
	return true;
}

// Start time getters and setters.
unsigned long M3_Timer::getStartTime() const {
    return m_startTime;
}
bool M3_Timer::setStartTime(unsigned long startTime) {
    m_startTime = startTime;
    return true;
}

// Duration getters and setters.
unsigned long M3_Timer::getDuration() const {
    return m_duration;
}
bool M3_Timer::setDuration(unsigned long duration) {
    m_duration = duration;
    return true;
}




// Methods.

    // start() with no arguments is used for counting up only.
    bool M3_Timer::start() {
        // If the timer is set for counting up then do so.
        if (m_timerType == M3_Timer::TimerType::COUNT_UP) {
            m_startTime = millis();
            return true;

        // Otherwise return false as this is invalid.
        } else {
            return false;
        }
    }

    // start() with a duration is used for counting down only.
    bool M3_Timer::start(unsigned long duration) {
        // If the timer is set for couting down then do so.
        if (m_timerType == M3_Timer::TimerType::COUNT_DOWN) {
            m_startTime = millis();
            m_duration = duration;
            return true;

        // Otherwise return false as this is invalid.
        } else {
            return false;
        }
    }


    // reset() can be used to restart while counting up or down.
    void M3_Timer::reset() {
        // If counting up, call start().
        if (m_timerType == M3_Timer::TimerType::COUNT_UP) {
            M3_Timer::start();
        
        // Else call start(duration).
        } else {
            M3_Timer::start(m_duration);
        }
    }


    // Function used to return the time remaining while counting down.
    unsigned long M3_Timer::timeRemaining() const{
        // If counting down, the return the remaining time.
        if (m_timerType == M3_Timer::TimerType::COUNT_DOWN) {
            return m_startTime + m_duration - millis();
        
        // Otherwise return 0 as an indication of error.
        } else {
            return 0;
        }
    }

    // Function used to return the elapsed time while counting up.
    unsigned long M3_Timer::elapsedTime() const{
        // If counting up, return the elapsed time.
        if (m_timerType == M3_Timer::TimerType::COUNT_UP) {
            return millis() - m_startTime;

        // Otherwise return 0 as an indication of error.
        } else {
            return 0;
        }
    }

    // Function used, while counting down, to determine if the timer has expired or not.
    bool M3_Timer::isTimerExpired() const {
        // If counting down, return if the timer has expired.
        if (m_timerType == M3_Timer::TimerType::COUNT_DOWN) {
            if (millis() - m_startTime >= m_duration) {
                return true;
            } else {
                return false;
            }

        // Else return false to indicate an error situation.    
        } else {
            return false;
        }
    }