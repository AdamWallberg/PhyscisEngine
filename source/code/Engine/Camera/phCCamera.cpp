#include "phCCamera.h"

phCCamera::phCCamera(float fov, float aspectRatio, float near, float far)
	: m_fov(fov)
	, m_aspectRatio(aspectRatio)
	, m_near(near)
	, m_far(far)
{
	m_position = pm::vec3::zero;
	m_rotation = pm::vec3::zero;

	m_projectionMatrix = pm::mat4::Perspective(fov, aspectRatio, near, far);
	m_transformationMatrix = pm::mat4(1.0f);

	m_clearColor = pm::vec4::black;
}

void phCCamera::Update( bool updateProjection /*= false*/, bool updateTransformation /*= true*/ )
{
	if(updateProjection)
	{
		m_projectionMatrix = pm::mat4::Perspective(m_fov, m_aspectRatio, m_near, m_far);
	}

	if(updateTransformation)
	{
		pm::mat4 newTransformMatrix( 1.0f );
		newTransformMatrix.Translate( m_position );
		
		pm::mat4 rotation(1.0f);
		rotation.RotateZYX(m_rotation);

		newTransformMatrix = rotation * newTransformMatrix;

		m_transformationMatrix = newTransformMatrix;
	}
}