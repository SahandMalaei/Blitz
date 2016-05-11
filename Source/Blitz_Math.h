#ifndef BLITZ_MATH_H
#define BLITZ_MATH_H 1

#include "Blitz_BaseTypes.h"

namespace blitz
{
	namespace math
	{
		struct Vec2
		{
		public:
			float x, y;

			Vec2();
			Vec2(const Vec2 &vector);
			Vec2(float x, float y);
			Vec2 & operator =(const Vec2 &vector);

			float length() const;
		};

		Vec2 & operator +=(Vec2 &vector0, const Vec2 &vector1);
		Vec2 & operator -=(Vec2 &vector0, const Vec2 &vector1);
		Vec2 & operator *=(Vec2 &vector0, const Vec2 &vector1);
		Vec2 & operator *=(Vec2 &vector0, float number);
		Vec2 & operator /=(Vec2 &vector0, const Vec2 &vector1);
		Vec2 & operator /=(Vec2 &vector0, float number);
		const Vec2 operator +(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator -(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator *(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator *(const Vec2 &vector, float number);
		const Vec2 operator /(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator /(const Vec2 &vector, float number);

		float distance(const Vec2 &position0, const Vec2 &position1);
	}
}

#endif