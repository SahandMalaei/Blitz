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
		Vec2 & operator *=(Vec2 &vector, float number)
		{
			vector.x *= number;
			vector.y *= number;
			return vector;
		}
		Vec2 & operator /=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x /= vector1.x;
			vector0.y /= vector1.y;
			return vector0;
		}
		Vec2 & operator /=(Vec2 &vector, float number)
		{
			vector.x /= number;
			vector.y /= number;
			return vector;
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
		/* --------------------------------------------------------------------------- */
		Vec3::Vec3() :
			x(0.0f),
			y(0.0f),
			z(0.0f)
		{

		}
		Vec3::Vec3(const Vec3 &vector) :
			x(vector.x),
			y(vector.y),
			z(vector.z)
		{
		}
		Vec3::Vec3(float x, float y, float z) :
			x(x),
			y(y),
			z(y)
		{
		}
		float Vec3::length() const
		{
			return sqrtf(x * x + y * y + z * z);
		}
		Vec3 & Vec3::operator =(const Vec3 &vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		Vec3 & operator +=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x += vector1.x;
			vector0.y += vector1.y;
			vector0.z += vector1.z;
			return vector0;
		}
		Vec3 & operator -=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x -= vector1.x;
			vector0.y -= vector1.y;
			vector0.z -= vector1.z;
			return vector0;
		}
		Vec3 & operator *=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x *= vector1.x;
			vector0.y *= vector1.y;
			vector0.z *= vector1.z;
			return vector0;
		}
		Vec3 & operator *=(Vec3 &vector, float number)
		{
			vector.x *= number;
			vector.y *= number;
			vector.z *= number;
			return vector;
		}
		Vec3 & operator /=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x /= vector1.x;
			vector0.y /= vector1.y;
			vector0.z /= vector1.z;
			return vector0;
		}
		Vec3 & operator /=(Vec3 &vector, float number)
		{
			vector.x /= number;
			vector.y /= number;
			vector.z /= number;
			return vector;
		}
		const Vec3 operator +(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x + vector1.x, vector0.y + vector1.y,
				vector0.z + vector1.z);
		}
		const Vec3 operator -(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x - vector1.x, vector0.y - vector1.y,
				vector0.z - vector1.z);
		}
		const Vec3 operator *(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x * vector1.x, vector0.y * vector1.y,
				vector0.z * vector1.z);
		}
		const Vec3 operator *(const Vec3 &vector, float number)
		{
			return Vec3(vector.x * number, vector.y * number, vector.z * number);
		}
		const Vec3 operator /(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x / vector1.x, vector0.y / vector1.y,
				vector0.z / vector1.z);
		}
		const Vec3 operator /(const Vec3 &vector, float number)
		{
			return Vec3(vector.x / number, vector.y / number, vector.z / number);
		}
		/* --------------------------------------------------------------------------- */
		float distance(const Vec3 &position0, const Vec3 &position1)
		{
			return Vec3(position1 - position0).length();
		}
	}
}