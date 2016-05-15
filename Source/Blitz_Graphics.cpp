#include "Blitz_Graphics.h"
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace graphics
	{
		ColorRgb::ColorRgb() :
			r(0.0f),
			g(0.0f),
			b(0.0f)
		{
		}
		ColorRgb::ColorRgb(const ColorRgb &color) :
			r(color.r),
			g(color.g),
			b(color.b)
		{
		}
		ColorRgb::ColorRgb(float r, float g, float b) :
			r(r),
			g(g),
			b(b)
		{
		}
		ColorRgb & ColorRgb::operator =(const ColorRgb &color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		ColorRgba::ColorRgba() :
			r(0.0f),
			g(0.0f),
			b(0.0f),
			a(0.0f)
		{
		}
		ColorRgba::ColorRgba(const ColorRgba &color) :
			r(color.r),
			g(color.g),
			b(color.b),
			a(color.a)
		{
		}
		ColorRgba::ColorRgba(float r, float g, float b, float a) :
			r(r),
			g(g),
			b(b),
			a(a)
		{
		}
		ColorRgba & ColorRgba::operator =(const ColorRgba &color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		Vertex::Vertex()
		{
		}
		Vertex::Vertex(const math::Vec3 position, const ColorRgba &color,
			const math::Vec2 textureCoordinates) :
			position(position),
			color(color),
			textureCoordinates(textureCoordinates)
		{
		}
		Vertex::Vertex(const Vertex &vertex) :
			position(vertex.position),
			color(vertex.color),
			textureCoordinates(vertex.textureCoordinates)
		{
		}
		Vertex & Vertex::operator =(const Vertex &vertex)
		{
			position = vertex.position;
			color = vertex.color;
			textureCoordinates = vertex.textureCoordinates;
			return *this;
		}
	}
}