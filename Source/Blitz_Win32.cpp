#include <GL/glew.h>
#include <GLFW/glfw3.h>
/* ----------------------------------------------------------------------------------- */
#include "Blitz_BaseTypes.h"
#include "Blitz_Core.h"
#include "Blitz_Window.h"
/* ----------------------------------------------------------------------------------- */
struct HINSTANCE__
{
	int unused;
};
typedef HINSTANCE__ *HINSTANCE;
/* ----------------------------------------------------------------------------------- */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char *lpCmdLine,
	int nCmdShow)
{
	glfwInit();
	blitz::Int32 result = blitz::__core::init();
	if (result != 0)
	{
		return 1;
	}
	while (!blitz::windowShouldClose(blitz::getCurrentWindow()) && !blitz::isEnded())
	{
		blitz::__core::update();
		blitz::__swapBuffers();
		glfwPollEvents();
	}
	blitz::__core::onEnd();
	return 0;
}