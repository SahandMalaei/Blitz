#include "Blitz_Graphics_Helper.h"
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace graphics
	{
		void fillRectangle(const math::Vec2 &origin, const math::Vec2 &dimensions,
			float depth, const ColorRgba &color,
			const math::Vec2 &originTextureCoordinates,
			const math::Vec2 &textureCoordinatesDimensions)
		{
			Vertex vertexList[4];
			vertexList[0] = Vertex(math::Vec3(origin.x, origin.y, depth), color,
				originTextureCoordinates);
			vertexList[1] = Vertex(math::Vec3(origin.x + dimensions.x, origin.y, depth),
				color, originTextureCoordinates +
				math::Vec2(textureCoordinatesDimensions.x, 0.0f));
			vertexList[2] = Vertex(
				math::Vec3(origin.x + dimensions.x, origin.y + dimensions.y, depth),
				color, originTextureCoordinates + textureCoordinatesDimensions);
			vertexList[3] = Vertex(
				math::Vec3(origin.x, origin.y + dimensions.y, depth),
				color, originTextureCoordinates +
				math::Vec2(0.0f, textureCoordinatesDimensions.y));
			Uint32 indexList[6] = {0, 1, 2, 0, 2, 3};
			draw(vertexList, 4, indexList, 6);
		}
	}
}