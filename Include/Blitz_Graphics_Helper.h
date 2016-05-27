#ifndef BLITZ_GRAPHICS_HELPER_H
#define BLITZ_GRAPHICS_HELPER_H

#include "Blitz_BaseTypes.h"
#include "Blitz_Math.h"
#include "Blitz_Graphics.h"

namespace blitz
{
	namespace graphics
	{
		void fillRectangle(const math::Vec2 &origin, const math::Vec2 &dimensions,
			float depth, const ColorRgba &color,
			const math::Vec2 &originTextureCoordinates = math::Vec2(0.0f, 0.0f),
			const math::Vec2 &textureCoordinatesDimensions = math::Vec2(1.0f, 1.0f));
	}
}

#endif