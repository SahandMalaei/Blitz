#ifndef BLITZ_INPUT_H
#define BLITZ_INPUT_H 1

#include "Blitz_BaseTypes.h"
#include "Blitz_Window.h"

namespace blitz
{
	namespace input
	{
		typedef void (*KeyboardCallback)(Window *window, Int32 key, Int32 action,
			Int32 modifiers);
		typedef void (*MouseButtonCallback)(Window *window, Int32 button, Int32 action,
			Int32 modifiers);

		Int32 setKeyboardCallback(Window *window, KeyboardCallback callback);
		void removeKeyboardCallback(Window *window);
		Int32 setMouseButtonCallback(Window *window, MouseButtonCallback callback);
		void removeMouseButtonCallback(Window *window);
	}
}

#endif