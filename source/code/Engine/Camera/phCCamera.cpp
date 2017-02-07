#include "phCCamera.h"

phCCamera::phCCamera(float fov, float aspectRatio, float near, float far)
	: m_fov(fov)
	, m_aspectRatio(aspectRatio)
	, m_near(near)
	, m_far(far)
{
	m_position = pmV3::zero;
	m_rotation = pmV3::zero;

	m_projectionMatrix = pmMat4::Perspective(fov, aspectRatio, near, far);
	m_transformationMatrix = pmMat4(1.0f);

	m_clearColor = pmV4::black;
}

void phCCamera::Update( bool updateProjection /*= false*/, bool updateTransformation /*= true*/ )
{
	if(updateProjection)
	{
		m_projectionMatrix = pmMat4::Perspective(m_fov, m_aspectRatio, m_near, m_far);
	}

	if(updateTransformation)
	{
		pmMat4 newTransformMatrix( 1.0f );
		
		float length;
		pmV3 rotationNormalized = m_rotation.normalize(&length);
		newTransformMatrix.Rotate( length, rotationNormalized );
		
		newTransformMatrix.Translate( m_position );
		
		m_transformationMatrix = newTransformMatrix;
	}
}