#include "../Include/Blitz_Math.h"
/* ------------------------------------------------------------------------------------ */
#include <math.h>
/* ------------------------------------------------------------------------------------ */
#include "Blitz_Debug.h"
/* ------------------------------------------------------------------------------------ */
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
		/* ---------------------------------------------------------------------------- */
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
		Vec2 & operator *=(Vec2 &vector, float number)
		{
			vector.x *= number;
			vector.y *= number;
			return vector;
		}
		Vec2 & operator *=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x *= vector1.x;
			vector0.y *= vector1.y;
			return vector0;
		}
		Vec2 & operator /=(Vec2 &vector, float number)
		{
			vector.x /= number;
			vector.y /= number;
			return vector;
		}
		Vec2 & operator /=(Vec2 &vector0, const Vec2 &vector1)
		{
			vector0.x /= vector1.x;
			vector0.y /= vector1.y;
			return vector0;
		}
		const Vec2 operator +(const Vec2 &vector)
		{
			return vector;
		}
		const Vec2 operator -(const Vec2 &vector)
		{
			return vector * -1.0f;
		}
		const Vec2 operator +(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x + vector1.x, vector0.y + vector1.y);
		}
		const Vec2 operator -(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x - vector1.x, vector0.y - vector1.y);
		}
		const Vec2 operator *(float number, const Vec2 &vector)
		{
			return Vec2(vector.x * number, vector.y * number);
		}
		const Vec2 operator *(const Vec2 &vector, float number)
		{
			return number * vector;
		}
		const Vec2 operator *(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x * vector1.x, vector0.y * vector1.y);
		}
		const Vec2 operator /(const Vec2 &vector, float number)
		{
			return Vec2(vector.x / number, vector.y / number);
		}
		const Vec2 operator /(const Vec2 &vector0, const Vec2 &vector1)
		{
			return Vec2(vector0.x / vector1.x, vector0.y / vector1.y);
		}
		Bool operator ==(const Vec2 &vector0, const Vec2 &vector1)
		{
			return vector0.x == vector1.x && vector0.y == vector1.y;
		}
		Bool operator !=(const Vec2 &vector0, const Vec2 &vector1)
		{
			return !(vector0 == vector1);
		}
		/* ---------------------------------------------------------------------------- */
		float getLength(const Vec2 &vector)
		{
			return sqrtf(vector.x * vector.x + vector.y * vector.y);
		}
		const Vec2 getNormal(const Vec2 &vector)
		{
			__BLITZ_ASSERT(getLength(vector) != 0);
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
		/* ---------------------------------------------------------------------------- */
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
			z(z)
		{
		}
		Vec3 & Vec3::operator =(const Vec3 &vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}
		/* ---------------------------------------------------------------------------- */
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
		Vec3 & operator *=(Vec3 &vector, float number)
		{
			vector.x *= number;
			vector.y *= number;
			vector.z *= number;
			return vector;
		}
		Vec3 & operator *=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x *= vector1.x;
			vector0.y *= vector1.y;
			vector0.z *= vector1.z;
			return vector0;
		}
		Vec3 & operator /=(Vec3 &vector, float number)
		{
			vector.x /= number;
			vector.y /= number;
			vector.z /= number;
			return vector;
		}
		Vec3 & operator /=(Vec3 &vector0, const Vec3 &vector1)
		{
			vector0.x /= vector1.x;
			vector0.y /= vector1.y;
			vector0.z /= vector1.z;
			return vector0;
		}
		const Vec3 operator +(const Vec3 &vector)
		{
			return vector;
		}
		const Vec3 operator -(const Vec3 &vector)
		{
			return vector * -1.0f;
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
		const Vec3 operator *(float number, const Vec3 &vector)
		{
			return Vec3(vector.x * number, vector.y * number, vector.z * number);
		}
		const Vec3 operator *(const Vec3 &vector, float number)
		{
			return number * vector;
		}
		const Vec3 operator *(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x * vector1.x, vector0.y * vector1.y,
				vector0.z * vector1.z);
		}
		const Vec3 operator /(const Vec3 &vector, float number)
		{
			return Vec3(vector.x / number, vector.y / number, vector.z / number);
		}
		const Vec3 operator /(const Vec3 &vector0, const Vec3 &vector1)
		{
			return Vec3(vector0.x / vector1.x, vector0.y / vector1.y,
				vector0.z / vector1.z);
		}
		Bool operator ==(const Vec3 &vector0, const Vec3 &vector1)
		{
			return vector0.x == vector1.x && vector0.y == vector1.y &&
				vector0.z == vector1.z;
		}
		Bool operator !=(const Vec3 &vector0, const Vec3 &vector1)
		{
			return !(vector0 == vector1);
		}
		/* ---------------------------------------------------------------------------- */
		float getLength(const Vec3 &vector)
		{
			return sqrtf(vector.x * vector.x + vector.y * vector.y +
				vector.z * vector.z);
		}
		const Vec3 getNormal(const Vec3 &vector)
		{
			__BLITZ_ASSERT(getLength(vector) != 0);
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
		/* ---------------------------------------------------------------------------- */
		Mat44::Mat44()
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					e[i][j] = 0.0f;
				}
			}
		}
		Mat44::Mat44(const Mat44 &matrix)
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					e[i][j] = matrix.e[i][j];
				}
			}
		}
		Mat44 & Mat44::operator =(const Mat44 &matrix)
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
		/* ---------------------------------------------------------------------------- */
		Mat44 & operator +=(Mat44 &matrix0, const Mat44 &matrix1)
		{
			return (matrix0 = matrix0 + matrix1);
		}
		Mat44 & operator -=(Mat44 &matrix0, const Mat44 &matrix1)
		{
			return (matrix0 = matrix0 - matrix1);
		}
		Mat44 & operator *=(Mat44 &matrix, float number)
		{
			return (matrix = matrix * number);
		}
		Mat44 & operator /=(Mat44 &matrix, float number)
		{
			return (matrix = matrix / number);
		}
		Mat44 & operator *=(Mat44 &matrix0, const Mat44 &matrix1)
		{
			return (matrix0 = matrix0 * matrix1);
		}
		const Mat44 operator +(const Mat44 &matrix)
		{
			return matrix;
		}
		const Mat44 operator -(const Mat44 &matrix)
		{
			return -1.0f * matrix;
		}
		const Mat44 operator +(const Mat44 &matrix0,
			const Mat44 &matrix1)
		{
			Mat44 result = matrix0;
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					result.e[i][j] += matrix1.e[i][j];
				}
			}
			return result;
		}
		const Mat44 operator -(const Mat44 &matrix0,
			const Mat44 &matrix1)
		{
			return matrix0 + (-matrix1);
		}
		const Mat44 operator *(float number, const Mat44 &matrix)
		{
			Mat44 result = matrix;
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					result.e[i][j] *= number;
				}
			}
			return result;
		}
		const Mat44 operator *(const Mat44 &matrix, float number)
		{
			return number * matrix;
		}
		const Mat44 operator *(const Mat44 &matrix0,
			const Mat44 &matrix1)
		{
			Mat44 result;
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					for (Int32 k = 0; k < 4; ++k)
					{
						result.e[i][j] += matrix0.e[i][k] * matrix1.e[k][j];
					}
				}
			}
			return result;
		}
		const Mat44 operator /(const Mat44 &matrix, float number)
		{
			return (1.0f / number) * matrix;
		}
		Bool operator ==(const Mat44 &matrix0, const Mat44 &matrix1)
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					if (matrix0.e[i][j] != matrix1.e[i][j])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		Bool operator !=(const Mat44 &matrix0, const Mat44 &matrix1)
		{
			return !(matrix0 == matrix1);
		}
		/* ---------------------------------------------------------------------------- */
		void buildEmpty(Mat44 *out_matrix)
		{
			__BLITZ_ASSERT(out_matrix);
			for (Int32 i = 0; i < 4; ++i)
			{
				for (Int32 j = 0; j < 4; ++j)
				{
					out_matrix->e[i][j] = 0.0f;
				}
			}
		}
		void buildIdentity(Mat44 *out_matrix)
		{
			__BLITZ_ASSERT(out_matrix);
			buildEmpty(out_matrix);
			for (Int32 i = 0; i < 4; ++i)
			{
				out_matrix->e[i][i] = 1.0f;
			}
		}
		void buildTranslation(Mat44 *out_matrix, const Vec2 &translation)
		{
			__BLITZ_ASSERT(out_matrix);
			buildIdentity(out_matrix);
			out_matrix->e[0][3] = translation.x;
			out_matrix->e[1][3] = translation.y;
		}
		void buildScaling(Mat44 *out_matrix, const Vec2 &scale)
		{
			__BLITZ_ASSERT(out_matrix);
			buildIdentity(out_matrix);
			out_matrix->e[0][0] = scale.x;
			out_matrix->e[1][1] = scale.y;
		}
		void buildRotation(Mat44 *out_matrix, const Vec2 &center, float angle)
		{
			__BLITZ_ASSERT(out_matrix);
			buildIdentity(out_matrix);
			out_matrix->e[0][0] = cosf(angle);
			out_matrix->e[0][1] = -sinf(angle);
			out_matrix->e[0][3] = center.x *
				(1.0f - cosf(angle)) + center.y * sinf(angle);
			out_matrix->e[1][0] = sinf(angle);
			out_matrix->e[1][1] = cosf(angle);
			out_matrix->e[1][3] = center.y *
				(1.0f - cosf(angle)) - center.x * sinf(angle);
		}
		void buildOrthographicProjection(Mat44 *out_matrix, float left, float right,
			float bottom, float top, float near, float far)
		{
			__BLITZ_ASSERT(out_matrix);
			buildEmpty(out_matrix);
			out_matrix->e[0][0] = 2.0f / (right - left);
			out_matrix->e[0][3] = -((right + left) / (right - left));
			out_matrix->e[1][1] = 2.0f / (top - bottom);
			out_matrix->e[1][3] = -((top + bottom) / (top - bottom));
			out_matrix->e[2][2] = 2.0f / (far - near);
			out_matrix->e[2][3] = -((far + near) / (far - near));
			out_matrix->e[3][3] = 1.0f;
		}
	}
}