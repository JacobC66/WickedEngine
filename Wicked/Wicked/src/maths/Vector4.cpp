#include <cassert>
#include <cmath>

#include "Vector4.h"

namespace wicked
{
	namespace maths
	{
		Vector4::Vector4()
			: x{ 0 },
			  y{ 0 },
			  z{ 0 },
			  w{ 0 },
			  magnitud{ 0 }
		{
		}

		Vector4::Vector4(float _x, float _y, float _z, float _w)
			: x{ _x },
			  y{ _y },
			  z{ _z },
			  w{ _w },
			  magnitud{ sqrt((_x * _x) + (_y * _y) + (_z * _z)) +(_w * _w) }
		{
		}

		Vector4::Vector4(const Vector4& u)
			: x{ u.x },
			  y{ u.y },
			  z{ u.z },
			  w{ u.w },
			  magnitud{ u.magnitud }
		{
		}

		float& Vector4::operator[](size_t index)
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		const float& Vector4::operator[](size_t index) const
		{
			assert(index >= 0 && index < m_length);
			return *(&x + index);
		}

		Vector4& Vector4::operator=(const Vector4& u)
		{
			x = u.x;
			y = u.y;
			z = u.z;
			w = u.w;
			return *this;
		}

		void Vector4::operator+= (const Vector4& u)
		{
			x += u.x;
			y += u.y;
			z += u.z;
			w += u.w;
		}

		void Vector4::operator-= (const Vector4& u)
		{
			x -= u.x;
			y -= u.y;
			z -= u.z;
			w -= u.w;
		}
		void Vector4::operator*= (const Vector4& u)
		{
			x *= u.x;
			y *= u.y;
			z *= u.z;
			w *= u.w;
		}

		void Vector4::operator/= (const Vector4& u)
		{
			x /= u.x;
			y /= u.y;
			z /= u.z;
			w /= u.w;
		}

		Vector4 operator+(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x + v.x,
				u.y + v.y,
				u.z + v.z,
				u.w + v.w
			);
		}

		Vector4 operator-(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x - v.x,
				u.y - v.y,
				u.z - v.z,
				u.w - v.w
			);
		}

		Vector4 operator*(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x * v.x,
				u.y * v.y,
				u.z * v.z,
				u.w * v.w
			);
		}

		Vector4 operator/(const Vector4& u, const Vector4& v)
		{
			return Vector4
			(
				u.x / v.x,
				u.y / v.y,
				u.z / v.z,
				u.w / v.w
			);
		}

		bool operator==(const Vector4& u, const Vector4& v)
		{
			return (u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w);
		}

		bool operator!=(const Vector4& u, const Vector4& v)
		{
			return !(u == v);
		}

		float Vector4::dot(const Vector4& u, const Vector4& v)
		{
			Vector4 temp(u * v);
			return (temp.x + temp.y + temp.z + temp.w);
		}

		Vector4 Vector4::normalize(const Vector4& u)
		{
			return Vector4(u.x / u.magnitud, u.y / u.magnitud, u.z / u.magnitud, u.w / u.magnitud);
		}

		float Vector4::distance(const Vector4& u, const Vector4& v)
		{
			float x((u.x - v.x) * (u.x - v.x));
			float y((u.y - v.y) * (u.y - v.y));
			float z((u.z - v.z) * (u.z - v.z));
			float w((u.w - v.w) * (u.w - v.w));
			return sqrtf(x + y + z + w);
		}
	}
}