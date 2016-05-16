#include "Blitz_Core.h"
/* ----------------------------------------------------------------------------------- */
#include "Blitz_Timer.h"
#include "Blitz_Graphics_Core.h"
/* ----------------------------------------------------------------------------------- */
namespace
{
	blitz::Int32 targetFrameRate = 0;
	const blitz::Int32 DEFAULT_TARGET_FRAME_RATE = 60;
	blitz::Bool appEnded = 0;
	float previousTime = 0.0f,
		lag = 0.0f;
	blitz::Int32 MAX_ALLOWED_UPDATES_PER_FRAME = 5;
}
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace __core
	{
		Int32 init()
		{
			targetFrameRate = DEFAULT_TARGET_FRAME_RATE;
			appEnded = 0;
			Int32 result = app::init();
			if (result != 0)
			{
				return 1;
			}
			result = graphics::__core::init();
			if (result != 0)
			{
				return 1;
			}
			previousTime = getTime();
			lag = 0.0f;
			return 0;
		}
		void update()
		{
			float currentTime = getTime();
			float timeElapsed = currentTime - previousTime;
			previousTime = currentTime;
			lag += timeElapsed;
			float targetFrameTime = 1.0f / targetFrameRate;
			Int32 updateCount = 0;
			while (lag >= targetFrameTime)
			{
				app::update();
				lag -= targetFrameTime;
				++updateCount;
				if (updateCount >= MAX_ALLOWED_UPDATES_PER_FRAME)
				{
					lag = 0.0f;
					break;
				}
			}
			graphics::__core::beginRender();
			app::render(lag);
			graphics::__core::endRender();
		}
		void onEnd()
		{
			app::onEnd();
			graphics::__core::onEnd();
		}
	}
	/* ------------------------------------------------------------------------------- */
	Int32 getTargetFrameRate()
	{
		return targetFrameRate;
	}
	void setTargetFrameRate(Int32 frameRate)
	{
		targetFrameRate = frameRate;
	}
	Bool isEnded()
	{
		return appEnded;
	}
	void end()
	{
		appEnded = 1;
	}
}