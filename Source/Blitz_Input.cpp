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
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	struct Window
	{
		GLFWwindow *handle;
	};
	/* ------------------------------------------------------------------------------- */
	namespace input
	{
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
		const Point<float> getMousePosition(Window *window)
		{
			double x, y;
			glfwGetCursorPos(window->handle, &x, &y);
			Point<float> position;
			position.x = (float)x;
			position.y = (float)y;
			return position;
		}
	}
}
/* ----------------------------------------------------------------------------------- */
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