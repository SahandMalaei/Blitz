#include "Blitz_Graphics_Debug.h"
/* ----------------------------------------------------------------------------------- */
#include "GL/glew.h"
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace graphics
	{
		namespace debug
		{
			void enableSolidFill()
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			void enableWireframe()
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
		}
	}
}