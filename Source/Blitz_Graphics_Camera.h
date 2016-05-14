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

			math::Vec2 getPosition() const;
			void setPosition(const math::Vec2 &position);
			float getAngle() const;
			void setAngle(float angle);
			math::Mat44 getViewTranslation() const;
			math::Mat44 getViewRotation() const;
			math::Mat44 getProjection() const;
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