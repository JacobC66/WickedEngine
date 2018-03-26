#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector4.h"

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
			Matrix4x4& operator=(Matrix4x4& A);
			friend Matrix4x4 operator*(Matrix4x4& A, Matrix4x4& B);

		private:
			Vector4 m_data[4];
			
			static const size_t m_rows = 4;
			static const size_t m_cols = 4;
		};
	}
}

#endif