#pragma once
#include "Math/pmMat4.h"

class phCCamera
{
public:

	phCCamera(float fov, float aspectRatio, float near, float far );

	void SetPosition(const pmV3& rPosition) { m_position = rPosition; }
	void SetRotationEuler(const pmV3& rRotation);
	void RotateEuler(const pmV3& rRotationDelta);
	void SetFOV(float fov);
	void SetAspectRatio(float aspectRatio);
	void SetNearClip(float near);
	void SetFarClip(float far);

	void Update();

private:

	float m_fov, m_aspectRatio, m_near, m_far;

	pmMat4 m_projectionMatrix;
	pmMat4 m_transformationMatrix;

	pmV3 m_position;
	pmV3 m_rotation;
};
