#pragma once

#include "pmV3.h"

class pmMat4
{
public:

	// Sets all values to 0 as default
	pmMat4();
	pmMat4( const pmMat4& other );

	// Defaults all values to 0, except the diagonal.
	// ie. pmMat4( 1.0f ) creates an identity matrix.
	// ASCII ART TIME!
	// [1 0 0 0]
	// [0 1 0 0]
	// [0 0 1 0]
	// [0 0 0 1]
	pmMat4( const float diagonal );

	~pmMat4();

	union
	{
		// Single elements of the matrix
		float elements[16];

		// Matrix represented as directional vectors and translation
		struct
		{
			// Instead of using padding floats, we align the vectors with 16 bytes
			_declspec( align(16) ) pmV3 left;
			_declspec( align(16) ) pmV3 up;
			_declspec( align(16) ) pmV3 forward;
			_declspec( align(16) ) pmV3 translation;
		};
	};

	void Translate( const pmV3& translation );
	void RotateZYX( const pmV3& axis ); // Recommended for camera rotation
	void RotateXYZ( const pmV3& axis );
	void Scale( const pmV3& scale );
	void Transpose();

	pmMat4 GetViewMatrix() const;
	pmMat4 GetInverse() const;

	static pmMat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
	static pmMat4 Perspective(float fov, float aspectRatio, float near, float far);

	pmMat4 operator * ( const pmMat4& other );

};

