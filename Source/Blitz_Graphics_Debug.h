#ifndef BLITZ_GRAPHICS_DEBUG_H
#define BLITZ_GRAPHICS_DEBUG_H

#include "Blitz_Math.h"
#include "Blitz_Graphics.h"

namespace blitz
{
	namespace graphics
	{
		namespace debug
		{
			void enableSolidFill();
			void enableWireframe();

			void drawLine(const math::Vec2 &position0, const math::Vec2 &position1,
				float depth, const ColorRgba &color);
			void setLineWidth(float width);
		}
	}
}

#endif