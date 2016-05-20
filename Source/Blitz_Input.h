#ifndef BLITZ_INPUT_H
#define BLITZ_INPUT_H 1

#include "Blitz_BaseTypes.h"
#include "Blitz_Window.h"

namespace blitz
{
	namespace input
	{
		extern const Int32 KEY_UNKNOWN;

		extern const Int32 KEY_SPACE;
		extern const Int32 KEY_APOSTROPHE;
		extern const Int32 KEY_COMMA;
		extern const Int32 KEY_MINUS;
		extern const Int32 KEY_PERIOD;
		extern const Int32 KEY_SLASH;
		extern const Int32 KEY_0;
		extern const Int32 KEY_1;
		extern const Int32 KEY_2;
		extern const Int32 KEY_3;
		extern const Int32 KEY_4;
		extern const Int32 KEY_5;
		extern const Int32 KEY_6;
		extern const Int32 KEY_7;
		extern const Int32 KEY_8;
		extern const Int32 KEY_9;
		extern const Int32 KEY_SEMICOLON;
		extern const Int32 KEY_EQUAL;
		extern const Int32 KEY_A;
		extern const Int32 KEY_B;
		extern const Int32 KEY_C;
		extern const Int32 KEY_D;
		extern const Int32 KEY_E;
		extern const Int32 KEY_F;
		extern const Int32 KEY_G;
		extern const Int32 KEY_H;
		extern const Int32 KEY_I;
		extern const Int32 KEY_J;
		extern const Int32 KEY_K;
		extern const Int32 KEY_L;
		extern const Int32 KEY_M;
		extern const Int32 KEY_N;
		extern const Int32 KEY_O;
		extern const Int32 KEY_P;
		extern const Int32 KEY_Q;
		extern const Int32 KEY_R;
		extern const Int32 KEY_S;
		extern const Int32 KEY_T;
		extern const Int32 KEY_U;
		extern const Int32 KEY_V;
		extern const Int32 KEY_W;
		extern const Int32 KEY_X;
		extern const Int32 KEY_Y;
		extern const Int32 KEY_Z;
		extern const Int32 KEY_LEFT_BRACKET;
		extern const Int32 KEY_BACKSLASH;
		extern const Int32 KEY_RIGHT_BRACKET;
		extern const Int32 KEY_GRAVE_ACCENT;
		extern const Int32 KEY_WORLD_1;
		extern const Int32 KEY_WORLD_2;
		extern const Int32 KEY_ESCAPE;
		extern const Int32 KEY_ENTER;
		extern const Int32 KEY_TAB;
		extern const Int32 KEY_BACKSPACE;
		extern const Int32 KEY_INSERT;
		extern const Int32 KEY_DELETE;
		extern const Int32 KEY_RIGHT;
		extern const Int32 KEY_LEFT;
		extern const Int32 KEY_DOWN;
		extern const Int32 KEY_UP;
		extern const Int32 KEY_PAGE_UP;
		extern const Int32 KEY_PAGE_DOWN;
		extern const Int32 KEY_HOME;
		extern const Int32 KEY_END;
		extern const Int32 KEY_CAPS_LOCK;
		extern const Int32 KEY_SCROLL_LOCK;
		extern const Int32 KEY_NUM_LOCK;
		extern const Int32 KEY_PRINT_SCREEN;
		extern const Int32 KEY_PAUSE;
		extern const Int32 KEY_F1;
		extern const Int32 KEY_F2;
		extern const Int32 KEY_F3;
		extern const Int32 KEY_F4;
		extern const Int32 KEY_F5;
		extern const Int32 KEY_F6;
		extern const Int32 KEY_F7;
		extern const Int32 KEY_F8;
		extern const Int32 KEY_F9;
		extern const Int32 KEY_F10;
		extern const Int32 KEY_F11;
		extern const Int32 KEY_F12;
		extern const Int32 KEY_F13;
		extern const Int32 KEY_F14;
		extern const Int32 KEY_F15;
		extern const Int32 KEY_F16;
		extern const Int32 KEY_F17;
		extern const Int32 KEY_F18;
		extern const Int32 KEY_F19;
		extern const Int32 KEY_F20;
		extern const Int32 KEY_F21;
		extern const Int32 KEY_F22;
		extern const Int32 KEY_F23;
		extern const Int32 KEY_F24;
		extern const Int32 KEY_F25;
		extern const Int32 KEY_KP_0;
		extern const Int32 KEY_KP_1;
		extern const Int32 KEY_KP_2;
		extern const Int32 KEY_KP_3;
		extern const Int32 KEY_KP_4;
		extern const Int32 KEY_KP_5;
		extern const Int32 KEY_KP_6;
		extern const Int32 KEY_KP_7;
		extern const Int32 KEY_KP_8;
		extern const Int32 KEY_KP_9;
		extern const Int32 KEY_KP_DECIMAL;
		extern const Int32 KEY_KP_DIVIDE;
		extern const Int32 KEY_KP_MULTIPLY;
		extern const Int32 KEY_KP_SUBTRACT;
		extern const Int32 KEY_KP_ADD;
		extern const Int32 KEY_KP_ENTER;
		extern const Int32 KEY_KP_EQUAL;
		extern const Int32 KEY_LEFT_SHIFT;
		extern const Int32 KEY_LEFT_CONTROL;
		extern const Int32 KEY_LEFT_ALT;
		extern const Int32 KEY_LEFT_SUPER;
		extern const Int32 KEY_RIGHT_SHIFT;
		extern const Int32 KEY_RIGHT_CONTROL;
		extern const Int32 KEY_RIGHT_ALT;
		extern const Int32 KEY_RIGHT_SUPER;
		extern const Int32 KEY_MENU;

		extern const Int32 MODIFIER_SHIFT;
		extern const Int32 MODIFIER_CONTROL;
		extern const Int32 MODIFIER_ALT;
		extern const Int32 MODIFIER_SUPER;

		extern const Int32 MOUSE_BUTTON_1;
		extern const Int32 MOUSE_BUTTON_2;
		extern const Int32 MOUSE_BUTTON_3;
		extern const Int32 MOUSE_BUTTON_4;
		extern const Int32 MOUSE_BUTTON_5;
		extern const Int32 MOUSE_BUTTON_6;
		extern const Int32 MOUSE_BUTTON_7;
		extern const Int32 MOUSE_BUTTON_8;
		extern const Int32 MOUSE_BUTTON_LEFT;
		extern const Int32 MOUSE_BUTTON_RIGHT;
		extern const Int32 MOUSE_BUTTON_MIDDLE;

		template<typename T> class Point
		{
		public:
			T x, y;
		};

		typedef void (*KeyboardCallback)(Window *window, Int32 key, Int32 action,
			Int32 modifiers);
		typedef void (*MouseButtonCallback)(Window *window, Int32 button, Int32 action,
			Int32 modifiers);
		typedef void (*MouseScrollCallback)(Window *window, const Point<float> &offset);

		Int32 setKeyboardCallback(Window *window, KeyboardCallback callback);
		void removeKeyboardCallback(Window *window);
		Int32 setMouseButtonCallback(Window *window, MouseButtonCallback callback);
		void removeMouseButtonCallback(Window *window);
		Int32 setMouseScrollCallback(Window *window, MouseScrollCallback callback);
		void removeMouseScrollCallback(Window *window);
		const Point<float> getMousePosition(Window *window);
	}
}

#endif