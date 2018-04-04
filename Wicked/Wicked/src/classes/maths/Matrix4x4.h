#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector4.h"
#include "Vector3.h"

namespace wicked
{
	namespace maths
	{
		struct Matrix4x4
		{
			Matrix4x4();
			Matrix4x4(const Vector4& col1, const Vector4& col2, const Vector4& col3, const Vector4& col4);
			Matrix4x4(const Matrix4x4& A);

			Vector4& operator[](size_t index);
			const Vector4& operator[](size_t index) const;
			Matrix4x4& operator=(const Matrix4x4& A);
			friend Matrix4x4 operator*(const Matrix4x4& A, const Matrix4x4& B);

			static Matrix4x4 translate(const Matrix4x4& matrix, const Vector3& translation);
			static Matrix4x4 scale(const Matrix4x4& matrix, const Vector3& scaleFactor);
			static Matrix4x4 rotate(const Matrix4x4& matrix, float angle, const Vector3& axis);
			static Matrix4x4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
			static Matrix4x4 ortho(float left, float right, float bottom, float top, float near, float far);

		private:
			Vector4 m_data[4];
			
			static const size_t m_rows = 4;
			static const size_t m_cols = 4;
		};
	}
}

#endif