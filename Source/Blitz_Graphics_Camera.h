#ifndef BLITZ_CAMERA_H
#define BLITZ_CAMERA_H 1

#include "Blitz_BaseTypes.h"
#include "Blitz_Math.h"

namespace blitz
{
	namespace graphics
	{
		class Camera
		{
		public:
			Camera();
			Camera(float left, float right, float bottom, float top,
				float near, float far, const math::Vec2 &position, float angle);
			Camera(const Camera &camera);
			Camera & operator =(const Camera &camera);

			math::Vec2 getPosition();
			void setPosition(const math::Vec2 &position);
			float getAngle();
			void setAngle(float angle);
			void setProjection(float left, float right, float bottom, float top,
				float near, float far);
		private:
			math::Vec2 position_;
			float angle_;
			math::Mat44 viewTranslation_, viewRotation_, projection_;
		};
	}
}

#endif