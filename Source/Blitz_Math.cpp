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
		float getLength(const Vec2 &vector)
		{
			return sqrtf(vector.x * vector.x + vector.y * vector.y);
		}
		const Vec2 getNormal(const Vec2 &vector)
		{
			return vector / getLength(vector);
		}
		float getDotProduct(const Vec2 &vector0, const Vec2 &vector1)
		{
			return (vector0.x * vector1.x) + (vector0.y * vector1.y);
		}
		float getDistance(const Vec2 &position0, const Vec2 &position1)
		{
			return getLength(Vec2(position1 - position0));
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
		float getLength(const Vec3 &vector)
		{
			return sqrtf(vector.x * vector.x + vector.y * vector.y +
				vector.z * vector.z);
		}
		const Vec3 getNormal(const Vec3 &vector)
		{
			return vector / getLength(vector);
		}
		float getDotProduct(const Vec3 &vector0, const Vec3 &vector1)
		{
			return (vector0.x * vector1.x) + (vector0.y * vector1.y) +
				(vector0.z * vector1.z);
		}
		const Vec3 getCrossProduct(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.y * vector1.z - vector0.z * vector1.y,
				vector0.z * vector1.x - vector0.x * vector1.z,
				vector0.x * vector1.y - vector0.y * vector1.x);
		}
		float getDistance(const Vec3 &position0, const Vec3 &position1)
		{
			return getLength(Vec3(position1 - position0));
		}
		/* --------------------------------------------------------------------------- */
		Matrix44::Matrix44()
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					e[i][j] = 0.0f;
				}
			}
		}
		Matrix44::Matrix44(const Matrix44 &matrix)
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					e[i][j] = matrix.e[i][j];
				}
			}
		}
		Matrix44 & Matrix44::operator =(const Matrix44 &matrix)
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					e[i][j] = matrix.e[i][j];
				}
			}
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		void buildEmpty(Matrix44 *out_matrix)
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					out_matrix->e[i][j] = 0.0f;
				}
			}
		}
		void buildIdentity(Matrix44 *out_matrix)
		{
			buildEmpty(out_matrix);
			for (Int32 i = 0; i < 4; ++i)
			{
				out_matrix->e[i][i] = 1.0f;
			}
		}
		void buildTranslation(Matrix44 *out_matrix, const Vec2 &translation)
		{
			buildIdentity(out_matrix);
			out_matrix->e[0][3] = translation.x;
			out_matrix->e[1][3] = translation.y;
		}
		void buildScaling(Matrix44 *out_matrix, const Vec2 &scale)
		{
			buildIdentity(out_matrix);
			out_matrix->e[0][0] = scale.x;
			out_matrix->e[1][1] = scale.y;
		}
		void buildRotation(Matrix44 *out_matrix, const Vec2 &center, float angle)
		{
			buildIdentity(out_matrix);
			out_matrix->e[0][0] = cosf(angle);
			out_matrix->e[0][1] = -sinf(angle);
			out_matrix->e[0][3] = center.x * (1 - cosf(angle)) + center.y * sinf(angle);
			out_matrix->e[1][0] = sinf(angle);
			out_matrix->e[2][1] = cosf(angle);
			out_matrix->e[3][3] = center.y * (1 - cosf(angle)) + center.y * sinf(angle);
		}
	}
}