#include "../Include/Blitz_Input.h"
/* ------------------------------------------------------------------------------------ */
#include <GLFW/glfw3.h>
/* ------------------------------------------------------------------------------------ */
#include "Blitz_Debug.h"
/* ------------------------------------------------------------------------------------ */
namespace
{
	void keyboardCallback(GLFWwindow *window, blitz::Int32 key, blitz::Int32 scanCode,
		blitz::Int32 action, blitz::Int32 modifiers);
	void mouseButtonCallback(GLFWwindow *window, blitz::Int32 button,
		blitz::Int32 action, blitz::Int32 modifiers);
	void mouseScrollCallback(GLFWwindow *window, double offsetX, double offsetY);
	void resetCallbacks();
	/* -------------------------------------------------------------------------------- */
	blitz::Window *currentWindow = 0;
	blitz::input::KeyboardCallback currentKeyboardCallback = 0;
	blitz::input::MouseButtonCallback currentMouseButtonCallback = 0;
	blitz::input::MouseScrollCallback currentMouseScrollCallback = 0;
}
/* ------------------------------------------------------------------------------------ */
namespace blitz
{
	struct Window
	{
		GLFWwindow *handle;
	};
	/* -------------------------------------------------------------------------------- */
	namespace input
	{
		Int32 setKeyboardCallback(Window *window, KeyboardCallback callback)
		{
			__BLITZ_ASSERT(window);
			__BLITZ_ASSERT(callback);
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
			__BLITZ_ASSERT(window);
			if (currentWindow == window)
			{
				currentKeyboardCallback = 0;
			}
		}
		Int32 setMouseButtonCallback(Window *window, MouseButtonCallback callback)
		{
			__BLITZ_ASSERT(window);
			__BLITZ_ASSERT(callback);
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
			__BLITZ_ASSERT(window);
			if (currentWindow == window)
			{
				currentMouseButtonCallback = 0;
			}
		}
		Int32 setMouseScrollCallback(Window *window, MouseScrollCallback callback)
		{
			__BLITZ_ASSERT(window);
			__BLITZ_ASSERT(callback);
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
			__BLITZ_ASSERT(window);
			if (currentWindow == window)
			{
				currentMouseScrollCallback = 0;
			}
		}
		void getMousePosition(Int32 *out_x, Int32 *out_y, Window *window)
		{
			__BLITZ_ASSERT(out_x);
			__BLITZ_ASSERT(out_y);
			__BLITZ_ASSERT(window);
			double x, y;
			glfwGetCursorPos(window->handle, &x, &y);
			*out_x = (Int32)x;
			*out_y = (Int32)y;
		}
	}
}
/* ------------------------------------------------------------------------------------ */
namespace
{
	void keyboardCallback(GLFWwindow *window, blitz::Int32 key, blitz::Int32 scanCode,
		blitz::Int32 action, blitz::Int32 modifiers)
	{
		if (window == currentWindow->handle && currentKeyboardCallback)
		{
			currentKeyboardCallback(currentWindow, (blitz::input::Key)key,
				(blitz::input::Action)action, modifiers);
		}
	}
	void mouseButtonCallback(GLFWwindow *window, blitz::Int32 button,
		blitz::Int32 action, blitz::Int32 modifiers)
	{
		if (window == currentWindow->handle && currentMouseButtonCallback)
		{
			currentMouseButtonCallback(currentWindow, (blitz::input::MouseButton)button,
				(blitz::input::Action)action, modifiers);
		}
	}
	void mouseScrollCallback(GLFWwindow *window, double offsetX, double offsetY)
	{
		if (window == currentWindow->handle && currentMouseScrollCallback)
		{
			currentMouseScrollCallback(currentWindow, (float)offsetX, (float)offsetY);
		}
	}
	void resetCallbacks()
	{
		currentKeyboardCallback = 0;
		currentMouseButtonCallback = 0;
		currentMouseScrollCallback = 0;
	}
}