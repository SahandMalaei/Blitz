#include "Blitz_Input.h"
/* ----------------------------------------------------------------------------------- */
#include <GLFW/glfw3.h>
/* ----------------------------------------------------------------------------------- */
namespace
{
	void keyboardCallback(GLFWwindow *window, blitz::Int32 key, blitz::Int32 scanCode,
		blitz::Int32 action, blitz::Int32 modifiers);
	void mouseButtonCallback(GLFWwindow *window, blitz::Int32 button,
		blitz::Int32 action, blitz::Int32 modifiers);
	void mouseScrollCallback(GLFWwindow *window, double offsetX, double offsetY);
	void resetCallbacks();
	/* ------------------------------------------------------------------------------- */
	blitz::Window *currentWindow = 0;
	blitz::input::KeyboardCallback currentKeyboardCallback = 0;
	blitz::input::MouseButtonCallback currentMouseButtonCallback = 0;
	blitz::input::MouseScrollCallback currentMouseScrollCallback = 0;
}
namespace blitz
{
	struct Window
	{
		GLFWwindow *handle;
	};
	namespace input
	{
		const Int32 KEY_UNKNOWN = GLFW_KEY_UNKNOWN;
		const Int32 KEY_SPACE = GLFW_KEY_SPACE;
		const Int32 KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE;
		const Int32 KEY_COMMA = GLFW_KEY_COMMA;
		const Int32 KEY_MINUS = GLFW_KEY_MINUS;
		const Int32 KEY_PERIOD = GLFW_KEY_PERIOD;
		const Int32 KEY_SLASH = GLFW_KEY_SLASH;
		const Int32 KEY_0 = GLFW_KEY_0;
		const Int32 KEY_1 = GLFW_KEY_1;
		const Int32 KEY_2 = GLFW_KEY_2;
		const Int32 KEY_3 = GLFW_KEY_3;
		const Int32 KEY_4 = GLFW_KEY_4;
		const Int32 KEY_5 = GLFW_KEY_5;
		const Int32 KEY_6 = GLFW_KEY_6;
		const Int32 KEY_7 = GLFW_KEY_7;
		const Int32 KEY_8 = GLFW_KEY_8;
		const Int32 KEY_9 = GLFW_KEY_9;
		const Int32 KEY_SEMICOLON = GLFW_KEY_SEMICOLON;
		const Int32 KEY_EQUAL = GLFW_KEY_EQUAL;
		const Int32 KEY_A = GLFW_KEY_A;
		const Int32 KEY_B = GLFW_KEY_B;
		const Int32 KEY_C = GLFW_KEY_C;
		const Int32 KEY_D = GLFW_KEY_D;
		const Int32 KEY_E = GLFW_KEY_E;
		const Int32 KEY_F = GLFW_KEY_F;
		const Int32 KEY_G = GLFW_KEY_G;
		const Int32 KEY_H = GLFW_KEY_H;
		const Int32 KEY_I = GLFW_KEY_I;
		const Int32 KEY_J = GLFW_KEY_J;
		const Int32 KEY_K = GLFW_KEY_K;
		const Int32 KEY_L = GLFW_KEY_L;
		const Int32 KEY_M = GLFW_KEY_M;
		const Int32 KEY_N = GLFW_KEY_N;
		const Int32 KEY_O = GLFW_KEY_O;
		const Int32 KEY_P = GLFW_KEY_P;
		const Int32 KEY_Q = GLFW_KEY_Q;
		const Int32 KEY_R = GLFW_KEY_R;
		const Int32 KEY_S = GLFW_KEY_S;
		const Int32 KEY_T = GLFW_KEY_T;
		const Int32 KEY_U = GLFW_KEY_U;
		const Int32 KEY_V = GLFW_KEY_V;
		const Int32 KEY_W = GLFW_KEY_W;
		const Int32 KEY_X = GLFW_KEY_X;
		const Int32 KEY_Y = GLFW_KEY_Y;
		const Int32 KEY_Z = GLFW_KEY_Z;
		const Int32 KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
		const Int32 KEY_BACKSLASH = GLFW_KEY_BACKSLASH;
		const Int32 KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
		const Int32 KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
		const Int32 KEY_WORLD_1 = GLFW_KEY_WORLD_1;
		const Int32 KEY_WORLD_2 = GLFW_KEY_WORLD_2;
		const Int32 KEY_ESCAPE = GLFW_KEY_ESCAPE;
		const Int32 KEY_ENTER = GLFW_KEY_ENTER;
		const Int32 KEY_TAB = GLFW_KEY_TAB;
		const Int32 KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
		const Int32 KEY_INSERT = GLFW_KEY_INSERT;
		const Int32 KEY_DELETE = GLFW_KEY_DELETE;
		const Int32 KEY_RIGHT = GLFW_KEY_RIGHT;
		const Int32 KEY_LEFT = GLFW_KEY_LEFT;
		const Int32 KEY_DOWN = GLFW_KEY_DOWN;
		const Int32 KEY_UP = GLFW_KEY_UP;
		const Int32 KEY_PAGE_UP = GLFW_KEY_PAGE_UP;
		const Int32 KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
		const Int32 KEY_HOME = GLFW_KEY_HOME;
		const Int32 KEY_END = GLFW_KEY_END;
		const Int32 KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
		const Int32 KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
		const Int32 KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK;
		const Int32 KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
		const Int32 KEY_PAUSE = GLFW_KEY_PAUSE;
		const Int32 KEY_F1 = GLFW_KEY_F1;
		const Int32 KEY_F2 = GLFW_KEY_F2;
		const Int32 KEY_F3 = GLFW_KEY_F3;
		const Int32 KEY_F4 = GLFW_KEY_F4;
		const Int32 KEY_F5 = GLFW_KEY_F5;
		const Int32 KEY_F6 = GLFW_KEY_F6;
		const Int32 KEY_F7 = GLFW_KEY_F7;
		const Int32 KEY_F8 = GLFW_KEY_F8;
		const Int32 KEY_F9 = GLFW_KEY_F9;
		const Int32 KEY_F10 = GLFW_KEY_F10;
		const Int32 KEY_F11 = GLFW_KEY_F11;
		const Int32 KEY_F12 = GLFW_KEY_F12;
		const Int32 KEY_F13 = GLFW_KEY_F13;
		const Int32 KEY_F14 = GLFW_KEY_F14;
		const Int32 KEY_F15 = GLFW_KEY_F15;
		const Int32 KEY_F16 = GLFW_KEY_F16;
		const Int32 KEY_F17 = GLFW_KEY_F17;
		const Int32 KEY_F18 = GLFW_KEY_F18;
		const Int32 KEY_F19 = GLFW_KEY_F19;
		const Int32 KEY_F20 = GLFW_KEY_F20;
		const Int32 KEY_F21 = GLFW_KEY_F21;
		const Int32 KEY_F22 = GLFW_KEY_F22;
		const Int32 KEY_F23 = GLFW_KEY_F23;
		const Int32 KEY_F24 = GLFW_KEY_F24;
		const Int32 KEY_F25 = GLFW_KEY_F25;
		const Int32 KEY_KP_0 = GLFW_KEY_KP_0;
		const Int32 KEY_KP_1 = GLFW_KEY_KP_1;
		const Int32 KEY_KP_2 = GLFW_KEY_KP_2;
		const Int32 KEY_KP_3 = GLFW_KEY_KP_3;
		const Int32 KEY_KP_4 = GLFW_KEY_KP_4;
		const Int32 KEY_KP_5 = GLFW_KEY_KP_5;
		const Int32 KEY_KP_6 = GLFW_KEY_KP_6;
		const Int32 KEY_KP_7 = GLFW_KEY_KP_7;
		const Int32 KEY_KP_8 = GLFW_KEY_KP_8;
		const Int32 KEY_KP_9 = GLFW_KEY_KP_9;
		const Int32 KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL;
		const Int32 KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE;
		const Int32 KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
		const Int32 KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT;
		const Int32 KEY_KP_ADD = GLFW_KEY_KP_ADD;
		const Int32 KEY_KP_ENTER = GLFW_KEY_KP_ENTER;
		const Int32 KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL;
		const Int32 KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
		const Int32 KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
		const Int32 KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
		const Int32 KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
		const Int32 KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
		const Int32 KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
		const Int32 KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
		const Int32 KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
		const Int32 KEY_MENU = GLFW_KEY_MENU;
		/* --------------------------------------------------------------------------- */
		const Int32 MODIFIER_SHIFT = GLFW_MOD_SHIFT;
		const Int32 MODIFIER_CONTROL = GLFW_MOD_CONTROL;
		const Int32 MODIFIER_ALT = GLFW_MOD_ALT;
		const Int32 MODIFIER_SUPER = GLFW_MOD_SUPER;
		/* --------------------------------------------------------------------------- */
		const Int32 MOUSE_BUTTON_1 = GLFW_MOUSE_BUTTON_1;
		const Int32 MOUSE_BUTTON_2 = GLFW_MOUSE_BUTTON_2;
		const Int32 MOUSE_BUTTON_3 = GLFW_MOUSE_BUTTON_3;
		const Int32 MOUSE_BUTTON_4 = GLFW_MOUSE_BUTTON_4;
		const Int32 MOUSE_BUTTON_5 = GLFW_MOUSE_BUTTON_5;
		const Int32 MOUSE_BUTTON_6 = GLFW_MOUSE_BUTTON_6;
		const Int32 MOUSE_BUTTON_7 = GLFW_MOUSE_BUTTON_7;
		const Int32 MOUSE_BUTTON_8 = GLFW_MOUSE_BUTTON_8;
		const Int32 MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1;
		const Int32 MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2;
		const Int32 MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3;
		/* --------------------------------------------------------------------------- */
		Int32 setKeyboardCallback(Window *window, KeyboardCallback callback)
		{
			if (currentWindow != window)
			{
				resetCallbacks();
				currentWindow = window;
			}
			currentKeyboardCallback = callback;
			glfwSetKeyCallback(window->handle, keyboardCallback);
			return 0;
		}
		void removeKeyboardCallback(Window *window)
		{
			if (currentWindow == window)
			{
				currentKeyboardCallback = 0;
			}
		}
		Int32 setMouseButtonCallback(Window *window, MouseButtonCallback callback)
		{
			if (currentWindow != currentWindow)
			{
				resetCallbacks();
				currentWindow = window;
			}
			currentMouseButtonCallback = callback;
			glfwSetMouseButtonCallback(window->handle, mouseButtonCallback);
			return 0;
		}
		void removeMouseButtonCallback(Window *window)
		{
			if (currentWindow == window)
			{
				currentMouseButtonCallback = 0;
			}
		}
		Int32 setMouseScrollCallback(Window *window, MouseScrollCallback callback)
		{
			if (currentWindow != currentWindow)
			{
				resetCallbacks();
				currentWindow = window;
			}
			currentMouseScrollCallback = callback;
			glfwSetScrollCallback(window->handle, mouseScrollCallback);
			return 0;
		}
		void removeMouseScrollCallback(Window *window)
		{
			if (currentWindow == window)
			{
				currentMouseScrollCallback = 0;
			}
		}
	}
}
namespace
{
	void keyboardCallback(GLFWwindow *window, blitz::Int32 key, blitz::Int32 scanCode,
		blitz::Int32 action, blitz::Int32 modifiers)
	{
		if (window == currentWindow->handle && currentKeyboardCallback)
		{
			currentKeyboardCallback(currentWindow, key, action, modifiers);
		}
	}
	void mouseButtonCallback(GLFWwindow *window, blitz::Int32 button,
		blitz::Int32 action, blitz::Int32 modifiers)
	{
		if (window == currentWindow->handle && currentMouseButtonCallback)
		{
			currentMouseButtonCallback(currentWindow, button, action, modifiers);
		}
	}
	void mouseScrollCallback(GLFWwindow *window, double offsetX, double offsetY)
	{
		if (window == currentWindow->handle && currentMouseScrollCallback)
		{
			blitz::input::Point<float> offset;
			offset.x = (float)offsetX;
			offset.y = (float)offsetY;
			currentMouseScrollCallback(currentWindow, offset);
		}
	}
	void resetCallbacks()
	{
		currentKeyboardCallback = 0;
		currentMouseButtonCallback = 0;
		currentMouseScrollCallback = 0;
	}
}