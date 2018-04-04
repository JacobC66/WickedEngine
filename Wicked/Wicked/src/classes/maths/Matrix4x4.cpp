#include <cassert>
#include "Matrix4x4.h"

namespace wicked
{
	namespace maths
	{
		Matrix4x4::Matrix4x4()
		{
			for (size_t row = 0; row < m_rows; row++)
				m_data[row][row] = 1;
		}

		Matrix4x4::Matrix4x4(const Vector4& col1, const Vector4& col2, const Vector4& col3, const Vector4& col4)
		{
			m_data[0] = col1;
			m_data[1] = col2;
			m_data[2] = col3;
			m_data[3] = col4;
		}

		Matrix4x4::Matrix4x4(const Matrix4x4& A)
		{
			for (size_t row = 0; row < m_rows; row++)
				for (size_t col = 0; col < m_cols; col++)
					m_data[row][col] = A[row][col];
		}

		Vector4& Matrix4x4::operator[](size_t index)
		{
			assert(index >= 0 && index < m_rows);
			return m_data[index];
		}

		const Vector4& Matrix4x4::operator[](size_t index) const
		{
			assert(index >= 0 && index < m_rows);
			return m_data[index];
		}

		Matrix4x4& Matrix4x4::operator=(const Matrix4x4 & A)
		{
			for (size_t row = 0; row < m_rows; row++)
				for (size_t col = 0; col < m_cols; col++)
					m_data[row][col] = A[row][col];
			return *this;
		}

		Matrix4x4 operator*(const Matrix4x4& A, const Matrix4x4& B)
		{
			Matrix4x4 temp;
			for (size_t k = 0; k < Matrix4x4::m_cols; k++)
			{
				for (size_t i = 0; i < Matrix4x4::m_rows; i++)
				{
					float sum{ 0.0f };
					for (size_t j = 0; j < Matrix4x4::m_cols; j++)
					{
						sum += A[j][k] * B[i][j];
					}
					temp[i][k] = sum;
				}
			}
			return temp;
		}

		Matrix4x4 Matrix4x4::translate(const Matrix4x4& matrix, const Vector3& translation)
		{
			Matrix4x4 temp(matrix);
			temp[3][0] = translation.x;
			temp[3][1] = translation.y;
			temp[3][2] = translation.z;
			return temp;
		}

		Matrix4x4 Matrix4x4::scale(const Matrix4x4& matrix, const Vector3& scaleFactor)
		{
			Matrix4x4 temp(matrix);
			temp[0][0] = scaleFactor.x;
			temp[1][1] = scaleFactor.y;
			temp[2][2] = scaleFactor.z;
			return temp;
		}

		Matrix4x4 Matrix4x4::rotate(const Matrix4x4 & matrix, float angle, const Vector3 & axis)
		{
			// Missing
			return Matrix4x4();
		}

		Matrix4x4 Matrix4x4::lookAt(const Vector3 & eye, const Vector3 & target, const Vector3 & up)
		{
			Vector3 zAxis(eye - target);
			Vector3 xAxis(Vector3::normalize(Vector3::cross(up, zAxis)));
			Vector3 yAxis(Vector3::cross(zAxis, xAxis));

			Matrix4x4 R;
			R[0][0] = xAxis.x;
			R[1][0] = xAxis.y;
			R[2][0] = xAxis.z;
			R[0][1] = yAxis.x;
			R[1][1] = yAxis.y;
			R[2][1] = yAxis.z;
			R[0][2] = zAxis.x;
			R[1][2] = zAxis.y;
			R[2][2] = zAxis.z;

			Matrix4x4 T;
			T[3][0] = -eye.x;
			T[3][1] = -eye.y;
			T[3][2] = -eye.z;

			return T * R;
		}

		Matrix4x4 Matrix4x4::ortho(float left, float right, float bottom, float top, float near, float far)
		{
			Matrix4x4 temp;
			temp[0][0] = 2.0f / (right - left);
			temp[1][1] = 2.0f / (top - bottom);
			temp[2][2] = 2.0f / (near - far);
			temp[3][0] = -(right + left) / (right - left);
			temp[3][1] = -(top + bottom) / (top - bottom);
			temp[3][2] = -(far + near) / (far - near);

			return temp;
		}
	}
}