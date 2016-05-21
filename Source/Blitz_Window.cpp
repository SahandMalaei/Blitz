#include "Blitz_Window.h"
/* ----------------------------------------------------------------------------------- */
#include <GLFW/glfw3.h>
/* ----------------------------------------------------------------------------------- */
namespace
{
	blitz::Bool windowPresent = 0;
	blitz::Window *currentWindow = 0;
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
		glfwMakeContextCurrent(window->handle);
		windowPresent = 1;
		currentWindow = window;
		return window;
	}
	void destroyWindow(Window *window)
	{
		if (windowPresent && window && window->handle)
		{
			glfwDestroyWindow(window->handle);
			delete window;
			windowPresent = 0;
			currentWindow = 0;
		}
	}
	Window *getCurrentWindow()
	{
		return currentWindow;
	}
	Bool windowShouldClose(Window *window)
	{
		return (Bool)glfwWindowShouldClose(window->handle);
	}
	void getWindowPosition(Int32 *out_x, Int32 *out_y, Window *window)
	{
		glfwGetWindowPos(window->handle, out_x, out_y);
	}
	void setWindowPosition(Window *window, Int32 x, Int32 y)
	{
		glfwSetWindowPos(window->handle, x, y);
	}
	void setWindowTitle(Window *window, const char *title)
	{
		glfwSetWindowTitle(window->handle, title);
	}
	/* ------------------------------------------------------------------------------- */
	namespace graphics
	{
		void setVsync(Bool state)
		{
			glfwSwapInterval(state ? 1 : 0);
		}
	}
	/* ------------------------------------------------------------------------------- */
	void __swapBuffers()
	{
		glfwSwapBuffers(currentWindow->handle);
	}
}