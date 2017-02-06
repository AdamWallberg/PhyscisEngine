#pragma once
#include "Math/pmMat4.h"

class phCCamera
{
public:

	phCCamera(float fov, float aspectRatio, float near, float far );

	// Getters and setters
	float GetFov() const { return m_fov; }
	float GetAspectRatio() const { return m_aspectRatio; }
	float GetNearClip() const { return m_near; }
	float GetFarClip() const { return m_far; }
	pmV3 GetPosition() const { return m_position; }
	pmV3 GetRotationEuler() const { return m_rotation; }
	pmMat4 GetTransformationMatrix() const { return m_transformationMatrix; }
	pmMat4 GetProjectionMatrix() const { return m_projectionMatrix; }
	pmV3 GetClearColor() const { return m_clearColor; }

	void SetPosition( const pmV3& rPosition ) { m_position = rPosition; }
	void SetRotationEuler( const pmV3& rRotation ) { m_rotation = rRotation; }
	void RotateEuler( const pmV3& rRotationDelta ) { m_rotation += rRotationDelta; }
	void SetFOV( float fov ) { m_fov = fov; }
	void SetAspectRatio( float aspectRatio ) { m_aspectRatio = aspectRatio; }
	void SetNearClip( float near ) { m_near = near; }
	void SetFarClip( float far ) { m_far = far; }
	void SetClearColor( const pmV4& clearColor ) { m_clearColor = clearColor; }

	// Updates the transformation and projection matrices.
	// Recommended to use after modifying camera values.
	void Update(bool updateProjection = false, bool updateTransformation = true);

private:

	float m_fov, m_aspectRatio, m_near, m_far;

	pmMat4 m_projectionMatrix;
	pmMat4 m_transformationMatrix;

	pmV3 m_position;
	pmV3 m_rotation;

	pmV4 m_clearColor;
};
