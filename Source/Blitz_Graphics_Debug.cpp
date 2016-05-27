#include "../Include/Blitz_Graphics_Debug.h"
/* ------------------------------------------------------------------------------------ */
#include "GL/glew.h"
/* ------------------------------------------------------------------------------------ */
#include "../Include/Blitz_Graphics.h"
/* ------------------------------------------------------------------------------------ */
namespace
{
	GLuint vertexBuffer, indexBuffer;
}
/* ------------------------------------------------------------------------------------ */
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
			void drawLine(const math::Vec2 &position0, const math::Vec2 &position1,
				float depth, const ColorRgba &color)
			{
				static Bool firstCall = 1;
				if (firstCall)
				{
					glGenBuffers(1, &vertexBuffer);
					glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
					glGenBuffers(1, &indexBuffer);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
					firstCall = 0;
				}
				Vertex vertexList[2];
				vertexList[0] = Vertex(math::Vec3(position0.x, position0.y, depth),
					color, math::Vec2(0.0f, 0.0f));
				vertexList[1] = Vertex(math::Vec3(position1.x, position1.y, depth),
					color, math::Vec2(0.0f, 0.0f));
				Uint32 indexList[2] = {0, 1};
				glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
				glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 2, vertexList,
					GL_DYNAMIC_DRAW);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Uint32) * 2,
					indexList, GL_DYNAMIC_DRAW);
				__setVertexFormat();
				glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, 0);
				__unsetVertexFormat();
			}
			void setLineWidth(float width)
			{
				glLineWidth(width);
			}
		}
	}
}