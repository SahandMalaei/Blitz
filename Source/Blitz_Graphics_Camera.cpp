#include "Blitz_Graphics_Camera.h"
/* ------------------------------------------------------------------------------------ */
namespace blitz
{
	namespace graphics
	{
		Camera::Camera() :
			angle_(0.0f),
			viewTranslationValid_(1),
			viewRotationValid_(1)
		{
			math::buildIdentity(&view_);
			math::buildIdentity(&viewTranslation_);
			math::buildIdentity(&viewRotation_);
			math::buildOrthographicProjection(&projection_, -1.0f, 1.0f, -1.0f, 1.0f,
				1.0f, -1.0f);
		}
		Camera::Camera(float left, float right, float bottom, float top,
			float near, float far, const math::Vec2 &position, float angle) :
			angle_(angle),
			position_(position),
			viewTranslationValid_(1),
			viewRotationValid_(1),
			viewportCenter_((left + right) / 2.0f, (bottom + top) / 2.0f)
		{
			math::buildTranslation(&viewTranslation_, viewportCenter_ - position_);
			math::buildRotation(&viewRotation_, math::Vec2(0.0f, 0.0f), -angle_);
			view_ = viewTranslation_ * viewRotation_;
			math::buildOrthographicProjection(&projection_, left, right, bottom, top,
				near, far);
		}
		Camera::Camera(const Camera &camera) :
			angle_(camera.angle_),
			position_(camera.position_),
			view_(camera.view_),
			viewTranslation_(camera.viewTranslation_),
			viewRotation_(camera.viewRotation_),
			projection_(camera.projection_),
			viewTranslationValid_(camera.viewTranslationValid_),
			viewRotationValid_(camera.viewRotationValid_),
			viewportCenter_(camera.viewportCenter_)
		{
		}
		Camera & Camera::operator =(const Camera &camera)
		{
			position_ = camera.position_;
			angle_ = camera.angle_;
			view_ = camera.view_;
			viewTranslation_ = camera.viewTranslation_;
			viewRotation_ = camera.viewRotation_;
			projection_ = camera.projection_;
			viewTranslationValid_ = camera.viewTranslationValid_;
			viewRotationValid_ = camera.viewRotationValid_;
			viewportCenter_ = camera.viewportCenter_;
			return *this;
		}
		const math::Vec2 Camera::getPosition() const
		{
			return position_;
		}
		void Camera::setPosition(const math::Vec2 &position)
		{
			if (position_ != position)
			{
				position_ = position;
				viewTranslationValid_ = 0;
			}
		}
		float Camera::getAngle() const
		{
			return angle_;
		}
		void Camera::setAngle(float angle)
		{
			if (angle_ != angle)
			{
				angle_ = angle;
				viewRotationValid_ = 0;
			}
		}
		const math::Mat44 Camera::getView() const
		{
			if (!viewTranslationValid_ || !viewRotationValid_)
			{
				if (!viewTranslationValid_)
				{
					blitz::math::buildTranslation(&viewTranslation_,
						viewportCenter_ - position_);
					viewTranslationValid_ = 1;
				}
				if (!viewRotationValid_)
				{
					blitz::math::buildRotation(&viewRotation_, position_, -angle_);
					viewRotationValid_ = 1;
				}
				view_ = viewTranslation_ * viewRotation_;
			}
			return view_;
		}
		const math::Mat44 Camera::getProjection() const
		{
			return projection_;
		}
		void Camera::setProjection(float left, float right, float bottom, float top,
			float near, float far)
		{
			math::buildOrthographicProjection(&projection_, left, right, bottom, top,
				near, far);
			viewportCenter_ = math::Vec2((left + right) / 2.0f, (bottom + top) / 2.0f);
			viewTranslationValid_ = 0;
		}
	}
}