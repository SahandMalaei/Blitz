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
	/* ------------------------------------------------------------------------------- */
	blitz::Window *currentWindow = 0;
	blitz::input::KeyboardCallback currentKeyboardCallback = 0;
	blitz::input::MouseButtonCallback currentMouseButtonCallback = 0;
}
namespace blitz
{
	struct Window
	{
		GLFWwindow *handle;
	};
	namespace input
	{
		Int32 setKeyboardCallback(Window *window, KeyboardCallback callback)
		{
			if (currentWindow != window)
			{
				currentMouseButtonCallback = 0;
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
				currentKeyboardCallback = 0;
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
}