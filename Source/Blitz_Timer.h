#ifndef BLITZ_TIMER_H
#define BLITZ_TIMER_H 1

#include "Blitz_BaseTypes.h"

namespace blitz
{
	float getTime();
	/* Used to get high-precision time information and also provides functionality
	   similar to that of a stopwatch. Time is measured in seconds. */
	class Timer
	{
	public:
		Timer();
		Timer(const Timer &timer);
		~Timer();
		Timer & operator =(const Timer &timer);
		float getTime() const;
		float getTimeElapsed() const;
		float getStartTime() const;
		Bool timeElapsed(float time) const;
		/* Resets the start time. */
		void reset();
	private:
		float startTime_;
	};
}

#endif