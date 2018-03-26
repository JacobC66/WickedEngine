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

		Matrix4x4& Matrix4x4::operator=(Matrix4x4 & A)
		{
			for (size_t row = 0; row < m_rows; row++)
				for (size_t col = 0; col < m_cols; col++)
					m_data[row][col] = A[row][col];
			return *this;
		}

		Matrix4x4 operator*(Matrix4x4& A, Matrix4x4& B)
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
	}
}