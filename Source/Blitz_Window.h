#ifndef BLITZ_WINDOW_H
#define BLITZ_WINDOW_H 1

#include "Blitz_BaseTypes.h"

namespace blitz
{
	struct Window;

	Window *createWindow(Int32 width, Int32 height, const char *title, Bool fullscreen);
	void destroyWindow(Window *window);
}

#endif