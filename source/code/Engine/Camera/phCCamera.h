#pragma once
#include <phMath/mat4.h>
#include <phMath/vec4.h>
#include <phMath/vec3.h>

class phCCamera
{
public:

	phCCamera(float fov, float aspectRatio, float near, float far );

	// Updates the transformation and projection matrices.
	// Recommended to use after modifying camera values.
	void Update(bool updateProjection = false, bool updateTransformation = true);

	// Getters and setters
	float GetFov() const { return m_fov; }
	float GetAspectRatio() const { return m_aspectRatio; }
	float GetNearClip() const { return m_near; }
	float GetFarClip() const { return m_far; }
	pm::vec3 GetPosition() const { return m_position; }
	pm::vec3 GetRotationEuler() const { return m_rotation; }
	pm::mat4 GetTransformationMatrix() const { return m_transformationMatrix; }
	pm::mat4 GetProjectionMatrix() const { return m_projectionMatrix; }
	pm::vec4 GetClearColor() const { return m_clearColor; }

	void SetPosition( const pm::vec3& rPosition ) { m_position = rPosition; }
	void SetRotationEuler( const pm::vec3& rRotation ) { m_rotation = rRotation; }
	void RotateEuler( const pm::vec3& rRotationDelta ) { m_rotation += rRotationDelta; }
	void SetFOV( float fov ) { m_fov = fov; }
	void SetAspectRatio( float aspectRatio ) { m_aspectRatio = aspectRatio; }
	void SetNearClip( float near ) { m_near = near; }
	void SetFarClip( float far ) { m_far = far; }
	void SetClearColor( const pm::vec4& clearColor ) { m_clearColor = clearColor; }

protected:

	float m_fov, m_aspectRatio, m_near, m_far;

	pm::mat4 m_projectionMatrix;
	pm::mat4 m_transformationMatrix;

	pm::vec3 m_position;
	pm::vec3 m_rotation;

	pm::vec4 m_clearColor;
};
