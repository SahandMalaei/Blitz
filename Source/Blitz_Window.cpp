#include "../Include/Blitz_Window.h"
/* ------------------------------------------------------------------------------------ */
#include <GLFW/glfw3.h>
/* ------------------------------------------------------------------------------------ */
#include "Blitz_Debug.h"
/* ------------------------------------------------------------------------------------ */
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
		__BLITZ_ASSERT(title);
		if (windowPresent)
		{
			__BLITZ_THROW_ERROR(
				"Failed to create window : A window is already present.");
			return 0;
		}
		glfwWindowHint(GLFW_RESIZABLE, 0);
		Window *window = new Window();
		window->handle = glfwCreateWindow(width, height, title,
			fullscreen ? glfwGetPrimaryMonitor() : 0, 0);
		if (!window->handle)
		{
			__BLITZ_THROW_ERROR("Failed to create window.");
			return 0;
		}
		glfwMakeContextCurrent(window->handle);
		windowPresent = 1;
		currentWindow = window;
		blitz::__debug::throwMessage("Window created.");
		return window;
	}
	void destroyWindow(Window *window)
	{
		__BLITZ_ASSERT(window);
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
		__BLITZ_ASSERT(window);
		return (Bool)glfwWindowShouldClose(window->handle);
	}
	void getWindowPosition(Int32 *out_x, Int32 *out_y, Window *window)
	{
		__BLITZ_ASSERT(out_x);
		__BLITZ_ASSERT(out_y);
		__BLITZ_ASSERT(window);
		glfwGetWindowPos(window->handle, out_x, out_y);
	}
	void setWindowPosition(Window *window, Int32 x, Int32 y)
	{
		__BLITZ_ASSERT(window);
		glfwSetWindowPos(window->handle, x, y);
	}
	void setWindowTitle(Window *window, const char *title)
	{
		__BLITZ_ASSERT(window);
		__BLITZ_ASSERT(title);
		glfwSetWindowTitle(window->handle, title);
	}
	/* -------------------------------------------------------------------------------- */
	namespace graphics
	{
		void setVsync(Bool state)
		{
			glfwSwapInterval(state ? 1 : 0);
		}
	}
	/* -------------------------------------------------------------------------------- */
	void __swapBuffers()
	{
		glfwSwapBuffers(currentWindow->handle);
	}
}