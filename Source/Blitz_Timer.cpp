#include "Blitz_Timer.h"
/* ----------------------------------------------------------------------------------- */
#include <GLFW/glfw3.h>
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	float getTime()
	{
		return (float)glfwGetTime();
	}
	/* ------------------------------------------------------------------------------- */
	Timer::Timer() :
		startTime_(0.0f)
	{
		reset();
	}
	Timer::Timer(const Timer &timer) :
		startTime_(timer.startTime_)
	{
	}
	Timer::~Timer()
	{
	}
	Timer & Timer::operator =(const Timer &timer)
	{
		startTime_ = timer.startTime_;
		return *this;
	}
	float Timer::getTime() const
	{
		return (float)glfwGetTime();
	}
	float Timer::getTimeElapsed() const
	{
		return getTime() - startTime_;
	}
	float Timer::getStartTime() const
	{
		return startTime_;
	}
	Bool Timer::timeElapsed(float time) const
	{
		return getTime() - startTime_ >= time;
	}
	void Timer::reset()
	{
		startTime_ = getTime();
	}
}