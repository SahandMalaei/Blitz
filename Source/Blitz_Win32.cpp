#include <GL/glew.h>
#include <GLFW/glfw3.h>
/* ------------------------------------------------------------------------------------ */
#include "Blitz_Debug.h"
#include "../Include/Blitz_BaseTypes.h"
#include "../Include/Blitz_Core.h"
#include "../Include/Blitz_Window.h"
/* ------------------------------------------------------------------------------------ */
struct HINSTANCE__
{
	int unused;
};
typedef HINSTANCE__ *HINSTANCE;
/* ------------------------------------------------------------------------------------ */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char *lpCmdLine,
	int nCmdShow)
{
	glfwInit();
	blitz::Int32 result = blitz::__core::init();
	if (result != 0)
	{
		__BLITZ_THROW_ERROR("Core initialization failed.");
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