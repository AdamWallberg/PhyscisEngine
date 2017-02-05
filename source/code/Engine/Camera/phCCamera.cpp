#include "phCCamera.h"

phCCamera::phCCamera(float fov, float aspectRatio, float near, float far)
	: m_fov(fov)
	, m_aspectRatio(aspectRatio)
	, m_near(near)
	, m_far(far)
{
	m_projectionMatrix = pmMat4::Perspective(fov, aspectRatio, near, far);
	m_transformationMatrix = pmMat4(1.0f);
}

void phCCamera::SetRotationEuler( const pmV3& rRotation )
{
	m_rotation = rRotation;
}

void phCCamera::RotateEuler( const pmV3& rRotationDelta )
{
	m_rotation += rRotationDelta;
}

void phCCamera::SetFOV( float fov )
{
	m_fov = fov;
}

void phCCamera::SetAspectRatio( float aspectRatio )
{
	m_aspectRatio = aspectRatio;
}

void phCCamera::SetNearClip( float near )
{
	m_near = near;
}

void phCCamera::SetFarClip( float far )
{
	m_far = far;
}

void phCCamera::Update()
{
	m_projectionMatrix = pmMat4::Perspective(m_fov, m_aspectRatio, m_near, m_far);

	pmMat4 newTransformMatrix(1.0f);
	newTransformMatrix.Rotate(1.0f, m_rotation);
	newTransformMatrix.Translate(m_position);
}