#ifndef BLITZ_GRAPHICS_CORE_H
#define BLITZ_GRAPHICS_CORE_H

#include "Blitz_BaseTypes.h"

namespace blitz
{
	namespace graphics
	{
		namespace __core
		{
			Int32 init();
			void beginRender();
			void endRender();
			void onEnd();
		}
	}
}

#endif