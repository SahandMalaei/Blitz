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
		
		float getLength(const Vec2 &vector);
		const Vec2 getNormal(const Vec2 &vector);
		float getDotProduct(const Vec2 &vector0, const Vec2 &vector1);
		float getDistance(const Vec2 &position0, const Vec2 &position1);

		struct Vec3
		{
		public:
			float x, y, z;

			Vec3();
			Vec3(const Vec3 &vector);
			Vec3(float x, float y, float z);
			Vec3 & operator =(const Vec3 &vector);
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

		float getLength(const Vec3 &vector);
		const Vec3 getNormal(const Vec3 &vector);
		float getDotProduct(const Vec3 &vector0, const Vec3 &vector1);
		const Vec3 getCrossProduct(const Vec3 &vector0, const Vec3 &vector1);
		float getDistance(const Vec3 &position0, const Vec3 &position1);

		struct Matrix44
		{
			float e[4][4];

			Matrix44();
			Matrix44(const Matrix44 &matrix);
			Matrix44 & operator =(const Matrix44 &matrix);
		};

		Matrix44 & operator +=(Matrix44 &matrix0, const Matrix44 &matrix1);
		Matrix44 & operator -=(Matrix44 &matrix0, const Matrix44 &matrix1);
		Matrix44 & operator *=(Matrix44 &matrix, float number);
		Matrix44 & operator /=(Matrix44 &matrix, float number);
		Matrix44 & operator *=(Matrix44 &matrix0, const Matrix44 &matrix1);
		const Matrix44 operator -(const Matrix44 &matrix);
		const Matrix44 operator +(const Matrix44 &matrix0, const Matrix44 &matrix1);
		const Matrix44 operator -(const Matrix44 &matrix0, const Matrix44 &matrix1);
		const Matrix44 operator *(float number, const Matrix44 &matrix);
		const Matrix44 operator *(const Matrix44 &matrix, float number);
		const Matrix44 operator *(const Matrix44 &matrix0, const Matrix44 &matrix1);
		const Matrix44 operator /(const Matrix44 &matrix, float number);

		void buildEmpty(Matrix44 *out_matrix);
		void buildIdentity(Matrix44 *out_matrix);
		void buildTranslation(Matrix44 *out_matrix, const Vec2 &translation);
		void buildScaling(Matrix44 *out_matrix, const Vec2 &scale);
		void buildRotation(Matrix44 *out_matrix, const Vec2 &center, float angle);
		void buildOrthographicProjection(Matrix44 *out_matrix, float left, float right,
			float bottom, float top, float near, float far);
	}
}

#endif