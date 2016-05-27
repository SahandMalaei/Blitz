#ifndef BLITZ_GRAPHICS_CAMERA_H
#define BLITZ_GRAPHICS_CAMERA_H

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

			const math::Vec2 getPosition() const;
			void setPosition(const math::Vec2 &position);
			float getAngle() const;
			void setAngle(float angle);
			const math::Mat44 getView() const;
			const math::Mat44 getProjection() const;
			void setProjection(float left, float right, float bottom, float top,
				float near, float far);
		private:
			math::Vec2 position_;
			float angle_;
			mutable math::Mat44 view_, viewTranslation_, viewRotation_, projection_;
			mutable Bool viewTranslationValid_, viewRotationValid_;
			math::Vec2 viewportCenter_;
		};
	}
}

#endif