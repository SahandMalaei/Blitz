#include "Blitz_Window.h"
/* ----------------------------------------------------------------------------------- */
#include <GLFW/glfw3.h>
/* ----------------------------------------------------------------------------------- */
namespace
{
	blitz::Bool windowPresent = 0;
}
namespace blitz
{
	struct Window
	{
		GLFWwindow *handle;
	};
	Window *createWindow(Int32 width, Int32 height, const char *title, Bool fullscreen)
	{
		if (windowPresent)
		{
			return 0;
		}
		glfwWindowHint(GLFW_RESIZABLE, 0);
		Window *window = new Window();
		window->handle = glfwCreateWindow(width, height, title,
			fullscreen ? glfwGetPrimaryMonitor() : 0, 0);
		if (!window->handle)
		{
			return 0;
		}
		windowPresent = 1;
	}
	void destroyWindow(Window *window)
	{
		if (windowPresent && window && window->handle)
		{
			glfwDestroyWindow(window->handle);
			delete window;
			windowPresent = 0;
		}
	}
}