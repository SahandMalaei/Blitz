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
		Vec2 & operator *=(Vec2 &vector, float number);
		Vec2 & operator /=(Vec2 &vector0, const Vec2 &vector1);
		Vec2 & operator /=(Vec2 &vector, float number);
		const Vec2 operator +(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator -(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator *(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator *(const Vec2 &vector, float number);
		const Vec2 operator /(const Vec2 &vector0, const Vec2 &vector1);
		const Vec2 operator /(const Vec2 &vector, float number);

		float distance(const Vec2 &position0, const Vec2 &position1);

		struct Vec3
		{
		public:
			float x, y, z;

			Vec3();
			Vec3(const Vec3 &vector);
			Vec3(float x, float y, float z);
			Vec3 & operator =(const Vec3 &vector);

			float length() const;
		};

		Vec3 & operator +=(Vec3 &vector0, const Vec3 &vector1);
		Vec3 & operator -=(Vec3 &vector0, const Vec3 &vector1);
		Vec3 & operator *=(Vec3 &vector0, const Vec3 &vector1);
		Vec3 & operator *=(Vec3 &vector, float number);
		Vec3 & operator /=(Vec3 &vector0, const Vec3 &vector1);
		Vec3 & operator /=(Vec3 &vector, float number);
		const Vec3 operator +(const Vec3 &vector0, const Vec3 &vector1);
		const Vec3 operator -(const Vec3 &vector0, const Vec3 &vector1);
		const Vec3 operator *(const Vec3 &vector0, const Vec3 &vector1);
		const Vec3 operator *(const Vec3 &vector, float number);
		const Vec3 operator /(const Vec3 &vector0, const Vec3 &vector1);
		const Vec3 operator /(const Vec3 &vector, float number);

		float distance(const Vec3 &position0, const Vec3 &position1);
	}
}

#endif