#include "Blitz_Graphics_Camera.h"
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace graphics
	{
		Camera::Camera() :
			angle_(0.0f)
		{
			math::buildIdentity(&viewTranslation_);
			math::buildIdentity(&viewRotation_);
			setProjection(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
		}
		Camera::Camera(float left, float right, float bottom, float top,
			float near, float far, const math::Vec2 &position, float angle) :
			angle_(angle),
			position_(position)
		{
			math::buildTranslation(&viewTranslation_, -position_);
			math::buildRotation(&viewRotation_, math::Vec2(0.0f, 0.0f), -angle_);
			math::buildOrthographicProjection(&projection_, left, right, bottom, top,
				near, far);
		}
		Camera::Camera(const Camera &camera) :
			angle_(camera.angle_),
			position_(camera.position_),
			viewTranslation_(camera.viewTranslation_),
			viewRotation_(camera.viewRotation_),
			projection_(camera.projection_)
		{
		}
		Camera & Camera::operator =(const Camera &camera)
		{
			position_ = camera.position_;
			angle_ = camera.angle_;
			viewTranslation_ = camera.viewTranslation_;
			viewRotation_ = camera.viewRotation_;
			projection_ = camera.projection_;
			return *this;
		}
		math::Vec2 Camera::getPosition()
		{
			return position_;
		}
		void Camera::setPosition(const math::Vec2 &position)
		{
			position_ = position;
			math::buildTranslation(&viewTranslation_, -position);
		}
		float Camera::getAngle()
		{
			return angle_;
		}
		void Camera::setAngle(float angle)
		{
			angle_ = angle;
			math::buildRotation(&viewRotation_, math::Vec2(0.0f, 0.0f), -angle);
		}
		void Camera::setProjection(float left, float right, float bottom, float top,
			float near, float far)
		{
			math::buildOrthographicProjection(&projection_, left, right, bottom, top,
				near, far);
		}
	}
}