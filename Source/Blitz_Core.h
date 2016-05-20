#ifndef BLITZ_CORE_H
#define BLITZ_CORE_H

#include "Blitz_BaseTypes.h"

namespace blitz
{
	namespace __core
	{
		Int32 init();
		void update();
		void onEnd();
	}

	namespace app
	{
		Int32 init();
		void update();
		void render(float timeOffset);
		void onEnd();
	}

	Int32 getTargetFrameRate();
	void setTargetFrameRate(Int32 frameRate);

	Bool isEnded();
	void end();
}

#endif