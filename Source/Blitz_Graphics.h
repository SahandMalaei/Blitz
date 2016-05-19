#ifndef BLITZ_GRAPHICS_H
#define BLITZ_GRAPHICS_H 1

#include "Blitz_BaseTypes.h"
#include "Blitz_Math.h"

namespace blitz
{
	namespace graphics
	{
		struct ColorRgb
		{
			float r, g, b;

			ColorRgb();
			ColorRgb(const ColorRgb &color);
			ColorRgb(float r, float g, float b);
			ColorRgb & operator =(const ColorRgb &color);
		};

		struct ColorRgba
		{
			float r, g, b, a;

			ColorRgba();
			ColorRgba(float r, float g, float b, float a);
			ColorRgba(const ColorRgba &color);
			ColorRgba & operator =(const ColorRgba &color);
		};

		struct Vertex
		{
			math::Vec3 position;
			ColorRgba color;
			math::Vec2 textureCoordinates;

			Vertex();
			Vertex(const math::Vec3 position, const ColorRgba &color,
				const math::Vec2 textureCoordinates);
			Vertex(const Vertex &vertex);
			Vertex & operator =(const Vertex &vertex);
		};

		void clear(const ColorRgba &color);
		void draw(Vertex *vertexList, Int32 vertexCount,
			Uint32 *indexList, Int32 indexCount);

		typedef Uint32 Texture;

		Int32 loadTexture(Texture *out_texture, const char *fileAddress);
		void unloadTexture(Texture texture);
		void setTexture(Texture texture);
		void unsetTexture();

		void setObjectTransform(const math::Mat44 &transform);
		void setViewTransform(const math::Mat44 &transform);
		void setProjectionTransform(const math::Mat44 &transform);

		class Camera;

		void setCamera(Camera *camera);
		void unsetCamera();

		void enableAlphaBlending();
		void enableAdditiveBlending();
		void disableBlending();
	}
}

#endif