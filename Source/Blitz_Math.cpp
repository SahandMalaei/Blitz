#include "Blitz_Math.h"
/* ----------------------------------------------------------------------------------- */
#include <math.h>
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace math
	{
		Vec2::Vec2() :
			x(0.0f),
			y(0.0f)
		{

		}
		Vec2::Vec2(const Vec2 &vector) :
			x(vector.x),
			y(vector.y)
		{
		}
		Vec2::Vec2(float x, float y) :
			x(x),
			y(y)
		{
		}
		float Vec2::length() const
		{
			return sqrtf(x * x + y * y);
		}
		Vec2 & Vec2::operator =(const Vec2 &vector)
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		Vec2 & operator +=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x += vector1.x;
			vector0.y += vector1.y;
			return vector0;
		}
		Vec2 & operator -=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x -= vector1.x;
			vector0.y -= vector1.y;
			return vector0;
		}
		Vec2 & operator *=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x *= vector1.x;
			vector0.y *= vector1.y;
			return vector0;
		}
		Vec2 & operator *=(Vec2 &vector0, float number)
		{
			vector0.x *= number;
			vector0.y *= number;
			return vector0;
		}
		Vec2 & operator /=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x /= vector1.x;
			vector0.y /= vector1.y;
			return vector0;
		}
		Vec2 & operator /=(Vec2 &vector0, float number)
		{
			vector0.x /= number;
			vector0.y /= number;
			return vector0;
		}
		const Vec2 operator +(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x + vector1.x, vector0.y + vector1.y);
		}
		const Vec2 operator -(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x - vector1.x, vector0.y - vector1.y);
		}
		const Vec2 operator *(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x * vector1.x, vector0.y * vector1.y);
		}
		const Vec2 operator *(const Vec2 &vector, float number)
		{
			return Vec2(vector.x * number, vector.y * number);
		}
		const Vec2 operator /(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x / vector1.x, vector0.y / vector1.y);
		}
		const Vec2 operator /(const Vec2 &vector, float number)
		{
			return Vec2(vector.x / number, vector.y / number);
		}
		/* --------------------------------------------------------------------------- */
		float distance(const Vec2 &position0, const Vec2 &position1)
		{
			return Vec2(position1 - position0).length();
		}
	}
}